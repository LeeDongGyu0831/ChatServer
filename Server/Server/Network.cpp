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

bool CNetwork::DataRecv(const CClient* client, const int& roomNumber)
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

			char buf[16]; // Ŭ���̾�Ʈ IP �ּ�
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

bool CNetwork::BroadCast(const CClient * client, const int& roomNumber)
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
		// �ش� Ŭ���̾�Ʈ �˻� �� ����
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

	// ��ɾ� ���� X
	if (bufCount < 3)
		return eMsgType;

	eMsgType = MSG_TYPE::NOTHING;

	// �޽��� ���� �������� ����
	vector<string> vecMsg = SplitString(message, ' ');

	// �α��� ���
	if (message[1] == COMMAND_TYPE::LOGIN)
	{
		eMsgType = Login(sock, vecMsg, roomNumber);
	}

	// ��ɾ� �ȳ� ���
	else if (message[1] == COMMAND_TYPE::HELP)
	{
		eMsgType = Help(sock, vecMsg, roomNumber);
	}

	// ��ȭ�� ��� ���
	else if (message[1] == COMMAND_TYPE::SHOWROOMALL)
	{
		eMsgType = ShowRoomAll(sock, vecMsg, roomNumber);
	}

	// ��ȭ�� ���� ���
	else if (message[1] == COMMAND_TYPE::SHOWROOM)
	{
		eMsgType = ShowRoom(sock, vecMsg, roomNumber);
	}

	// ��ȭ�� ����
	else if (message[1] == COMMAND_TYPE::CREATEROOM)
	{
		eMsgType = CreateRoom(sock, vecMsg, roomNumber);
	}
	
	// ��ȭ�� ����
	else if (message[1] == COMMAND_TYPE::JOINROOM)
	{
		eMsgType = JoinRoom(sock, vecMsg, roomNumber);
	}

	// ��ȭ�� ����
	else if (message[1] == COMMAND_TYPE::DESTROYROOM)
	{
		eMsgType = DestoryRoom(sock, vecMsg, roomNumber);
	}

	// �̿��� ��� ���
	else if (message[1] == COMMAND_TYPE::SHOWUSERALL)
	{
		eMsgType = ShowUserAll(sock, vecMsg, roomNumber);
	}

	// �̿��� �˻�
	else if (message[1] == COMMAND_TYPE::SHOWUSER)
	{
		eMsgType = ShowUser(sock, vecMsg, roomNumber);
	}

	// ���� ������
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
	// Enum.h �� ������ ��ɾ� Ű�� �����Ǿ� ��µǰԲ�
	string command = "/";
	string msg = "=========================================\n\r";
	msg.reserve(50);

	msg += command + char(COMMAND_TYPE::HELP);
	msg += "\t\t\t��ɾ� �ȳ�\n\r";

	msg += command + char(COMMAND_TYPE::LOGIN);
	msg += "\t\t\t�α���\n\r";

	msg += command + char(COMMAND_TYPE::SHOWUSERALL);
	msg += "\t\t\t�̿��� ��� ����\n\r";

	msg += command + char(COMMAND_TYPE::SHOWROOMALL);
	msg += "\t\t\t��ȭ�� ��� ����\n\r";

	msg += command + char(COMMAND_TYPE::SHOWROOM);
	msg += " [���ȣ]";
	msg += "\t\t��ȭ�� ���� ����\n\r";

	msg += command + char(COMMAND_TYPE::SHOWUSER);
	msg += " [����ID]";
	msg += "\t\t�̿��� ���� ����\n\r";

	msg += command + char(COMMAND_TYPE::SENDMSG);
	msg += " [���ȣ] [�޽���]";
	msg += "\t���� ������\n\r";

	msg += command + char(COMMAND_TYPE::CREATEROOM);
	msg += " [�ִ��ο�] [������]";
	msg += "\t��ȭ�� �����\n\r";

	msg += command + char(COMMAND_TYPE::JOINROOM);
	msg += " [���ȣ]";
	msg += "\t\t��ȭ�� �����ϱ�\n\r";

	msg += command + char(COMMAND_TYPE::DESTROYROOM);
	msg += "\t\t\t��ȭ�� ������\n\r";

	msg += command + char(COMMAND_TYPE::CLOSE);
	msg += "\t\t\t������\n\r";

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
	// ���ڿ��� ���̴� �� �̻��ϰ� �Է� ���� ���
	if (maxUser == 0)
	{
		msg = "�߸��� ��ɾ� �Դϴ�. �ٽ� Ȯ�����ּ���.\n\r";
		Send(sock, msg.c_str(), msg.size(), roomNumber);
		return MSG_TYPE::NOTHING;
	}

	bool result = CRoomMgr::GetInst()->CreateRoom(strRoomName.c_str(), maxUser);
	// �� ���� ����
	if (FALSE == result)
	{
		msg = "��ȭ���� ������ �� �����ϴ�.\n\r";
		Send(sock, msg.c_str(), msg.size(), roomNumber);
		return MSG_TYPE::NOTHING;
	}

	msg += strRoomName;
	msg += " [";
	msg += to_string(maxUser);
	msg += "] �� �����Ǿ����ϴ�.\n\r";
	Send(sock, msg.c_str(), msg.size(), roomNumber);

	return MSG_TYPE::CREATEROOM_MSG;
}

MSG_TYPE CNetwork::JoinRoom(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	int newRoomNumber = atoi(vecMsg[1].c_str());
	bool result = CRoomMgr::GetInst()->JoinRoom(sock, roomNumber, newRoomNumber);
	// ���� �ʰ�
	if (FALSE == result)
	{
		cout << "���� �ʰ�\n\r" << endl;
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
