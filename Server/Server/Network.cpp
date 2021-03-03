#include "stdafx.h"
#include "Network.h"
#include "RoomMgr.h"
#include "Client.h"
#include "Room.h"

CNetwork::CNetwork() : m_nClientCount(0)
{
	m_mapClient.clear();
	m_mapNamePool.clear();
}


CNetwork::~CNetwork()
{
	Safe_Delete_Unordered_Map(m_mapClient);
	m_mapNamePool.clear();
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

			string msg{ "=================================================\n\r\t환영합니다 채팅서버 입니다.\n\n\r\t로그인 명령어(/l)을 사용해주세요.\n\n\n\r\t명령어 안내(/h)\n\r=================================================\n\r" };
			Send(m_sockClient, msg.c_str(), msg.size(), 0);

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
	uint roomNumber = CRoomMgr::GetInst()->GetRoomNumber(sock->sock);
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
			if (int(MSG_TYPE::ERROR_MSG) <= int(m_eMsgType) && int(m_eMsgType) < int(MSG_TYPE::ERROR_END))
			{
				CheckErrorMsgType(sock->sock, m_eMsgType, roomNumber);
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
				// 백스페이스를 누를 경우
				if (temp == char(BACKSPACE) &&
					sock->bufCount > 0)
				{
					// 기존 클라이언트 콘솔창 문자열을 공백으로 덧씌우기
					string space;
					space.resize(sock->bufCount, ' ');
					Send(sock->sock, space.c_str(), space.size(), roomNumber);

					sock->buf[--sock->bufCount] = '\0';

					// 줄어든 문자열로 덮어쓰기
					string msg = "\r>> ";
					Send(sock->sock, msg.c_str(), msg.size(), roomNumber);
					msg = "";
					msg += sock->buf;
					Send(sock->sock, msg.c_str(), msg.size(), roomNumber);
				}
				else
				{
					sock->buf[sock->bufCount++] = temp;
					sock->buf[sock->bufCount] = '\0';
				}
			}
		}
	}
	return TRUE;
}

bool CNetwork::BroadCast(SOCKETINFO* sock)
{
	uint roomNumber = CRoomMgr::GetInst()->GetRoomNumber(sock->sock);
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
				if (CRoomMgr::GetInst()->GetRoomNumber(otherClient.first) != roomNumber ||
					roomNumber == uint(ROOM_TYPE::LOGIN_ROOM))
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
				if (m_mapClient[otherClient.first]->bufCount > 0)
				{
					// 입력하던거 마저 보내주는
					Send(otherClient.first, m_mapClient[otherClient.first]->buf, m_mapClient[otherClient.first]->bufCount, 0);
				}
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

bool CNetwork::Send(const SOCKET& sock, const char * msg, const uint& size, const uint& roomNumber = NONE)
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

MSG_TYPE CNetwork::CheckMessage(const SOCKET& sock, const char* message, const uint& bufCount, const uint& roomNumber)
{
	MSG_TYPE eMsgType = MSG_TYPE::NORMAL;

	// 명령어가 아니라면 바로 리턴하여 브로드캐스팅을 할 수 있도록
	if (message[0] != '/')
		return eMsgType;

	// 명령어 조건 X
	// 명령어는 /r, /l 등등으로 시작하기 때문에 MINIMUM 보다 작으면 성립이 불가능
	if (bufCount < MINIMUM_LEN)
		return eMsgType;

	eMsgType = MSG_TYPE::ERROR_MSG;

	// 메시지 공백 기준으로 분할
	vector<string> vecMsg = SplitString(message, ' ');
	// 0번 인덱스에는 /r, /l, /c 등등..
	// 1번 인덱스부터 단어들 나열
	if (vecMsg[0].size() != 2)
	{
		return eMsgType;
	}

	if (roomNumber == uint(ROOM_TYPE::LOGIN_ROOM))
	{
		// 로그인 룸에서는 로그인명령과 도움말명령만 인식
		if (message[COMMAND] != uint(COMMAND_TYPE::LOGIN) &&
			message[COMMAND] != uint(COMMAND_TYPE::HELP))
			return MSG_TYPE::MUST_LOGIN_MSG;
	}

	switch (message[COMMAND])
	{
	case COMMAND_TYPE::LOGIN:
		// 로그인 명령
		eMsgType = Login(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::HELP:
		// 명령어 안내 출력
		eMsgType = Help(sock);
		break;
	case COMMAND_TYPE::SHOWROOMALL:
		// 대화방 목록 출력
		eMsgType = ShowRoomAll(sock);
		break;
	case COMMAND_TYPE::SHOWROOM:
		// 대화방 정보 출력
		eMsgType = ShowRoom(sock, vecMsg);
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
		eMsgType = DestoryRoom(vecMsg);
		break;
	case COMMAND_TYPE::SHOWUSERALL:
		// 이용자 목록 출력
		eMsgType = ShowUserAll(sock);
		break;
	case COMMAND_TYPE::SHOWUSER:
		// 특정 이용자 검색
		eMsgType = ShowUser(sock, vecMsg);
		break;
	case COMMAND_TYPE::SENDMSG:
		// 귓속말
		eMsgType = SendMsg(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::CLOSE:
		// 접속 종료
		eMsgType = Close(sock);
		break;
	default:
		break;
	}

	return eMsgType;
}

void CNetwork::BroadCastMessage(const SOCKET & sock, const char * message, const uint & bufCount, const uint & roomNumber)
{
	// 해당 클라이언트 외에 방에 존재하는 다른 모든 클라이언트에게 뿌려주는 메시지 전송 함수
	unordered_map<uint, CClient*> mapClient = CRoomMgr::GetInst()->GetClients(roomNumber);
	for (auto& client : mapClient)
	{
		if (sock == client.first ||
			roomNumber == uint(ROOM_TYPE::LOGIN_ROOM))
		{
			continue;
		}
		// 기존 다른 클라이언트들은 >> 로 입력을 대기받는 모습을 보여주기 때문에 덮어씌움으로써 자연스럽게 출력되도록
		Send(client.first, "\r", 1, roomNumber);
		Send(client.first, message, bufCount, roomNumber);
		Send(client.first, ">> ", 3, roomNumber);
	}
}

void CNetwork::CheckErrorMsgType(const SOCKET & sock, MSG_TYPE eType, const uint& roomNumber)
{
	string msg;
	switch (eType)
	{
	case MSG_TYPE::ERROR_MSG:
		msg = "/      잘못된 명령어 입니다. 다시 확인해주세요.\n\r";
		break;
	case MSG_TYPE::DO_NOT_LOGIN_MSG:
		msg = "/      이미 로그인 했습니다. 다시 확인해주세요.\n\r";
		break;
	case MSG_TYPE::MUST_LOGIN_MSG:
		msg = "/      로그인을 먼저 해야합니다. 다시 확인해주세요.\n\r";
		break;
	case MSG_TYPE::CANT_LOGIN_MSG:
		msg = "/      로그인할 수 없습니다. 다시 확인해주세요.\n\r";
		break;
	case MSG_TYPE::CANT_USE_ID_MSG:
		msg = "/      사용중인 아이디입니다. 다시 확인해주세요.\n\r";
		break;
	case MSG_TYPE::CANT_SEARCH_USER_MSG:
		msg = "/      해당 유저를 찾을 수 없습니다. 다시 확인해주세요.\n\r";
		break;
	case MSG_TYPE::CANT_SEARCH_ROOM_MSG:
		msg = "/      해당 대화방이 존재하지 않습니다. 다시 확인해주세요.\n\r";
		break;
	case MSG_TYPE::CANT_CREATE_ROOM_MSG:
		msg = "/      해당 대화방을 개설할 수 없습니다. 다시 확인해주세요.\n\r";
		break;
	case MSG_TYPE::CANT_JOIN_ROOM_MSG:
		msg = "/      해당 대화방에 참가할 수 없습니다. 다시 확인해주세요.\n\r";
		break;
	case MSG_TYPE::NO_MSG:
		msg = "/      전송할 수 없습니다 메시지를 확인해주세요.\n\r";
		break;
	default:
		msg = " /     정의되지 않은 에러 명령입니다. 다시 확인해주세요.\n\r";
		cout << int(eType) << " 타입의 에러 발생!\n";
		break;
	}
	Send(sock, msg.c_str(), msg.size(), roomNumber);
}

MSG_TYPE CNetwork::Login(const SOCKET & sock, const vector<string>& vecMsg, const uint& roomNumber)
{
	if (vecMsg.size() < 2)
		return MSG_TYPE::CANT_LOGIN_MSG;
	CClient* client = CRoomMgr::GetInst()->GetClient(sock, roomNumber);
	if (NULL == client)
	{
		cout << "Login Func Null Error! \n";
		return MSG_TYPE::ERROR_END;
		//exit(1);
	}
	// 로그인이 되어있는 상태에서 다시 로그인을 시도하는 경우
	if (uint(ROOM_TYPE::LOGIN_ROOM) != roomNumber)
	{
		return MSG_TYPE::DO_NOT_LOGIN_MSG;
	}
	const char* name = vecMsg[KEYWORD].c_str();
	if (m_mapNamePool.find(name) != m_mapNamePool.end()) // 중복체크
	{
		// 중복이 있다는 것
		return MSG_TYPE::CANT_USE_ID_MSG;
	}
	m_mapNamePool[name] = sock;

	client->SetName(vecMsg[KEYWORD].c_str());

	string logMsg;
	logMsg += "\r/      [";
	logMsg += vecMsg[KEYWORD].c_str();
	logMsg += "] 으로 로그인 하였습니다..\n\r";
	Send(sock, logMsg.c_str(), logMsg.size(), roomNumber);

	CRoomMgr::GetInst()->JoinRoom(sock, uint(ROOM_TYPE::LOGIN_ROOM), uint(ROOM_TYPE::MAIN_ROOM));

	CRoom* pMainRoom = CRoomMgr::GetInst()->GetRoom(uint(ROOM_TYPE::MAIN_ROOM));
	if (NULL == pMainRoom)
	{
		// 메인 룸이 없는 경우는 존재해서는 안됨
		cout << "MainRoom is not exist! can't Login \n";
		return MSG_TYPE::ERROR_END;
		//exit(1);
	}

	return MSG_TYPE::LOGIN_MSG;
}

MSG_TYPE CNetwork::Help(const SOCKET & sock)
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

MSG_TYPE CNetwork::ShowRoomAll(const SOCKET & sock)
{
	vector<uint> vecNumber = CRoomMgr::GetInst()->GetRoomNumberArray();
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

		msg += "\r/      [";
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

MSG_TYPE CNetwork::ShowRoom(const SOCKET & sock, const vector<string>& vecMsg)
{
	// 방번호가 입력되지 않은 경우
	if (vecMsg.size() <= 1)
	{
		return MSG_TYPE::CANT_SEARCH_ROOM_MSG;
	}
	// /명령어 [방번호]
	int number = atoi(vecMsg[KEYWORD].c_str());
	if (number < 0)
	{
		return MSG_TYPE::CANT_SEARCH_ROOM_MSG;
	}
	const CRoom* room = CRoomMgr::GetInst()->GetRoom(number);
	if (NULL == room)
	{
		cout << "ShowRoom Func Null Error! \n";
		return MSG_TYPE::CANT_SEARCH_ROOM_MSG;
	}

	string msg;
	msg.reserve(50);

	msg += "\r/      [";
	msg += to_string(room->GetNumber());
	msg += "] ";
	msg += room->GetRoomName();
	msg += " [";
	msg += to_string(room->GetCurrentUser());
	msg += "/";
	msg += to_string(room->GetMaxUser());
	msg += "]\n\r      ====대화방 이용자====\n\r";

	unordered_map<uint, CClient*> mapClient = CRoomMgr::GetInst()->GetClients(number);
	uint index = 0;
	for (auto& client : mapClient)
	{
		msg += "\r      [";
		msg += to_string(index++);
		msg += "] ";
		msg += client.second->GetName();
		msg += "\n\r";
	}

	Send(sock, msg.c_str(), msg.size(), 0);

	return MSG_TYPE::SHOWROOM_MSG;
}

MSG_TYPE CNetwork::CreateRoom(const SOCKET & sock, const vector<string>& vecMsg, const uint& roomNumber)
{
	// /명령어 [최대인원] [방제목] 이기 때문에 1번 인덱스에 최대인원 문자열이 담겨있음
	// 최대인원 및 방제목이 입력되지 않은 경우
	if (vecMsg.size() <= 2)
	{
		return MSG_TYPE::CANT_CREATE_ROOM_MSG;
	}
	int maxUser = atoi(vecMsg[KEYWORD].c_str());
	if (maxUser < 0)
	{
		return MSG_TYPE::CANT_CREATE_ROOM_MSG;
	}
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
		return MSG_TYPE::CANT_CREATE_ROOM_MSG;
	}

	bool result = CRoomMgr::GetInst()->CreateRoom(strRoomName.c_str(), maxUser);
	// 방 생성 실패
	if (FALSE == result)
	{
		//string msg;
		//msg = "대화방을 생성할 수 없습니다.\n\r";
		//Send(sock, msg.c_str(), msg.size(), roomNumber);
		return MSG_TYPE::CANT_CREATE_ROOM_MSG;
	}
	string msg = "\r/      ";
	msg += strRoomName;
	msg += " [";
	msg += to_string(maxUser);
	msg += "] 가 생성되었습니다.\n\r";
	Send(sock, msg.c_str(), msg.size(), roomNumber);

	return MSG_TYPE::CREATEROOM_MSG;
}

MSG_TYPE CNetwork::JoinRoom(const SOCKET & sock, const vector<string>& vecMsg, const uint& roomNumber)
{
	// /명령어 [방번호]
	// 방번호가 입력되지 않은 경우
	if (vecMsg.size() <= 1)
	{
		return MSG_TYPE::CANT_SEARCH_ROOM_MSG;
	}

	int newRoomNumber = atoi(vecMsg[KEYWORD].c_str());
	// 들어가려는 방과 현재 내 방이 같은 상황 or 음수 입력
	if (newRoomNumber <= 0 ||
		uint(newRoomNumber) == roomNumber)
	{
		return MSG_TYPE::CANT_JOIN_ROOM_MSG;
	}

	bool result = CRoomMgr::GetInst()->JoinRoom(sock, roomNumber, newRoomNumber);
	// 정원 초과 or 해당 방이 없음
	if (FALSE == result)
	{

		return MSG_TYPE::CANT_JOIN_ROOM_MSG;
	}

	// newRoom은 앞에서 예외처리를 진행했고 roomNumber는 메시지를 보낸 클라이언트가 있는 방
	//CRoom* pPrevRoom = CRoomMgr::GetInst()->GetRoom(roomNumber);
	//CRoom* pNewRoom = CRoomMgr::GetInst()->GetRoom(newRoomNumber);

	return MSG_TYPE::JOINROOM_MSG;
}

MSG_TYPE CNetwork::DestoryRoom(const vector<string>& vecMsg)
{
	// /명령어 [방번호]
	// 방번호가 입력되지 않은 경우
	if (vecMsg.size() <= 1)
	{
		return MSG_TYPE::CANT_SEARCH_ROOM_MSG;
	}

	int destroyNumber = atoi(vecMsg[KEYWORD].c_str());
	if (destroyNumber < 0 ||
		destroyNumber == int(ROOM_TYPE::MAIN_ROOM))
	{
		return MSG_TYPE::CANT_SEARCH_ROOM_MSG;
	}
	bool result = CRoomMgr::GetInst()->DestroyRoom(destroyNumber);
	// 폭파 실패
	if (FALSE == result)
	{
		return MSG_TYPE::CANT_SEARCH_ROOM_MSG;
	}

	return MSG_TYPE::DESTROYROOM_MSG;
}

MSG_TYPE CNetwork::ShowUserAll(const SOCKET & sock)
{
	vector<uint> vecNum = CRoomMgr::GetInst()->GetRoomNumberArray();
	for (auto& num : vecNum)
	{
		if (num == int(ROOM_TYPE::LOGIN_ROOM))
			continue;
		unordered_map<uint, CClient*> mapClient = CRoomMgr::GetInst()->GetClients(num);
		CRoom* room = CRoomMgr::GetInst()->GetRoom(num);
		if (NULL == room)
		{
			cout << num << " Room is not exist \n";
			exit(1);
		}
		for (auto& client : mapClient)
		{
			string msg;
			msg += "\r/      아이디 : [";
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

MSG_TYPE CNetwork::ShowUser(const SOCKET & sock, const vector<string>& vecMsg)
{
	// 유저아이디가 입력되지 않은 경우
	// /명령어 [아이디]
	if (vecMsg.size() <= 1)
	{
		return MSG_TYPE::CANT_SEARCH_USER_MSG;
	}
	CClient* client = CRoomMgr::GetInst()->GetClientByName(vecMsg[KEYWORD].c_str());
	if (NULL == client)
	{
		// 해당 유저를 찾을 수 없음
		return  MSG_TYPE::CANT_SEARCH_USER_MSG;
	}
	uint num = client->GetRoomNumber();
	CRoom* room = CRoomMgr::GetInst()->GetRoom(num);
	if (NULL == room)
	{
		cout << num << " Room is not exist \n";
		exit(1);
	}
	string msg;
	msg += "\r/      아이디 : [";
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

MSG_TYPE CNetwork::SendMsg(const SOCKET & sock, const vector<string>& vecMsg, const uint& roomNumber)
{
	// /명령어 [아이디] [메시지]
	// 제대로 입력되지 않은 경우
	if (vecMsg.size() <= 2)
	{
		return MSG_TYPE::NO_MSG;
	}
	CClient* pToClient = CRoomMgr::GetInst()->GetClientByName(vecMsg[KEYWORD].c_str());
	if (NULL == pToClient)
	{
		// 해당 유저를 찾을 수 없음
		return MSG_TYPE::CANT_SEARCH_USER_MSG;
	}
	CClient* pFromClient = CRoomMgr::GetInst()->GetClient(sock, roomNumber);
	if (NULL == pFromClient)
	{
		// 해당 유저를 찾을 수 없음
		return MSG_TYPE::CANT_SEARCH_USER_MSG;
	}
	//int num = client->GetRoomNumber();
	//CRoom* room = CRoomMgr::GetInst()->GetRoom(num);
	
	{
		string msg = "\r[귓속말] [";
		msg += pFromClient->GetName();
		msg += "] ";
		for (size_t i = KEYWORD + 1; i < vecMsg.size(); ++i)
		{
			msg += vecMsg[i];
			if (i + 1 < vecMsg.size())
				msg += " ";
		}
		msg += "\n\r";
		Send(pToClient->GetID(), msg.c_str(), msg.size());
		Send(pToClient->GetID(), ">> ", 4);
	}
	{
		string msg = "\r[전송] [";
		msg += pToClient->GetName();
		msg += "] ";
		for (size_t i = KEYWORD + 1; i < vecMsg.size(); ++i)
		{
			msg += vecMsg[i];
			if (i + 1 < vecMsg.size())
				msg += " ";
		}
		msg += "\n\r";
		Send(pFromClient->GetID(), msg.c_str(), msg.size());
	}

	return MSG_TYPE::SENDMSG_MSG;
}

MSG_TYPE CNetwork::Close(const SOCKET & sock)
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
	CRoomMgr::GetInst()->AddClient(ptr->sock, uint(ROOM_TYPE::LOGIN_ROOM));

	m_mapClient[ptr->sock] = ptr;

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

	CClient* pClient = CRoomMgr::GetInst()->GetClientByID(socket);
	if (NULL == pClient)
	{
		cout << "Remove Client is NULL\n" << endl;
		exit(1);
	}
	const char* name = pClient->GetName();
	if('\0' != name[0])
		m_mapNamePool.erase(name);
	m_mapClient.erase(socket);
	CRoomMgr::GetInst()->RemoveClient(socket);
	closesocket(socket);
	m_nClientCount--;
}
