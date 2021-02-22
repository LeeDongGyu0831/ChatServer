#include "stdafx.h"
#include "Network.h"

int main()
{

	CNetwork::GetInst()->Init(SERVERPORT);

	while (TRUE == CNetwork::GetInst()->Update())
	{

	}

	CNetwork::GetInst()->Close();
}