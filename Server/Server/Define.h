#pragma once
#define SERVERPORT 9000
#define BUFSIZE 512

// Singleton 매크로 함수
#define SINGLE(type) private: type(); ~type();\
public:\
static type* GetInst()\
{\
	static type mgr;\
	return &mgr;\
}

//#define SAFE_RELEASE(p) if(nullptr != p) p->Release()
#define SAFE_DELETE(p) if(nullptr != p) delete p; p = nullptr;