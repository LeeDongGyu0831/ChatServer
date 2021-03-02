#include "stdafx.h"
#include "RoomMgr.h"
#include "Room.h"
#include "Client.h"
#include "Network.h"

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

	cout << "\tRoomManager Init" << endl;

	CreateRoom("Login Room", MAXUSER);
	CreateRoom("Main Room", MAXUSER);
}

bool CRoomMgr::CreateRoom(const char* strRoomName, const uint& maxUser)
{
	uint nRoomCount;
	// Pool이 비어있을 경우 맨 뒤에서 이어붙이면서 시작
	if (m_stackNumberPool.empty())
	{
		m_nMaxRoomNumber = m_mapRoom.size();
		nRoomCount = m_nMaxRoomNumber;
	}
	else
	{
		nRoomCount = m_stackNumberPool.top();
		if (nRoomCount > m_nMaxRoomNumber)
		{
			cout << "StackPoolNumber bigger than MaxRoomNumber\n";
			return FALSE;
			//exit(1);
		}
		m_stackNumberPool.pop();
	}

	CRoom* room = new CRoom(strRoomName, nRoomCount, maxUser);
	if (NULL == room)
	{
		cout << "[오류] 메모리가 부족합니다! \n";
		exit(1);
	}

	m_mapRoom[nRoomCount] = room;
	cout << "(" << nRoomCount <<") " << strRoomName << " (" << maxUser << ") Create" << endl;

	return TRUE;
}

bool CRoomMgr::JoinRoom(const uint& id, const uint& roomNumber, const uint& newRoomNumber)
{
	// 해당 대화방 존재X
	if (FALSE == FindRoom(newRoomNumber))
		return FALSE;

	// 참가하려는 대화방
	CRoom* pDestRoom = m_mapRoom.find(newRoomNumber)->second;
	uint currentUser = pDestRoom->GetCurrentUser();
	uint maxUser = pDestRoom->GetMaxUser();

	// 정원 초과
	if (currentUser >= maxUser)
		return FALSE;


	CClient* client = GetClient(id, roomNumber);
	if (NULL == client)
	{
		// 해당 클라이언트가 없음
		cout << roomNumber << " Room has not " << id << "\n";
		return FALSE;
	}
	pDestRoom->AddClient(id, client);

	m_mapRoom.find(roomNumber)->second->RemoveClient(id);

	return TRUE;
}

bool CRoomMgr::DestroyRoom(const uint& number)
{
	// NORMAL_ROOM은 유저가 생성한 방
	// 그 이하는 기본적으로 서버에서 필수로 들고있어야 하는 방
	if (number < uint(ROOM_TYPE::NORMAL_ROOM))
		return FALSE;
	// 없는 방인가?
	if (FALSE == FindRoom(number))
		return FALSE;

	//uint currentUser = m_mapRoom.find(number)->second->GetCurrentUser();

	// 메인 대화방으로 이동
	CRoom* pMainRoom = m_mapRoom.find(uint(ROOM_TYPE::MAIN_ROOM))->second;
	if (NULL == pMainRoom)
	{
		cout << "MainRoom is not exist! can't DestroyRoom\n";
		return FALSE;
		//exit(1);
	}

	CRoom* pRoom = GetRoom(number);
	{
		string msg;
		msg += "\r/      [";
		msg += pRoom->GetRoomName();
		msg += "] 대화방이 파괴되었습니다.\n\r";
		CNetwork::GetInst()->BroadCastMessage(NONE, msg.c_str(), msg.size(), number);
	}

	unordered_map<uint, CClient*> mapClient = pRoom->GetClients();
	for (auto& client : mapClient)
	{
		uint id = client.second->GetID();
		pMainRoom->AddClient(id, client.second);

		// 기존 대화방 클라이언트 모두 삭제
		m_mapRoom.find(number)->second->RemoveClient(id);
	}
	m_mapRoom.erase(number);
	m_stackNumberPool.push(number);
	return TRUE;
}

unordered_map<uint, CClient*> CRoomMgr::GetClients(const uint& roomNumber)
{
	unordered_map<uint, CRoom*>::iterator iter = m_mapRoom.find(roomNumber);
	if (iter == m_mapRoom.end())
	{
		// 해당 룸이 없음
		cout << "RoomMgr GetClients Func Error \n";
		return m_mapRoom.find(uint(ROOM_TYPE::MAIN_ROOM))->second->GetClients();
		//exit(1);
	}
	return iter->second->GetClients();
}

CClient * CRoomMgr::GetClient(const uint& id, const uint& roomNumber)
{
	unordered_map<uint, CRoom*>::iterator iter = m_mapRoom.find(roomNumber);
	if (iter == m_mapRoom.end())
	{
		// 해당 룸이 없음
		cout << "RoomMgr GetClient Func Error \n";
		return NULL;
	}
	return iter->second->GetClient(id);
}

CClient * CRoomMgr::GetClientByID(const uint & id)
{
	for (auto& room : m_mapRoom)
	{
		CClient* client = room.second->GetClient(id);	
		if (NULL != client)
		{
			return client;
		}
	}
	return NULL;
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

const char * CRoomMgr::GetClientName(const uint& id, const uint& roomNumber)
{
	unordered_map<uint, CRoom*>::iterator iter = m_mapRoom.find(roomNumber);
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

CRoom * CRoomMgr::GetRoom(const uint& roomNumber)
{
	unordered_map<uint, CRoom*>::iterator iter = m_mapRoom.find(roomNumber);
	if (iter == m_mapRoom.end())
	{
		// 해당 룸이 없음
		cout << "RoomMgr GetClientName Func Error \n";
		return NULL;
	}
	return iter->second;
}

bool CRoomMgr::FindRoom(const uint & roomNumber)
{
	unordered_map<uint, CRoom*>::iterator iter = m_mapRoom.find(roomNumber);
	if (iter == m_mapRoom.end())
	{
		return FALSE;
	}
	return TRUE;
}

vector<uint> CRoomMgr::GetRoomNumberArray() const
{
	vector<uint> vecNumber;
	vecNumber.reserve(m_mapRoom.size());
	for (auto& room : m_mapRoom)
	{
		vecNumber.emplace_back(room.second->GetNumber());
	}
	return vecNumber;
}

bool CRoomMgr::AddClient(const uint& id, const uint& roomNumber)
{
	CClient* client = new CClient(id, roomNumber);
	if (NULL == client)
	{
		cout << "[오류] 메모리가 부족합니다! \n";
		exit(1);
	}

	unordered_map<uint, CRoom*>::iterator roomIter = m_mapRoom.find(roomNumber);
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

//bool CRoomMgr::MoveClient(const CClient * client, const int& currentRoomNumber, const int& destRoomNumber)
//{
//	// 클라이언트 대화방 이동
//	return TRUE;
//}

bool CRoomMgr::RemoveClient(const uint& id)
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

bool CRoomMgr::RemoveClient(const uint& id, const uint& roomNumber)
{
	unordered_map<uint, CRoom*>::iterator iter = m_mapRoom.find(roomNumber);
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

uint CRoomMgr::GetRoomCount() const
{
	return m_mapRoom.size();
}

uint CRoomMgr::GetRoomNumber(const uint & id)
{
	return GetClientByID(id)->GetRoomNumber();
}
