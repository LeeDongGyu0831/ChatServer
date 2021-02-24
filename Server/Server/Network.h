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

	// ���� �޽����� �Ϲ� ä�� �޽������� ��ɾ� Ŀ�ǵ����� Enum��
	MSG_TYPE m_eMsgType;

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
	bool DataRecv(const CClient* client, const int& roomNumber);
	bool BroadCast(const CClient* client, const int& roomNumber); // 

	// �ش� ���Ͽ� �޽��� ����
	bool Send(const SOCKET& sock, const char* msg, const int& size, const int& roomNumber);

	// ���� ���� �Լ�
	BOOL AddSocketInfo(const SOCKET& sock); // ����
	void RemoveSocketInfo(const SOCKET& socket); // ��������

	// ���۹��� ���ڿ��� �������� ��ɾ�üũ or ��ε�ĳ���� �Ǵ�
	MSG_TYPE CheckMessage(const SOCKET& sock, const char* message, const int& bufCount, const int& roomNumber);

	// ��ɾ� ó�� �Լ�
	MSG_TYPE Login(const SOCKET& sock, const vector<string>& vecMsg, const int& roomNumber); // �α��� ó��
	MSG_TYPE Help(const SOCKET& sock, const vector<string>& vecMsg, const int& roomNumber); // ��ɾ� ���� ����
	MSG_TYPE ShowRoomAll(const SOCKET& sock, const vector<string>& vecMsg, const int& roomNumber); // ��ȭ�� ��� ���
	MSG_TYPE ShowRoom(const SOCKET& sock, const vector<string>& vecMsg, const int& roomNumber); // Ư�� ��ȭ�� ���� ���
	MSG_TYPE CreateRoom(const SOCKET& sock, const vector<string>& vecMsg, const int& roomNumber); // ��ȭ�� ����
	MSG_TYPE JoinRoom(const SOCKET& sock, const vector<string>& vecMsg, const int& roomNumber); // ��ȭ�� ����
	MSG_TYPE DestoryRoom(const SOCKET& sock, const vector<string>& vecMsg, const int& roomNumber); // ��ȭ�� ����
	MSG_TYPE ShowUserAll(const SOCKET& sock, const vector<string>& vecMsg, const int& roomNumber); // ���� ��� ���
	MSG_TYPE ShowUser(const SOCKET& sock, const vector<string>& vecMsg, const int& roomNumber); // Ư�� ���� ���� ���
	MSG_TYPE SendMsg(const SOCKET& sock, const vector<string>& vecMsg, const int& roomNumber); // ����������(�ӼӸ�)
};

