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
}

void CRoomMgr::Init()
{
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
	m_mapRoom[m_nRoomCount] = room;

	cout << "(" << m_nRoomCount <<") " << strRoomName << " (" << maxUser << ") Create" << endl;

	m_nRoomCount++;

	return TRUE;
}

bool CRoomMgr::JoinRoom(const int& id, const int& roomNumber, const int& newRoomNumber)
{
	// 현재 추가해야함
	int currentUser = m_mapRoom.find(newRoomNumber)->second->GetCurrentUser();
	int maxUser = m_mapRoom.find(newRoomNumber)->second->GetMaxUser();

	// 정원 초과
	if (currentUser >= maxUser)
		return false;

	const CClient* client = GetClient(id, roomNumber);
	if (NULL == client)
	{
		cout << "JoinRoom Func Null Error! \n";
		exit(1);
	}

	return true;
}

bool CRoomMgr::DestroyRoom(const int& number)
{
	return false;
}

void CRoomMgr::ShowRoomInfo(const int& number)
{
}

unordered_map<int, CClient*> CRoomMgr::GetClients(const int& roomNumber)
{
	unordered_map<int, CRoom*>::iterator iter = m_mapRoom.find(roomNumber);
	if (iter == m_mapRoom.end())
	{
		// 해당 룸이 없음
		cout << "RoomMgr GetClients Func Error \n";
		exit(1);
	}
	return iter->second->GetClients();
}

CClient * CRoomMgr::GetClient(const int& id, const int& roomNumber)
{
	unordered_map<int, CRoom*>::iterator iter = m_mapRoom.find(roomNumber);
	if (iter == m_mapRoom.end())
	{
		// 해당 룸이 없음
		cout << "RoomMgr GetClient Func Error \n";
		return NULL;
	}
	return iter->second->GetClient(id);
}

CClient * CRoomMgr::GetClientByName(const char * name)
{
	for (auto& room : m_mapRoom)
	{
		CClient* client = room.second->GetClientByName(name);
		if (NULL != client)
		{
			return client;
		}
	}
	cout << "Wrong Search Client Name \n";
	return NULL;
}

const char * CRoomMgr::GetClientName(const int& id, const int& roomNumber)
{
	unordered_map<int, CRoom*>::iterator iter = m_mapRoom.find(roomNumber);
	if (iter == m_mapRoom.end())
	{
		// 해당 룸이 없음
		cout << "RoomMgr GetClientName Func Error No Room \n";
		return NULL;
	}

	const char* name = iter->second->GetClientName(id);
	if (NULL == name)
	{
		// 해당 클라이언트 없음
		cout << "RoomMgr GetClientName Func Error Name is NULL \n";
		return NULL;
	}

	return name;
}

CRoom * CRoomMgr::GetRoom(const int& roomNumber)
{
	unordered_map<int, CRoom*>::iterator iter = m_mapRoom.find(roomNumber);
	if (iter == m_mapRoom.end())
	{
		// 해당 룸이 없음
		cout << "RoomMgr GetClientName Func Error \n";
		return NULL;
	}
	return iter->second;
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

	unordered_map<int, CRoom*>::iterator roomIter = m_mapRoom.find(roomNumber);
	if (roomIter == m_mapRoom.end())
	{
		// 해당 룸이 없음
		cout << "RoomMgr GetClientName Func Error \n";
		return FALSE;
	}
	// 해당 방이 다 차버렸을 경우
	if (FALSE == roomIter->second->GetState())
		return FALSE;

	roomIter->second->AddClient(id, client);

	const char* roomName = roomIter->second->GetRoomName();
	cout << roomNumber << " " << roomName << " Join " << endl;

	return TRUE;
}

bool CRoomMgr::MoveClient(const CClient * client, const int& currentRoomNumber, const int& destRoomNumber)
{
	// 클라이언트 대화방 이동
	return TRUE;
}

bool CRoomMgr::RemoveClient(const int& id)
{
	for (auto& room : m_mapRoom)
	{
		if (TRUE == room.second->FindClient(id))
		{
			room.second->RemoveClient(id);
			return TRUE;
		}
	}
	return FALSE;

	//for (auto& clientList : m_mapClient)
	//{
	//	auto p = find_if(clientList.second.begin(), clientList.second.end(), [&](const CClient* cl) {
	//		if (cl->GetID() == id)
	//			return true;
	//		return false;
	//	});
	//	if (p != clientList.second.end()) {
	//		clientList.second.erase(p);
	//		return TRUE;
	//	}
	//}
}

bool CRoomMgr::RemoveClient(const int& id, const int& roomNumber)
{
	unordered_map<int, CRoom*>::iterator iter = m_mapRoom.find(roomNumber);
	if (iter == m_mapRoom.end())
	{
		// 해당 룸이 없음
		cout << "RoomMgr RemoveClient Func Error \n";
		return FALSE;
	}
	return iter->second->RemoveClient(id);

	//auto p = find_if(m_mapClient.find(roomNumber)->second.begin(), m_mapClient.find(roomNumber)->second.end(), [&](const CClient* cl) {
	//	if (cl->GetID() == id)
	//		return true;
	//	return false;
	//});
	//if (p != m_mapClient.find(roomNumber)->second.end()) {
	//	m_mapClient.find(roomNumber)->second.erase(p);
	//	return TRUE;
	//}
}

int CRoomMgr::GetRoomCount() const
{
	return m_nRoomCount;
}
