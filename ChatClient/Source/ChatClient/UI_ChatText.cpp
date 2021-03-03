// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_ChatText.h"


UUI_ChatText::UUI_ChatText(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UUI_ChatText::NativeConstruct()
{
	Super::NativeConstruct();

	chatText = Cast<UTextBlock>(WidgetTree->FindWidget("Chat"));
	if (NULL == chatText)
	{
		UE_LOG(LogTemp, Error, TEXT("Do Not Construct ChatText"));
	}
}

void UUI_ChatText::SetChatMessage(const FString& chatMessage)
{
	if (!chatText)
	{
		chatText = Cast<UTextBlock>(WidgetTree->FindWidget("Chat"));
		if (NULL == chatText)
		{
			UE_LOG(LogTemp, Error, TEXT("Do Not Construct ChatText"));
		}
	}

	if(chatText)
		chatText->SetText(FText::FromString(chatMessage));
}