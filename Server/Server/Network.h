#define BUFSIZE 512

// 소켓 정보 저장을 위한 구조체와 변수
struct SOCKETINFO
{
	SOCKET sock;
	char buf[BUFSIZE + 1];	// 맨 끝에 '\0'
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

	// 소켓 관리 함수
	BOOL AddSocketInfo(SOCKET sock);
	void RemoveSocketInfo(SOCKET socket);
};

