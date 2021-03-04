// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"

#include "MainRoomLevel.generated.h"

/**
 * 
 */

class UUI_MainRoom;

UCLASS()
class CHATCLIENT_API AMainRoomLevel : public ALevelScriptActor
{
	GENERATED_BODY()
	
private:
	// �� ����� �� �ʸ��� �����ؼ� ������ ������
	// ���� ���������� ���� �ı��ǰų� ������ �� ���� ��ȭ�� �� �ٸ� ��ȭ���� �������Դ� ������ �������� �ʱ� ����
	constexpr static float REFRESH_TIME = 2.5f;

	// ���� ��ȭ�� UI
	UUI_MainRoom* mainRoomWidget;

	float refreshTime;

public:
	// ���� �� �������� ǥ���� UI ����
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> mainRoomClass;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	FString FindPlayerName(const FString& recvString);
};
