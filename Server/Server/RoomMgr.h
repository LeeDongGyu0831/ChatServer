#pragma once

class CRoom;

class CRoomMgr
{
	unordered_map<int, CRoom*> m_mapRoom;

	SINGLE(CRoomMgr);

public:

	bool CreateRoom(int number, int maxUser);
	bool DestroyRoom(int number);
	void ShowRoomInfo(int number);
};

