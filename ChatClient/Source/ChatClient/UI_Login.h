// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/UMG/Public/UMG.h"

#include "UI_Login.generated.h"

/**
 * 
 */
UCLASS()
class CHATCLIENT_API UUI_Login : public UUserWidget
{
	GENERATED_BODY()

private:
	class UEditableText* inputID;
	class UButton* connectButton;
	FString strID;

public:
	UUI_Login(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UFUNCTION()
	void InputIDEvent(const FText& InText);

	UFUNCTION()
	void ConnectButtonClick();
};
