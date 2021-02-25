#pragma once

class CClient
{
	int m_nID; // ���Ϲ�ȣ == ���̵�
	string m_strName; // �̸�

	// ���� �������ִ� ��ȭ�� ��ȣ
	uint m_nRoomNumber;

public:
	CClient(int id, int roomNumber);
	~CClient();

	int GetRoomNumber() const; // ���� Ŭ���̾�Ʈ�� �������� �� ��ȣ
	const char* GetName() const; // Ŭ���̾�Ʈ�� �̸�, �г���
	int GetNameSize() const; // ������
	int GetID() const; // ���̵�

	void SetName(const char* name);
	void SetRoomNumber(int roomNumber);
};

