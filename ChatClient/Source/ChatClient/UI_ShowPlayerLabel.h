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
	// �÷��̾� �̸��� ����� Text ������Ʈ
	class UTextBlock* playerNameTextBlock;
	// �ش� �÷��̾�� �ӼӸ��� ������ ��ɾ �������ִ� ��ư
	class UButton* sendMessageButton;

	// ���� �� ���� �ǹ��ϴ� �÷��̾� �̸�
	FString _playerName;
public:
	// ���� ��ȭâ �������� �������� �ӼӸ��� �����Ұ��� �޽��� ����
	FDele_Single_SendMessage Fuc_DeleSingle_OneParam;

public:
	UUI_ShowPlayerLabel(const FObjectInitializer & ObjectInitializer);

	virtual void NativeConstruct() override;
	virtual void BeginDestroy() override;

	// Add To Viewport �Լ��� ����ϸ� NativeConstruct�� ȣ����� �ʾ� ���Ƿ� ������ �ʱ�ȭ �Լ��Դϴ�.
	void Init();

	void SetPlayerName(const FString & playerName);

	// �ش� �Լ����� ��������Ʈ�� ���� ��ȭ���� ��ǲ �ؽ�Ʈ�� ������ �ְ���
	UFUNCTION()
	void SendMessageButton();
};
