#include "stdafx.h"
#include "Network.h"
#include "RoomMgr.h"
#include "Client.h"
#include "Room.h"

CNetwork::CNetwork()
{
}


CNetwork::~CNetwork()
{
	Safe_Delete_Unordered_Map(m_mapClient);
}

bool CNetwork::Init(int nPortNum = SERVERPORT)
{
	int retVal;

	// 윈속 초기화
	WSADATA wsa;
	retVal = WSAStartup(MAKEWORD(2, 2), &wsa);
	if (retVal != 0)
	{
		printf("error WSAStartup() %d\n", retVal);
		return FALSE;
	}

	// listen socket
	m_Sock = socket(AF_INET, SOCK_STREAM, 0);
	if (m_Sock == INVALID_SOCKET)
	{
		printf("error listen socket()\n");
		return FALSE;
	}

	// bind
	SOCKADDR_IN serverAddr;
	ZeroMemory(&serverAddr, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(nPortNum);
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	retVal = bind(m_Sock, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
	if (retVal == SOCKET_ERROR)
	{
		printf("error bind()\n");
		return FALSE;
	}

	// listen
	retVal = listen(m_Sock, SOMAXCONN);
	if (retVal == SOCKET_ERROR)
	{
		printf("error listen()\n");
		return FALSE;
	}

	// 넌블로킹 소켓으로 전환
	u_long on = 1;
	retVal = ioctlsocket(m_Sock, FIONBIO, &on);
	if (retVal == SOCKET_ERROR)
	{
		printf("error ioctlsocket()\n");
		return FALSE;
	}


	cout << "Network Init" << endl;
	return TRUE;
}

bool CNetwork::Update()
{
	FD_Set();

	Select();

	Accept();

	// 소켓 셋 검사(2) : 데이터 통신
	// 각 방을 순회하면서 방에 있는 클라이언트들과 통신
	for (int i = 0; i < CRoomMgr::GetInst()->GetRoomCount(); ++i)
	{
		for (auto& client : CRoomMgr::GetInst()->GetClients(i))
		{
			bool result = DataRecv(client.second, i);
			if (FALSE == result)
				continue;

			result = BroadCast(client.second, i);
			if (FALSE == result)
				continue;
		}
	}

	return TRUE;
}

void CNetwork::Close()
{
	// 윈속 종료
	WSACleanup();
	return;
}

bool CNetwork::FD_Set()
{
	// 소켓 셋 초기화
	FD_ZERO(&rset);
	FD_ZERO(&wset);
	FD_SET(m_Sock, &rset);
	for (auto& client : m_mapClient)
	{
		if (client.second->recvBytes > client.second->sendBytes)
			FD_SET(client.second->sock, &wset);
		else
			FD_SET(client.second->sock, &rset);
	}
	return TRUE;
}

bool CNetwork::Select()
{
	// select()
	int retVal = select(0, &rset, &wset, NULL, NULL);
	if (retVal == SOCKET_ERROR)
	{
		printf("error select()\n");
		return FALSE;
	}
	return TRUE;
}

bool CNetwork::Accept()
{
	// 소켓 셋 검사(1) : 클라이언트 접속 수용
	if (FD_ISSET(m_Sock, &rset))
	{
		addrLen = sizeof(clientAddr);
		clientSock = accept(m_Sock, (SOCKADDR*)&clientAddr, &addrLen);
		if (clientSock == INVALID_SOCKET)
		{
			printf("error accept()\n");
			return FALSE;
		}
		else
		{
			char buf[16];
			inet_ntop(AF_INET, &clientAddr.sin_addr, buf, sizeof(buf));
			printf("[TCP 서버] 클라이언트 접속 : IP 주소 = %s, 포트 번호 = %d\n", buf, ntohs(clientAddr.sin_port));

			// 소켓 정보 추가
			if (FALSE == AddSocketInfo(clientSock))
				return FALSE;
		}
	}
	return TRUE;
}

bool CNetwork::DataRecv(const CClient* client, const int& roomNumber)
{
	SOCKETINFO* ptr = m_mapClient.find(client->GetID())->second;
	const char* name = CRoomMgr::GetInst()->GetClientName(ptr->sock, roomNumber);
	if (FD_ISSET(ptr->sock, &rset))
	{
		// 데이터 받기
		char temp;
		int retVal = recv(ptr->sock, &temp, 1, 0);
		if (retVal == SOCKET_ERROR)
		{
			printf("recv SOCKET_ERROR\n");
			RemoveSocketInfo(ptr->sock);
			CRoomMgr::GetInst()->RemoveClient(ptr->sock, roomNumber);
			return FALSE;
		}
		else if (retVal == 0)
		{
			printf("recv 0\n");
			RemoveSocketInfo(ptr->sock);
			CRoomMgr::GetInst()->RemoveClient(ptr->sock, roomNumber);
			return FALSE;
		}
		if (temp == '\n')
		{
			// 지금까지 모은 문자열을 바탕으로 명령어 체크
			m_eMsgType = CheckMessage(ptr->sock, ptr->buf, ptr->bufCount, roomNumber);

			ptr->buf[ptr->bufCount++] = temp;
			ptr->buf[ptr->bufCount] = '\0';

			// 초기화
			ptr->recvBytes = ptr->bufCount;
			ptr->bufCount = 0;

			// 받은 데이터 출력
			addrLen = sizeof(clientAddr);
			getpeername(ptr->sock, (SOCKADDR*)&clientAddr, &addrLen);
			//ptr->buf[retVal] = '\0';

			char buf[16]; // 클라이언트 IP 주소
			inet_ntop(AF_INET, &clientAddr.sin_addr, buf, sizeof(buf));
			printf("[TCP %s:%d] [%s] %s", buf, ntohs(clientAddr.sin_port), name, ptr->buf);

		}
		else
		{
			// 조립
			ptr->buf[ptr->bufCount++] = temp;
			ptr->buf[ptr->bufCount] = '\0';
		}
	}
	return TRUE;
}

bool CNetwork::BroadCast(const CClient * client, const int& roomNumber)
{
	SOCKETINFO* ptr = m_mapClient.find(client->GetID())->second;
	const char* name = CRoomMgr::GetInst()->GetClientName(ptr->sock, roomNumber);
	if (FD_ISSET(ptr->sock, &wset))
	{
		// 데이터 보내기
		for (auto& otherClient : m_mapClient)
		{
			// 자기자신
			if (otherClient.first == ptr->sock)
			{
				string msg{ "[Me] " };
				Send(otherClient.first, msg.c_str(), msg.size(), 0);
				continue;
			}
			else
			{
				// 기본적으로 같은 방에 있는 사람들에게만 브로드캐스팅

				// 아이디가 없다 == 로그인이 되어있지 않는 상태
				if (name[0] == '\0')
				{
					ptr->recvBytes = 0;
					ptr->sendBytes = 0;
					continue;
				}

				// 일반 채팅(명령어는 보이지 않는다)
				if (m_eMsgType != MSG_TYPE::NORMAL)
					continue;

				string msg = "[";
				msg += name;
				msg += "] ";
				Send(otherClient.first, msg.c_str(), msg.size(), 0);
				Send(otherClient.first, ptr->buf, ptr->recvBytes - ptr->sendBytes, 0);
			}
		}

		ptr->recvBytes = 0;
		ptr->sendBytes = 0;
	}
	return TRUE;
}

bool CNetwork::Send(const SOCKET& sock, const char * msg, const int& size, const int& roomNumber = -1)
{
	int retVal = send(sock, msg, size, 0);
	if (retVal == SOCKET_ERROR)
	{
		printf("send() SOCKET_ERROR\n");
		RemoveSocketInfo(sock);
		
		if(roomNumber != -1)
			CRoomMgr::GetInst()->RemoveClient(sock, roomNumber);
		// 해당 클라이언트 검색 후 제거
		else
			CRoomMgr::GetInst()->RemoveClient(sock);
		return FALSE;
	}
	return TRUE;
}

MSG_TYPE CNetwork::CheckMessage(const SOCKET& sock, const char* message, const int& bufCount, const int& roomNumber)
{
	MSG_TYPE eMsgType = MSG_TYPE::NORMAL;

	if (message[0] != '/')
		return eMsgType;

	// 명령어 조건 X
	if (bufCount < 3)
		return eMsgType;

	eMsgType = MSG_TYPE::NOTHING;

	// 메시지 공백 기준으로 분할
	vector<string> vecMsg = SplitString(message, ' ');

	// 로그인 명령
	if (message[1] == COMMAND_TYPE::LOGIN)
	{
		eMsgType = Login(sock, vecMsg, roomNumber);
	}

	// 명령어 안내 출력
	else if (message[1] == COMMAND_TYPE::HELP)
	{
		eMsgType = Help(sock, vecMsg, roomNumber);
	}

	// 대화방 목록 출력
	else if (message[1] == COMMAND_TYPE::SHOWROOMALL)
	{
		eMsgType = ShowRoomAll(sock, vecMsg, roomNumber);
	}

	// 대화방 정보 출력
	else if (message[1] == COMMAND_TYPE::SHOWROOM)
	{
		eMsgType = ShowRoom(sock, vecMsg, roomNumber);
	}

	// 대화방 생성
	else if (message[1] == COMMAND_TYPE::CREATEROOM)
	{
		eMsgType = CreateRoom(sock, vecMsg, roomNumber);
	}
	
	// 대화방 참가
	else if (message[1] == COMMAND_TYPE::JOINROOM)
	{
		eMsgType = JoinRoom(sock, vecMsg, roomNumber);
	}

	// 대화방 폭파
	else if (message[1] == COMMAND_TYPE::DESTROYROOM)
	{
		eMsgType = DestoryRoom(sock, vecMsg, roomNumber);
	}

	// 이용자 목록 출력
	else if (message[1] == COMMAND_TYPE::SHOWUSERALL)
	{
		eMsgType = ShowUserAll(sock, vecMsg, roomNumber);
	}

	// 이용자 검색
	else if (message[1] == COMMAND_TYPE::SHOWUSER)
	{
		eMsgType = ShowUser(sock, vecMsg, roomNumber);
	}

	// 쪽지 보내기
	else if (message[1] == COMMAND_TYPE::SENDMSG)
	{
		eMsgType = SendMsg(sock, vecMsg, roomNumber);
	}


	return eMsgType;
}

MSG_TYPE CNetwork::Login(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	CClient* client = CRoomMgr::GetInst()->GetClient(sock, roomNumber);
	if (NULL == client)
	{
		cout << "Login Func Null Error! \n";
		exit(1);
	}

	client->SetName(vecMsg[1].c_str());

	return MSG_TYPE::LOGIN_MSG;
}

MSG_TYPE CNetwork::Help(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	// Enum.h 에 정의한 명령어 키에 대응되어 출력되게끔
	string command = "/";
	string msg = "=========================================\n\r";
	msg.reserve(50);

	msg += command + char(COMMAND_TYPE::HELP);
	msg += "\t\t\t명령어 안내\n\r";

	msg += command + char(COMMAND_TYPE::LOGIN);
	msg += "\t\t\t로그인\n\r";

	msg += command + char(COMMAND_TYPE::SHOWUSERALL);
	msg += "\t\t\t이용자 목록 보기\n\r";

	msg += command + char(COMMAND_TYPE::SHOWROOMALL);
	msg += "\t\t\t대화방 목록 보기\n\r";

	msg += command + char(COMMAND_TYPE::SHOWROOM);
	msg += " [방번호]";
	msg += "\t\t대화방 정보 보기\n\r";

	msg += command + char(COMMAND_TYPE::SHOWUSER);
	msg += " [상대방ID]";
	msg += "\t\t이용자 정보 보기\n\r";

	msg += command + char(COMMAND_TYPE::SENDMSG);
	msg += " [방번호] [메시지]";
	msg += "\t쪽지 보내기\n\r";

	msg += command + char(COMMAND_TYPE::CREATEROOM);
	msg += " [최대인원] [방제목]";
	msg += "\t대화방 만들기\n\r";

	msg += command + char(COMMAND_TYPE::JOINROOM);
	msg += " [방번호]";
	msg += "\t\t대화방 참여하기\n\r";

	msg += command + char(COMMAND_TYPE::DESTROYROOM);
	msg += "\t\t\t대화방 끝내기\n\r";

	msg += command + char(COMMAND_TYPE::CLOSE);
	msg += "\t\t\t끝내기\n\r";

	msg += "=========================================\n\r";
	Send(sock, msg.c_str(), msg.size(), 0);

	return MSG_TYPE::HELP_MSG;
}

MSG_TYPE CNetwork::ShowRoomAll(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	vector<int> vecNumber = CRoomMgr::GetInst()->GetRoomNumberArray();
	string msg;
	msg.reserve(50);
	for (auto& num : vecNumber)
	{
		const CRoom* room = CRoomMgr::GetInst()->GetRoom(num);
		if (NULL == room)
		{
			cout << "ShowRoomAll Func Null Error! \n";
			exit(1);
		}

		msg += "[";
		msg += to_string(room->GetNumber());
		msg += "] ";
		msg += room->GetRoomName();
		msg += " [";
		msg += to_string(room->GetCurrentUser());
		msg += "/";
		msg += to_string(room->GetMaxUser());
		msg += "]\n\r";
	}
	Send(sock, msg.c_str(), msg.size(), 0);

	return MSG_TYPE::SHOWROOMALL_MSG;
}

MSG_TYPE CNetwork::ShowRoom(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	int number = atoi(vecMsg[1].c_str());
	const CRoom* room = CRoomMgr::GetInst()->GetRoom(number);
	if (NULL == room)
	{
		cout << "ShowRoom Func Null Error! \n";
		exit(1);
	}

	string msg;
	msg.reserve(50);

	msg += "[";
	msg += to_string(room->GetNumber());
	msg += "] ";
	msg += room->GetRoomName();
	msg += " [";
	msg += to_string(room->GetCurrentUser());
	msg += "/";
	msg += to_string(room->GetMaxUser());
	msg += "]\n\r";

	unordered_map<int, CClient*> mapClient = CRoomMgr::GetInst()->GetClients(number);
	int index = 0;
	for (auto& client : mapClient)
	{
		msg += "[";
		msg += to_string(index);
		msg += "] ";
		msg += client.second->GetName();
		msg += "\n\r";
	}

	Send(sock, msg.c_str(), msg.size(), 0);

	return MSG_TYPE::SHOWROOM_MSG;
}

MSG_TYPE CNetwork::CreateRoom(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	int maxUser = atoi(vecMsg[1].c_str());
	string strRoomName = "";
	for (int i = 2; i < vecMsg.size(); ++i)
	{
		strRoomName += vecMsg[i];
		if (i + 1 < vecMsg.size())
			strRoomName += " ";
	}
	cout << strRoomName.c_str() << endl;
	string msg;
	// 문자열이 섞이는 등 이상하게 입력 받은 경우
	if (maxUser == 0)
	{
		msg = "잘못된 명령어 입니다. 다시 확인해주세요.\n\r";
		Send(sock, msg.c_str(), msg.size(), roomNumber);
		return MSG_TYPE::NOTHING;
	}

	bool result = CRoomMgr::GetInst()->CreateRoom(strRoomName.c_str(), maxUser);
	// 방 생성 실패
	if (FALSE == result)
	{
		msg = "대화방을 생성할 수 없습니다.\n\r";
		Send(sock, msg.c_str(), msg.size(), roomNumber);
		return MSG_TYPE::NOTHING;
	}

	msg += strRoomName;
	msg += " [";
	msg += to_string(maxUser);
	msg += "] 가 생성되었습니다.\n\r";
	Send(sock, msg.c_str(), msg.size(), roomNumber);

	return MSG_TYPE::CREATEROOM_MSG;
}

MSG_TYPE CNetwork::JoinRoom(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	int newRoomNumber = atoi(vecMsg[1].c_str());
	bool result = CRoomMgr::GetInst()->JoinRoom(sock, roomNumber, newRoomNumber);
	// 정원 초과
	if (FALSE == result)
	{
		cout << "정원 초과\n\r" << endl;
		return MSG_TYPE::JOINROOM_MSG;
	}
	return MSG_TYPE::JOINROOM_MSG;
}

MSG_TYPE CNetwork::DestoryRoom(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	return MSG_TYPE::DESTROYROOM_MSG;
}

MSG_TYPE CNetwork::ShowUserAll(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	return MSG_TYPE::SHOWUSERALL_MSG;
}

MSG_TYPE CNetwork::ShowUser(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	return MSG_TYPE::SHOWUSER_MSG;
}

MSG_TYPE CNetwork::SendMsg(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	return MSG_TYPE::SENDMSG_MSG;
}

BOOL CNetwork::AddSocketInfo(const SOCKET& sock)
{
	if (m_mapClient.size() > FD_SETSIZE)
	{
		printf("[오류] 소켓 정보를 추가할 수 없습니다\n");
		return FALSE;
	}

	SOCKETINFO* ptr = new SOCKETINFO;
	if (ptr == NULL)
	{
		printf("[오류] 메모리가 부족합니다\n");
		return FALSE;
	}

	ptr->sock = sock;
	ptr->recvBytes = 0;
	ptr->sendBytes = 0;
	ptr->bufCount = 0;

	// Client ID 및 시작 방 번호 초기화
	CRoomMgr::GetInst()->AddClient(ptr->sock, 0);

	m_mapClient[ptr->sock] = ptr;

	string msg { "=========================================\n\r\t환영합니다 채팅서버 입니다.\n\n\r\t로그인 명령어(/l)을 사용해주세요.\n\n\n\r\t명령어 안내(/h)\n\r=========================================\n\r[Me] " };
	Send(ptr->sock, msg.c_str(), msg.size(), 0);

	return TRUE;
}

void CNetwork::RemoveSocketInfo(const SOCKET& socket)
{
	// 클라이언트 정보 얻기
	SOCKADDR_IN clientAddr;
	int addrLen = sizeof(clientAddr);
	getpeername(socket, (SOCKADDR*)&clientAddr, &addrLen);
	char buf[16];
	inet_ntop(AF_INET, &clientAddr.sin_addr, buf, sizeof(buf));
	printf("[TCP 서버] 클라이언트 종료: IP 주소 = %s, 포트 번호 = %d\n", buf, ntohs(clientAddr.sin_port));

	m_mapClient.erase(socket);
	CRoomMgr::GetInst()->RemoveClient(socket);
	closesocket(socket);
}
