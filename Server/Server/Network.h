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
	BOOL AddSocketInfo(const SOCKET& sock);
	void RemoveSocketInfo(const SOCKET& socket);

	MSGTYPE CheckMessage(const SOCKET& sock, const char* message, const int bufCount, const int roomNumber);

	// 명령어 처리 함수
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

