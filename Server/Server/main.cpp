#include "stdafx.h"
#include "Network.h"
#include "RoomMgr.h"

// Network Ŭ������ �� ���ϵ�� ���

// RoomMgr�� Room�� �����ϰ� Room�� Client�� ������

int main()
{
	// 9000 ��Ʈ �̿�
	CNetwork::GetInst()->Init(SERVERPORT);
	CRoomMgr::GetInst()->Init();

	while (TRUE == CNetwork::GetInst()->Update())
	{

	}

	CNetwork::GetInst()->Close();
}