#pragma once

class CClient
{
	int m_nID;
	string m_strName;
	int m_nNameSize;

	int m_nRoomNumber;

public:
	CClient(int id, int roomNumber);
	~CClient();

	int GetRoomNumber() const;
	const char* GetName() const;
	int GetNameSize() const;
	int GetID() const;

	void SetName(const char* name);
	void SetRoomNumber(int roomNumber);
};

