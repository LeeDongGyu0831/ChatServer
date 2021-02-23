#pragma once

class CRoom;
class CClient;

class CRoomMgr
{
	unordered_map<int, CRoom*> m_mapRoom;
	unordered_map<int, list<CClient*>> m_mapClient;

	int m_nRoomCount;
	SINGLE(CRoomMgr);

public:
	void Init();

	bool CreateRoom(const char* strRoomName, int maxUser);
	bool DestroyRoom(int number);
	void ShowRoomInfo(int number);

	list<CClient*> GetClient(int roomNumber) const;
	CClient* GetClient(int id, int roomNumber) const;
	const char* GetClientName(int id, int roomNumber) const;
	CRoom* GetRoom(int roomNumber) const;

	bool AddClient(int id, int roomNumber);
	bool RemoveClient(int id);
	bool RemoveClient(int id, int roomNumber);

	int GetRoomCount() const;
};

