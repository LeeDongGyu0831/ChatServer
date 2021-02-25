// 소켓 정보 저장을 위한 구조체와 변수
struct SOCKETINFO
{
	SOCKET	sock;
	char	buf[BUFSIZE + 1];	// 맨 끝에 '\0'
	uint	recvBytes;
	uint	sendBytes;

	uint	bufCount;
};

class CClient;

class CNetwork
{

	unordered_map<SOCKET, SOCKETINFO*>	m_mapClient;

	// 아이디 중복체크를 위한 맵
	unordered_map<string, SOCKET>		m_mapNamePool;
	uint								m_nClientCount;

	// 받은 메시지가 일반 채팅 메시지인지 명령어 커맨드인지 Enum값
	MSG_TYPE		m_eMsgType;

	// 데이터 통신에 사용할 변수
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

	// Network 함수
	bool FD_Set();
	bool Select();
	bool Accept();
	bool DataRecv(SOCKETINFO* sock);
	bool BroadCast(SOCKETINFO* sock);

	// IP 주소 얻어오기
	IN_ADDR GetDefaultMyIP();

	// 해당 소켓에 메시지 전송
	bool Send(const SOCKET& sock, const char* msg, const uint& size, const uint& roomNumber);

	// 소켓 관리 함수
	BOOL AddSocketInfo(const SOCKET& sock);			// 접속
	void RemoveSocketInfo(const SOCKET& socket);	// 접속해제

	// 전송받은 문자열을 바탕으로 명령어체크 or 브로드캐스팅 판단
	MSG_TYPE CheckMessage(const SOCKET& sock, const char* message, const uint& bufCount, const uint& roomNumber);
	void BroadCastMessage(const SOCKET& sock, const char* message, const uint& bufCount, const uint& roomNumber);

	// 에러 타입에 따른 메시지 전송
	void CheckErrorMsgType(const SOCKET& sock, MSG_TYPE eType, const uint& roomNumber);

	// 명령어 처리 함수
	MSG_TYPE Login(const SOCKET& sock, const vector<string>& vecMsg, const uint& roomNumber);		// 로그인 처리
	MSG_TYPE Help(const SOCKET& sock);																// 명령어 도움말 전송
	MSG_TYPE ShowRoomAll(const SOCKET& sock);														// 대화방 목록 출력
	MSG_TYPE ShowRoom(const SOCKET& sock, const vector<string>& vecMsg);							// 특정 대화방 정보 출력
	MSG_TYPE CreateRoom(const SOCKET& sock, const vector<string>& vecMsg, const uint& roomNumber);	// 대화방 생성
	MSG_TYPE JoinRoom(const SOCKET& sock, const vector<string>& vecMsg, const uint& roomNumber);	// 대화방 참가
	MSG_TYPE DestoryRoom(const vector<string>& vecMsg);												// 대화방 폭파
	MSG_TYPE ShowUserAll(const SOCKET& sock);														// 유저 목록 출력
	MSG_TYPE ShowUser(const SOCKET& sock, const vector<string>& vecMsg);							// 특정 유저 정보 출력
	MSG_TYPE SendMsg(const SOCKET& sock, const vector<string>& vecMsg, const uint& roomNumber);		// 쪽지보내기(귓속말)
	MSG_TYPE Close(const SOCKET& sock);																// 접속 종료
};

