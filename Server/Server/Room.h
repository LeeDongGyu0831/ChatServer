#pragma once

class CClient;

class CRoom
{
	// 대화방 이름
	string m_strName;

	// 대화방 번호
	uint m_nNumber;

	// 대화방 최대 접속 인원
	uint m_nMaxUser;

	// 대화방 현재 접속 인원
	uint m_nCurrentUser;

	// 대화방 접속 클라이언트
	unordered_map<uint, CClient*> m_mapClient;

public:
	CRoom(const char* strName, const uint& roomNumber, const uint& maxUser);
	~CRoom();

	uint GetNumber() const; // 방 번호
	uint GetMaxUser() const; // 최대 인원
	uint GetCurrentUser() const; // 현재 인원
	bool GetState() const; // 현재 접속 인원이 여유가 있는지

	const char* GetRoomName() const;

	// 현재 접속중인 클라이언트들 반환
	unordered_map<uint, CClient*> GetClients();

	// 클라이언트 ID (소켓번호)를 바탕으로 검색
	CClient* GetClient(const uint& id);
	bool FindClient(const uint& id);

	// 클라이언트 이름을 바탕으로 검색
	CClient* GetClientByName(const char * name);

	// 클라이언트 ID (소켓번호)를 바탕으로 검색, 이름을 반환
	const char* GetClientName(const uint& id);

	// 대화방에 클라이언트 등록
	void AddClient(const uint& id, CClient* client);
	// 해당 클라이언트 제거
	bool RemoveClient(const uint& id);

	bool ChangeCurrentUserCount(const int& count);
};

