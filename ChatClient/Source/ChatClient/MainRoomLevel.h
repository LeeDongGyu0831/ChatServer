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
	// 메인 대화방 UI
	UUI_MainRoom* mainRoomWidget;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> mainRoomClass;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	FString FindPlayerName(const FString& recvString);
};
