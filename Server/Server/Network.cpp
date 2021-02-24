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


	cout << "Network Init" << endl;
	return TRUE;
}

bool CNetwork::Update()
{
	FD_Set();

	Select();

	Accept();

	// ���� �� �˻�(2) : ������ ���
	// �� ���� ��ȸ�ϸ鼭 �濡 �ִ� Ŭ���̾�Ʈ��� ���
	for (int i = 0; i < CRoomMgr::GetInst()->GetRoomCount(); ++i)
	{
		for (auto& client : CRoomMgr::GetInst()->GetClientList(i))
		{
			bool result = DataRecv(client, i);
			if (FALSE == result)
				continue;

			result = BroadCast(client, i);
			if (FALSE == result)
				continue;
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

bool CNetwork::FD_Set()
{
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
	return TRUE;
}

bool CNetwork::DataRecv(CClient* client, int roomNumber)
{
	SOCKETINFO* ptr = m_mapClient.find(client->GetID())->second;
	const char* name = CRoomMgr::GetInst()->GetClientName(ptr->sock, roomNumber);
	if (FD_ISSET(ptr->sock, &rset))
	{
		// ������ �ޱ�
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
			// ���ݱ��� ���� ���ڿ��� �������� ��ɾ� üũ
			m_eMsgType = CheckMessage(ptr->sock, ptr->buf, ptr->bufCount, roomNumber);

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
	return TRUE;
}

bool CNetwork::BroadCast(CClient * client, int roomNumber)
{
	SOCKETINFO* ptr = m_mapClient.find(client->GetID())->second;
	const char* name = CRoomMgr::GetInst()->GetClientName(ptr->sock, roomNumber);
	if (FD_ISSET(ptr->sock, &wset))
	{
		// ������ ������
		for (auto& otherClient : m_mapClient)
		{
			// �ڱ��ڽ�
			if (otherClient.first == ptr->sock)
			{
				string msg{ "[Me] " };
				Send(otherClient.first, msg.c_str(), msg.size(), 0);
				continue;
			}
			else
			{
				// �⺻������ ���� �濡 �ִ� ����鿡�Ը� ��ε�ĳ����

				// ���̵� ���� == �α����� �Ǿ����� �ʴ� ����
				if (name[0] == '\0')
				{
					ptr->recvBytes = 0;
					ptr->sendBytes = 0;
					continue;
				}

				// �Ϲ� ä��(��ɾ�� ������ �ʴ´�)
				if (m_eMsgType != MSGTYPE::NORMAL)
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

bool CNetwork::Send(const SOCKET& sock, const char * msg, const int size, int roomNumber = -1)
{
	int retVal = send(sock, msg, size, 0);
	if (retVal == SOCKET_ERROR)
	{
		printf("send() SOCKET_ERROR\n");
		RemoveSocketInfo(sock);
		
		if(roomNumber != -1)
			CRoomMgr::GetInst()->RemoveClient(sock, roomNumber);
		// �ش� Ŭ���̾�Ʈ �˻� �� ����
		else
			CRoomMgr::GetInst()->RemoveClient(sock);
		return FALSE;
	}
	return TRUE;
}

MSGTYPE CNetwork::CheckMessage(const SOCKET& sock, const char* message, const int bufCount, const int roomNumber)
{
	MSGTYPE eMsgType = MSGTYPE::NORMAL;

	if (message[0] != '/')
		return eMsgType;

	// ��ɾ� ���� X
	if (bufCount < 3)
		return eMsgType;

	eMsgType = MSGTYPE::NOTHING;

	// �޽��� ���� �������� ����
	vector<string> vecMsg = SplitString(message, ' ');

	// �α��� ���
	if (message[1] == COMMAND::LOGIN)
	{
		//CClient* client = CRoomMgr::GetInst()->GetClient(sock, roomNumber);
		//string name;
		//name.assign(message, 3, bufCount - 4);
		//client->SetName(name.c_str());
		////m_mapClientInfo[sock]->roomNumber = 0;
		//eMsgType = MSGTYPE::LOGIN_MSG;

		eMsgType = Login(sock, vecMsg, roomNumber);
	}

	// ��ɾ� �ȳ� ���
	else if (message[1] == COMMAND::HELP)
	{
		eMsgType = Help(sock, vecMsg, roomNumber);
	}

	// ��ȭ�� ��� ���
	else if (message[1] == COMMAND::SHOWROOMALL)
	{
		eMsgType = ShowRoomAll(sock, vecMsg, roomNumber);
	}

	// ��ȭ�� ���� ���
	else if (message[1] == COMMAND::SHOWROOM)
	{
		eMsgType = ShowRoom(sock, vecMsg, roomNumber);
	}

	// ��ȭ�� ����
	else if (message[1] == COMMAND::CREATEROOM)
	{
		eMsgType = CreateRoom(sock, vecMsg, roomNumber);
	}

	return eMsgType;
}

MSGTYPE CNetwork::Login(const SOCKET & sock, const vector<string>& vecMsg, const int roomNumber)
{
	CClient* client = CRoomMgr::GetInst()->GetClient(sock, roomNumber);

	client->SetName(vecMsg[1].c_str());

	return MSGTYPE::LOGIN_MSG;
}

MSGTYPE CNetwork::Help(const SOCKET & sock, const vector<string>& vecMsg, const int roomNumber)
{
	// Enum.h �� ������ ��ɾ� Ű�� �����Ǿ� ��µǰԲ�
	string command = "/";
	string msg = "=========================================\n\r";
	msg.reserve(50);

	msg += command + char(COMMAND::HELP);
	msg += "\t\t\t��ɾ� �ȳ�\n\r";

	msg += command + char(COMMAND::LOGIN);
	msg += "\t\t\t�α���\n\r";

	msg += command + char(COMMAND::SHOWUSERALL);
	msg += "\t\t\t�̿��� ��� ����\n\r";

	msg += command + char(COMMAND::SHOWROOMALL);
	msg += "\t\t\t��ȭ�� ��� ����\n\r";

	msg += command + char(COMMAND::SHOWROOM);
	msg += " [���ȣ]";
	msg += "\t\t��ȭ�� ���� ����\n\r";

	msg += command + char(COMMAND::SHOWUSER);
	msg += " [����ID]";
	msg += "\t\t�̿��� ���� ����\n\r";

	msg += command + char(COMMAND::SENDMSG);
	msg += " [���ȣ] [�޽���]";
	msg += "\t���� ������\n\r";

	msg += command + char(COMMAND::CREATEROOM);
	msg += " [�ִ��ο�] [������]";
	msg += "\t��ȭ�� �����\n\r";

	msg += command + char(COMMAND::JOINROOM);
	msg += " [���ȣ]";
	msg += "\t\t��ȭ�� �����ϱ�\n\r";

	msg += command + char(COMMAND::DESTROYROOM);
	msg += "\t\t\t��ȭ�� ������\n\r";

	msg += command + char(COMMAND::CLOSE);
	msg += "\t\t\t������\n\r";

	msg += "=========================================\n\r";
	Send(sock, msg.c_str(), msg.size(), 0);

	return MSGTYPE::HELP_MSG;
}

MSGTYPE CNetwork::ShowRoomAll(const SOCKET & sock, const vector<string>& vecMsg, const int roomNumber)
{
	vector<int> vecNumber = CRoomMgr::GetInst()->GetRoomNumberArray();
	string msg;
	msg.reserve(50);
	for (auto& num : vecNumber)
	{
		CRoom* room = CRoomMgr::GetInst()->GetRoom(num);
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

	return MSGTYPE::SHOWROOMALL_MSG;
}

MSGTYPE CNetwork::ShowRoom(const SOCKET & sock, const vector<string>& vecMsg, const int roomNumber)
{
	int number = atoi(vecMsg[1].c_str());
	CRoom* room = CRoomMgr::GetInst()->GetRoom(number);

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

	list<CClient*> listClient = CRoomMgr::GetInst()->GetClientList(number);
	int index = 0;
	for (auto& client : listClient)
	{
		msg += "[";
		msg += to_string(index);
		msg += "] ";
		msg += client->GetName();
		msg += "\n\r";
	}

	Send(sock, msg.c_str(), msg.size(), 0);

	return MSGTYPE::SHOWROOM_MSG;
}

MSGTYPE CNetwork::CreateRoom(const SOCKET & sock, const vector<string>& vecMsg, const int roomNumber)
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
	// ���ڿ��� ���̴� �� �̻��ϰ� �Է� ���� ���
	if (maxUser == 0)
	{
		msg = "�߸��� ��ɾ� �Դϴ�. �ٽ� Ȯ�����ּ���.\n\r";
		Send(sock, msg.c_str(), msg.size(), roomNumber);
		return MSGTYPE::NOTHING;
	}

	bool result = CRoomMgr::GetInst()->CreateRoom(strRoomName.c_str(), maxUser);
	// �� ���� ����
	if (FALSE == result)
	{
		msg = "��ȭ���� ������ �� �����ϴ�.\n\r";
		Send(sock, msg.c_str(), msg.size(), roomNumber);
		return MSGTYPE::NOTHING;
	}

	msg += strRoomName;
	msg += " [";
	msg += to_string(maxUser);
	msg += "] �� �����Ǿ����ϴ�.\n\r";
	Send(sock, msg.c_str(), msg.size(), roomNumber);

	return MSGTYPE::CREATEROOM_MSG;
}

MSGTYPE CNetwork::JoinRoom(const SOCKET & sock, const vector<string>& vecMsg, const int roomNumber)
{
	return MSGTYPE::JOINROOM_MSG;
}

MSGTYPE CNetwork::DestoryRoom(const SOCKET & sock, const vector<string>& vecMsg, const int roomNumber)
{
	return MSGTYPE::DESTROYROOM_MSG;
}

MSGTYPE CNetwork::ShowUserAll(const SOCKET & sock, const vector<string>& vecMsg, const int roomNumber)
{
	return MSGTYPE::SHOWUSERALL_MSG;
}

MSGTYPE CNetwork::ShowUser(const SOCKET & sock, const vector<string>& vecMsg, const int roomNumber)
{
	return MSGTYPE::SHOWUSER_MSG;
}

MSGTYPE CNetwork::SendMsg(const SOCKET & sock, const vector<string>& vecMsg, const int roomNumber)
{
	return MSGTYPE::SENDMSG_MSG;
}

BOOL CNetwork::AddSocketInfo(const SOCKET& sock)
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

	string msg { "=========================================\n\r\tȯ���մϴ� ä�ü��� �Դϴ�.\n\n\r\t�α��� ��ɾ�(/l)�� ������ּ���.\n\n\n\r\t��ɾ� �ȳ�(/h)\n\r=========================================\n\r[Me] " };
	Send(ptr->sock, msg.c_str(), msg.size(), 0);

	return TRUE;
}

void CNetwork::RemoveSocketInfo(const SOCKET& socket)
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
