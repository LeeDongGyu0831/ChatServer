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
	RoomInfoTextBlock = Cast<UTextBlock>(WidgetTree->FindWidget("RoomName"));
	destroyButton = Cast<UButton>(WidgetTree->FindWidget("DestroyButton"));
	joinButton = Cast<UButton>(WidgetTree->FindWidget("ConnectButton"));
	if (NULL == RoomInfoTextBlock)
	{
		UE_LOG(LogTemp, Error, TEXT("Do Not Construct ShowPlayerLabel"));
	}

	destroyButton->OnClicked.AddDynamic(this, &UUI_ShowRoomLabel::DestroyButtonClickEvent);
	joinButton->OnClicked.AddDynamic(this, &UUI_ShowRoomLabel::JoinButtonClickEvent);
}

void UUI_ShowRoomLabel::SetRoomInfo(const FString& roomName)
{

	if (RoomInfoTextBlock)
		RoomInfoTextBlock->SetText(FText::FromString(roomName));
}

void UUI_ShowRoomLabel::DestroyButtonClickEvent()
{
	UE_LOG(LogTemp, Error, TEXT("DestroyButtonClickEvent"));

}

void UUI_ShowRoomLabel::JoinButtonClickEvent()
{
	UE_LOG(LogTemp, Error, TEXT("JoinButtonClickEvent"));
}