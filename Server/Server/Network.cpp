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

	// �ͺ��ŷ �������� ��ȯ
	u_long on = 1;
	retVal = ioctlsocket(m_Sock, FIONBIO, &on);
	if (retVal == SOCKET_ERROR)
	{
		printf("error ioctlsocket()\n");
		return FALSE;
	}

	IN_ADDR addr;

	addr = GetDefaultMyIP();//����Ʈ IPv4 �ּ� ������
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

	// ���� �� �˻�(2) : ������ ���
	// �� ���� ��ȸ�ϸ鼭 �濡 �ִ� Ŭ���̾�Ʈ��� ���

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
	// ���� ����
	WSACleanup();
	return;
}

bool CNetwork::FD_Set()
{
	// ���� �� �ʱ�ȭ
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
	// �Ѱ� �ʰ�
	if (m_nClientCount >= MAXUSER)
		return FALSE;

	// ���� �� �˻�(1) : Ŭ���̾�Ʈ ���� ����
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
			// Ŭ���̾�Ʈ IP �ּ�
			char buf[IP_ADDR_LEN];
			inet_ntop(AF_INET, &m_addrClientSock.sin_addr, buf, sizeof(buf));
			printf("[TCP ����] Ŭ���̾�Ʈ ���� : IP �ּ� = %s, ��Ʈ ��ȣ = %d\n", buf, ntohs(m_addrClientSock.sin_port));

			// ���� ���� �߰�
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
		// ������ �ޱ�
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
			// ���ݱ��� ���� ���ڿ��� �������� ��ɾ� üũ
			m_eMsgType = CheckMessage(sock->sock, sock->buf, sock->bufCount, roomNumber);
			if (MSG_TYPE::NOTHING == m_eMsgType)
			{
				string msg;
				msg = "�߸��� ��ɾ� �Դϴ�. �ٽ� Ȯ�����ּ���.\n\r";
				Send(sock->sock, msg.c_str(), msg.size(), roomNumber);
			}
			if (MSG_TYPE::CLOSE_MSG == m_eMsgType)
			{
				return FALSE;
			}
			sock->buf[sock->bufCount++] = temp;
			sock->buf[sock->bufCount] = '\0';

			// �ʱ�ȭ
			sock->recvBytes = sock->bufCount;
			sock->bufCount = 0;

			// ���� ������ ���
			m_nAddrLen = sizeof(m_addrClientSock);
			getpeername(sock->sock, (SOCKADDR*)&m_addrClientSock, &m_nAddrLen);
			//ptr->buf[retVal] = '\0';

			char buf[IP_ADDR_LEN]; // Ŭ���̾�Ʈ IP �ּ�
			inet_ntop(AF_INET, &m_addrClientSock.sin_addr, buf, sizeof(buf));
			printf("[TCP %s:%d] [%s] %s", buf, ntohs(m_addrClientSock.sin_port), name, sock->buf);

		}
		else
		{
			// ����
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
		// ������ ������
		for (auto& otherClient : m_mapClient)
		{
			// �ڱ��ڽ�
			if (otherClient.first == sock->sock)
			{
				string msg{ ">> " };
				Send(otherClient.first, msg.c_str(), msg.size(), 0);
				continue;
			}
			else
			{
				// �⺻������ ���� �濡 �ִ� ����鿡�Ը� ��ε�ĳ����
				// �α��η��� ��ε�ĳ���� X
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

				// �Ϲ� ä��(��ɾ�� ������ �ʴ´�)
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

	if (gethostname(localhostname, MAX_PATH) == SOCKET_ERROR)//ȣ��Ʈ �̸� ������
	{
		return addr;
	}
	HOSTENT *ptr = gethostbyname(localhostname);//ȣ��Ʈ ��Ʈ�� ������
	while (ptr && ptr->h_name)
	{
		if (ptr->h_addrtype == PF_INET)//IPv4 �ּ� Ÿ���� ��
		{
			memcpy(&addr, ptr->h_addr_list[0], ptr->h_length);//�޸� ����
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

	// ��ɾ �ƴ϶�� �ٷ� �����Ͽ� ��ε�ĳ������ �� �� �ֵ���
	if (message[0] != '/')
		return eMsgType;

	// ��ɾ� ���� X
	// ��ɾ�� /r, /l ������� �����ϱ� ������ MINIMUM ���� ������ ������ �Ұ���
	if (bufCount < MINIMUM_LEN)
		return eMsgType;

	eMsgType = MSG_TYPE::NOTHING;

	// �޽��� ���� �������� ����
	vector<string> vecMsg = SplitString(message, ' ');
	// 0�� �ε������� /r, /l, /c ���..
	// 1�� �ε������� �ܾ�� ����

	if (roomNumber == int(ROOM_TYPE::LOGIN_ROOM))
	{
		// �α��� �뿡���� �α��θ�ɰ� ���򸻸�ɸ� �ν�
		if (message[COMMAND] != int(COMMAND_TYPE::LOGIN) &&
			message[COMMAND] != int(COMMAND_TYPE::HELP))
			return eMsgType;
	}

	switch (message[COMMAND])
	{
	case COMMAND_TYPE::LOGIN:
		// �α��� ���
		eMsgType = Login(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::HELP:
		// ��ɾ� �ȳ� ���
		eMsgType = Help(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::SHOWROOMALL:
		// ��ȭ�� ��� ���
		eMsgType = ShowRoomAll(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::SHOWROOM:
		// ��ȭ�� ���� ���
		eMsgType = ShowRoom(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::CREATEROOM:
		// ��ȭ�� ����
		eMsgType = CreateRoom(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::JOINROOM:
		// ��ȭ�� ����
		eMsgType = JoinRoom(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::DESTROYROOM:
		// ��ȭ�� ����
		eMsgType = DestoryRoom(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::SHOWUSERALL:
		// �̿��� ��� ���
		eMsgType = ShowUserAll(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::SHOWUSER:
		// Ư�� �̿��� �˻�
		eMsgType = ShowUser(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::SENDMSG:
		// �ӼӸ�
		eMsgType = SendMsg(sock, vecMsg, roomNumber);
		break;
	case COMMAND_TYPE::CLOSE:
		// ���� ����
		eMsgType = Close(sock, vecMsg, roomNumber);
		break;
	default:
		break;
	}

	return eMsgType;
}

void CNetwork::BroadCastMessage(const SOCKET & sock, const char * message, const int & bufCount, const int & roomNumber)
{
	// �ش� Ŭ���̾�Ʈ �ܿ� �濡 �����ϴ� �ٸ� ��� Ŭ���̾�Ʈ���� �ѷ��ִ� �޽��� ���� �Լ�
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
	// �α����� �Ǿ��ִ� ���¿��� �ٽ� �α����� �õ��ϴ� ���
	if (int(ROOM_TYPE::LOGIN_ROOM) != roomNumber)
	{
		return MSG_TYPE::NOTHING;
	}
	client->SetName(vecMsg[KEYWORD].c_str());

	string logMsg;
	logMsg += "[";
	logMsg += vecMsg[KEYWORD].c_str();
	logMsg += "] ���� �α��� �Ͽ����ϴ�..\n\r";
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
		msg += "] �� �����Ͽ����ϴ�.\n\r";
		Send(sock, msg.c_str(), msg.size(), roomNumber);
	}

	{
		string msg;
		msg += pMainRoom->GetRoomName();
		msg += " [";
		msg += to_string(pMainRoom->GetCurrentUser());
		msg += "/";
		msg += to_string(pMainRoom->GetMaxUser());
		msg += "] �� [";
		msg += vecMsg[KEYWORD].c_str();
		msg += "] ���� �����Ͽ����ϴ�.\n\r";
		BroadCastMessage(sock, msg.c_str(), msg.size(), int(ROOM_TYPE::MAIN_ROOM));
	}

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
	msg += " [���̵�] [�޽���]";
	msg += "\t���� ������\n\r";

	msg += command + char(COMMAND_TYPE::CREATEROOM);
	msg += " [�ִ��ο�] [������]";
	msg += "\t��ȭ�� �����\n\r";

	msg += command + char(COMMAND_TYPE::JOINROOM);
	msg += " [���ȣ]";
	msg += "\t\t��ȭ�� �����ϱ�\n\r";

	msg += command + char(COMMAND_TYPE::DESTROYROOM);
	msg += " [���ȣ]";
	msg += "\t\t��ȭ�� ������\n\r";

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

	return MSG_TYPE::SHOWROOMALL_MSG;;
}

MSG_TYPE CNetwork::ShowRoom(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	// /��ɾ� [���ȣ]
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
	// /��ɾ� [�ִ��ο�] [������] �̱� ������ 1�� �ε����� �ִ��ο� ���ڿ��� �������
	int maxUser = atoi(vecMsg[KEYWORD].c_str());
	string strRoomName = "";
	for (size_t i = 2; i < vecMsg.size(); ++i)
	{
		// ���⵵ �����Ͽ� ������ �ޱ� ���ؼ�
		strRoomName += vecMsg[i];
		if (i + 1 < vecMsg.size())
			strRoomName += " ";
	}
	
	// ���ڿ��� ���̴� �� �̻��ϰ� �Է� ���� ���
	if (maxUser <= 0)
	{
		return MSG_TYPE::NOTHING;
	}

	bool result = CRoomMgr::GetInst()->CreateRoom(strRoomName.c_str(), maxUser);
	// �� ���� ����
	if (FALSE == result)
	{
		//string msg;
		//msg = "��ȭ���� ������ �� �����ϴ�.\n\r";
		//Send(sock, msg.c_str(), msg.size(), roomNumber);
		return MSG_TYPE::NOTHING;
	}
	string msg;
	msg += strRoomName;
	msg += " [";
	msg += to_string(maxUser);
	msg += "] �� �����Ǿ����ϴ�.\n\r";
	Send(sock, msg.c_str(), msg.size(), roomNumber);

	return MSG_TYPE::CREATEROOM_MSG;
}

MSG_TYPE CNetwork::JoinRoom(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	// /��ɾ� [���ȣ]
	int newRoomNumber = atoi(vecMsg[KEYWORD].c_str());
	// ������ ��� ���� �� ���� ���� ��Ȳ
	if (newRoomNumber == roomNumber)
	{
		return MSG_TYPE::NOTHING;
	}

	bool result = CRoomMgr::GetInst()->JoinRoom(sock, roomNumber, newRoomNumber);
	// ���� �ʰ� or �ش� ���� ����
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
		msg += "] �� �����Ͽ����ϴ�.\n\r";
		Send(sock, msg.c_str(), msg.size(), roomNumber);
	}

	{
		string msg;
		msg += room->GetRoomName();
		msg += " [";
		msg += to_string(room->GetCurrentUser());
		msg += "/";
		msg += to_string(room->GetMaxUser());
		msg += "] �� [";
		msg += vecMsg[KEYWORD].c_str();
		msg += "] ���� �����Ͽ����ϴ�.\n\r";
		BroadCastMessage(sock, msg.c_str(), msg.size(), roomNumber);
	}

	{
		string msg;
		msg += room->GetRoomName();
		msg += " [";
		msg += to_string(room->GetCurrentUser());
		msg += "/";
		msg += to_string(room->GetMaxUser());
		msg += "] �� [";
		msg += vecMsg[KEYWORD].c_str();
		msg += "] ���� �����Ͽ����ϴ�.\n\r";
		BroadCastMessage(sock, msg.c_str(), msg.size(), newRoomNumber);
	}

	return MSG_TYPE::JOINROOM_MSG;
}

MSG_TYPE CNetwork::DestoryRoom(const SOCKET & sock, const vector<string>& vecMsg, const int& roomNumber)
{
	// /��ɾ� [���ȣ]
	int destoryNumber = atoi(vecMsg[KEYWORD].c_str());
	bool result = CRoomMgr::GetInst()->DestroyRoom(destoryNumber);
	// ���� ����
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
			msg += "���̵� : [";
			msg += client.second->GetName();
			msg += "] \t\t��ȭ�� ��ȣ : [";
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
		// �ش� ������ ã�� �� ����
		return  MSG_TYPE::SHOWUSER_MSG;
	}
	int num = client->GetRoomNumber();
	CRoom* room = CRoomMgr::GetInst()->GetRoom(num);
	string msg;
	msg += "���̵� : [";
	msg += client->GetName();
	msg += "] \t\t��ȭ�� ��ȣ : [";
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
		// �ش� ������ ã�� �� ����
		return  MSG_TYPE::NOTHING;
	}
	//int num = client->GetRoomNumber();
	//CRoom* room = CRoomMgr::GetInst()->GetRoom(num);
	
	string msg = "\r[�ӼӸ�] [";
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
	CRoomMgr::GetInst()->AddClient(ptr->sock, int(ROOM_TYPE::LOGIN_ROOM));

	m_mapClient[ptr->sock] = ptr;

	string msg { "=========================================\n\r\tȯ���մϴ� ä�ü��� �Դϴ�.\n\n\r\t�α��� ��ɾ�(/l)�� ������ּ���.\n\n\n\r\t��ɾ� �ȳ�(/h)\n\r=========================================\n\r>> " };
	Send(ptr->sock, msg.c_str(), msg.size(), 0);

	return TRUE;
}

void CNetwork::RemoveSocketInfo(const SOCKET& socket)
{
	// Ŭ���̾�Ʈ ���� ���
	SOCKADDR_IN clientAddr;
	int addrLen = sizeof(clientAddr);
	getpeername(socket, (SOCKADDR*)&clientAddr, &addrLen);
	char buf[IP_ADDR_LEN];
	inet_ntop(AF_INET, &clientAddr.sin_addr, buf, sizeof(buf));
	printf("[TCP ����] Ŭ���̾�Ʈ ����: IP �ּ� = %s, ��Ʈ ��ȣ = %d\n", buf, ntohs(clientAddr.sin_port));

	m_mapClient.erase(socket);
	CRoomMgr::GetInst()->RemoveClient(socket);
	closesocket(socket);
	m_nClientCount--;
}
