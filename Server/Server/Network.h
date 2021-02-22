#pragma once
#pragma comment(lib, "ws2_32")
#include <stdio.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
using namespace std;

#define SERVERPORT 9000
#define BUFSIZE 512

// ���� ���� ������ ���� ����ü�� ����
struct SOCKETINFO
{
	SOCKET sock;
	char buf[BUFSIZE + 1];	// �� ���� '\0'
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

	// ���� ���� �Լ�
	BOOL AddSocketInfo(SOCKET sock);
	void RemoveSocketInfo(int nIndex);
};

