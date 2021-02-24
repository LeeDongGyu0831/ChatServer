// ���� ���� ������ ���� ����ü�� ����
struct SOCKETINFO
{
	SOCKET sock;
	char buf[BUFSIZE + 1];	// �� ���� '\0'
	int recvBytes;
	int sendBytes;

	int bufCount;
};

class CClient;

class CNetwork
{
	SOCKET m_Sock;

	unordered_map<SOCKET, SOCKETINFO*> m_mapClient;

	MSGTYPE m_eMsgType;

	// ������ ��ſ� ����� ����
	FD_SET rset, wset;
	SOCKET clientSock;
	SOCKADDR_IN clientAddr;
	int addrLen;

	SINGLE(CNetwork);

public:
	bool Init(int nPortNum);
	bool Update();
	void Close();

	// Network �Լ�
	bool FD_Set();
	bool Select();
	bool Accept();
	bool DataRecv(CClient* client, int roomNumber);
	bool BroadCast(CClient* client, int roomNumber);
	bool Send(const SOCKET& sock, const char* msg, const int size, int roomNumber);

	// ���� ���� �Լ�
	BOOL AddSocketInfo(const SOCKET& sock);
	void RemoveSocketInfo(const SOCKET& socket);

	MSGTYPE CheckMessage(const SOCKET& sock, const char* message, const int bufCount, const int roomNumber);

	// ��ɾ� ó�� �Լ�
	MSGTYPE Login(const SOCKET& sock, const vector<string>& vecMsg, const int roomNumber);
	MSGTYPE Help(const SOCKET& sock, const vector<string>& vecMsg, const int roomNumber);
	MSGTYPE ShowRoomAll(const SOCKET& sock, const vector<string>& vecMsg, const int roomNumber);
	MSGTYPE ShowRoom(const SOCKET& sock, const vector<string>& vecMsg, const int roomNumber);
	MSGTYPE CreateRoom(const SOCKET& sock, const vector<string>& vecMsg, const int roomNumber);
	MSGTYPE JoinRoom(const SOCKET& sock, const vector<string>& vecMsg, const int roomNumber);
	MSGTYPE DestoryRoom(const SOCKET& sock, const vector<string>& vecMsg, const int roomNumber);
	MSGTYPE ShowUserAll(const SOCKET& sock, const vector<string>& vecMsg, const int roomNumber);
	MSGTYPE ShowUser(const SOCKET& sock, const vector<string>& vecMsg, const int roomNumber);
	MSGTYPE SendMsg(const SOCKET& sock, const vector<string>& vecMsg, const int roomNumber);
};

