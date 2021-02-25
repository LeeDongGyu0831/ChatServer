#pragma once

class CClient
{
	int m_nID; // 소켓번호 == 아이디
	string m_strName; // 이름

	// 현재 접속해있는 대화방 번호
	uint m_nRoomNumber;

public:
	CClient(int id, int roomNumber);
	~CClient();

	int GetRoomNumber() const; // 현재 클라이언트가 접속중인 방 번호
	const char* GetName() const; // 클라이언트의 이름, 닉네임
	int GetNameSize() const; // 사이즈
	int GetID() const; // 아이디

	void SetName(const char* name);
	void SetRoomNumber(int roomNumber);
};

