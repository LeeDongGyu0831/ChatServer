// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_ChatGameMode.h"
#include "ChatPawn.h"
#include "PC_ChatPlayerController.h"

#include "GI_Network.h"

AGM_ChatGameMode::AGM_ChatGameMode()
{
	DefaultPawnClass = AChatPawn::StaticClass();
	PlayerControllerClass = APC_ChatPlayerController::StaticClass();

}

void AGM_ChatGameMode::PostLogin(APlayerController* NewPlayer)
{
	UE_LOG(LogTemp, Warning, TEXT("PostLogin Begin"));
	Super::PostLogin(NewPlayer);
	UE_LOG(LogTemp, Warning, TEXT("PostLogin End"));

	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("Network GameInstance is NULL!!"));
	}
	GINetwork->ConnectToServer(TEXT("127.0.0.1"), 9000);
}