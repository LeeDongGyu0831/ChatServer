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

	// ���� �ʱ�ȭ
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

	// �ͺ��ŷ �������� ��ȯ
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

	// ������ ��ſ� ����� ����
	FD_SET rset, wset;
	SOCKET clientSock;
	SOCKADDR_IN clientAddr;
	int addrLen;

	// ���� �� �ʱ�ȭ
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

	// ���� �� �˻�(1) : Ŭ���̾�Ʈ ���� ����
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
			printf("[TCP ����] Ŭ���̾�Ʈ ���� : IP �ּ� = %s, ��Ʈ ��ȣ = %d\n", buf, ntohs(clientAddr.sin_port));

			// ���� ���� �߰�
			if (FALSE == AddSocketInfo(clientSock))
				return FALSE;
		}
	}

	// ���� �� �˻�(2) : ������ ���
	for (auto& client : m_mapClient)
	{
		SOCKETINFO* ptr = client.second;
		if (FD_ISSET(ptr->sock, &rset))
		{
			// ������ �ޱ�
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
				ptr->buf[ptr->bufCount++] = temp;
				ptr->buf[ptr->bufCount] = '\0';
				ptr->recvBytes = ptr->bufCount;
				ptr->bufCount = 0;

				// ���� ������ ���
				addrLen = sizeof(clientAddr);
				getpeername(ptr->sock, (SOCKADDR*)&clientAddr, &addrLen);
				//ptr->buf[retVal] = '\0';
				char buf[16];
				inet_ntop(AF_INET, &clientAddr.sin_addr, buf, sizeof(buf));
				printf("[TCP %s:%d] %s\n", buf, ntohs(clientAddr.sin_port), ptr->buf);
			}
			else
			{
				ptr->buf[ptr->bufCount++] = temp;
				ptr->buf[ptr->bufCount] = '\0';
			}
		}

		if (FD_ISSET(ptr->sock, &wset))
		{
			// ������ ������
			for (auto& otherClient : m_mapClient)
			{
				if (otherClient.first == ptr->sock)
					continue;

				retVal = send(otherClient.second->sock, ptr->buf + ptr->sendBytes, ptr->recvBytes - ptr->sendBytes, 0);
				if (retVal == SOCKET_ERROR)
				{
					printf("send() SOCKET_ERROR\n");
					RemoveSocketInfo(client.first);
					break;
				}
			}

			ptr->sendBytes += retVal;
			if (ptr->recvBytes == ptr->sendBytes)
			{
				ptr->recvBytes = 0;
				ptr->sendBytes = 0;
			}
		}
	}
	return TRUE;
}

void CNetwork::Close()
{
	// ���� ����
	WSACleanup();
	return;
}

BOOL CNetwork::AddSocketInfo(SOCKET sock)
{
	if (m_mapClient.size() > FD_SETSIZE)
	{
		printf("[����] ���� ������ �߰��� �� �����ϴ�\n");
		return FALSE;
	}

	SOCKETINFO* ptr = new SOCKETINFO;
	if (ptr == NULL)
	{
		printf("[����] �޸𸮰� �����մϴ�\n");
		return FALSE;
	}

	ptr->sock = sock;
	ptr->recvBytes = 0;
	ptr->sendBytes = 0;
	ptr->bufCount = 0;

	m_mapClient[ptr->sock] = ptr;

	char msg[BUFSIZE]{ "ä�� ������ �����Ͽ����ϴ�\n\n" };

	send(ptr->sock, msg, BUFSIZE, 0);

	return TRUE;
}

void CNetwork::RemoveSocketInfo(SOCKET socket)
{
	// Ŭ���̾�Ʈ ���� ���
	SOCKADDR_IN clientAddr;
	int addrLen = sizeof(clientAddr);
	getpeername(socket, (SOCKADDR*)&clientAddr, &addrLen);
	char buf[16];
	inet_ntop(AF_INET, &clientAddr.sin_addr, buf, sizeof(buf));
	printf("[TCP ����] Ŭ���̾�Ʈ ����: IP �ּ� = %s, ��Ʈ ��ȣ = %d\n", buf, ntohs(clientAddr.sin_port));

	m_mapClient.erase(socket);
	closesocket(socket);
}
