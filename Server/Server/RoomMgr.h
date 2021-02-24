#pragma once

class CRoom;
class CClient;

class CRoomMgr
{
	// �� ��ȣ�� Key�� �����Ͽ� Hash�� ������
	unordered_map<int, CRoom*>		m_mapRoom;

	stack<int>						m_stackNumberPool; // �� ��ȣ�� ������ ���� �� �ִ� Pool
	int								m_nMaxRoomNumber; // Pool�� ���� ��� �ش� ������ �̿��Ͽ� ��ȣ �ο�

	SINGLE(CRoomMgr);

public:
	void Init();

	// ��ȭ�� ����
	bool CreateRoom(const char* strRoomName, const int& maxUser);
	// ��ȭ�� ����
	bool JoinRoom(const int& id, const int& roomNumber, const int& newRoomNumber);
	// ��ȭ�� ����
	bool DestroyRoom(const int& number);

	// �ش� ���ȣ Ŭ���̾�Ʈ ��� ��ȯ
	unordered_map<int, CClient*> GetClients(const int& roomNumber);

	// �� ������ �������� Ŭ���̾�Ʈ �˻� �� ��ȯ
	CClient* GetClient(const int& id, const int& roomNumber);
	CClient* GetClientByID(const int& id);
	CClient* GetClientByName(const char * name);
	const char* GetClientName(const int& id, const int& roomNumber);
	
	// ��ȭ�� ��ȯ
	CRoom* GetRoom(const int& roomNumber);
	bool FindRoom(const int& roomNumber);

	// �� ����� �� ��ȣ�� vector�� ���� ��ȯ
	vector<int> GetRoomNumberArray() const;

	// �ش� ��ȭ�濡 Ŭ���̾�Ʈ �߰�
	bool AddClient(const int& id, const int& roomNumber);
	// Ŭ���̾�Ʈ ��ȭ�� �̵�
	// bool MoveClient(const CClient* client, const int& currentRoomNumber, const int& destRoomNumber);
	// Ŭ���̾�Ʈ ����
	bool RemoveClient(const int& id);
	bool RemoveClient(const int& id, const int& roomNumber);

	// ��ȭ�� ���� ��ȯ
	int GetRoomCount() const;
	// Ŭ���̾�Ʈ ���̵� �������� ��ȭ�� ��ȣ ��ȯ
	int GetRoomNumber(const int& id);
};

