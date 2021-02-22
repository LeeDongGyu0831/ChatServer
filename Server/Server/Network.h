#define BUFSIZE 512

// ���� ���� ������ ���� ����ü�� ����
struct SOCKETINFO
{
	SOCKET sock;
	char buf[BUFSIZE + 1];	// �� ���� '\0'
	int recvBytes;
	int sendBytes;

	int bufCount;
};

class CNetwork
{
	SOCKET m_Sock;

	unordered_map<SOCKET, SOCKETINFO*> m_mapClient;

public:
	CNetwork();
	~CNetwork();

public:
	bool Init(int nPortNum);
	bool Update();
	void Close();

	// ���� ���� �Լ�
	BOOL AddSocketInfo(SOCKET sock);
	void RemoveSocketInfo(SOCKET socket);
};

