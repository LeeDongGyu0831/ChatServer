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

UENUM(BlueprintType)
enum class MSG_TYPE : uint8
{
	JOIN UMETA(DisplayName = "JOIN"),
	CHAT UMETA(DisplayName = "CHAT"),
	EXIT UMETA(DisplayName = "EXIT"),
	//ATTACK UMETA(DisplayName = "ATTACK"),
};

UCLASS()
class CHATCLIENT_API UGI_Network : public UGameInstance
{
	GENERATED_BODY()
	
private:
	FSocket* Socket;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Socket)
	FString strID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Socket)
	FString strIP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Socket)
	FString strPort;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Socket)
	bool bConnect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Socket)
	bool bLogin;

public:
	UGI_Network();

	virtual void Init() override;
	virtual void Shutdown() override;

	UFUNCTION(BlueprintCallable, Category = Socket)
	void RecvData();

	UFUNCTION(BlueprintCallable, Category = Socket)
	bool ConnectToServer();

	UFUNCTION(BlueprintCallable, Category = Socket)
	bool LoginToServer();

	UFUNCTION(BlueprintCallable, Category = Socket)
	FString Recv();

	UFUNCTION(BlueprintCallable, Category = Socket)
	bool Send(const FString& data);

	FString BytesToStringFixed(const uint8* In, int32 Count);
};
