// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"

#include "UI_Login.h"

#include "LoginLevel.generated.h"

/**
 * 
 */
UCLASS()
class CHATCLIENT_API ALoginLevel : public ALevelScriptActor
{
	GENERATED_BODY()
	
private:
	UUI_Login* loginWidget;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> connectLoginClass;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
