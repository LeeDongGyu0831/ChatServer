// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_ChatGameMode.h"
#include "ChatPawn.h"
#include "PC_ChatPlayerController.h"

#include "GI_Network.h"
#include "PS_ChatState.h"
#include "ChatHUD.h"

AGM_ChatGameMode::AGM_ChatGameMode()
{
	DefaultPawnClass = AChatPawn::StaticClass();
	PlayerControllerClass = APC_ChatPlayerController::StaticClass();
	PlayerStateClass = APS_ChatState::StaticClass();
	//HUDClass = AChatHUD::StaticClass();
}

void AGM_ChatGameMode::PostLogin(APlayerController* NewPlayer)
{
	UE_LOG(LogTemp, Warning, TEXT("PostLogin Begin"));
	Super::PostLogin(NewPlayer);
	UE_LOG(LogTemp, Warning, TEXT("PostLogin End"));
	setlocale(LC_ALL, "Korean");

	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("Network GameInstance is NULL!!"));
	}
}