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

void UGI_Network::SetID(FString id)
{
	strID = id;
}

void UGI_Network::SetIP(FString ip)
{
	strIP = ip;
}
void UGI_Network::SetPort(FString port)
{
	strPort = port;
}

FString UGI_Network::GetID()
{
	return strID;
}

bool UGI_Network::ConnectToServer()
{
	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);
	if (nullptr == Socket)
	{
		UE_LOG(LogTemp, Error, TEXT("Not Create Socket"));
		return false;
	}

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
	
	//UE_LOG(LogTemp, Warning, TEXT("Recv : %s"), finalMessage);

	FString result = finalMessage;
	//if (false == recvSuccess)
	//	return FString("");
	return result;
}

bool UGI_Network::Send(const FString& data)
{
	FString sendData = data;
	sendData += "\r\n";

	char message[BUF_SIZE];
	wchar_t finalMessage[BUF_SIZE];
	size_t convertedNum = 0;

	wcstombs_s<BUF_SIZE>(&convertedNum, message, *sendData, BUF_SIZE);

	mbstowcs(finalMessage, message, convertedNum + 1);

	int32 sent = 0;
	bool result = Socket->Send(reinterpret_cast<const uint8*>(message), strlen(message), (int32&)sent);
	UE_LOG(LogTemp, Warning, TEXT("Send : %s"), finalMessage);
	return result;
}

void UGI_Network::RequestPlayerList(const int32& roomNumber)
{
	FString requestString = "/s ";
	requestString += FString::FromInt(roomNumber);
	Send(requestString);

}

void UGI_Network::RequestRoomList()
{
	FString requestString = "/o ";
	Send(requestString);
}

FString UGI_Network::TrimMessage(const FString& originString, const FString& subString)
{
	FString data, leftString, rightString;
	data = originString.TrimStart();

	bool result = data.Split(subString, &leftString, &rightString);
	if (true == result)
	{
		data = leftString.TrimEnd();
	}
	else
	{
		data = data.TrimEnd();
	}
	data.TrimQuotesInline();
	return data;
}

MSG_TYPE UGI_Network::CheckMessage(FString originString)
{
	FString FuncName = "CheckMessage";

	if (originString[0] != L'/')
		return MSG_TYPE::CHAT;

	if (originString.Contains(L"님이 참가"))
	{
		return MSG_TYPE::JOIN;
	}

	if (originString.Contains(L"님이 퇴장"))
	{
		return MSG_TYPE::EXIT;
	}

	if (originString.Contains(L"대화방 이용자"))
	{
		return MSG_TYPE::PLAYERLIST;
	}

	if (originString.Contains(L"[0] Login Room"))
	{
		return MSG_TYPE::ROOMLIST;
	}

	PrintLog(FuncName, originString);

	return MSG_TYPE::CHAT;
}

FString UGI_Network::GetKeyworkByChar(FString originString, TCHAR startChar, TCHAR endChar)
{
	FString FuncName = "GetKeyworkByChar";
	FString data = originString;
	int startIndex = 0;
	int endIndex = 0;
	if (false == data.FindLastChar(startChar, startIndex))
		return "";
	if (false == data.FindLastChar(endChar, endIndex))
		return "";

	FString subString = "";
	for (int i = startIndex; i < endIndex; ++i)
	{
		subString.AppendChar(data[i]);
	}

	PrintLog(FuncName, subString);

	return subString;
}

void UGI_Network::PrintLog(const FString& message1, const FString& message2)
{
	char logMsg1[BUF_SIZE];
	char logMsg2[BUF_SIZE];
	wchar_t finallogMsg1[BUF_SIZE];
	wchar_t finallogMsg2[BUF_SIZE];
	size_t convertedNum = 0;

	wcstombs_s<BUF_SIZE>(&convertedNum, logMsg1, *message1, BUF_SIZE);
	wcstombs_s<BUF_SIZE>(&convertedNum, logMsg2, *message2, BUF_SIZE);

	mbstowcs(finallogMsg1, logMsg1, message1.Len());
	mbstowcs(finallogMsg2, logMsg2, message2.Len());

	UE_LOG(LogTemp, Warning, TEXT("%s, : %s"), finallogMsg1, finallogMsg2);
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