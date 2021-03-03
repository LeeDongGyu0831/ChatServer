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

	// ��������� STL �����̳ʸ� ����ؾ��ϳ�?
	UUI_ChatText* chatTextWidget = CreateWidget<UUI_ChatText>(GetWorld(), chatTextClass);
	if (!chatTextWidget)
	{
		UE_LOG(LogTemp, Error, TEXT("!!!!!!!!!!!!!!!!")); 
		return;
	}
	if(chatTextWidget)
		chatTextWidget->SetChatMessage(chatMessage);

	// ��ũ�� �ڽ��� ����
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

	// �÷��̾ ����Ʈ�� �ִµ� �Ǵٽ� ������ �� ���?
	if(true == find)
	{
		UE_LOG(LogTemp, Error, TEXT("[Bug] Same Player Name Join"));
		return;
	}

	// ���� ����Ʈ�� �ش� �÷��̾� �̸��� ���� ���
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

		// �ʿ� ����
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

	// ���� �÷��̾ �����ϴ� ���
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

		// �ʿ��� ����
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