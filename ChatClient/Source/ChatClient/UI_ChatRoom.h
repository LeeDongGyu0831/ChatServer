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
	// 채팅을 최대 몇개까지 보여줄 것인가
	// 플레이어나 방은 갯수 제한을 따로 설정하지 않았습니다.
	constexpr static uint32 MAX_SHOW_CHAT = 100;
	// 서버에서 따로 패킷 없이 문자열로 받다보니 플레이어 리스트의 경우 인덱스를 일정구간 뛰어넘고 탐색 시작
	constexpr static uint32 FIND_PLAYERLIST_STARTINDEX = 25;
	// [번호] 이름 이기 때문에 [ ] 를 생략하기 위해
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

	// 채팅창 한줄 한줄에 대한 UI 템플릿
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		TSubclassOf<UUserWidget> chatTextClass;

	// 플레이어 스크롤박스에 표시될 한줄의 템플릿
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		TSubclassOf<UUserWidget> playerNameLabelClass;

	// 이름이 Key, 인덱스가 UserWidget 자식 클래스
	// 기존 리스트 정보가 갱신될 때 맵을 통해 위젯이 리스트박스에 담겨있는지 아닌지 확인하는 용도
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

	// 플레이어 목록 문자열에서 한줄씩 추출
	void FindPlayerListFromMessage(const FString& recvString);

	// Delegate
	// 네트워크에게 메시지 전송 요청
	UFUNCTION()
		void ReadySendMessage(const FString& playerName);
	UFUNCTION()
		void RequestLeaveRoom(const int32& roomNumber);
	UFUNCTION()
		void RequestDestroyRoom(const int32& roomNumber);
};
