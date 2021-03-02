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

	// �� �� ���� + �ٹٲ� ���� + >> ���� ���ſ�
	UFUNCTION(BlueprintCallable, Category = Socket)
	FString TrimMessage(const FString& originString, const FString& subString);

	// ���� �տ� /�� �پ��ִ� �޽������� /�� �پ��ִ� �޽������ �Ϲ� ä�� �޽����� �ƴ�
	UFUNCTION(BlueprintCallable, Category = Socket)
	MSG_TYPE CheckMessage(FString originString);

	// ��ɾ� �޽����� �ν��ߴٸ� �ش� ��ɾ�� Ư�� ������ �߶󳻾� ���̵��� �ܾ �̾Ƴ� 
	FString GetKeyworkByChar(FString originString, TCHAR startChar, TCHAR endChar);

	// UE_LOG ��¿�
	void PrintLog(const FString& message1, const FString& message2);

	FString BytesToStringFixed(const uint8* In, int32 Count);
};
