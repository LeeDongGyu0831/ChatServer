// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"

#include "UI_Connect.h"

#include "ConnectLevel.generated.h"
/**
 * �������� ������ �õ��ϴ� ����
 */
UCLASS()
class CHATCLIENT_API AConnectLevel : public ALevelScriptActor
{
	GENERATED_BODY()

private:
	// ����â UI
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
