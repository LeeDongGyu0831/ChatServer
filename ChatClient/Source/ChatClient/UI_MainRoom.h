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
	// 채팅을 최대 몇개까지 보여줄 것인가
	// 플레이어나 방은 갯수 제한을 따로 설정하지 않았습니다.
	constexpr static uint32 MAX_SHOW_CHAT = 100;
	// 서버에서 따로 패킷 없이 문자열로 받다보니 플레이어 리스트의 경우 인덱스를 일정구간 뛰어넘고 탐색 시작
	constexpr static uint32 FIND_PLAYERLIST_STARTINDEX = 25;
	// [번호] 이름 이기 때문에 [ ] 를 생략하기 위해
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

	// 채팅창 한줄 한줄에 대한 UI 템플릿
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> chatTextClass;

	// 플레이어 스크롤박스에 표시될 한줄의 템플릿
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> playerNameLabelClass;

	// 방 정보 스크롤 박스에 추가되는 한줄의 템플릿
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> roomNameLabelClass;

	// 방 생성 버튼 클릭시 팝업시킬 방 생성 UI 위젯
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> createRoomWidgetClass;

	// 이름이 Key, 인덱스가 UserWidget 자식 클래스
	// 기존 리스트 정보가 갱신될 때 맵을 통해 위젯이 리스트박스에 담겨있는지 아닌지 확인하는 용도
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

	// 플레이어 목록 문자열에서 한줄씩 추출
	void FindPlayerListFromMessage(const FString& recvString);
	// 방 목록에서 한줄씩 문자열을 추출하는 함수
	void FindRoomListFromMessage(const FString& recvString);
	// 생성, 파괴 정보를 받았을때 한줄의 문자열에서 방 이름을 추출하는 함수
	FString GetRoomNameFromRecvString(const FString& recvString);

	// 방 리스트를 받았을때 한줄의 문자열에서 각각 정보들을 추출하는 함수
	FString GetRoomNameFromString(const FString& recvString);
	FString GetRoomNumberFromString(const FString& recvString);
	FString GetRoomPlayerCountFromString(const FString& recvString);

	// Delegate
	// 네트워크에게 메시지 전송 요청
	UFUNCTION()
	void ReadySendMessage(const FString& playerName);
	UFUNCTION()
	void RequestJoinRoom(const int32& roomNumber);
	UFUNCTION()
	void RequestDestroyRoom(const int32& roomNumber);
};
