// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_MainRoom.h"

#include "GI_Network.h"
#include "UI_ChatText.h"
#include "UI_ShowPlayerLabel.h"
#include "UI_ShowRoomLabel.h"

UUI_MainRoom::UUI_MainRoom(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UUI_MainRoom::NativeConstruct()
{
	Super::NativeConstruct();

	chatListScrollBox = Cast<UScrollBox>(WidgetTree->FindWidget("ChatScroll"));
	playerListScrollBox = Cast<UScrollBox>(WidgetTree->FindWidget("PlayerList"));
	roomListScrollBox = Cast<UScrollBox>(WidgetTree->FindWidget("RoomList"));
	inputMessageText = Cast<UEditableText>(WidgetTree->FindWidget("Input"));
	recvButton = Cast<UButton>(WidgetTree->FindWidget("SendButton"));
	refreshButton = Cast<UButton>(WidgetTree->FindWidget("Refresh"));
	createRoomButton = Cast<UButton>(WidgetTree->FindWidget("CreateRoomButton"));
	closeButton = Cast<UButton>(WidgetTree->FindWidget("CloseButton"));

	if (nullptr == chatListScrollBox ||
		nullptr == playerListScrollBox ||
		nullptr == recvButton ||
		nullptr == refreshButton ||
		nullptr == createRoomButton ||
		nullptr == closeButton
		)
	{
		UE_LOG(LogTemp, Error, TEXT("Do Not Construct UI_MainRoom"));
	}

	recvButton->OnClicked.AddDynamic(this, &UUI_MainRoom::RecvButtonClickEvent);
	refreshButton->OnClicked.AddDynamic(this, &UUI_MainRoom::RefreshButtonClickEvent);
	createRoomButton->OnClicked.AddDynamic(this, &UUI_MainRoom::CreateRoomButtonClickEvent);
	closeButton->OnClicked.AddDynamic(this, &UUI_MainRoom::CloseButtonClickEvent);

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

	UUI_ChatText* chatTextWidget = CreateWidget<UUI_ChatText>(GetWorld(), chatTextClass);
	if (!chatTextWidget)
	{
		UE_LOG(LogTemp, Error, TEXT("!!!!!!!!!!!!!!!!")); 
		return;
	}
	chatTextWidget->Init();
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
	if (!playerNameLabelClass)
	{
		return;
	}
	bool find = playerNameToWidgetMap.Contains(playerName);

	// 플레이어가 리스트에 있는데 또다시 참가를 한 경우?
	if(true == find)
	{
		return;
	}

	// 기존 리스트에 해당 플레이어 이름이 없을 경우
	UUI_ShowPlayerLabel* playerNameLabelWidget = CreateWidget<UUI_ShowPlayerLabel>(GetWorld(), playerNameLabelClass);

	if (!playerNameLabelWidget)
	{
		UE_LOG(LogTemp, Error, TEXT("Do Not CreateWidget playerTextWidget"));
		return;
	}
	playerNameLabelWidget->Init();

	playerNameLabelWidget->SetPlayerName(playerName);

	if (playerListScrollBox)
	{
		playerListScrollBox->AddChild(playerNameLabelWidget);
		playerListScrollBox->ScrollToEnd();

		// 맵에 저장
		playerNameToWidgetMap.Emplace(playerName, TWeakObjectPtr<UUI_ShowPlayerLabel>(playerNameLabelWidget));
	}
}

void UUI_MainRoom::ExitPlayer(const FString& playerName)
{
	if (!playerNameLabelClass)
	{
		return;
	}
	bool find = playerNameToWidgetMap.Contains(playerName);

	// 없던 플레이어가 퇴장하는 경우
	if (false == find)
	{
		UE_LOG(LogTemp, Error, TEXT("[Bug] Non Player Name Exit"));
		return;
	}

	if (playerListScrollBox)
	{
		UUI_ShowPlayerLabel* playerNameLabelWidget = playerNameToWidgetMap.Find(playerName)->Get();

		playerListScrollBox->RemoveChild(playerNameLabelWidget);
		playerListScrollBox->ScrollToEnd();

		// 맵에서 삭제
		playerNameToWidgetMap.Remove(playerName);
	}
}


void UUI_MainRoom::AddRoom(const FString& roomName)
{
	if (!roomNameLabelClass)
	{
		return;
	}
	bool find = roomNameToWidgetMap.Contains(roomName);

	// 플레이어가 리스트에 있는데 또다시 참가를 한 경우?
	if (true == find)
	{
		return;
	}

	// 기존 리스트에 해당 플레이어 이름이 없을 경우
	UUI_ShowRoomLabel* roomNameLabelWidget = CreateWidget<UUI_ShowRoomLabel>(GetWorld(), roomNameLabelClass);

	if (!roomNameLabelWidget)
	{
		UE_LOG(LogTemp, Error, TEXT("Do Not CreateWidget playerTextWidget"));
		return;
	}
	roomNameLabelWidget->Init();

	roomNameLabelWidget->SetRoomInfo(roomName);

	if (roomListScrollBox)
	{
		roomListScrollBox->AddChild(roomNameLabelWidget);
		roomListScrollBox->ScrollToEnd();

		// 맵에 저장
		roomNameToWidgetMap.Emplace(roomName, TWeakObjectPtr<UUI_ShowRoomLabel>(roomNameLabelWidget));
	}
}

void UUI_MainRoom::ExitRoom(const FString& roomName)
{
	if (!roomNameLabelClass)
	{
		return;
	}
	bool find = roomNameToWidgetMap.Contains(roomName);

	// 없던 플레이어가 퇴장하는 경우
	if (false == find)
	{
		UE_LOG(LogTemp, Error, TEXT("Non Room Destoryed"));
		return;
	}

	if (roomListScrollBox)
	{
		UUI_ShowRoomLabel* roomNameLabelWidget = roomNameToWidgetMap.Find(roomName)->Get();

		roomListScrollBox->RemoveChild(roomNameLabelWidget);
		roomListScrollBox->ScrollToEnd();

		// 맵에서 삭제
		roomNameToWidgetMap.Remove(roomName);
	}
}

void UUI_MainRoom::FindPlayerListFromMessage(const FString& recvString)
{
	//FString keyword = L"대화방 이용자";
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


void UUI_MainRoom::FindRoomListFromMessage(const FString& recvString)
{
	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	FString strMessage = recvString;
	GINetwork->PrintLog("RecvString", recvString);
	/*  도착하는 명령어 형태
		/      [0] Login Room [0/1000]
		/      [1] Main Room [3/1000]
		/      [2] Test [0/2]
		/      [3] Test [0/3]
	*/
	int index = -1;
	int32 endIndex = index;
	int32 startIndex = index;
	while (1)
	{
		startIndex = strMessage.Find("/", ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart, startIndex + 1);
		endIndex = strMessage.Find("\n", ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart, startIndex + 1);
		if (startIndex == -1)
			break;
		if (endIndex == -1)
			endIndex = strMessage.Len();

		FString roomName = "";
		for (int i = startIndex + 1; i < endIndex; ++i)
		{
			roomName.AppendChar(strMessage[i]);
		}
		roomName.TrimStartAndEndInline(); // 공백 제거
		roomName.TrimQuotesInline(); // 줄바꿈 제거

		GINetwork->PrintLog("RoomName", roomName);

		AddRoom(roomName);
		startIndex = endIndex;
	}

	return;
}

void UUI_MainRoom::CreateRoomButtonClickEvent()
{
	UE_LOG(LogTemp, Warning, TEXT("CreateRoomButtonClick"));
	return;
}

void UUI_MainRoom::CloseButtonClickEvent()
{
	UE_LOG(LogTemp, Warning, TEXT("CloseButtonClick"));

	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	GINetwork->RequestRoomList();
	return;
}