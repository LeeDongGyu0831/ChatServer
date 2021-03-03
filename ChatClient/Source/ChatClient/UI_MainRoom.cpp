// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_MainRoom.h"

#include "GI_Network.h"

UUI_MainRoom::UUI_MainRoom(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UUI_MainRoom::NativeConstruct()
{
	Super::NativeConstruct();

	chatListScrollBox = Cast<UScrollBox>(WidgetTree->FindWidget("ChatScroll"));
	playerListScrollBox = Cast<UScrollBox>(WidgetTree->FindWidget("PlayerList"));
	inputMessageText = Cast<UEditableText>(WidgetTree->FindWidget("Input"));
	recvButton = Cast<UButton>(WidgetTree->FindWidget("SendButton"));
	if (NULL == chatListScrollBox || NULL == playerListScrollBox || NULL == recvButton)
	{
		UE_LOG(LogTemp, Error, TEXT("Do Not Construct UI_MainRoom"));
	}

	recvButton->OnClicked.AddDynamic(this, &UUI_MainRoom::RecvButtonClickEvent);

	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	AddPlayer(GINetwork->GetID());
}

void UUI_MainRoom::RecvButtonClickEvent()
{
	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	FText inputText = inputMessageText->GetText();
	FString message = inputText.ToString();
	GINetwork->Send(message);
	AddChatting(message);
	inputMessageText->SetText(FText::FromString(""));
}

void UUI_MainRoom::AddChatting(const FString& chatMessage)
{
	if (!chatTextClass)
	{
		return;
	}
	if (chatMessage.Len() == 0)
		return;

	// 멤버변수로 STL 컨테이너를 사용해야하나?
	UUI_ChatText* chatTextWidget = CreateWidget<UUI_ChatText>(GetWorld(), chatTextClass);
	if (!chatTextWidget)
	{
		UE_LOG(LogTemp, Error, TEXT("!!!!!!!!!!!!!!!!")); 
		return;
	}
	if(chatTextWidget)
		chatTextWidget->SetChatMessage(chatMessage);

	// 스크롤 박스에 연결
	if (chatListScrollBox)
	{
		chatListScrollBox->AddChild(chatTextWidget);
		chatListScrollBox->ScrollToEnd();

		int32 chatListCount = chatListScrollBox->GetChildrenCount();
		if(chatListCount > MAX_SHOW_CHAT)
			chatListScrollBox->RemoveChildAt(0);
	}
}

void UUI_MainRoom::AddPlayer(const FString& playerName)
{
	if (!chatTextClass)
	{
		return;
	}
	bool find = TestWidgetMap.Contains(playerName);
	//UUI_ChatText* playerTextWidget = TestWidgetMap.Find(playerName)->Get();

	// 플레이어가 리스트에 있는데 또다시 참가를 한 경우?
	if(true == find)
	{
		UE_LOG(LogTemp, Error, TEXT("[Bug] Same Player Name Join"));
		return;
	}

	// 기존 리스트에 해당 플레이어 이름이 없을 경우
	UUI_ChatText* playerTextWidget = CreateWidget<UUI_ChatText>(GetWorld(), chatTextClass);

	if (!playerTextWidget)
	{
		UE_LOG(LogTemp, Error, TEXT("Do Not CreateWidget playerTextWidget"));
		return;
	}

	playerTextWidget->SetChatMessage(playerName);

	if (playerListScrollBox)
	{
		playerListScrollBox->AddChild(playerTextWidget);
		playerListScrollBox->ScrollToEnd();

		// 맵에 저장
		TestWidgetMap.Emplace(playerName, TWeakObjectPtr<UUI_ChatText>(playerTextWidget));
		//TestWidgetMap.Emplace(playerName, false);
	}
}

void UUI_MainRoom::ExitPlayer(const FString& playerName)
{
	if (!chatTextClass)
	{
		return;
	}
	bool find = TestWidgetMap.Contains(playerName);

	// 없던 플레이어가 퇴장하는 경우
	if (false == find)
	{
		UE_LOG(LogTemp, Error, TEXT("[Bug] Same Player Name Join"));
		return;
	}

	if (playerListScrollBox)
	{
		UUI_ChatText* playerTextWidget = TestWidgetMap.Find(playerName)->Get();

		playerListScrollBox->RemoveChild(playerTextWidget);
		playerListScrollBox->ScrollToEnd();

		// 맵에서 삭제
		TestWidgetMap.Remove(playerName);
	}
}

void UUI_MainRoom::FindPlayerListFromMessage(const FString& recvString)
{
	FString strMessage = recvString;

	TArray<FString> strArray;
	int32 result = strMessage.CullArray(&strArray);
	UE_LOG(LogTemp, Error, TEXT("Result : %d"), result);
	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	for (auto& str : strArray)
		GINetwork->PrintLog("CullArray", str);
	return;
}