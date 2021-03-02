// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "ChatHUD.generated.h"

/**
 * 
 */
UCLASS()
class CHATCLIENT_API AChatHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AChatHUD();

	virtual void BeginPlay() override;

	virtual void DrawHUD() override;

	virtual void Tick(float DeltaSeconds) override;
};
