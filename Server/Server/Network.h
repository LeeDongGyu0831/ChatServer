// 소켓 정보 저장을 위한 구조체와 변수
struct SOCKETINFO
{
	SOCKET sock;
	char buf[BUFSIZE + 1];	// 맨 끝에 '\0'
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

	// 데이터 통신에 사용할 변수
	FD_SET rset, wset;
	SOCKET clientSock;
	SOCKADDR_IN clientAddr;
	int addrLen;

	SINGLE(CNetwork);

public:
	bool Init(int nPortNum);
	bool Update();
	void Close();

	// Network 함수
	bool FD_Set();
	bool Select();
	bool Accept();
	bool DataRecv(CClient* client, int roomNumber);
	bool BroadCast(CClient* client, int roomNumber);
	bool Send(const SOCKET& sock, const char* msg, const int size, int roomNumber);

	// 소켓 관리 함수
	BOOL AddSocketInfo(SOCKET sock);
	void RemoveSocketInfo(SOCKET socket);

	MSGTYPE CheckMessage(SOCKET sock, char* message, int bufCount, int roomNumber);
};

