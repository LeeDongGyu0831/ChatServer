// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/UMG/Public/UMG.h"

#include "UI_ChatText.generated.h"

/**
 * 
 */
UCLASS()
class CHATCLIENT_API UUI_ChatText : public UUserWidget
{
	GENERATED_BODY()

private:
	class UTextBlock* chatText;

public:
	UUI_ChatText(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	void Init();

	void SetChatMessage(const FString& chatMessage);
};
