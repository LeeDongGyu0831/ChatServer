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

	CreateRoom("MainRoom", 64);
}

bool CRoomMgr::CreateRoom(const char* strRoomName, const int& maxUser)
{
	CRoom* room = new CRoom(strRoomName, m_nRoomCount, maxUser);
	if (NULL == room)
	{
		cout << "[오류] 메모리가 부족합니다! \n";
		exit(1);
	}
	list<CClient*> clients;
	m_mapRoom[m_nRoomCount] = room;
	m_mapClient[m_nRoomCount] = clients;

	cout << "(" << m_nRoomCount <<") " << strRoomName << " (" << maxUser << ") Create" << endl;

	m_nRoomCount++;

	return TRUE;
}

bool CRoomMgr::JoinRoom(const int& id, const int& roomNumber, const int& newRoomNumber)
{
	int currentUser = m_mapRoom.find(newRoomNumber)->second->GetCurrentUser();
	int maxUser = m_mapRoom.find(newRoomNumber)->second->GetMaxUser();

	// 정원 초과
	if (currentUser >= maxUser)
		return false;

	CClient* client = GetClient(id, roomNumber);
	if (NULL == client)
	{
		cout << "JoinRoom Func Null Error! \n";
		exit(1);
	}
	
	RemoveClient(id);

	return true;
}

bool CRoomMgr::DestroyRoom(const int& number)
{
	return false;
}

void CRoomMgr::ShowRoomInfo(const int& number)
{
}

list<CClient*> CRoomMgr::GetClientList(const int& roomNumber) const
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return m_mapClient.find(roomNumber)->second;
}

CClient * CRoomMgr::GetClient(const int& id, const int& roomNumber) const
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
	//for (auto& clients : m_mapClient)
	//{
	//	auto client = find_if(clients->second.begin(), clients->second.end(), [&](const CClient* cl) {
	//		if (cl->GetName() == name)
	//			return true;
	//		return false;
	//	});
	//	if (client == clients->second.end())
	//		return NULL;
	//	return (*client);
	//}
	return NULL;
}

const char * CRoomMgr::GetClientName(const int& id, const int& roomNumber) const
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

CRoom * CRoomMgr::GetRoom(const int& roomNumber) const
{
	return m_mapRoom.find(roomNumber)->second;
}

vector<int> CRoomMgr::GetRoomNumberArray() const
{
	vector<int> vecNumber;
	vecNumber.reserve(m_nRoomCount);
	for (auto& room : m_mapRoom)
	{
		vecNumber.emplace_back(room.second->GetNumber());
	}
	return vecNumber;
}

bool CRoomMgr::AddClient(const int& id, const int& roomNumber)
{
	CClient* client = new CClient(id, roomNumber);
	if (NULL == client)
	{
		cout << "[오류] 메모리가 부족합니다! \n";
		exit(1);
	}
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

		CRoom* room = m_mapRoom.find(roomNumber)->second;
		// 해당 방이 다 차버렸을 경우
		if (FALSE == room->GetState())
			return FALSE;

		p->second.emplace_back(client);
		room->ChangeCount(1);

		const char* roomName = room->GetRoomName();
		cout << roomNumber << " " << roomName << " Join " << endl;

	}
	return TRUE;
}

bool CRoomMgr::MoveClient(const CClient * client, const int& currentRoomNumber, const int& destRoomNumber)
{
	return TRUE;
}

bool CRoomMgr::RemoveClient(const int& id)
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

bool CRoomMgr::RemoveClient(const int& id, const int& roomNumber)
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
