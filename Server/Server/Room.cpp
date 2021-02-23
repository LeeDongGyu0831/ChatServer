#include "stdafx.h"
#include "Room.h"


CRoom::CRoom(int number, int maxUser) : m_nNumber(number), m_nMaxUser(maxUser), m_nCurrentUser(0)
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
