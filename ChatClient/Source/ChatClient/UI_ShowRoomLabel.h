// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/UMG/Public/UMG.h"

#include "UI_ShowRoomLabel.generated.h"

/**
 * 
 */
UCLASS()
class CHATCLIENT_API UUI_ShowRoomLabel : public UUserWidget
{
	GENERATED_BODY()

private:
	class UTextBlock* RoomInfoTextBlock;
	class UButton* destroyButton;
	class UButton* joinButton;

public:
	UUI_ShowRoomLabel(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	void Init();

	void SetRoomInfo(const FString& roomName);

	UFUNCTION()
	void DestroyButtonClickEvent();
	UFUNCTION()
	void JoinButtonClickEvent();
};
