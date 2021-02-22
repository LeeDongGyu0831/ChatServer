#pragma once

class CRoom;

class CRoomMgr
{
	unordered_map<int, CRoom*> m_mapRoom;
public:
	CRoomMgr();
	~CRoomMgr();

	bool CreateRoom(int number, int maxUser);
	bool DestroyRoom(int number);
	void ShowRoomInfo(int number);
};

