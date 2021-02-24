#include "stdafx.h"
#include "Room.h"
#include "Client.h"

CRoom::CRoom(const char* strName, int roomNumber, int maxUser) : m_strName(strName), m_nNumber(roomNumber), m_nMaxUser(maxUser), m_nCurrentUser(0)
{
	m_mapClient.clear();
}

CRoom::~CRoom()
{
	Safe_Delete_Unordered_Map(m_mapClient);
}

int CRoom::GetNumber() const
{
	return m_nNumber;
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

unordered_map<int, CClient*> CRoom::GetClients()
{
	return m_mapClient;
}

CClient * CRoom::GetClient(const int & id)
{
	unordered_map<int, CClient*>::iterator iter = m_mapClient.find(id);
	if (iter == m_mapClient.end())
	{
		// 여기에는 해당 클라가 없음
		return NULL;
	}
	return m_mapClient.find(id)->second;
}

bool CRoom::FindClient(const int & id)
{
	if (m_mapClient.find(id) == m_mapClient.end())
	{
		// 여기에는 해당 클라가 없음
		return FALSE;
	}
	return TRUE;
}

CClient * CRoom::GetClientByName(const char * name)
{
	for (auto& client : m_mapClient)
	{
		if (0 == strcmp(client.second->GetName(), name))
		{
			return client.second;
		}
	}
	return NULL;
}

const char * CRoom::GetClientName(const int & id)
{
	unordered_map<int, CClient*>::iterator iter = m_mapClient.find(id);
	if (iter == m_mapClient.end())
	{
		// 여기에는 해당 클라가 없음
		cout << "Wrong Search ClientName [" << m_nNumber << "]\n";
		return NULL;
	}
	return iter->second->GetName();
}

void CRoom::AddClient(const int& id, CClient * client)
{
	m_mapClient[id] = client;
	m_mapClient[id]->SetRoomNumber(m_nNumber);
	ChangeCurrentUserCount(1); // 인원 1명 증가
}

bool CRoom::RemoveClient(const int & id)
{
	int count = m_mapClient.erase(id);
	if (0 == count) // 하나도 못찾은 경우 == 삭제된게 없다
	{
		return FALSE;
	}
	ChangeCurrentUserCount(-count);
	return TRUE;
}

bool CRoom::ChangeCurrentUserCount(int count)
{
	// 정원 초과 or 0명 보다 떨어지는 경우 체크
	if (m_nCurrentUser + count > m_nMaxUser || m_nCurrentUser + count < 0)
		return FALSE;

	m_nCurrentUser += count;
	return TRUE;
}
