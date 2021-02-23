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

	MSGTYPE m_eMsgType;


	SINGLE(CNetwork);

public:
	bool Init(int nPortNum);
	bool Update();
	void Close();

	// Network �Լ�
	bool Bind();
	bool Accept();
	bool Listen();

	// ���� ���� �Լ�
	BOOL AddSocketInfo(SOCKET sock);
	void RemoveSocketInfo(SOCKET socket);

	MSGTYPE CheckMessage(SOCKET sock, char* message, int bufCount);
};

