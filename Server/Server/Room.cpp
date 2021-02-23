#include "stdafx.h"
#include "Room.h"


CRoom::CRoom(const char* strName, int roomNumber, int maxUser) : m_strName(strName), m_nNumber(roomNumber), m_nMaxUser(maxUser), m_nCurrentUser(0)
{
}

CRoom::~CRoom()
{
}

int CRoom::GetNumber() const
{
	return m_nMaxUser;
}

int CRoom::GetMaxUser() const
{
	return m_nMaxUser;
}

int CRoom::GetCurrentUser() const
{
	return m_nCurrentUser;
}

bool CRoom::GetState() const
{
	if (m_nCurrentUser >= m_nMaxUser)
		return false;
	return true;
}

const char* CRoom::GetRoomName() const
{
	return m_strName.c_str();
}

bool CRoom::ChangeCount(int count)
{
	m_nCurrentUser += count;
	if (m_nCurrentUser + count > m_nMaxUser || m_nCurrentUser + count < 0)
		cout << m_nCurrentUser + count << " in (" << m_nNumber << ") " << m_strName.c_str() << endl;

	return TRUE;
}
