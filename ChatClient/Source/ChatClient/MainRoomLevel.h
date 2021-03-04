// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"

#include "MainRoomLevel.generated.h"

/**
 * 
 */

class UUI_MainRoom;

UCLASS()
class CHATCLIENT_API AMainRoomLevel : public ALevelScriptActor
{
	GENERATED_BODY()
	
private:
	// 방 목록을 몇 초마다 갱신해서 보여줄 것인지
	// 기존 서버에서는 방이 파괴되거나 생성될 때 메인 대화방 및 다른 대화방의 유저에게는 정보를 전송하지 않기 때문
	constexpr static float REFRESH_TIME = 2.5f;

	// 메인 대화방 UI
	UUI_MainRoom* mainRoomWidget;

	float refreshTime;

public:
	// 메인 룸 레벨에서 표시할 UI 위젯
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> mainRoomClass;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	FString FindPlayerName(const FString& recvString);
};
