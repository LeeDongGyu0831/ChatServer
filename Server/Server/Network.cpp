#include "stdafx.h"
#include "Network.h"
#include "RoomMgr.h"
#include "Client.h"

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
		for (auto& client : CRoomMgr::GetInst()->GetClient(i))
		{
			bool result = Recv(client, i);
			if (FALSE == result)
				continue;

			result = Send(client, i);
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

bool CNetwork::Recv(CClient* client, int roomNumber)
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
			char buf[16];
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

bool CNetwork::Send(CClient * client, int roomNumber)
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
				int retVal = send(otherClient.first, msg.c_str(), msg.size(), 0);
				if (retVal == SOCKET_ERROR)
				{
					printf("send() SOCKET_ERROR\n");
					RemoveSocketInfo(ptr->sock);
					CRoomMgr::GetInst()->RemoveClient(ptr->sock, roomNumber);
					break;
				}
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
				if (m_eMsgType != MSGTYPE::NORMAL)
					continue;

				string msg = "[";
				msg += name;
				msg += "] ";
				int retVal = send(otherClient.first, msg.c_str(), msg.size(), 0);
				if (retVal == SOCKET_ERROR)
				{
					printf("send() SOCKET_ERROR\n");
					RemoveSocketInfo(ptr->sock);
					CRoomMgr::GetInst()->RemoveClient(ptr->sock, roomNumber);
					break;
				}
				retVal = send(otherClient.first, ptr->buf, ptr->recvBytes - ptr->sendBytes, 0);
				if (retVal == SOCKET_ERROR)
				{
					printf("send() SOCKET_ERROR\n");
					RemoveSocketInfo(ptr->sock);
					CRoomMgr::GetInst()->RemoveClient(ptr->sock, roomNumber);
					break;
				}
			}
		}

		ptr->recvBytes = 0;
		ptr->sendBytes = 0;
	}
	return TRUE;
}

MSGTYPE CNetwork::CheckMessage(SOCKET sock, char* message, int bufCount, int roomNumber)
{
	MSGTYPE eMsgType = MSGTYPE::NORMAL;

	if (message[0] == '/')
	{
		eMsgType = MSGTYPE::NOTHING;

		// 명령어 조건 X
		if (bufCount < 3)
			return eMsgType;

		// 로그인 명령
		if (message[1] == COMMAND::LOGIN)
		{
			CClient* client = CRoomMgr::GetInst()->GetClient(sock, roomNumber);
			string name;
			name.assign(message, 3, bufCount - 4);
			client->SetName(name.c_str());
			//m_mapClientInfo[sock]->roomNumber = 0;
			eMsgType = MSGTYPE::LOGIN_MSG;
		}

		else if (message[1] == COMMAND::HELP)
		{
			// Enum.h 에 정의한 명령어 키에 대응되어 출력되게끔
			string command = "/";
			string msg = "=========================================\n\r";

			msg += command + char(COMMAND::HELP);
			msg += "\t\t\t명령어 안내\n\r";

			msg += command + char(COMMAND::LOGIN);
			msg += "\t\t\t로그인\n\r";

			msg += command + char(COMMAND::SHOWUSERALL);
			msg += "\t\t\t이용자 목록 보기\n\r";

			msg += command + char(COMMAND::SHOWROOMALL);
			msg += "\t\t\t대화방 목록 보기\n\r";

			msg += command + char(COMMAND::SHOWROOM);
			msg += " [방번호]";
			msg += "\t\t대화방 정보 보기\n\r";

			msg += command + char(COMMAND::SHOWUSER);
			msg += " [상대방ID]";
			msg += "\t\t이용자 정보 보기\n\r";

			msg += command + char(COMMAND::SENDMSG);
			msg += " [방번호] [메시지]";
			msg += "\t쪽지 보내기\n\r";

			msg += command + char(COMMAND::CREATEROOM);
			msg += " [방제목] [최대인원]";
			msg += "\t대화방 만들기\n\r";

			msg += command + char(COMMAND::JOINROOM);
			msg += " [방번호]";
			msg += "\t\t대화방 참여하기\n\r";

			msg += command + char(COMMAND::DESTROYROOM);
			msg += "\t\t\t대화방 끝내기\n\r";

			msg += command + char(COMMAND::CLOSE);
			msg += "\t\t\t끝내기\n\r";

			msg += "=========================================\n\r";
			send(sock, msg.c_str(), msg.size(), 0);
			eMsgType = MSGTYPE::HELP_MSG;
		}


	}

	return eMsgType;
}

BOOL CNetwork::AddSocketInfo(SOCKET sock)
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

	string msg { "=========================================\n\r\t환영합니다 채팅서버 입니다.\n\n\r   로그인 명령어(/l)을 사용해주세요.\n\n\n\r\t명령어 안내(/h)\n\r=========================================\n\r[Me] " };
	send(ptr->sock, msg.c_str(), msg.size(), 0);

	return TRUE;
}

void CNetwork::RemoveSocketInfo(SOCKET socket)
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
