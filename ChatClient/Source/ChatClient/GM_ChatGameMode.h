// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GM_ChatGameMode.generated.h"


/**
 * 
 */
UCLASS()
class CHATCLIENT_API AGM_ChatGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGM_ChatGameMode();

	virtual void PostLogin(APlayerController* NewPlayer) override;
};
