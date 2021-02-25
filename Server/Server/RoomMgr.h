#pragma once

class CRoom;
class CClient;

class CRoomMgr
{
	// �� ��ȣ�� Key�� �����Ͽ� Hash�� ������
	unordered_map<uint, CRoom*>			m_mapRoom;

	stack<uint>							m_stackNumberPool; // �� ��ȣ�� ������ ���� �� �ִ� Pool
	uint								m_nMaxRoomNumber; // Pool�� ���� ��� �ش� ������ �̿��Ͽ� ��ȣ �ο�

	SINGLE(CRoomMgr);

public:
	void Init();

	// ��ȭ�� ����
	bool CreateRoom(const char* strRoomName, const uint& maxUser);
	// ��ȭ�� ����
	bool JoinRoom(const uint& id, const uint& roomNumber, const uint& newRoomNumber);
	// ��ȭ�� ����
	bool DestroyRoom(const uint& number);

	// �ش� ���ȣ Ŭ���̾�Ʈ ��� ��ȯ
	unordered_map<uint, CClient*> GetClients(const uint& roomNumber);

	// �� ������ �������� Ŭ���̾�Ʈ �˻� �� ��ȯ
	CClient* GetClient(const uint& id, const uint& roomNumber);
	CClient* GetClientByID(const uint& id);
	CClient* GetClientByName(const char * name);
	const char* GetClientName(const uint& id, const uint& roomNumber);
	
	// ��ȭ�� ��ȯ
	CRoom* GetRoom(const uint& roomNumber);
	bool FindRoom(const uint& roomNumber);

	// �� ����� �� ��ȣ�� vector�� ���� ��ȯ
	vector<uint> GetRoomNumberArray() const;

	// �ش� ��ȭ�濡 Ŭ���̾�Ʈ �߰�
	bool AddClient(const uint& id, const uint& roomNumber);
	// Ŭ���̾�Ʈ ��ȭ�� �̵�
	// bool MoveClient(const CClient* client, const int& currentRoomNumber, const int& destRoomNumber);
	// Ŭ���̾�Ʈ ����
	bool RemoveClient(const uint& id);
	bool RemoveClient(const uint& id, const uint& roomNumber);

	// ��ȭ�� ���� ��ȯ
	uint GetRoomCount() const;
	// Ŭ���̾�Ʈ ���̵� �������� ��ȭ�� ��ȣ ��ȯ
	uint GetRoomNumber(const uint& id);
};

