#pragma once

class CClient;

class CRoom
{
	// ��ȭ�� �̸�
	string m_strName;

	// ��ȭ�� ��ȣ
	int m_nNumber;

	// ��ȭ�� �ִ� ���� �ο�
	int m_nMaxUser;

	// ��ȭ�� ���� ���� �ο�
	int m_nCurrentUser;

	// ��ȭ�� ���� Ŭ���̾�Ʈ
	unordered_map<int, CClient*> m_mapClient;

public:
	CRoom(const char* strName, int roomNumber, int maxUser);
	~CRoom();

	int GetNumber() const; // �� ��ȣ
	int GetMaxUser() const; // �ִ� �ο�
	int GetCurrentUser() const; // ���� �ο�
	bool GetState() const; // ���� ���� �ο��� ������ �ִ���

	const char* GetRoomName() const;

	// ���� �������� Ŭ���̾�Ʈ�� ��ȯ
	unordered_map<int, CClient*> GetClients();

	// Ŭ���̾�Ʈ ID (���Ϲ�ȣ)�� �������� �˻�
	CClient* GetClient(const int& id);
	bool FindClient(const int& id);

	// Ŭ���̾�Ʈ �̸��� �������� �˻�
	CClient* GetClientByName(const char * name);

	// Ŭ���̾�Ʈ ID (���Ϲ�ȣ)�� �������� �˻�, �̸��� ��ȯ
	const char* GetClientName(const int& id);

	// ��ȭ�濡 Ŭ���̾�Ʈ ���
	void AddClient(const int& id, CClient* client);
	// �ش� Ŭ���̾�Ʈ ����
	bool RemoveClient(const int& id);

	bool ChangeCurrentUserCount(int count);
};

