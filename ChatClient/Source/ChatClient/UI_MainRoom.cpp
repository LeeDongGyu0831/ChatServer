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
	refreshButton = Cast<UButton>(WidgetTree->FindWidget("Refresh"));
	if (NULL == chatListScrollBox || NULL == playerListScrollBox || NULL == recvButton)
	{
		UE_LOG(LogTemp, Error, TEXT("Do Not Construct UI_MainRoom"));
	}

	recvButton->OnClicked.AddDynamic(this, &UUI_MainRoom::RecvButtonClickEvent);
	refreshButton->OnClicked.AddDynamic(this, &UUI_MainRoom::RefreshButtonClickEvent);

	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	AddPlayer(GINetwork->GetID());

	GINetwork->RequestPlayerList(1);
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

void UUI_MainRoom::RefreshButtonClickEvent()
{
	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	GINetwork->RequestPlayerList(1);
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
		UE_LOG(LogTemp, Error, TEXT("[Bug] Non Player Name Exit"));
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
	FString keyword = L"대화방 이용자";
	FString strMessage = recvString;
	
	/*  도착하는 명령어 형태
		[1] Main Room[4 / 1000]
		====대화방 이용자====
		[0] Player_1
		[1] Player_2
		[2] Player_3
		[3] Test		
	*/
	// 대략적으로 앞에서부터 시작
	int index = FIND_PLAYERLIST_STARTINDEX;
	int32 endIndex = index;
	int32 startIndex = index;
	while (1)
	{
		startIndex = strMessage.Find("[", ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart, startIndex + 1);
		endIndex = strMessage.Find("[", ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart, startIndex + 1);
		if (startIndex == -1)
			break;
		if (endIndex == -1)
			endIndex = strMessage.Len();

		//[숫자] 만큼 벌린다
		startIndex += REMOVE_PLAYERNUM;

		FString playerName = "";
		for (int i = startIndex; i < endIndex; ++i)
		{
			playerName.AppendChar(strMessage[i]);
		}
		playerName.TrimStartAndEndInline(); // 공백 제거
		playerName.TrimQuotesInline(); // 줄바꿈 제거
		AddPlayer(playerName);
	}

	return;
}