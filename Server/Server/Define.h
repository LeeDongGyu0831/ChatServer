#pragma once
#define SERVERPORT		9000
#define MAXUSER			1000

#define BUFSIZE			512
#define COMMAND			1
#define IP_ADDR_LEN		16
#define MINIMUM_LEN		3

#define NONE			0
#define KEYWORD			1

#define BACKSPACE		8

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