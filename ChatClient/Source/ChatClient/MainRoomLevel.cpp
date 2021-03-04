// Fill out your copyright notice in the Description page of Project Settings.


#include "MainRoomLevel.h"

#include "GI_Network.h"

void AMainRoomLevel::BeginPlay()
{
	Super::BeginPlay();

	if (mainRoomClass)
	{
		mainRoomWidget = CreateWidget<UUI_MainRoom>(GetWorld(), mainRoomClass);
		if (mainRoomWidget)
		{
			mainRoomWidget->AddToViewport();

		}
	}

	//auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	//if (NULL == GINetwork)
	//{
	//	UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
	//	return;
	//}

	refreshTime = REFRESH_TIME;
}

void AMainRoomLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	refreshTime -= DeltaTime;
	// 대화방 리스트 갱신
	if (refreshTime < 0.f)
	{
		refreshTime = REFRESH_TIME;
		GINetwork->RequestRoomList();
	}

	FString recvString = GINetwork->Recv();

	if (recvString.Len() < 3)
		return;

	recvString = GINetwork->TrimMessage(recvString, ">>");

	if (recvString.Len() < 3)
		return;

	MSG_TYPE msgType = GINetwork->CheckMessage(recvString);

	switch (msgType)
	{
	case MSG_TYPE::JOIN:
	{
		FString playerName = FindPlayerName(recvString);
		if(playerName.Len() > 0)
			mainRoomWidget->AddPlayer(playerName);
	}
		break;
	case MSG_TYPE::EXIT:
	{
		FString playerName = FindPlayerName(recvString);
		if (playerName.Len() > 0)
			mainRoomWidget->ExitPlayer(playerName);
	}
		break;
	case MSG_TYPE::CHAT:
	{
		mainRoomWidget->AddChatting(recvString);
	}
		break;
	case MSG_TYPE::PLAYERLIST:
	{
		mainRoomWidget->FindPlayerListFromMessage(recvString);
	}
		break;
	case MSG_TYPE::ROOMLIST:
	{
		mainRoomWidget->FindRoomListFromMessage(recvString);
	}
	break;
	case MSG_TYPE::DESTROYROOM:
	{
		mainRoomWidget->DestroyRoom(recvString);
	}
	break;
	case MSG_TYPE::CREATEROOM:
	{
		// mainRoomWidget->CheckCreateRoom(recvString);
	}
	break;
	default:
		break;
	}
}

FString AMainRoomLevel::FindPlayerName(const FString& recvString)
{
	FString playerName = "";

	int32 startIndex = 0;
	int32 endIndex = 0;
	bool result = recvString.FindLastChar('[', startIndex);
	if (false == result)
		return playerName;
	result = recvString.FindLastChar(']', endIndex);
	if (false == result)
		return playerName;

	for (int32 i = startIndex + 1; i < endIndex; ++i)
	{
		playerName.AppendChar(recvString[i]);
	}
	playerName.AppendChar('\0');

	return playerName;
}