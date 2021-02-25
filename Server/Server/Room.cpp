#include "stdafx.h"
#include "Room.h"
#include "Client.h"

#include "Network.h"

CRoom::CRoom(const char* strName, const uint& roomNumber, const uint& maxUser) : m_strName(strName), m_nNumber(roomNumber), m_nMaxUser(maxUser), m_nCurrentUser(0)
{
	m_mapClient.clear();
}

CRoom::~CRoom()
{
	Safe_Delete_Unordered_Map(m_mapClient);
}

uint CRoom::GetNumber() const
{
	return m_nNumber;
}

uint CRoom::GetMaxUser() const
{
	return m_nMaxUser;
}

uint CRoom::GetCurrentUser() const
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

unordered_map<uint, CClient*> CRoom::GetClients()
{
	return m_mapClient;
}

CClient * CRoom::GetClient(const uint & id)
{
	unordered_map<uint, CClient*>::iterator iter = m_mapClient.find(id);
	if (iter == m_mapClient.end())
	{
		// 여기에는 해당 클라가 없음
		return NULL;
	}
	return iter->second;
}

bool CRoom::FindClient(const uint & id)
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

const char * CRoom::GetClientName(const uint & id)
{
	unordered_map<uint, CClient*>::iterator iter = m_mapClient.find(id);
	if (iter == m_mapClient.end())
	{
		// 여기에는 해당 클라가 없음
		cout << "Wrong Search ClientName [" << m_nNumber << "]\n";
		return NULL;
	}
	return iter->second->GetName();
}

void CRoom::AddClient(const uint& id, CClient * client)
{
	if (NULL == client)
	{
		cout << "CRoom::AddClient Func Null Error [" << id << "] \n";
		exit(1);
	}
	m_mapClient[id] = client;
	m_mapClient[id]->SetRoomNumber(m_nNumber);

	{
		string msg;
		msg += "\r      [";
		msg += GetRoomName();
		msg += "] 에 참가하였습니다.\n\r";
		CNetwork::GetInst()->Send(id, msg.c_str(), msg.size(), m_nNumber);
	}

	{
		string msg;
		msg += "\r      [";
		msg += GetRoomName();
		msg += "] 에 [";
		msg += client->GetName();
		msg += "] 님이 참가하였습니다.\n\r";
		CNetwork::GetInst()->BroadCastMessage(id, msg.c_str(), msg.size(), m_nNumber);
	}

	ChangeCurrentUserCount(1); // 인원 1명 증가
}

bool CRoom::RemoveClient(const uint & id)
{
	const char* name = GetClientName(id);
	uint count = m_mapClient.erase(id);
	if (0 == count) // 하나도 못찾은 경우 == 삭제된게 없다
	{
		return FALSE;
	}

	{
		string msg;
		msg += "\r      [";
		msg += GetRoomName();
		msg += "] 에 [";
		msg += name;
		msg += "] 님이 퇴장하였습니다.\n\r";
		CNetwork::GetInst()->BroadCastMessage(id, msg.c_str(), msg.size(), m_nNumber);
	}

	ChangeCurrentUserCount(int(count) * -1);
	return TRUE;
}

bool CRoom::ChangeCurrentUserCount(const int& count)
{
	// 정원 초과 or 0명 보다 떨어지는 경우 체크
	if (m_nCurrentUser + count > m_nMaxUser || m_nCurrentUser + count < 0)
		return FALSE;

	m_nCurrentUser += count;
	return TRUE;
}
