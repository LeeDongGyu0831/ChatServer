// Fill out your copyright notice in the Description page of Project Settings.


#include "PC_ChatPlayerController.h"

APC_ChatPlayerController::APC_ChatPlayerController()
{

}

void APC_ChatPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	UE_LOG(LogTemp, Warning, TEXT("PostInitilizeComponents"))
}

void APC_ChatPlayerController::OnPossess(APawn* aPawn)
{
	UE_LOG(LogTemp, Warning, TEXT("OnPossess"));
	Super::OnPossess(aPawn);
}
