#pragma once

class CRoom;
class CClient;

class CRoomMgr
{
	// 방 번호를 Key로 매핑하여 Hash로 관리함
	unordered_map<int, CRoom*> m_mapRoom;
	
	int m_nRoomCount; // 대화방 갯수

	SINGLE(CRoomMgr);

public:
	void Init();

	// 대화방 생성
	bool CreateRoom(const char* strRoomName, const int& maxUser);
	// 대화방 참가
	bool JoinRoom(const int& id, const int& roomNumber, const int& newRoomNumber);
	// 대화방 폭파
	bool DestroyRoom(const int& number);
	void ShowRoomInfo(const int& number); // 미구현, 삭제예정

	// 해당 방번호 클라이언트 목록 반환
	unordered_map<int, CClient*> GetClients(const int& roomNumber);

	// 각 조건을 바탕으로 클라이언트 검색 및 반환
	CClient* GetClient(const int& id, const int& roomNumber);
	CClient* GetClientByID(const int& id);
	CClient* GetClientByName(const char * name);
	const char* GetClientName(const int& id, const int& roomNumber);
	
	// 대화방 반환
	CRoom* GetRoom(const int& roomNumber);
	bool FindRoom(const int& roomNumber);

	// 각 방들의 방 번호를 vector로 묶어 반환
	vector<int> GetRoomNumberArray() const;

	// 해당 대화방에 클라이언트 추가
	bool AddClient(const int& id, const int& roomNumber);
	// 클라이언트 대화방 이동
	bool MoveClient(const CClient* client, const int& currentRoomNumber, const int& destRoomNumber);
	// 클라이언트 삭제
	bool RemoveClient(const int& id);
	bool RemoveClient(const int& id, const int& roomNumber);

	// 대화방 갯수 반환
	int GetRoomCount() const;
	// 클라이언트 아이디를 바탕으로 대화방 번호 반환
	int GetRoomNumber(const int& id);
};

