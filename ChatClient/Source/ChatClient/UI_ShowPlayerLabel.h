// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/UMG/Public/UMG.h"

#include "UI_ShowPlayerLabel.generated.h"

/**
 * 
 */

DECLARE_DELEGATE_OneParam(FDele_Single_SendMessage, FString);

UCLASS()
class CHATCLIENT_API UUI_ShowPlayerLabel : public UUserWidget
{
	GENERATED_BODY()

private:
	// 플레이어 이름을 출력할 Text 오브젝트
	class UTextBlock* playerNameTextBlock;
	// 해당 플레이어에게 귓속말을 보내는 명령어를 생성해주는 버튼
	class UButton* sendMessageButton;

	// 현재 이 라벨이 의미하는 플레이어 이름
	FString _playerName;
public:
	// 상위 대화창 위젯에게 누구에게 귓속말을 전송할건지 메시지 전달
	FDele_Single_SendMessage Fuc_DeleSingle_OneParam;

public:
	UUI_ShowPlayerLabel(const FObjectInitializer & ObjectInitializer);

	virtual void NativeConstruct() override;
	virtual void BeginDestroy() override;

	// Add To Viewport 함수를 사용하면 NativeConstruct가 호출되지 않아 임의로 제작한 초기화 함수입니다.
	void Init();

	void SetPlayerName(const FString & playerName);

	// 해당 함수에서 델리게이트를 통해 대화방의 인풋 텍스트에 영향을 주게함
	UFUNCTION()
	void SendMessageButton();
};
