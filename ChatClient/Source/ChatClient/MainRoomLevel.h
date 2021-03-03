// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"

#include "UI_MainRoom.h"

#include "MainRoomLevel.generated.h"

/**
 * 
 */
UCLASS()
class CHATCLIENT_API AMainRoomLevel : public ALevelScriptActor
{
	GENERATED_BODY()
	
private:
	constexpr static float REFRESH_TIME = 1.f;

	// ���� ��ȭ�� UI
	UUI_MainRoom* mainRoomWidget;

	float refreshTime;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> mainRoomClass;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	FString FindPlayerName(const FString& recvString);
};
