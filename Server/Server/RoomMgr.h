#pragma once

class CRoom;
class CClient;

class CRoomMgr
{
	// 방 번호를 Key로 매핑하여 Hash로 관리함
	unordered_map<uint, CRoom*>			m_mapRoom;

	stack<uint>							m_stackNumberPool; // 빈 번호를 빠르게 받을 수 있는 Pool
	uint								m_nMaxRoomNumber; // Pool이 없을 경우 해당 변수를 이용하여 번호 부여

	SINGLE(CRoomMgr);

public:
	void Init();

	// 대화방 생성
	bool CreateRoom(const char* strRoomName, const uint& maxUser);
	// 대화방 참가
	bool JoinRoom(const uint& id, const uint& roomNumber, const uint& newRoomNumber);
	// 대화방 폭파
	bool DestroyRoom(const uint& number);

	// 해당 방번호 클라이언트 목록 반환
	unordered_map<uint, CClient*> GetClients(const uint& roomNumber);

	// 각 조건을 바탕으로 클라이언트 검색 및 반환
	CClient* GetClient(const uint& id, const uint& roomNumber);
	CClient* GetClientByID(const uint& id);
	CClient* GetClientByName(const char * name);
	const char* GetClientName(const uint& id, const uint& roomNumber);
	
	// 대화방 반환
	CRoom* GetRoom(const uint& roomNumber);
	bool FindRoom(const uint& roomNumber);

	// 각 방들의 방 번호를 vector로 묶어 반환
	vector<uint> GetRoomNumberArray() const;

	// 해당 대화방에 클라이언트 추가
	bool AddClient(const uint& id, const uint& roomNumber);
	// 클라이언트 대화방 이동
	// bool MoveClient(const CClient* client, const int& currentRoomNumber, const int& destRoomNumber);
	// 클라이언트 삭제
	bool RemoveClient(const uint& id);
	bool RemoveClient(const uint& id, const uint& roomNumber);

	// 대화방 갯수 반환
	uint GetRoomCount() const;
	// 클라이언트 아이디를 바탕으로 대화방 번호 반환
	uint GetRoomNumber(const uint& id);
};

