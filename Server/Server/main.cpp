#include "stdafx.h"
#include "Network.h"

int main()
{
	CNetwork network;

	network.Init(SERVERPORT);

	while (TRUE == network.Update())
	{

	}

	cout << "Close" << endl;
	network.Close();
}