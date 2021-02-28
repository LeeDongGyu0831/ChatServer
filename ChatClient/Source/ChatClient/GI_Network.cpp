// Fill out your copyright notice in the Description page of Project Settings.


#include "GI_Network.h"

UGI_Network::UGI_Network()
{

}

void UGI_Network::Init()
{
	Super::Init();
	UE_LOG(LogTemp, Warning, TEXT("Network GameInstance Init"));
}


void UGI_Network::ConnectToServer(const FString& strIP, const int32& nPort)
{
	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);

	FString address = strIP;
	int32 port = nPort;
	FIPv4Address ip;
	FIPv4Address::Parse(address, ip);

	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(port);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Trying to connect.")));

	bool connected = Socket->Connect(*addr);
	if (true == connected)
	{
		UE_LOG(LogTemp, Warning, TEXT("Connect To Server"));
	}
}