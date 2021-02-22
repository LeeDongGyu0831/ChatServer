#pragma once

struct tEvent
{
	EVENT_TYPE eType;
	DWORD_PTR  wParam;
	DWORD_PTR  lParam;
};

class CEventMgr
{
	SINGLE(CEventMgr);
private:
	vector<tEvent>			m_vecEvent;
	vector<tEvent>			m_vecDeadEvent;
	//vector<CGameObject*>	m_vecDead; // ���� ���� ������Ʈ

public:
	void Update();
	void clear() { m_vecEvent.clear(); }
	void AddEvent(tEvent& _event) { m_vecEvent.push_back(_event); }

	const vector<tEvent>& GetEventList() { return m_vecEvent; }

private:
	void Execute(tEvent& _event);
};
