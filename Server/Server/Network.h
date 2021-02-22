#pragma once
#pragma comment(lib, "ws2_32")
#include <stdio.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
using namespace std;

#define SERVERPORT 9000
#define BUFSIZE 512

// 소켓 정보 저장을 위한 구조체와 변수
struct SOCKETINFO
{
	SOCKET sock;
	char buf[BUFSIZE + 1];	// 맨 끝에 '\0'
	int recvBytes;
	int sendBytes;
};

class CNetwork
{
	SOCKET m_Sock;

	int m_nTotalSockets = 0;
	SOCKETINFO* m_socketInfoArray[FD_SETSIZE];

public:
	CNetwork();
	~CNetwork();

public:
	bool Init();
	bool Update();
	void Close();

	// 소켓 관리 함수
	BOOL AddSocketInfo(SOCKET sock);
	void RemoveSocketInfo(int nIndex);
};

