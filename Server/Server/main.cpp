#include "stdafx.h"
#include "Network.h"
#include "RoomMgr.h"

// Network Ŭ������ �� ���ϵ�� ���

// RoomMgr�� Room�� �����ϰ� Room�� Client�� ������

int main(int argc, char **argv)
{
	if (1 == argc)
	{
		// 9000 ��Ʈ �̿�
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