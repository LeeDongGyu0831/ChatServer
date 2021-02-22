#define BUFSIZE 512
#define NAMESIZE 10

// 소켓 정보 저장을 위한 구조체와 변수
struct SOCKETINFO
{
	SOCKET sock;
	char buf[BUFSIZE + 1];	// 맨 끝에 '\0'
	int recvBytes;
	int sendBytes;

	int bufCount;
};

struct CLIENTINFO
{
	char name[NAMESIZE + 1];
	int nameSize;
	int roomNumber;
};

class CNetwork
{
	SOCKET m_Sock;

	unordered_map<SOCKET, SOCKETINFO*> m_mapClient;
	unordered_map<SOCKET, CLIENTINFO*> m_mapClientInfo;

	MSGTYPE m_eMsgType;


	SINGLE(CNetwork);

public:
	bool Init(int nPortNum);
	bool Update();
	void Close();

	// 소켓 관리 함수
	BOOL AddSocketInfo(SOCKET sock);
	void RemoveSocketInfo(SOCKET socket);

	MSGTYPE CheckMessage(SOCKET sock, char* message, int bufCount);
};

