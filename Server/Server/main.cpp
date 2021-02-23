#include "stdafx.h"
#include "Network.h"
#include "RoomMgr.h"

int main()
{

	CNetwork::GetInst()->Init(SERVERPORT);
	CRoomMgr::GetInst()->Init();

	while (TRUE == CNetwork::GetInst()->Update())
	{

	}

	CNetwork::GetInst()->Close();
}