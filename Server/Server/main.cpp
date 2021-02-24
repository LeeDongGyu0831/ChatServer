#include "stdafx.h"
#include "Network.h"
#include "RoomMgr.h"

// Network 클래스가 각 소켓들과 통신

// RoomMgr는 Room을 관리하고 Room은 Client를 관리함

int main(int argc, char **argv)
{
	if (1 == argc)
	{
		// 9000 포트 이용
		CNetwork::GetInst()->Init(SERVERPORT);
	}
	else
	{
		int nPort = atoi(argv[1]);
		if(0 == nPort)
			CNetwork::GetInst()->Init(SERVERPORT);
		else
			CNetwork::GetInst()->Init(nPort);
	}
	CRoomMgr::GetInst()->Init();

	cout << "====================================\n";
	while (TRUE == CNetwork::GetInst()->Update())
	{

	}

	CNetwork::GetInst()->Close();
}