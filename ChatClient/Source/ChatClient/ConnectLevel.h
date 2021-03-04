// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"

#include "UI_Connect.h"

#include "ConnectLevel.generated.h"
/**
 * 서버와의 접속을 시도하는 레벨
 */
UCLASS()
class CHATCLIENT_API AConnectLevel : public ALevelScriptActor
{
	GENERATED_BODY()

private:
	// 접속창 UI
	UUI_Connect* connectWidget;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> connectWidgetClass;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void Destroyed() override;
};
