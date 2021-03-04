// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/UMG/Public/UMG.h"

#include "UI_ChatRoom.generated.h"

/**
 * 
 */

class UUI_ShowPlayerLabel;
class UUI_ShowRoomLabel;
class UUI_CreateRoomWidget;

UCLASS()
class CHATCLIENT_API UUI_ChatRoom : public UUserWidget
{
	GENERATED_BODY()

private:
	// ä���� �ִ� ����� ������ ���ΰ�
	// �÷��̾ ���� ���� ������ ���� �������� �ʾҽ��ϴ�.
	constexpr static uint32 MAX_SHOW_CHAT = 100;
	// �������� ���� ��Ŷ ���� ���ڿ��� �޴ٺ��� �÷��̾� ����Ʈ�� ��� �ε����� �������� �پ�Ѱ� Ž�� ����
	constexpr static uint32 FIND_PLAYERLIST_STARTINDEX = 25;
	// [��ȣ] �̸� �̱� ������ [ ] �� �����ϱ� ����
	constexpr static uint32 REMOVE_PLAYERNUM = 4;

	FString _roomName;
	int32 _roomNumber;

	class UScrollBox* chatListScrollBox;
	class UScrollBox* playerListScrollBox;

	class UTextBlock* roomNameText;

	class UEditableText* inputMessageText;

	class UButton* recvButton;
	class UButton* refreshPlayerButton;
	class UButton* destroyRoomButton;
	class UButton* leaveRoomButton;
	class UButton* closeButton;

	// ä��â ���� ���ٿ� ���� UI ���ø�
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		TSubclassOf<UUserWidget> chatTextClass;

	// �÷��̾� ��ũ�ѹڽ��� ǥ�õ� ������ ���ø�
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		TSubclassOf<UUserWidget> playerNameLabelClass;

	// �̸��� Key, �ε����� UserWidget �ڽ� Ŭ����
	// ���� ����Ʈ ������ ���ŵ� �� ���� ���� ������ ����Ʈ�ڽ��� ����ִ��� �ƴ��� Ȯ���ϴ� �뵵
	TMap<FString, TWeakObjectPtr<UUI_ShowPlayerLabel>> playerNameToWidgetMap;

public:
	UUI_ChatRoom(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	virtual void BeginDestroy() override;

	void SetInfo(const FString& roomName, const int32& roomNumber);

	UFUNCTION()
		void RecvButtonClickEvent();
	UFUNCTION()
		void RefreshPlayerButtonClickEvent();
	UFUNCTION()
		void LeaveRoomButtonClickEvent();
	UFUNCTION()
		void CloseButtonClickEvent();
	UFUNCTION()
		void DestroyRoomButtonClickEvent();

	void AddChatting(const FString& chatMessage);
	void AddPlayer(const FString& playerName);
	void ExitPlayer(const FString& playerName);

	// �÷��̾� ��� ���ڿ����� ���پ� ����
	void FindPlayerListFromMessage(const FString& recvString);

	// Delegate
	// ��Ʈ��ũ���� �޽��� ���� ��û
	UFUNCTION()
		void ReadySendMessage(const FString& playerName);
	UFUNCTION()
		void RequestLeaveRoom(const int32& roomNumber);
	UFUNCTION()
		void RequestDestroyRoom(const int32& roomNumber);
};
