#pragma once

class CClient;

class CRoom
{
	// ��ȭ�� �̸�
	string m_strName;

	// ��ȭ�� ��ȣ
	uint m_nNumber;

	// ��ȭ�� �ִ� ���� �ο�
	uint m_nMaxUser;

	// ��ȭ�� ���� ���� �ο�
	uint m_nCurrentUser;

	// ��ȭ�� ���� Ŭ���̾�Ʈ
	unordered_map<uint, CClient*> m_mapClient;

public:
	CRoom(const char* strName, const uint& roomNumber, const uint& maxUser);
	~CRoom();

	uint GetNumber() const; // �� ��ȣ
	uint GetMaxUser() const; // �ִ� �ο�
	uint GetCurrentUser() const; // ���� �ο�
	bool GetState() const; // ���� ���� �ο��� ������ �ִ���

	const char* GetRoomName() const;

	// ���� �������� Ŭ���̾�Ʈ�� ��ȯ
	unordered_map<uint, CClient*> GetClients();

	// Ŭ���̾�Ʈ ID (���Ϲ�ȣ)�� �������� �˻�
	CClient* GetClient(const uint& id);
	bool FindClient(const uint& id);

	// Ŭ���̾�Ʈ �̸��� �������� �˻�
	CClient* GetClientByName(const char * name);

	// Ŭ���̾�Ʈ ID (���Ϲ�ȣ)�� �������� �˻�, �̸��� ��ȯ
	const char* GetClientName(const uint& id);

	// ��ȭ�濡 Ŭ���̾�Ʈ ���
	void AddClient(const uint& id, CClient* client);
	// �ش� Ŭ���̾�Ʈ ����
	bool RemoveClient(const uint& id);

	bool ChangeCurrentUserCount(const int& count);
};

