// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/UMG/Public/UMG.h"

#include "UI_ShowRoomLabel.generated.h"

/**
 * 
 */

DECLARE_DELEGATE_OneParam(FDele_Single_RoomEvent, int32);

UCLASS()
class CHATCLIENT_API UUI_ShowRoomLabel : public UUserWidget
{
	GENERATED_BODY()

private:
	class UTextBlock* roomNameTextBlock;
	class UTextBlock* roomNumberTextBlock;
	class UTextBlock* roomPlayerCountTextBlock;
	class UButton* destroyButton;
	class UButton* joinButton;

	int32 _roomNumber;
	FString _roomName;
	int32 _roomPlayerCount;

public:
	// 대화방 파괴 및 참가를 요청하는 델리게이트
	// 대화방 위젯에서 따로 메시지를 전달바다 호출하도록
	FDele_Single_RoomEvent Fuc_DeleSingle_OneParam_DestroyRoom;
	FDele_Single_RoomEvent Fuc_DeleSingle_OneParam_JoinRoom;

public:
	UUI_ShowRoomLabel(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;
	virtual void BeginDestroy() override;

	// Add To Viewport 함수를 사용하면 NativeConstruct가 호출되지 않아 임의로 제작한 초기화 함수입니다.
	void Init();

	void SetRoomInfo(const FString& roomNumber, const FString& roomName, const FString& roomPlayerCount);

	UFUNCTION()
	void DestroyButtonClickEvent();
	UFUNCTION()
	void JoinButtonClickEvent();
};
