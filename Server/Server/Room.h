#pragma once
class CRoom
{
	string m_strName;
	int m_nNumber;
	int m_nMaxUser;
	int m_nCurrentUser;
public:
	CRoom(const char* strName, int roomNumber, int maxUser);
	~CRoom();

	int GetNumber() const;
	int GetMaxUser() const;
	int GetCurrentUser() const;
	const char* GetRoomName() const;
};

