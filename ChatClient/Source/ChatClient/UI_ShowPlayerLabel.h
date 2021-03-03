// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/UMG/Public/UMG.h"

#include "UI_ShowPlayerLabel.generated.h"

/**
 * 
 */
UCLASS()
class CHATCLIENT_API UUI_ShowPlayerLabel : public UUserWidget
{
	GENERATED_BODY()

private:
	class UTextBlock* playerNameTextBlock;
	class UButton* sendMessageButton;

public:
	UUI_ShowPlayerLabel(const FObjectInitializer & ObjectInitializer);

	virtual void NativeConstruct() override;

	void Init();

	void SetPlayerName(const FString & playerName);

	UFUNCTION()
	void SendMessageButton();
};
