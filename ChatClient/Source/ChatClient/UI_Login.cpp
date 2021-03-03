// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_Login.h"

#include "GI_Network.h"

UUI_Login::UUI_Login(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UUI_Login::NativeConstruct()
{
	Super::NativeConstruct();

	inputID = Cast<UEditableText>(WidgetTree->FindWidget("InputID"));
	connectButton = Cast<UButton>(WidgetTree->FindWidget("Connect"));
	if (NULL == inputID || NULL == connectButton)
	{
		UE_LOG(LogTemp, Error, TEXT("Do Not Construct UI_Login"));
	}

	connectButton->OnClicked.AddDynamic(this, &UUI_Login::ConnectButtonClick);
	inputID->OnTextChanged.AddDynamic(this, &UUI_Login::InputIDEvent);
}

void UUI_Login::InputIDEvent(const FText& InText)
{
	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	strID = InText.ToString();
	GINetwork->SetID(strID);
}

void UUI_Login::ConnectButtonClick()
{
	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	GINetwork->LoginToServer();
}