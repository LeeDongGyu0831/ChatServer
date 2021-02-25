// ���� ���� ������ ���� ����ü�� ����
struct SOCKETINFO
{
	SOCKET	sock;
	char	buf[BUFSIZE + 1];	// �� ���� '\0'
	uint	recvBytes;
	uint	sendBytes;

	uint	bufCount;
};

class CClient;

class CNetwork
{

	unordered_map<SOCKET, SOCKETINFO*>	m_mapClient;

	// ���̵� �ߺ�üũ�� ���� ��
	unordered_map<string, SOCKET>		m_mapNamePool;
	uint								m_nClientCount;

	// ���� �޽����� �Ϲ� ä�� �޽������� ��ɾ� Ŀ�ǵ����� Enum��
	MSG_TYPE		m_eMsgType;

	// ������ ��ſ� ����� ����
	SOCKET			m_Sock;

	FD_SET			m_rset, m_wset;
	SOCKET			m_sockClient;
	SOCKADDR_IN		m_addrClientSock;
	int				m_nAddrLen;

	SINGLE(CNetwork);

public:
	bool Init(int nPortNum);
	bool Update();
	void Close();

	// Network �Լ�
	bool FD_Set();
	bool Select();
	bool Accept();
	bool DataRecv(SOCKETINFO* sock);
	bool BroadCast(SOCKETINFO* sock);

	// IP �ּ� ������
	IN_ADDR GetDefaultMyIP();

	// �ش� ���Ͽ� �޽��� ����
	bool Send(const SOCKET& sock, const char* msg, const uint& size, const uint& roomNumber);

	// ���� ���� �Լ�
	BOOL AddSocketInfo(const SOCKET& sock);			// ����
	void RemoveSocketInfo(const SOCKET& socket);	// ��������

	// ���۹��� ���ڿ��� �������� ��ɾ�üũ or ��ε�ĳ���� �Ǵ�
	MSG_TYPE CheckMessage(const SOCKET& sock, const char* message, const uint& bufCount, const uint& roomNumber);
	void BroadCastMessage(const SOCKET& sock, const char* message, const uint& bufCount, const uint& roomNumber);

	// ���� Ÿ�Կ� ���� �޽��� ����
	void CheckErrorMsgType(const SOCKET& sock, MSG_TYPE eType, const uint& roomNumber);

	// ��ɾ� ó�� �Լ�
	MSG_TYPE Login(const SOCKET& sock, const vector<string>& vecMsg, const uint& roomNumber);		// �α��� ó��
	MSG_TYPE Help(const SOCKET& sock);																// ��ɾ� ���� ����
	MSG_TYPE ShowRoomAll(const SOCKET& sock);														// ��ȭ�� ��� ���
	MSG_TYPE ShowRoom(const SOCKET& sock, const vector<string>& vecMsg);							// Ư�� ��ȭ�� ���� ���
	MSG_TYPE CreateRoom(const SOCKET& sock, const vector<string>& vecMsg, const uint& roomNumber);	// ��ȭ�� ����
	MSG_TYPE JoinRoom(const SOCKET& sock, const vector<string>& vecMsg, const uint& roomNumber);	// ��ȭ�� ����
	MSG_TYPE DestoryRoom(const vector<string>& vecMsg);												// ��ȭ�� ����
	MSG_TYPE ShowUserAll(const SOCKET& sock);														// ���� ��� ���
	MSG_TYPE ShowUser(const SOCKET& sock, const vector<string>& vecMsg);							// Ư�� ���� ���� ���
	MSG_TYPE SendMsg(const SOCKET& sock, const vector<string>& vecMsg, const uint& roomNumber);		// ����������(�ӼӸ�)
	MSG_TYPE Close(const SOCKET& sock);																// ���� ����
};

