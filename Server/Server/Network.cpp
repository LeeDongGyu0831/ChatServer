#include "stdafx.h"
#include "Network.h"
#include "RoomMgr.h"
#include "Client.h"
#include "Room.h"

CNetwork::CNetwork() : m_nClientCount(0)
{
	m_mapClient.clear();
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
	serverAddr.sin_port = htons(u_short(nPortNum));
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

	IN_ADDR addr;

	addr = GetDefaultMyIP();//디폴트 IPv4 주소 얻어오기
	cout << "IP\t[" << inet_ntoa(addr) << "]\n";

	cout << "Port\t[" << nPortNum << "]\n";
	cout << "MaxUser\t[" << MAXUSER << "]\n\tNetwork Init\n";
	return TRUE;
}

bool CNetwork::Update()
{
	FD_Set();

	Select();

	Accept();

	// 소켓 셋 검사(2) : 데이터 통신
	// 각 방을 순회하면서 방에 있는 클라이언트들과 통신

	for (auto& clientSocket : m_mapClient)
	{
		bool result = DataRecv(clientSocket.second);
		if (FALSE == result)
			break;

		result = BroadCast(clientSocket.second);
		if (FALSE == result)
			break;
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
	FD_ZERO(&m_rset);
	FD_ZERO(&m_wset);
	FD_SET(m_Sock, &m_rset);
	for (auto& client : m_mapClient)
	{
		if (client.second->recvBytes > client.second->sendBytes)
			FD_SET(client.second->sock, &m_wset);
		else
			FD_SET(client.second->sock, &m_rset);
	}
	return TRUE;
}

bool CNetwork::Select()
{
	// select()
	int retVal = select(0, &m_rset, &m_wset, NULL, NULL);
	if (retVal == SOCKET_ERROR)
	{
		printf("error select()\n");
		return FALSE;
	}
	return TRUE;
}

bool CNetwork::Accept()
{
	// 한계 초과
	if (m_nClientCount >= MAXUSER)
		return FALSE;

	// 소켓 셋 검사(1) : 클라이언트 접속 수용
	if (FD_ISSET(m_Sock, &m_rset))
	{
		m_nAddrLen = sizeof(m_addrClientSock);
		m_sockClient = accept(m_Sock, (SOCKADDR*)&m_addrClientSock, &m_nAddrLen);
		if (m_sockClient == INVALID_SOCKET)
		{
			printf("error accept()\n");
			return FALSE;
		}
		else
		{
			// 클라이언트 IP 주소
			char buf[IP_ADDR_LEN];
			inet_ntop(AF_INET, &m_addrClientSock.sin_addr, buf, sizeof(buf));
			printf("[TCP 서버] 클라이언트 접속 : IP 주소 = %s, 포트 번호 = %d\n", buf, ntohs(m_addrClientSock.sin_port));

			// 소켓 정보 추가
			if (FALSE == AddSocketInfo(m_sockClient))
				return FALSE;
		}
	}
	m_nClientCount++;
	return TRUE;
}

bool CNetwork::DataRecv(SOCKETINFO* sock)
{
	int roomNumber = CRoomMgr::GetInst()->GetRoomNumber(sock->sock);
	const char* name = CRoomMgr::GetInst()->GetClientName(sock->sock, roomNumber);
	if (FD_ISSET(sock->sock, &m_rset))
	{
		// 데이터 받기
		char temp;
		int retVal = recv(sock->sock, &temp, 1, 0);
		if (retVal == SOCKET_ERROR)
		{
			printf("recv SOCKET_ERROR\n");
			RemoveSocketInfo(sock->sock);
			CRoomMgr::GetInst()->RemoveClient(sock->sock, roomNumber);
			return FALSE;
		}
		else if (retVal == 0)
		{
			printf("recv 0\n");
			RemoveSocketInfo(sock->sock);
			CRoomMgr::GetInst()->RemoveClient(sock->sock, roomNumber);
			return FALSE;
		}
		if (temp == '\n')
		{
			// 지금까지 모은 문자열을 바탕으로 명령어 체크
			m_eMsgType = CheckMessage(sock->sock, sock->buf, sock->bufCount, roomNumber);
			if (MSG_TYPE::NOTHING == m_eMsgType)
			{
				string msg;
				msg = "잘못된 명령어 입니다. 다시 확인해주세요.\n\r";
				Send(sock->sock, msg.c_str(), msg.size(), roomNumber);
			}
			if (MSG_TYPE::CLOSE_MSG == m_eMsgType)
			{
				return FALSE;
			}
			sock->buf[sock->bufCount++] = temp;
			sock->buf[sock->bufCount] = '\0';

			// 초기화
			sock->recvBytes = sock->bufCount;
			sock->bufCount = 0;

			// 받은 데이터 출력
			m_nAddrLen = sizeof(m_addrClientSock);
			getpeername(sock->sock, (SOCKADDR*)&m_addrClientSock, &m_nAddrLen);
			//ptr->buf[retVal] = '\0';

			char buf[IP_ADDR_LEN]; // 클라이언트 IP 주소
			inet_ntop(AF_INET, &m_addrClientSock.sin_addr, buf, sizeof(buf));
			printf("[TCP %s:%d] [%s] %s", buf, ntohs(m_addrClientSock.sin_port), name, sock->buf);

		}
		else
		{
			// 조립
			if (sock->bufCount < BUFSIZE)
			{
				sock->buf[sock->bufCount++] = temp;
				sock->buf[sock->bufCount] = '\0';
			}
		}
	}
	return TRUE;
}

bool CNetwork::BroadCast(SOCKETINFO* sock)
{
	int roomNumber = CRoomMgr::GetInst()->GetRoomNumber(sock->sock);
	const char* name = CRoomMgr::GetInst()->GetClientName(sock->sock, roomNumber);
	if (FD_ISSET(sock->sock, &m_wset))
	{
		// 데이터 보내기
		for (auto& otherClient : m_mapClient)
		{
			// 자기자신
			if (otherClient.first == sock->sock)
			{
				string msg{ ">> " };
				Send(otherClient.first, msg.c_str(), msg.size(), 0);
				continue;
			}
			else
			{
				// 기본적으로 같은 방에 있는 사람들에게만 브로드캐스팅
				// 로그인룸은 브로드캐스팅 X
				if (CRoomMgr::GetInst()->GetRoomNumber(otherClient.first) != roomNumber)
				{
					sock->recvBytes = 0;
					sock->sendBytes = 0;
					continue;
				}
				if (roomNumber == int(ROOM_TYPE::LOGIN_ROOM))
				{
					sock->recvBytes = 0;
					sock->sendBytes = 0;
					continue;
				}

				// 일반 채팅(명령어는 보이지 않는다)
				if (m_eMsgType != MSG_TYPE::NORMAL)
					continue;

				string msg = "\r[";
				msg += name;
				msg += "] ";
				Send(otherClient.first, msg.c_str(), msg.size(), 0);
				Send(otherClient.first, sock->buf, sock->recvBytes - sock->sendBytes, 0);
				Send(otherClient.first, ">> ", 3, 0);
			}
		}

		sock->recvBytes = 0;
		sock->sendBytes = 0;
	}
	return TRUE;
}

IN_ADDR CNetwork::GetDefaultMyIP()
{
	char localhostname[MAX_PATH];
	IN_ADDR addr = { 0, };

	if (gethostname(localhostname, MAX_PATH) == SOCKET_ERROR)//호스트 이름 얻어오기
	{
		return addr;
	}
	HOSTENT *ptr = gethostbyname(localhostname);//호스트 엔트리 얻어오기
	while (ptr && ptr->h_name)
	{
		if (ptr->h_addrtype == PF_INET)//IPv4 주소 타입일 때
		{
			memcpy(&addr, ptr->h_addr_list[0], ptr->h_length);//메모리 복사
			break;
		}
		ptr++;
	}
	return addr;
}

bool CNetwork::Send(const SOCKET& sock, const char * msg, const int& size, const int& roomNumber = NONE)
{
	int retVal = send(sock, msg, size, 0);
	if (retVal == SOCKET_ERROR)
	{
		printf("send() SOCKET_ERROR\n");
		RemoveSocketInfo(sock);
		
		if(roomNumber != NONE)
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

	// 명령어가 아니라면 바로 리턴하여 브로드캐스팅을 할 수 있도록
	if (message[0] != '/')
		return eMsgType;

	// 명령어 조건 X
	// 명령어는 /r, /l 등등으로 시작하기 때문에 MINIMUM 보다 작으면 성립이 불가능
	if (bufCount < MINIMUM_LEN)
		return eMsgType;

	eMsgType = MSG_TYPE::NOTHING;

	// 메시지 공백 기준으로 분할
	vector<string> vecMsg = SplitString(message, ' ');
	// 0번 인덱스에는 /r, /l, /c 등등..
	// 1번 인덱스부터 단어들 나열

	if (roomNumber == int(ROOM_TYPE::LOGIN_ROOM))
	{
		// 로그인 룸에서는 로그인명령과 도움말명령만 인식
		if (message[COMMAND] != int(COMMAND_TYPE::LOGIN) &&
			message[COMMAND] != int(COMMAND_TYPE::HELP))
			return eMsgType;
	}

	switch (message[COMMAND])
	{
	case COMMAND_TYPE::LOGIN:
		// 로그인 명령
		eMsgType = Login(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::HELP:
		// 명령어 안내 출력
		eMsgType = Help(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::SHOWROOMALL:
		// 대화방 목록 출력
		eMsgType = ShowRoomAll(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::SHOWROOM:
		// 대화방 정보 출력
		eMsgType = ShowRoom(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::CREATEROOM:
		// 대화방 생성
		eMsgType = CreateRoom(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::JOINROOM:
		// 대화방 참가
		eMsgType = JoinRoom(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::DESTROYROOM:
		// 대화방 폭파
		eMsgType = DestoryRoom(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::SHOWUSERALL:
		// 이용자 목록 출력
		eMsgType = ShowUserAll(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::SHOWUSER:
		// 특정 이용자 검색
		eMsgType = ShowUser(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::SENDMSG:
		// 귓속말
		eMsgType = SendMsg(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::CLOSE:
		// 접속 종료
		eMsgType = Close(sock, vecMsg, roomNumber);
		break;
	default:
		break;
	}

	return eMsgType;
}

void CNetwork::BroadCastMessage(const SOCKET & sock, const char * message, const int & bufCount, const int & roomNumber)
{
	// 해당 클라이언트 외에 방에 존재하는 다른 모든 클라이언트에게 뿌려주는 메시지 전송 함수
	unordered_map<int, CClient*> mapClient = CRoomMgr::GetInst()->GetClients(roomNumber);
	for (auto& client : mapClient)
	{
		if (sock == client.first)
		{
			continue;
		}
		Send(client.first, "\r", 1, roomNumber);
		Send(client.first, message, bufCount, roomNumber);
		Send(client.first, ">> ", 3, roomNumber);
	}
	cout << "[" << message << "] Message BroadCast\n";
}

MSG_TYPE CNetwork::Login(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	CClient* client = CRoomMgr::GetInst()->GetClient(sock, roomNumber);
	if (NULL == client)
	{
		cout << "Login Func Null Error! \n";
		exit(1);
	}
	// 로그인이 되어있는 상태에서 다시 로그인을 시도하는 경우
	if (int(ROOM_TYPE::LOGIN_ROOM) != roomNumber)
	{
		return MSG_TYPE::NOTHING;
	}
	client->SetName(vecMsg[KEYWORD].c_str());

	string logMsg;
	logMsg += "[";
	logMsg += vecMsg[KEYWORD].c_str();
	logMsg += "] 으로 로그인 하였습니다..\n\r";
	Send(sock, logMsg.c_str(), logMsg.size(), roomNumber);

	CRoomMgr::GetInst()->JoinRoom(sock, int(ROOM_TYPE::LOGIN_ROOM), int(ROOM_TYPE::MAIN_ROOM));

	CRoom* pMainRoom = CRoomMgr::GetInst()->GetRoom(int(ROOM_TYPE::MAIN_ROOM));
	{
		string msg;
		msg += pMainRoom->GetRoomName();
		msg += " [";
		msg += to_string(pMainRoom->GetCurrentUser());
		msg += "/";
		msg += to_string(pMainRoom->GetMaxUser());
		msg += "] 에 참가하였습니다.\n\r";
		Send(sock, msg.c_str(), msg.size(), roomNumber);
	}

	{
		string msg;
		msg += pMainRoom->GetRoomName();
		msg += " [";
		msg += to_string(pMainRoom->GetCurrentUser());
		msg += "/";
		msg += to_string(pMainRoom->GetMaxUser());
		msg += "] 에 [";
		msg += vecMsg[KEYWORD].c_str();
		msg += "] 님이 참가하였습니다.\n\r";
		BroadCastMessage(sock, msg.c_str(), msg.size(), int(ROOM_TYPE::MAIN_ROOM));
	}

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
	msg += " [아이디] [메시지]";
	msg += "\t쪽지 보내기\n\r";

	msg += command + char(COMMAND_TYPE::CREATEROOM);
	msg += " [최대인원] [방제목]";
	msg += "\t대화방 만들기\n\r";

	msg += command + char(COMMAND_TYPE::JOINROOM);
	msg += " [방번호]";
	msg += "\t\t대화방 참여하기\n\r";

	msg += command + char(COMMAND_TYPE::DESTROYROOM);
	msg += " [방번호]";
	msg += "\t\t대화방 끝내기\n\r";

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

	return MSG_TYPE::SHOWROOMALL_MSG;;
}

MSG_TYPE CNetwork::ShowRoom(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	// /명령어 [방번호]
	int number = atoi(vecMsg[KEYWORD].c_str());
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
	// /명령어 [최대인원] [방제목] 이기 때문에 1번 인덱스에 최대인원 문자열이 담겨있음
	int maxUser = atoi(vecMsg[KEYWORD].c_str());
	string strRoomName = "";
	for (size_t i = 2; i < vecMsg.size(); ++i)
	{
		// 띄어쓰기도 포함하여 제목을 달기 위해서
		strRoomName += vecMsg[i];
		if (i + 1 < vecMsg.size())
			strRoomName += " ";
	}
	
	// 문자열이 섞이는 등 이상하게 입력 받은 경우
	if (maxUser <= 0)
	{
		return MSG_TYPE::NOTHING;
	}

	bool result = CRoomMgr::GetInst()->CreateRoom(strRoomName.c_str(), maxUser);
	// 방 생성 실패
	if (FALSE == result)
	{
		//string msg;
		//msg = "대화방을 생성할 수 없습니다.\n\r";
		//Send(sock, msg.c_str(), msg.size(), roomNumber);
		return MSG_TYPE::NOTHING;
	}
	string msg;
	msg += strRoomName;
	msg += " [";
	msg += to_string(maxUser);
	msg += "] 가 생성되었습니다.\n\r";
	Send(sock, msg.c_str(), msg.size(), roomNumber);

	return MSG_TYPE::CREATEROOM_MSG;
}

MSG_TYPE CNetwork::JoinRoom(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	// /명령어 [방번호]
	int newRoomNumber = atoi(vecMsg[KEYWORD].c_str());
	// 들어가려는 방과 현재 내 방이 같은 상황
	if (newRoomNumber == roomNumber)
	{
		return MSG_TYPE::NOTHING;
	}

	bool result = CRoomMgr::GetInst()->JoinRoom(sock, roomNumber, newRoomNumber);
	// 정원 초과 or 해당 방이 없음
	if (FALSE == result)
	{

		return MSG_TYPE::NOTHING;
	}

	CRoom* room = CRoomMgr::GetInst()->GetRoom(newRoomNumber);
	{
		string msg;
		msg += room->GetRoomName();
		msg += " [";
		msg += to_string(room->GetCurrentUser());
		msg += "/";
		msg += to_string(room->GetMaxUser());
		msg += "] 에 참가하였습니다.\n\r";
		Send(sock, msg.c_str(), msg.size(), roomNumber);
	}

	{
		string msg;
		msg += room->GetRoomName();
		msg += " [";
		msg += to_string(room->GetCurrentUser());
		msg += "/";
		msg += to_string(room->GetMaxUser());
		msg += "] 에 [";
		msg += vecMsg[KEYWORD].c_str();
		msg += "] 님이 퇴장하였습니다.\n\r";
		BroadCastMessage(sock, msg.c_str(), msg.size(), roomNumber);
	}

	{
		string msg;
		msg += room->GetRoomName();
		msg += " [";
		msg += to_string(room->GetCurrentUser());
		msg += "/";
		msg += to_string(room->GetMaxUser());
		msg += "] 에 [";
		msg += vecMsg[KEYWORD].c_str();
		msg += "] 님이 참가하였습니다.\n\r";
		BroadCastMessage(sock, msg.c_str(), msg.size(), newRoomNumber);
	}

	return MSG_TYPE::JOINROOM_MSG;
}

MSG_TYPE CNetwork::DestoryRoom(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	// /명령어 [방번호]
	int destoryNumber = atoi(vecMsg[KEYWORD].c_str());
	bool result = CRoomMgr::GetInst()->DestroyRoom(destoryNumber);
	// 폭파 실패
	if (FALSE == result)
	{
		return MSG_TYPE::NOTHING;
	}
	return MSG_TYPE::DESTROYROOM_MSG;
}

MSG_TYPE CNetwork::ShowUserAll(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	vector<int> vecNum = CRoomMgr::GetInst()->GetRoomNumberArray();
	for (auto& num : vecNum)
	{
		if (num == int(ROOM_TYPE::LOGIN_ROOM))
			continue;
		unordered_map<int, CClient*> mapClient = CRoomMgr::GetInst()->GetClients(num);
		CRoom* room = CRoomMgr::GetInst()->GetRoom(num);
		for (auto& client : mapClient)
		{
			string msg;
			msg += "아이디 : [";
			msg += client.second->GetName();
			msg += "] \t\t대화방 번호 : [";
			msg += to_string(num);
			msg += "] ";
			msg += room->GetRoomName();
			msg += " (";
			msg += to_string(room->GetCurrentUser());
			msg += "/";
			msg += to_string(room->GetMaxUser());
			msg += ")\n\r";

			Send(sock, msg.c_str(), msg.size());
		}
	}
	return MSG_TYPE::SHOWUSERALL_MSG;
}

MSG_TYPE CNetwork::ShowUser(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	CClient* client = CRoomMgr::GetInst()->GetClientByName(vecMsg[KEYWORD].c_str());
	if (NULL == client)
	{
		// 해당 유저를 찾을 수 없음
		return  MSG_TYPE::SHOWUSER_MSG;
	}
	int num = client->GetRoomNumber();
	CRoom* room = CRoomMgr::GetInst()->GetRoom(num);
	string msg;
	msg += "아이디 : [";
	msg += client->GetName();
	msg += "] \t\t대화방 번호 : [";
	msg += to_string(num);
	msg += "] ";
	msg += room->GetRoomName();
	msg += " (";
	msg += to_string(room->GetCurrentUser());
	msg += "/";
	msg += to_string(room->GetMaxUser());
	msg += ")\n\r";

	Send(sock, msg.c_str(), msg.size());
	return MSG_TYPE::SHOWUSER_MSG;
}

MSG_TYPE CNetwork::SendMsg(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	CClient* client = CRoomMgr::GetInst()->GetClientByName(vecMsg[KEYWORD].c_str());
	if (NULL == client)
	{
		// 해당 유저를 찾을 수 없음
		return  MSG_TYPE::NOTHING;
	}
	//int num = client->GetRoomNumber();
	//CRoom* room = CRoomMgr::GetInst()->GetRoom(num);
	
	string msg = "\r[귓속말] [";
	msg += client->GetName();
	msg += "] ";
	for (size_t i = KEYWORD + 1; i < vecMsg.size(); ++i)
	{
		msg += vecMsg[i];
		if (i + 1 < vecMsg.size())
			msg += " ";
	}
	msg += "\n\r";
	Send(client->GetID(), msg.c_str(), msg.size());

	return MSG_TYPE::SENDMSG_MSG;
}

MSG_TYPE CNetwork::Close(const SOCKET & sock, const vector<string>& vecMsg, const int & roomNumber)
{
	RemoveSocketInfo(sock);
	return MSG_TYPE::CLOSE_MSG;
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
	CRoomMgr::GetInst()->AddClient(ptr->sock, int(ROOM_TYPE::LOGIN_ROOM));

	m_mapClient[ptr->sock] = ptr;

	string msg { "=========================================\n\r\t환영합니다 채팅서버 입니다.\n\n\r\t로그인 명령어(/l)을 사용해주세요.\n\n\n\r\t명령어 안내(/h)\n\r=========================================\n\r>> " };
	Send(ptr->sock, msg.c_str(), msg.size(), 0);

	return TRUE;
}

void CNetwork::RemoveSocketInfo(const SOCKET& socket)
{
	// 클라이언트 정보 얻기
	SOCKADDR_IN clientAddr;
	int addrLen = sizeof(clientAddr);
	getpeername(socket, (SOCKADDR*)&clientAddr, &addrLen);
	char buf[IP_ADDR_LEN];
	inet_ntop(AF_INET, &clientAddr.sin_addr, buf, sizeof(buf));
	printf("[TCP 서버] 클라이언트 종료: IP 주소 = %s, 포트 번호 = %d\n", buf, ntohs(clientAddr.sin_port));

	m_mapClient.erase(socket);
	CRoomMgr::GetInst()->RemoveClient(socket);
	closesocket(socket);
	m_nClientCount--;
}
