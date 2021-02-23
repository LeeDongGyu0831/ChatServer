#include "stdafx.h"
#include "Client.h"


CClient::CClient(int id, int roomNumber = 0) : m_nID(id), m_nRoomNumber(roomNumber)
{
}


CClient::~CClient()
{
}

int CClient::GetRoomNumber() const
{
	return m_nRoomNumber;
}

const char * CClient::GetName() const
{
	return m_strName.c_str();
}

int CClient::GetNameSize() const
{
	return m_strName.size();
}

int CClient::GetID() const
{
	return m_nID;
}

void CClient::SetName(const char * name)
{
	m_strName = name;
}

void CClient::SetRoomNumber(int roomNumber)
{
	m_nRoomNumber = roomNumber;
}
