// Fill out your copyright notice in the Description page of Project Settings.


#include "GI_Network.h"

#include <locale.h>
#include <stdlib.h>
#define BUF_SIZE 1024

UGI_Network::UGI_Network()
{

}

void UGI_Network::Init()
{
	Super::Init();
	setlocale(LC_ALL, "Korean");

	UE_LOG(LogTemp, Warning, TEXT("Network GameInstance Init"));

	bLogin = false;
	bConnect = false;
}

void UGI_Network::Shutdown()
{
	Super::Shutdown();
	UE_LOG(LogTemp, Warning, TEXT("Network GameInstance Shutdown"));
	if(true == bConnect)
		Socket->Close();
}
bool UGI_Network::ConnectToServer()
{
	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);

	FString address = strIP;
	int32 port = FCString::Atoi(*strPort);
	FIPv4Address ip;
	FIPv4Address::Parse(address, ip);

	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(port);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Trying to connect.")));

	bConnect = Socket->Connect(*addr);
	if (false == bConnect)
	{
		return false;
	}

	FString result = Recv();
	result = Recv();

	Socket->SetNonBlocking(true);

	return true;
}

void UGI_Network::RecvData()
{
	if (false == bLogin)
		return;

	int32 recvBytes = 0;
	char message[BUF_SIZE];
	Socket->Recv(reinterpret_cast<uint8*>(message), BUF_SIZE, recvBytes, ESocketReceiveFlags::None);

	UE_LOG(LogTemp, Warning, TEXT("%s"), message);
}
 
bool UGI_Network::LoginToServer()
{
	FString data = L"/l ";
	data += strID;
	data.AppendChar('\r');
	data.AppendChar('\n');

	// 로그인 명령어 전송
	Send(data);

	//FString recvMessage = Recv();
	//recvMessage = Recv();

	//if(recvMessage ==  L"      사용중인 아이디입니다. 다시 확인해주세요.\n\r")
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("중복된 아이디"));
	//	return false;
	//}

	//bLogin = true;
	//Socket->SetNonBlocking(true);
	return true;
}

FString UGI_Network::Recv()
{
	int32 recvBytes = 0;
	char recvMessage[BUF_SIZE] { '\0' };
	wchar_t finalMessage[BUF_SIZE] { '\0' };
	bool recvSuccess = Socket->Recv(reinterpret_cast<uint8*>(recvMessage), BUF_SIZE, recvBytes, ESocketReceiveFlags::None);

	mbstowcs(finalMessage, recvMessage, recvBytes + 1);
	
	UE_LOG(LogTemp, Warning, TEXT("Recv : %s"), finalMessage);

	FString result = finalMessage;
	//if (false == recvSuccess)
	//	return FString("");
	return result;
}

bool UGI_Network::Send(const FString& data)
{
	char message[BUF_SIZE];
	wchar_t finalMessage[BUF_SIZE];
	size_t convertedNum = 0;

	wcstombs_s<BUF_SIZE>(&convertedNum, message, *data, BUF_SIZE);

	mbstowcs(finalMessage, message, convertedNum + 1);

	int32 sent = 0;
	bool result = Socket->Send(reinterpret_cast<const uint8*>(message), strlen(message), (int32&)sent);
	UE_LOG(LogTemp, Warning, TEXT("Send : %s"), finalMessage);
	return result;
}

FString UGI_Network::BytesToStringFixed(const uint8* In, int32 Count)
{
	FString Broken = BytesToString(In, Count);
	FString Fixed;

	for (int i = 0; i < Broken.Len(); i++)
	{
		const TCHAR c = Broken[i] - 1;
		Fixed.AppendChar(c);
	}

	return Fixed;
}