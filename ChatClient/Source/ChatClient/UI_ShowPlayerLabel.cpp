// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_ShowPlayerLabel.h"

#include "UI_MainRoom.h"

UUI_ShowPlayerLabel::UUI_ShowPlayerLabel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UUI_ShowPlayerLabel::NativeConstruct()
{
	Super::NativeConstruct();
}

void UUI_ShowPlayerLabel::Init()
{
	playerNameTextBlock = Cast<UTextBlock>(WidgetTree->FindWidget("PlayerName"));
	sendMessageButton = Cast<UButton>(WidgetTree->FindWidget("SendMessage"));
	if (NULL == playerNameTextBlock)
	{
		UE_LOG(LogTemp, Error, TEXT("Do Not Construct ShowPlayerLabel"));
	}
	sendMessageButton->OnClicked.AddDynamic(this, &UUI_ShowPlayerLabel::SendMessageButton);
}

void UUI_ShowPlayerLabel::SetPlayerName(const FString& playerName)
{
	if (playerNameTextBlock) 
		playerNameTextBlock->SetText(FText::FromString(playerName));
	_playerName = playerName;
}

void UUI_ShowPlayerLabel::SendMessageButton()
{
	UE_LOG(LogTemp, Error, TEXT("SendMessageButton"));
}