#include "stdafx.h"
#include "RoomMgr.h"
#include "Room.h"
#include "Client.h"

CRoomMgr::CRoomMgr()
{
}


CRoomMgr::~CRoomMgr()
{
	//Safe_Delete_Unordered_Map(m_mapClient);
	Safe_Delete_Unordered_Map(m_mapRoom);
	for (auto& data : m_mapClient)
	{
		Safe_Delete_List(data.second);
	}
}

void CRoomMgr::Init()
{
	m_mapClient.clear();
	m_mapRoom.clear();
	m_nRoomCount = 0;

	cout << "RoomManager Init" << endl;

	CreateRoom("Main Room", 64);
}

bool CRoomMgr::CreateRoom(const char* strRoomName, int maxUser)
{
	CRoom* room = new CRoom(strRoomName, m_nRoomCount, 64);
	list<CClient*> clients;
	m_mapRoom[m_nRoomCount] = room;
	m_mapClient[m_nRoomCount] = clients;

	cout << "(" << m_nRoomCount <<") " << strRoomName << " (" << maxUser << ") Create" << endl;

	m_nRoomCount++;

	return TRUE;
}

bool CRoomMgr::JoinRoom(int id, int roomNumber)
{
	return false;
}

bool CRoomMgr::DestroyRoom(int number)
{
	return false;
}

void CRoomMgr::ShowRoomInfo(int number)
{
}

list<CClient*> CRoomMgr::GetClient(int roomNumber) const
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	return m_mapClient.find(roomNumber)->second;
}

CClient * CRoomMgr::GetClient(int id, int roomNumber) const
{
	auto clients = m_mapClient.find(roomNumber);
	auto client = find_if(clients->second.begin(), clients->second.end(), [&](const CClient* cl) {
		if (cl->GetID() == id)
			return true;
		return false;
	});
	if (client == clients->second.end())
		return NULL;
	return (*client);
}

CClient * CRoomMgr::GetClientByName(const char * name) const
{
	/*for (auto& clients : m_mapClient)
	auto client = find_if(clients->second.begin(), clients->second.end(), [&](const CClient* cl) {
		if (cl->GetName() == name)
			return true;
		return false;
	});
	if (client == clients->second.end())
		return NULL;
	return (*client);*/
	return NULL;
}

const char * CRoomMgr::GetClientName(int id, int roomNumber) const
{
	auto clients = m_mapClient.find(roomNumber);
	auto client = find_if(clients->second.begin(), clients->second.end(), [&](const CClient* cl) {
		if (cl->GetID() == id)
			return true;
		return false;
	});
	if (client == clients->second.end())
		return NULL;
	return (*client)->GetName();
}

CRoom * CRoomMgr::GetRoom(int roomNumber) const
{
	return m_mapRoom.find(roomNumber)->second;
}

bool CRoomMgr::AddClient(int id, int roomNumber)
{
	CClient* client = new CClient(id, roomNumber);
	auto p = m_mapClient.find(roomNumber);
	if (p == m_mapClient.end())
	{
		// init���� 0���� ������

		// ������ ���� ����Ʈ �߰�
		/*list<CClient*> dataList;
		dataList.emplace_back(client);
		m_mapClient.insert(make_pair(roomNumber, dataList));*/

		cout << "CRoomMgr AddClient Error" << endl;
	}
	else
	{
		// ������ ���� ����Ʈ�� �߰�

		CRoom* room = m_mapRoom.find(roomNumber)->second;
		// �ش� ���� �� �������� ���
		if (FALSE == room->GetState())
			return FALSE;

		p->second.emplace_back(client);
		room->ChangeCount(1);

		const char* roomName = room->GetRoomName();
		cout << roomNumber << " " << roomName << " Join " << endl;

	}
	return TRUE;
}

bool CRoomMgr::RemoveClient(int id)
{
	for (auto& clientList : m_mapClient)
	{
		auto p = find_if(clientList.second.begin(), clientList.second.end(), [&](const CClient* cl) {
			if (cl->GetID() == id)
				return true;
			return false;
		});
		if (p != clientList.second.end()) {
			clientList.second.erase(p);
			return TRUE;
		}
	}
	return FALSE;
}

bool CRoomMgr::RemoveClient(int id, int roomNumber)
{
	auto p = find_if(m_mapClient.find(roomNumber)->second.begin(), m_mapClient.find(roomNumber)->second.end(), [&](const CClient* cl) {
		if (cl->GetID() == id)
			return true;
		return false;
	});
	if (p != m_mapClient.find(roomNumber)->second.end()) {
		m_mapClient.find(roomNumber)->second.erase(p);
		return TRUE;
	}
	return FALSE;
}

int CRoomMgr::GetRoomCount() const
{
	return m_nRoomCount;
}
