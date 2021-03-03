// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_Connect.h"
#include "Components/EditableText.h"

#include "GI_Network.h"

UUI_Connect::UUI_Connect(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UUI_Connect::OnCreate()
{
	//inputIP = Cast<UEditableText>(WidgetTree->FindWidget("InputIP"));
	//if (NULL == inputIP)
	//{
	//	UE_LOG(LogTemp, Error, TEXT("Not Found InputIP"));
	//}
	//else
	//	UE_LOG(LogTemp, Error, TEXT("Found InputIP"));

	//UE_LOG(LogTemp, Error, TEXT("OnCreate"));
}

void UUI_Connect::NativeConstruct()
{
	Super::NativeConstruct();

	inputIP = Cast<UEditableText>(WidgetTree->FindWidget("InputIP"));
	inputPort = Cast<UEditableText>(WidgetTree->FindWidget("InputPort"));
	connectButton = Cast<UButton>(WidgetTree->FindWidget("Connect"));
	if (NULL == inputIP || NULL == inputPort || NULL == connectButton)
	{
		UE_LOG(LogTemp, Error, TEXT("Do Not Construct UI_Connect"));
	}

	connectButton->OnClicked.AddDynamic(this, &UUI_Connect::ButtonClick);
	inputIP->OnTextChanged.AddDynamic(this, &UUI_Connect::InputIPEvent);
	inputPort->OnTextChanged.AddDynamic(this, &UUI_Connect::InputPortEvent);
}

void UUI_Connect::TestFunc()
{
	UE_LOG(LogTemp, Error, TEXT("TestFunc"));
}

void UUI_Connect::InputIPEvent(const FText& InText)
{
	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	FString ip = InText.ToString();
	GINetwork->SetIP(ip);
}

void UUI_Connect::InputPortEvent(const FText& InText)
{
	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	FString port = InText.ToString();
	GINetwork->SetPort(port);
}

void UUI_Connect::ButtonClick()
{
	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	bool result = GINetwork->ConnectToServer();

	if (true == result)
	{
		UGameplayStatics::OpenLevel(this, "LoginLevel");
	}
}