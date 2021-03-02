// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/UMG/Public/UMG.h"

#include "UI_Connect.generated.h"

/**
 * 
 */
UCLASS()
class CHATCLIENT_API UUI_Connect : public UUserWidget
{
	GENERATED_BODY()
private:
	class UEditableText* inputIP;
	class UEditableText* inputPort;
	class UButton* connectButton;

protected:
	virtual void OnCreate();

public:
	UUI_Connect(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	void TestFunc();

	// Do it via a C++ delegate
	UFUNCTION()
	void InputIPEvent(const FText& InText);

	UFUNCTION()
	void InputPortEvent(const FText& InText);

	UFUNCTION()
	void ButtonClick();

};
