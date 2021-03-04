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

	// 한줄의 채팅 라벨에 정보 갱신
	void SetChatMessage(const FString& chatMessage);
};
