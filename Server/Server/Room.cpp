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
		// ���⿡�� �ش� Ŭ�� ����
		return NULL;
	}
	return iter->second;
}

bool CRoom::FindClient(const uint & id)
{
	if (m_mapClient.find(id) == m_mapClient.end())
	{
		// ���⿡�� �ش� Ŭ�� ����
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
		// ���⿡�� �ش� Ŭ�� ����
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
		msg += "] �� �����Ͽ����ϴ�.\n\r";
		CNetwork::GetInst()->Send(id, msg.c_str(), msg.size(), m_nNumber);
	}

	{
		string msg;
		msg += "\r      [";
		msg += GetRoomName();
		msg += "] �� [";
		msg += client->GetName();
		msg += "] ���� �����Ͽ����ϴ�.\n\r";
		CNetwork::GetInst()->BroadCastMessage(id, msg.c_str(), msg.size(), m_nNumber);
	}

	ChangeCurrentUserCount(1); // �ο� 1�� ����
}

bool CRoom::RemoveClient(const uint & id)
{
	const char* name = GetClientName(id);
	uint count = m_mapClient.erase(id);
	if (0 == count) // �ϳ��� ��ã�� ��� == �����Ȱ� ����
	{
		return FALSE;
	}

	{
		string msg;
		msg += "\r      [";
		msg += GetRoomName();
		msg += "] �� [";
		msg += name;
		msg += "] ���� �����Ͽ����ϴ�.\n\r";
		CNetwork::GetInst()->BroadCastMessage(id, msg.c_str(), msg.size(), m_nNumber);
	}

	ChangeCurrentUserCount(int(count) * -1);
	return TRUE;
}

bool CRoom::ChangeCurrentUserCount(const int& count)
{
	// ���� �ʰ� or 0�� ���� �������� ��� üũ
	if (m_nCurrentUser + count > m_nMaxUser || m_nCurrentUser + count < 0)
		return FALSE;

	m_nCurrentUser += count;
	return TRUE;
}
