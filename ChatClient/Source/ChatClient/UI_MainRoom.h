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
	// ä���� �ִ� ����� ������ ���ΰ�
	// �÷��̾ ���� ���� ������ ���� �������� �ʾҽ��ϴ�.
	constexpr static uint32 MAX_SHOW_CHAT = 100;
	// �������� ���� ��Ŷ ���� ���ڿ��� �޴ٺ��� �÷��̾� ����Ʈ�� ��� �ε����� �������� �پ�Ѱ� Ž�� ����
	constexpr static uint32 FIND_PLAYERLIST_STARTINDEX = 25;
	// [��ȣ] �̸� �̱� ������ [ ] �� �����ϱ� ����
	constexpr static uint32 REMOVE_PLAYERNUM = 4;

	class UScrollBox* chatListScrollBox;
	class UScrollBox* playerListScrollBox;
	class UScrollBox* roomListScrollBox;
	class UEditableText* inputMessageText;
	class UButton* recvButton;
	class UButton* refreshPlayerButton;
	class UButton* refreshRoomButton;
	class UButton* createRoomButton;
	class UButton* closeButton;

	// ä��â ���� ���ٿ� ���� UI ���ø�
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> chatTextClass;

	// �÷��̾� ��ũ�ѹڽ��� ǥ�õ� ������ ���ø�
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> playerNameLabelClass;

	// �� ���� ��ũ�� �ڽ��� �߰��Ǵ� ������ ���ø�
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> roomNameLabelClass;

	// �� ���� ��ư Ŭ���� �˾���ų �� ���� UI ����
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> createRoomWidgetClass;

	// �̸��� Key, �ε����� UserWidget �ڽ� Ŭ����
	// ���� ����Ʈ ������ ���ŵ� �� ���� ���� ������ ����Ʈ�ڽ��� ����ִ��� �ƴ��� Ȯ���ϴ� �뵵
	TMap<FString, TWeakObjectPtr<UUI_ShowPlayerLabel>> playerNameToWidgetMap;
	TMap<FString, TWeakObjectPtr<UUI_ShowRoomLabel>> roomNameToWidgetMap;

public:
	UUI_MainRoom(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	virtual void BeginDestroy() override;

	UFUNCTION()
	void RecvButtonClickEvent();
	UFUNCTION()
	void RefreshPlayerButtonClickEvent();
	UFUNCTION()
	void RefreshRoomButtonClickEvent();
	UFUNCTION()
	void CloseButtonClickEvent();
	UFUNCTION()
	void CreateRoomButtonClickEvent();

	void AddChatting(const FString& chatMessage);
	void AddPlayer(const FString& playerName);
	void ExitPlayer(const FString& playerName);

	void AddRoom(const FString& roomNunmber, const FString& roomName, const FString& roomPlayerCount);
	void DestroyRoom(const FString& recvString);
	//void CheckCreateRoom(const FString& recvString);

	// �÷��̾� ��� ���ڿ����� ���پ� ����
	void FindPlayerListFromMessage(const FString& recvString);
	// �� ��Ͽ��� ���پ� ���ڿ��� �����ϴ� �Լ�
	void FindRoomListFromMessage(const FString& recvString);
	// ����, �ı� ������ �޾����� ������ ���ڿ����� �� �̸��� �����ϴ� �Լ�
	FString GetRoomNameFromRecvString(const FString& recvString);

	// �� ����Ʈ�� �޾����� ������ ���ڿ����� ���� �������� �����ϴ� �Լ�
	FString GetRoomNameFromString(const FString& recvString);
	FString GetRoomNumberFromString(const FString& recvString);
	FString GetRoomPlayerCountFromString(const FString& recvString);

	// Delegate
	// ��Ʈ��ũ���� �޽��� ���� ��û
	UFUNCTION()
	void ReadySendMessage(const FString& playerName);
	UFUNCTION()
	void RequestJoinRoom(const int32& roomNumber);
	UFUNCTION()
	void RequestDestroyRoom(const int32& roomNumber);
};
