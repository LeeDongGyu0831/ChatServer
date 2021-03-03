// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_ShowRoomLabel.h"


UUI_ShowRoomLabel::UUI_ShowRoomLabel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UUI_ShowRoomLabel::NativeConstruct()
{
	Super::NativeConstruct();
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

void UUI_ShowRoomLabel::SetRoomInfo(const FString& roomNunmber, const FString& roomName, const FString& roomPlayerCount)
{
	if (roomNameTextBlock)
		roomNameTextBlock->SetText(FText::FromString(roomName));
	if (roomNumberTextBlock)
		roomNumberTextBlock->SetText(FText::FromString(roomNunmber));
	if (roomPlayerCountTextBlock)
		roomPlayerCountTextBlock->SetText(FText::FromString(roomPlayerCount));
}

void UUI_ShowRoomLabel::DestroyButtonClickEvent()
{
	UE_LOG(LogTemp, Error, TEXT("DestroyButtonClickEvent"));

}

void UUI_ShowRoomLabel::JoinButtonClickEvent()
{
	UE_LOG(LogTemp, Error, TEXT("JoinButtonClickEvent"));
}