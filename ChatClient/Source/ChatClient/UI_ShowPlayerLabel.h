// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/UMG/Public/UMG.h"

#include "UI_ShowPlayerLabel.generated.h"

/**
 * 
 */

DECLARE_DELEGATE_OneParam(FDele_Single_OneParam, FString);

UCLASS()
class CHATCLIENT_API UUI_ShowPlayerLabel : public UUserWidget
{
	GENERATED_BODY()

private:
	class UTextBlock* playerNameTextBlock;
	class UButton* sendMessageButton;

	FString _playerName;
public:
	FDele_Single_OneParam Fuc_DeleSingle_OneParam;

public:
	UUI_ShowPlayerLabel(const FObjectInitializer & ObjectInitializer);

	virtual void NativeConstruct() override;
	virtual void BeginDestroy() override;

	void Init();

	void SetPlayerName(const FString & playerName);

	UFUNCTION()
	void SendMessageButton();
};
