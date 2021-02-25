#pragma once

class CClient;

class CRoom
{
	// 대화방 이름
	string m_strName;

	// 대화방 번호
	int m_nNumber;

	// 대화방 최대 접속 인원
	int m_nMaxUser;

	// 대화방 현재 접속 인원
	int m_nCurrentUser;

	// 대화방 접속 클라이언트
	unordered_map<int, CClient*> m_mapClient;

public:
	CRoom(const char* strName, int roomNumber, int maxUser);
	~CRoom();

	int GetNumber() const; // 방 번호
	int GetMaxUser() const; // 최대 인원
	int GetCurrentUser() const; // 현재 인원
	bool GetState() const; // 현재 접속 인원이 여유가 있는지

	const char* GetRoomName() const;

	// 현재 접속중인 클라이언트들 반환
	unordered_map<int, CClient*> GetClients();

	// 클라이언트 ID (소켓번호)를 바탕으로 검색
	CClient* GetClient(const int& id);
	bool FindClient(const int& id);

	// 클라이언트 이름을 바탕으로 검색
	CClient* GetClientByName(const char * name);

	// 클라이언트 ID (소켓번호)를 바탕으로 검색, 이름을 반환
	const char* GetClientName(const int& id);

	// 대화방에 클라이언트 등록
	void AddClient(const int& id, CClient* client);
	// 해당 클라이언트 제거
	bool RemoveClient(const int& id);

	bool ChangeCurrentUserCount(int count);
};

