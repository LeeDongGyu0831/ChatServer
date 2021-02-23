#pragma once
class CRoom
{
	int m_nNumber;
	int m_nMaxUser;
	int m_nCurrentUser;
public:
	CRoom(int number, int maxUser);
	~CRoom();

	int GetNumber() const;
	int GetMaxUser() const;
	int GetCurrentUser() const;
};

