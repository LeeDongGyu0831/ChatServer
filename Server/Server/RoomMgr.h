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
	bool JoinRoom(int id, int roomNumber);
	bool DestroyRoom(int number);
	void ShowRoomInfo(int number);

	list<CClient*> GetClientList(int roomNumber) const;
	CClient* GetClient(int id, int roomNumber) const;
	CClient* GetClientByName(const char * name) const;
	const char* GetClientName(int id, int roomNumber) const;
	CRoom* GetRoom(int roomNumber) const;

	vector<int> GetRoomNumberArray() const;

	bool AddClient(int id, int roomNumber);
	bool RemoveClient(int id);
	bool RemoveClient(int id, int roomNumber);

	int GetRoomCount() const;
};

