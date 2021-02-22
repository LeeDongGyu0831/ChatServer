#include "stdafx.h"
#include "Network.h"

CNetwork::CNetwork()
{
}


CNetwork::~CNetwork()
{
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

	return TRUE;
}

bool CNetwork::Update()
{
	int retVal;

	// 데이터 통신에 사용할 변수
	FD_SET rset, wset;
	SOCKET clientSock;
	SOCKADDR_IN clientAddr;
	int addrLen;

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

	// select()
	retVal = select(0, &rset, &wset, NULL, NULL);
	if (retVal == SOCKET_ERROR)
	{
		printf("error select()\n");
		return FALSE;
	}

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

	// 소켓 셋 검사(2) : 데이터 통신
	for (auto& client : m_mapClient)
	{
		SOCKETINFO* ptr = client.second;
		if (FD_ISSET(ptr->sock, &rset))
		{
			// 데이터 받기
			char temp;
			retVal = recv(ptr->sock, &temp, 1, 0);
			if (retVal == SOCKET_ERROR)
			{
				printf("recv SOCKET_ERROR\n");
				RemoveSocketInfo(client.first);
				break;
			}
			else if (retVal == 0)
			{
				printf("recv 0\n");
				RemoveSocketInfo(client.first);
				break;
			}
			if (temp == '\n')
			{
				// 지금까지 모은 문자열을 바탕으로 명령어 체크
				m_eMsgType = CheckMessage(ptr->sock, ptr->buf, ptr->bufCount);

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
				printf("[TCP %s:%d] [%s] %s", buf, ntohs(clientAddr.sin_port), m_mapClientInfo[ptr->sock]->name, ptr->buf);

			}
			else
			{
				// 조립
				ptr->buf[ptr->bufCount++] = temp;
				ptr->buf[ptr->bufCount] = '\0';
			}
		}

		if (FD_ISSET(ptr->sock, &wset))
		{
			// 데이터 보내기
			for (auto& otherClient : m_mapClient)
			{
				// 자기자신
				if (otherClient.first == ptr->sock)
				{
					string msg{ "[Me] " };
					retVal = send(otherClient.first, msg.c_str(), msg.size(), 0);
					if (retVal == SOCKET_ERROR)
					{
						printf("send() SOCKET_ERROR\n");
						RemoveSocketInfo(client.first);
						break;
					}
					continue;
				}
				else
				{
					// 같은 방이 아니라면 대화 전송X
					if (m_mapClientInfo[otherClient.first]->roomNumber != m_mapClientInfo[ptr->sock]->roomNumber)
						continue;

					// 브로드캐스팅
					string msg = "[";
					msg += m_mapClientInfo[ptr->sock]->name;
					msg += "] ";
					retVal = send(otherClient.first, msg.c_str(), msg.size(), 0);
					if (retVal == SOCKET_ERROR)
					{
						printf("send() SOCKET_ERROR\n");
						RemoveSocketInfo(client.first);
						break;
					}
					retVal = send(otherClient.first, ptr->buf, ptr->recvBytes - ptr->sendBytes, 0);
					if (retVal == SOCKET_ERROR)
					{
						printf("send() SOCKET_ERROR\n");
						RemoveSocketInfo(client.first);
						break;
					}
				}
			}

			ptr->recvBytes = 0;
			ptr->sendBytes = 0;
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

MSGTYPE CNetwork::CheckMessage(SOCKET sock, char* message, int bufCount)
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
			strcpy_s(m_mapClientInfo[sock]->name, NAMESIZE, message + 3);
			m_mapClientInfo[sock]->name[bufCount - 4] = '\0';
			m_mapClientInfo[sock]->nameSize = bufCount - 4;
			m_mapClientInfo[sock]->roomNumber = 0;
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

	CLIENTINFO* clientptr = new CLIENTINFO;
	if (clientptr == NULL)
	{
		printf("[오류] 메모리가 부족합니다\n");
		return FALSE;
	}

	// Client ID 및 시작 방 번호 초기화
	clientptr->name[0] = '\0';
	clientptr->roomNumber = -1;

	m_mapClient[ptr->sock] = ptr;
	m_mapClientInfo[ptr->sock] = clientptr;

	char msg[BUFSIZE]{ "================================\n\r로그인 명령어(/l)을 사용해주세요.\n\r================================\n\r[Me] " };
	send(ptr->sock, msg, BUFSIZE, 0);

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
	m_mapClientInfo.erase(socket);
	closesocket(socket);
}
