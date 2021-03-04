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
	// ��ȭ�� �ı� �� ������ ��û�ϴ� ��������Ʈ
	// ��ȭ�� �������� ���� �޽����� ���޹ٴ� ȣ���ϵ���
	FDele_Single_RoomEvent Fuc_DeleSingle_OneParam_DestroyRoom;
	FDele_Single_RoomEvent Fuc_DeleSingle_OneParam_JoinRoom;

public:
	UUI_ShowRoomLabel(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;
	virtual void BeginDestroy() override;

	// Add To Viewport �Լ��� ����ϸ� NativeConstruct�� ȣ����� �ʾ� ���Ƿ� ������ �ʱ�ȭ �Լ��Դϴ�.
	void Init();

	void SetRoomInfo(const FString& roomNumber, const FString& roomName, const FString& roomPlayerCount);

	UFUNCTION()
	void DestroyButtonClickEvent();
	UFUNCTION()
	void JoinButtonClickEvent();
};
