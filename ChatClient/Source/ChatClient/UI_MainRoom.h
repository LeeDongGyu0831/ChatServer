// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/UMG/Public/UMG.h"

#include "UI_MainRoom.generated.h"

/**
 * 
 */

class UUI_ShowPlayerLabel;
class UUI_ShowRoomLabel;

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
	class UScrollBox* roomListScrollBox;
	class UEditableText* inputMessageText;
	class UButton* recvButton;
	class UButton* refreshButton;
	class UButton* createRoomButton;
	class UButton* closeButton;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> chatTextClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> playerNameLabelClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> roomNameLabelClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> createRoomWidgetClass;

	// 이름이 Key, 인덱스가 UserWidget 자식 클래스
	TMap<FString, TWeakObjectPtr<UUI_ShowPlayerLabel>> playerNameToWidgetMap;
	TMap<FString, TWeakObjectPtr<UUI_ShowRoomLabel>> roomNameToWidgetMap;

public:
	UUI_MainRoom(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	virtual void BeginDestroy() override;

	UFUNCTION()
	void RecvButtonClickEvent();
	UFUNCTION()
	void RefreshButtonClickEvent();
	UFUNCTION()
	void CloseButtonClickEvent();
	UFUNCTION()
	void CreateRoomButtonClickEvent();

	void AddChatting(const FString& chatMessage);
	void AddPlayer(const FString& playerName);
	void ExitPlayer(const FString& playerName);

	void AddRoom(const FString& roomName);
	void ExitRoom(const FString& roomName);

	void FindPlayerListFromMessage(const FString& recvString);
	void FindRoomListFromMessage(const FString& recvString);

	// Delegate
	UFUNCTION()
	void ReadySendMessage(const FString& playerName);
};
