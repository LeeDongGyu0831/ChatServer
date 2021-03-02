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
};

UCLASS()
class CHATCLIENT_API UGI_Network : public UGameInstance
{
	GENERATED_BODY()
	
private:
	FSocket* Socket;

private:
	FString strID;
	FString strIP;
	FString strPort;
	bool bConnect;
	bool bLogin;

public:
	UGI_Network();

	virtual void Init() override;
	virtual void Shutdown() override;

public:
	void SetID(FString id);
	void SetIP(FString ip);
	void SetPort(FString port);

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

	// 앞 뒤 공백 + 줄바꿈 문자 + >> 문자 제거용
	UFUNCTION(BlueprintCallable, Category = Socket)
	FString TrimMessage(const FString& originString, const FString& subString);

	// 가장 앞에 /가 붙어있는 메시지인지 /가 붙어있는 메시지라면 일반 채팅 메시지가 아님
	UFUNCTION(BlueprintCallable, Category = Socket)
	MSG_TYPE CheckMessage(FString originString);

	// 명령어 메시지를 인식했다면 해당 명령어에서 특정 구간을 잘라내어 아이디같은 단어를 뽑아냄 
	FString GetKeyworkByChar(FString originString, TCHAR startChar, TCHAR endChar);

	// UE_LOG 출력용
	void PrintLog(const FString& message1, const FString& message2);

	FString BytesToStringFixed(const uint8* In, int32 Count);
};
