// Fill out your copyright notice in the Description page of Project Settings.


#include "ChatRoomLevel.h"

#include "GI_Network.h"
#include "UI_ChatRoom.h"

void AChatRoomLevel::BeginPlay()
{
	Super::BeginPlay();

	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}

	if (chatRoomClass)
	{
		chatRoomWidget = CreateWidget<UUI_ChatRoom>(GetWorld(), chatRoomClass);
		if (chatRoomWidget)
		{
			chatRoomWidget->AddToViewport();

			roomName = GINetwork->GetCurrentRoomName();
			roomNumber = GINetwork->GetCurrentRoomNumber();
			chatRoomWidget->SetInfo(roomName, roomNumber);
		}
	}

	int32 index =GetWorld()->GetActiveLevelCollectionIndex();
	for (int i = 0; i < index; ++i)
	{
		GetWorld()->GetLevel(i)->GetLevelScriptActor()->SetActorTickEnabled(false);
	}
	SetActorTickEnabled(true);
}

void AChatRoomLevel::Tick(float DeltaTime)
{
	UE_LOG(LogTemp, Error, TEXT("CHATROOM TICK"));
	Super::Tick(DeltaTime);

	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
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
		if (playerName.Len() > 0)
			chatRoomWidget->AddPlayer(playerName);
	}
	break;
	case MSG_TYPE::EXIT:
	{
		FString playerName = FindPlayerName(recvString);
		if (playerName.Len() > 0)
			chatRoomWidget->ExitPlayer(playerName);
	}
	break;
	case MSG_TYPE::CHAT:
	{
		chatRoomWidget->AddChatting(recvString);
	}
	break;
	case MSG_TYPE::PLAYERLIST:
	{
		chatRoomWidget->FindPlayerListFromMessage(recvString);
	}
	break;
	case MSG_TYPE::ROOMLIST:
	{
		//chatRoomWidget->FindRoomListFromMessage(recvString);
	}
	break;
	case MSG_TYPE::DESTROYROOM:
	{
		//chatRoomWidget->DestroyRoom(recvString);
	}
	break;
	case MSG_TYPE::CREATEROOM:
	{
		//mainRoomWidget->CheckCreateRoom(recvString);
	}
	break;
	case MSG_TYPE::JOINROOM:
	{
		if (GINetwork->GetCurrentRoomNumber() == 1)
		{
			SetActorTickEnabled(false);
			UGameplayStatics::OpenLevel(this, "MainLevel");
		}
		else
		{ 
			//SetActorTickEnabled(false);
			UGameplayStatics::OpenLevel(this, "ChatRoomLevel");
		}
	}
	break;
	default:
		break;
	}
}

FString AChatRoomLevel::FindPlayerName(const FString& recvString)
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