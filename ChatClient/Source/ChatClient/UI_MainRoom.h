// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/UMG/Public/UMG.h"
#include "UI_ChatText.h"

#include "UI_MainRoom.generated.h"

/**
 * 
 */

UCLASS()
class CHATCLIENT_API UUI_MainRoom : public UUserWidget
{
	GENERATED_BODY()

private:
	constexpr static uint32 MAX_SHOW_CHAT = 100;
	constexpr static uint32 FIND_PLAYERLIST_STARTINDEX = 25;
	constexpr static uint32 REMOVE_PLAYERNUM = 4;

	class UScrollBox* chatListScrollBox;
	class UScrollBox* playerListScrollBox;
	class UEditableText* inputMessageText;
	class UButton* recvButton;
	class UButton* refreshButton;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> chatTextClass;

	// 이름이 Key, 인덱스가 UserWidget 자식 클래스
	//std::unordered_map<FString, UUI_ChatText*> playerNameToWidgetMap;
	TMap<FString, TWeakObjectPtr<UUI_ChatText>> TestWidgetMap;

public:
	UUI_MainRoom(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UFUNCTION()
	void RecvButtonClickEvent();
	UFUNCTION()
	void RefreshButtonClickEvent();

	void AddChatting(const FString& chatMessage);
	void AddPlayer(const FString& playerName);
	void ExitPlayer(const FString& playerName);

	void FindPlayerListFromMessage(const FString& recvString);
};
