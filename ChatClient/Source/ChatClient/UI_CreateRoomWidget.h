// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/UMG/Public/UMG.h"

#include "UI_CreateRoomWidget.generated.h"

/**
 * 
 */
UCLASS()
class CHATCLIENT_API UUI_CreateRoomWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	class UEditableText* inputRoomName;
	class UEditableText* inputMaxCount;
	class UButton* createButton;
	class UButton* cancleButton;

public:
	UUI_CreateRoomWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;
	virtual void BeginDestroy() override;

	void Init();

	UFUNCTION()
	void CreateButtonClickEvent();

	UFUNCTION()
	void CancleButtonClickEvent();
};
