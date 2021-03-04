// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_CreateRoomWidget.h"

#include "GI_Network.h"

UUI_CreateRoomWidget::UUI_CreateRoomWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}


void UUI_CreateRoomWidget::NativeConstruct()
{
	Super::NativeConstruct();

	inputRoomName = Cast<UEditableText>(WidgetTree->FindWidget("RoomNameInput"));
	inputMaxCount = Cast<UEditableText>(WidgetTree->FindWidget("MaxCountInput"));
	createButton = Cast<UButton>(WidgetTree->FindWidget("CreateRoomButton"));
	cancleButton = Cast<UButton>(WidgetTree->FindWidget("CancelButton"));
	if (nullptr == inputRoomName ||
		nullptr == inputMaxCount ||
		nullptr == createButton ||
		nullptr == cancleButton )
	{
		UE_LOG(LogTemp, Error, TEXT("Do Not Construct UI_Connect"));
		return;
	}

	createButton->OnClicked.AddDynamic(this, &UUI_CreateRoomWidget::CreateButtonClickEvent);
	cancleButton->OnClicked.AddDynamic(this, &UUI_CreateRoomWidget::CancleButtonClickEvent);
}

void UUI_CreateRoomWidget::BeginDestroy()
{
	Super::BeginDestroy();
}

void UUI_CreateRoomWidget::Init()
{
	SetVisibility(ESlateVisibility::Collapsed);

}

UFUNCTION()
void UUI_CreateRoomWidget::CreateButtonClickEvent()
{
	FString maxPlayerCountStr = inputMaxCount->GetText().ToString();
	FString roomName = inputRoomName->GetText().ToString();
	int32 maxPlayerCount = FCString::Atoi(*maxPlayerCountStr);
	if (maxPlayerCount == 0)
		return;

	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	GINetwork->RequestCreateRoom(maxPlayerCount, roomName);

	inputRoomName->SetText(FText::FromString(""));
	inputMaxCount->SetText(FText::FromString(""));
	SetVisibility(ESlateVisibility::Collapsed);
}

UFUNCTION()
void UUI_CreateRoomWidget::CancleButtonClickEvent()
{
	SetVisibility(ESlateVisibility::Collapsed);
}