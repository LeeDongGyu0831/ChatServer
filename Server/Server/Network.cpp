#include "Network.h"



CNetwork::CNetwork()
{
}


CNetwork::~CNetwork()
{
}

bool CNetwork::Init()
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
	serverAddr.sin_port = htons(SERVERPORT);
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
	int addrLen, i;

	while (1)
	{
		// 소켓 셋 초기화
		FD_ZERO(&rset);
		FD_ZERO(&wset);
		FD_SET(m_Sock, &rset);
		for (i = 0; i < m_nTotalSockets; i++)
		{
			if (m_socketInfoArray[i]->recvBytes > m_socketInfoArray[i]->sendBytes)
				FD_SET(m_socketInfoArray[i]->sock, &wset);
			else
				FD_SET(m_socketInfoArray[i]->sock, &rset);
		}

		// select()
		retVal = select(0, &rset, &wset, NULL, NULL);
		if (retVal == SOCKET_ERROR)
		{
			printf("error select()\n");
			cout << m_nTotalSockets << endl;
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
			}
			else
			{
				char buf[16];
				inet_ntop(AF_INET, &clientAddr.sin_addr, buf, sizeof(buf));
				printf("[TCP 서버] 클라이언트 접속 : IP 주소 = %s, 포트 번호 = %d\n", buf, ntohs(clientAddr.sin_port));

				// 소켓 정보 추가
				AddSocketInfo(clientSock);
			}
		}

		// 소켓 셋 검사(2) : 데이터 통신
		for (i = 0; i < m_nTotalSockets; i++)
		{
			SOCKETINFO* ptr = m_socketInfoArray[i];
			if (FD_ISSET(ptr->sock, &rset))
			{
				// 데이터 받기
				retVal = recv(ptr->sock, ptr->buf, BUFSIZE, 0);
				if (retVal == SOCKET_ERROR)
				{
					printf("recv SOCKET_ERROR\n");
					RemoveSocketInfo(i);
					continue;
				}
				else if (retVal == 0)
				{
					printf("recv 0\n");
					RemoveSocketInfo(i);
					continue;
				}

				ptr->recvBytes = retVal;
				// 받은 데이터 출력
				addrLen = sizeof(clientAddr);
				getpeername(ptr->sock, (SOCKADDR*)&clientAddr, &addrLen);
				ptr->buf[retVal] = '\0';
				char buf[16];
				inet_ntop(AF_INET, &clientAddr.sin_addr, buf, sizeof(buf));
				printf("[TCP %s:%d] %s\n", buf, ntohs(clientAddr.sin_port), ptr->buf);
			}

			if (FD_ISSET(ptr->sock, &wset))
			{
				// 데이터 보내기
				retVal = send(ptr->sock, ptr->buf + ptr->sendBytes, ptr->recvBytes - ptr->sendBytes, 0);
				if (retVal == SOCKET_ERROR)
				{
					printf("send() SOCKET_ERROR\n");
					RemoveSocketInfo(i);
					continue;
				}

				ptr->sendBytes += retVal;
				if (ptr->recvBytes == ptr->sendBytes)
				{
					ptr->recvBytes = 0;
					ptr->sendBytes = 0;
				}
			}
		}
	}
}

void CNetwork::Close()
{
	// 윈속 종료
	WSACleanup();
	return;
}

BOOL CNetwork::AddSocketInfo(SOCKET sock)
{
	if (m_nTotalSockets >= FD_SETSIZE)
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
	m_socketInfoArray[m_nTotalSockets++] = ptr;

	return TRUE;
}

void CNetwork::RemoveSocketInfo(int nIndex)
{
	SOCKETINFO* ptr = m_socketInfoArray[nIndex];

	// 클라이언트 정보 얻기
	SOCKADDR_IN clientAddr;
	int addrLen = sizeof(clientAddr);
	getpeername(ptr->sock, (SOCKADDR*)&clientAddr, &addrLen);
	char buf[16];
	inet_ntop(AF_INET, &clientAddr.sin_addr, buf, sizeof(buf));
	printf("[TCP 서버] 클라이언트 종료: IP 주소 = %s, 포트 번호 = %d\n", buf, ntohs(clientAddr.sin_port));

	closesocket(ptr->sock);
	delete ptr;

	if (nIndex != (m_nTotalSockets - 1))
		m_socketInfoArray[nIndex] = m_socketInfoArray[m_nTotalSockets - 1];

	--m_nTotalSockets;
}
