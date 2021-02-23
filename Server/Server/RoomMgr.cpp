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

	CreateRoom(0, 64);
}

bool CRoomMgr::CreateRoom(int number, int maxUser)
{
	CRoom* room = new CRoom(0, 64);
	list<CClient*> clients;
	m_mapRoom[number] = room;
	m_mapClient[number] = clients;
	m_nRoomCount++;
	return TRUE;
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

const char * CRoomMgr::GetClientName(int id, int roomNumber) const
{
	auto clients = m_mapClient.find(roomNumber);
	auto client = find_if(clients->second.begin(), clients->second.end(), [&](const CClient* cl) {
		if (cl->GetID() == id)
			return true;
		return false;
	});
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
		p->second.emplace_back(client);
	}
	return TRUE;
}

bool CRoomMgr::RemoveClient(int id) const
{
	return false;
}

bool CRoomMgr::RemoveClient(int id, int roomNumber) const
{
	return false;
}

int CRoomMgr::GetRoomCount() const
{
	return m_nRoomCount;
}
