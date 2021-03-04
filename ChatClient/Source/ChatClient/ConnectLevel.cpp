// Fill out your copyright notice in the Description page of Project Settings.


#include "ConnectLevel.h"

#include "GI_Network.h"

void AConnectLevel::BeginPlay()
{
	Super::BeginPlay();

	if (connectWidgetClass)
	{
		connectWidget = CreateWidget<UUI_Connect>(GetWorld(), connectWidgetClass);
		if (connectWidget)
		{
			connectWidget->AddToViewport();
			
		}
	}
}

void AConnectLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	GINetwork->RecvData();
}