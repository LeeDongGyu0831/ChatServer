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

	bool CreateRoom(const char* strRoomName, const int& maxUser);
	bool JoinRoom(const int& id, const int& roomNumber, const int& newRoomNumber);
	bool DestroyRoom(const int& number);
	void ShowRoomInfo(const int& number);

	list<CClient*> GetClientList(const int& roomNumber) const;
	CClient* GetClient(const int& id, const int& roomNumber) const;
	CClient* GetClientByName(const char * name) const;
	const char* GetClientName(const int& id, const int& roomNumber) const;
	CRoom* GetRoom(const int& roomNumber) const;

	vector<int> GetRoomNumberArray() const;

	bool AddClient(const int& id, const int& roomNumber);
	bool MoveClient(const CClient* client, const int& currentRoomNumber, const int& destRoomNumber);
	bool RemoveClient(const int& id);
	bool RemoveClient(const int& id, const int& roomNumber);

	int GetRoomCount() const;
};

