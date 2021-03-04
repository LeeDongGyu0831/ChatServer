// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"

#include "UI_Login.h"

#include "LoginLevel.generated.h"

/**
 * 로그인창을 보여주려는 레벨
 */
UCLASS()
class CHATCLIENT_API ALoginLevel : public ALevelScriptActor
{
	GENERATED_BODY()
	
private:
	// 아이디 로그인창 UI
	UUI_Login* loginWidget;

public:
	// 로그인 레벨에서 표시할 로그인 UI 위젯
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> connectLoginClass;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
