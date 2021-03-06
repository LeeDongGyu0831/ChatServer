// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_ShowRoomLabel.h"


UUI_ShowRoomLabel::UUI_ShowRoomLabel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UUI_ShowRoomLabel::NativeConstruct()
{
	Super::NativeConstruct();
}

void UUI_ShowRoomLabel::BeginDestroy()
{
	Fuc_DeleSingle_OneParam_JoinRoom.Unbind();
	Fuc_DeleSingle_OneParam_DestroyRoom.Unbind();

	//destroyButton->OnClicked.RemoveDynamic(this, &UUI_ShowRoomLabel::DestroyButtonClickEvent);
	//joinButton->OnClicked.RemoveDynamic(this, &UUI_ShowRoomLabel::JoinButtonClickEvent);

	Super::BeginDestroy();
}

void UUI_ShowRoomLabel::Init()
{
	roomNameTextBlock = Cast<UTextBlock>(WidgetTree->FindWidget("RoomName"));
	roomNumberTextBlock = Cast<UTextBlock>(WidgetTree->FindWidget("RoomNumber"));
	roomPlayerCountTextBlock = Cast<UTextBlock>(WidgetTree->FindWidget("RoomPlayerCount"));

	destroyButton = Cast<UButton>(WidgetTree->FindWidget("DestroyButton"));
	joinButton = Cast<UButton>(WidgetTree->FindWidget("ConnectButton"));
	if (nullptr == roomNameTextBlock ||
		nullptr == roomNumberTextBlock ||
		nullptr == roomPlayerCountTextBlock )
	{
		UE_LOG(LogTemp, Error, TEXT("Do Not Construct ShowPlayerLabel"));
	}

	destroyButton->OnClicked.AddDynamic(this, &UUI_ShowRoomLabel::DestroyButtonClickEvent);
	joinButton->OnClicked.AddDynamic(this, &UUI_ShowRoomLabel::JoinButtonClickEvent);
}

void UUI_ShowRoomLabel::SetRoomInfo(const FString& roomNumber, const FString& roomName, const FString& roomPlayerCount, const FString& roomCurrentPlayerCount)
{
	if (roomNameTextBlock)
		roomNameTextBlock->SetText(FText::FromString(roomName));

	FString roomInfo = "[";
	roomInfo += roomNumber;
	roomInfo += "]";

	if (roomNumberTextBlock)
		roomNumberTextBlock->SetText(FText::FromString(roomInfo));

	roomInfo = "[";
	roomInfo += roomCurrentPlayerCount;
	roomInfo += "/";
	roomInfo += roomPlayerCount;
	roomInfo += "]";

	if (roomPlayerCountTextBlock)
		roomPlayerCountTextBlock->SetText(FText::FromString(roomInfo));


	_roomNumber = FCString::Atoi(*roomNumber);
	_roomName = roomName;
	_roomPlayerCount = FCString::Atoi(*roomPlayerCount);
	_roomCurrentPlayerCount = FCString::Atoi(*roomCurrentPlayerCount);
}

void UUI_ShowRoomLabel::DestroyButtonClickEvent()
{
	if (Fuc_DeleSingle_OneParam_DestroyRoom.IsBound() == true)
		Fuc_DeleSingle_OneParam_DestroyRoom.Execute(_roomNumber);
}

void UUI_ShowRoomLabel::JoinButtonClickEvent()
{
	if (Fuc_DeleSingle_OneParam_JoinRoom.IsBound() == true)
		Fuc_DeleSingle_OneParam_JoinRoom.Execute(_roomNumber);
}