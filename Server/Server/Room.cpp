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

const char* CRoom::GetRoomName() const
{
	return m_strName.c_str();
}
