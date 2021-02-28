// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Networking/Public/Networking.h"
#include "Sockets.h"
#include "SocketSubsystem.h"

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GI_Network.generated.h"

/**
 * 
 */
UCLASS()
class CHATCLIENT_API UGI_Network : public UGameInstance
{
	GENERATED_BODY()
	
private:
	FSocket* Socket;

public:
	UGI_Network();

	virtual void Init() override;

	UFUNCTION(BlueprintCallable, Category = Socket)
	void ConnectToServer(const FString& strIP, const int32& nPort);
};
