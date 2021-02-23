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
	for (int i = 0; i < CRoomMgr::GetInst()->GetRoomCount(); ++i)
	{
		for (auto& client : CRoomMgr::GetInst()->GetClient(i))
		{
			SOCKETINFO* ptr = m_mapClient.find(client->GetID())->second;
			const char* name = CRoomMgr::GetInst()->GetClientName(ptr->sock, i);
			if (FD_ISSET(ptr->sock, &rset))
			{
				// ������ �ޱ�
				char temp;
				retVal = recv(ptr->sock, &temp, 1, 0);
				if (retVal == SOCKET_ERROR)
				{
					printf("recv SOCKET_ERROR\n");
					RemoveSocketInfo(ptr->sock);
					CRoomMgr::GetInst()->RemoveClient(ptr->sock, i);
					break;
				}
				else if (retVal == 0)
				{
					printf("recv 0\n");
					RemoveSocketInfo(ptr->sock);
					CRoomMgr::GetInst()->RemoveClient(ptr->sock, i);
					break;
				}
				if (temp == '\n')
				{
					// ���ݱ��� ���� ���ڿ��� �������� ��ɾ� üũ
					m_eMsgType = CheckMessage(ptr->sock, ptr->buf, ptr->bufCount);

					ptr->buf[ptr->bufCount++] = temp;
					ptr->buf[ptr->bufCount] = '\0';

					// �ʱ�ȭ
					ptr->recvBytes = ptr->bufCount;
					ptr->bufCount = 0;

					// ���� ������ ���
					addrLen = sizeof(clientAddr);
					getpeername(ptr->sock, (SOCKADDR*)&clientAddr, &addrLen);
					//ptr->buf[retVal] = '\0';
					char buf[16];
					inet_ntop(AF_INET, &clientAddr.sin_addr, buf, sizeof(buf));
					printf("[TCP %s:%d] [%s] %s", buf, ntohs(clientAddr.sin_port), name, ptr->buf);

				}
				else
				{
					// ����
					ptr->buf[ptr->bufCount++] = temp;
					ptr->buf[ptr->bufCount] = '\0';
				}
			}

			if (FD_ISSET(ptr->sock, &wset))
			{
				// ������ ������
				for (auto& otherClient : m_mapClient)
				{
					// �ڱ��ڽ�
					if (otherClient.first == ptr->sock)
					{
						string msg{ "[Me] " };
						retVal = send(otherClient.first, msg.c_str(), msg.size(), 0);
						if (retVal == SOCKET_ERROR)
						{
							printf("send() SOCKET_ERROR\n");
							RemoveSocketInfo(ptr->sock);
							CRoomMgr::GetInst()->RemoveClient(ptr->sock, i);
							break;
						}
						continue;
					}
					else
					{
						// ��ε�ĳ����
						string msg = "[";
						msg += name;
						msg += "] ";
						retVal = send(otherClient.first, msg.c_str(), msg.size(), 0);
						if (retVal == SOCKET_ERROR)
						{
							printf("send() SOCKET_ERROR\n");
							RemoveSocketInfo(ptr->sock);
							CRoomMgr::GetInst()->RemoveClient(ptr->sock, i);
							break;
						}
						retVal = send(otherClient.first, ptr->buf, ptr->recvBytes - ptr->sendBytes, 0);
						if (retVal == SOCKET_ERROR)
						{
							printf("send() SOCKET_ERROR\n");
							RemoveSocketInfo(ptr->sock);
							CRoomMgr::GetInst()->RemoveClient(ptr->sock, i);
							break;
						}
					}
				}

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

MSGTYPE CNetwork::CheckMessage(SOCKET sock, char* message, int bufCount)
{
	MSGTYPE eMsgType = MSGTYPE::NORMAL;

	if (message[0] == '/')
	{
		eMsgType = MSGTYPE::NOTHING;

		// ��ɾ� ���� X
		if (bufCount < 3)
			return eMsgType;

		// �α��� ���
		if (message[1] == COMMAND::LOGIN)
		{
			//CRoomMgr::GetInst()->GetClient()
			//strcpy_s(m_mapClientInfo[sock]->name, NAMESIZE, message + 3);
			//m_mapClientInfo[sock]->name[bufCount - 4] = '\0';
			//m_mapClientInfo[sock]->nameSize = bufCount - 4;
			//m_mapClientInfo[sock]->roomNumber = 0;
		}
	}

	return eMsgType;
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

	// Client ID �� ���� �� ��ȣ �ʱ�ȭ
	CRoomMgr::GetInst()->AddClient(ptr->sock, 0);

	m_mapClient[ptr->sock] = ptr;

	char msg[BUFSIZE]{ "================================\n\r�α��� ��ɾ�(/l)�� ������ּ���.\n\r================================\n\r[Me] " };
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
	CRoomMgr::GetInst()->RemoveClient(socket);
	closesocket(socket);
}
