// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "ChatRoomLevel.generated.h"

/**
 * 
 */

class UUI_ChatRoom;

UCLASS()
class CHATCLIENT_API AChatRoomLevel : public ALevelScriptActor
{
	GENERATED_BODY()

private:
	// ���� ��ȭ�� UI
	UUI_ChatRoom* chatRoomWidget;

	float refreshTime;

	int32 roomNumber;
	FString roomName;

public:
	// ���� �� �������� ǥ���� UI ����
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		TSubclassOf<UUserWidget> chatRoomClass;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	FString FindPlayerName(const FString& recvString);
};
