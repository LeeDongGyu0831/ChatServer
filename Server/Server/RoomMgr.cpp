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

	CreateRoom(0, 64);
}

bool CRoomMgr::CreateRoom(int number, int maxUser)
{
	CRoom* room = new CRoom(0, 64);
	list<CClient*> clients;
	m_mapRoom[number] = room;
	m_mapClient[number] = clients;
	m_nRoomCount++;

	cout << "Create " << number <<" Room (" << maxUser << ") Finish" << endl;
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
	// TODO: 여기에 반환 구문을 삽입합니다.
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
		// init에서 0번방 생성함

		// 없으니 새로 리스트 추가
		/*list<CClient*> dataList;
		dataList.emplace_back(client);
		m_mapClient.insert(make_pair(roomNumber, dataList));*/

		cout << "CRoomMgr AddClient Error" << endl;
	}
	else
	{
		// 있으니 기존 리스트에 추가
		p->second.emplace_back(client);
		cout << roomNumber << " Room Join " << endl;
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
