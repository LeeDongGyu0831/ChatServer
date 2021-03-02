// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginLevel.h"

#include "GI_Network.h"


void ALoginLevel::BeginPlay()
{
	Super::BeginPlay();

	if (connectLoginClass)
	{
		loginWidget = CreateWidget<UUI_Login>(GetWorld(), connectLoginClass);
		if (loginWidget)
		{
			loginWidget->AddToViewport();

		}
	}
}

void ALoginLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	FString recvString = GINetwork->Recv();

	FText recvText = FText::FromString(recvString);
	if (recvString.Len() < 3)
		return;

	int32 index = recvString.Find(L"로그인");
	UE_LOG(LogTemp, Warning, TEXT("%d"), index);
	if (index != -1)
	{
		UGameplayStatics::OpenLevel(this, "MainLevel");
	}
}
