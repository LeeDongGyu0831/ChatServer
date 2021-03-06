﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_MainRoom.h"

#include "GI_Network.h"
#include "UI_ChatText.h"
#include "UI_ShowPlayerLabel.h"
#include "UI_ShowRoomLabel.h"
#include "UI_CreateRoomWidget.h"

UUI_MainRoom::UUI_MainRoom(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UUI_MainRoom::NativeConstruct()
{
	Super::NativeConstruct();

	UE_LOG(LogTemp, Error, TEXT("Constructing UI_MainRoom..."));

	chatListScrollBox = Cast<UScrollBox>(WidgetTree->FindWidget("ChatScroll"));
	playerListScrollBox = Cast<UScrollBox>(WidgetTree->FindWidget("PlayerList"));
	roomListScrollBox = Cast<UScrollBox>(WidgetTree->FindWidget("RoomList"));
	inputMessageText = Cast<UEditableText>(WidgetTree->FindWidget("Input"));
	recvButton = Cast<UButton>(WidgetTree->FindWidget("SendButton"));
	refreshPlayerButton = Cast<UButton>(WidgetTree->FindWidget("RefreshPlayerBt"));
	refreshRoomButton = Cast<UButton>(WidgetTree->FindWidget("RefreshRoomBt"));
	createRoomButton = Cast<UButton>(WidgetTree->FindWidget("CreateRoomBt"));
	closeButton = Cast<UButton>(WidgetTree->FindWidget("CloseBt"));

	if (nullptr == chatListScrollBox ||
		nullptr == playerListScrollBox ||
		nullptr == roomListScrollBox ||
		nullptr == recvButton ||
		nullptr == refreshPlayerButton ||
		nullptr == refreshRoomButton ||
		nullptr == createRoomButton ||
		nullptr == closeButton || 
		nullptr == inputMessageText
		)
	{
		UE_LOG(LogTemp, Error, TEXT("Do Not Construct UI_MainRoom"));
		return;
	}

	recvButton->OnClicked.AddDynamic(this, &UUI_MainRoom::RecvButtonClickEvent);
	refreshPlayerButton->OnClicked.AddDynamic(this, &UUI_MainRoom::RefreshPlayerButtonClickEvent);
	refreshRoomButton->OnClicked.AddDynamic(this, &UUI_MainRoom::RefreshRoomButtonClickEvent);
	createRoomButton->OnClicked.AddDynamic(this, &UUI_MainRoom::CreateRoomButtonClickEvent);
	closeButton->OnClicked.AddDynamic(this, &UUI_MainRoom::CloseButtonClickEvent);

	if (createRoomWidgetClass)
	{
		createRoomWidget = CreateWidget<UUI_CreateRoomWidget>(GetWorld(), createRoomWidgetClass);
		if (!createRoomWidget)
		{
			UE_LOG(LogTemp, Error, TEXT("Can't Create ChatTextWidget"));
			return;
		}
		createRoomWidget->AddToViewport(1);
		createRoomWidget->Init();
	}

	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	AddPlayer(GINetwork->GetID());

	GINetwork->RequestPlayerList(1);
}

void UUI_MainRoom::BeginDestroy()
{
	//recvButton->OnClicked.RemoveDynamic(this, &UUI_MainRoom::RecvButtonClickEvent);
	//refreshPlayerButton->OnClicked.RemoveDynamic(this, &UUI_MainRoom::RefreshPlayerButtonClickEvent);
	//refreshRoomButton->OnClicked.RemoveDynamic(this, &UUI_MainRoom::RefreshRoomButtonClickEvent);
	//createRoomButton->OnClicked.RemoveDynamic(this, &UUI_MainRoom::CreateRoomButtonClickEvent);
	//closeButton->OnClicked.RemoveDynamic(this, &UUI_MainRoom::CloseButtonClickEvent);

	Super::BeginDestroy();
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

void UUI_MainRoom::RefreshPlayerButtonClickEvent()
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
		UE_LOG(LogTemp, Error, TEXT("Can't Create ChatTextWidget")); 
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

	if (!playerListScrollBox)
	{
		UE_LOG(LogTemp, Error, TEXT("playerListScrollBox is not Exist"));
		return;
	}
	playerNameLabelWidget->Init();

	playerNameLabelWidget->SetPlayerName(playerName);

	playerNameLabelWidget->Fuc_DeleSingle_OneParam.BindUFunction(this, FName("ReadySendMessage"));

	playerListScrollBox->AddChild(playerNameLabelWidget);
	playerListScrollBox->ScrollToEnd();

	// 맵에 저장
	playerNameToWidgetMap.Emplace(playerName, TWeakObjectPtr<UUI_ShowPlayerLabel>(playerNameLabelWidget));
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

	if (!playerListScrollBox)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerListScrollBox is not Exist"));
		return;
	}

	UUI_ShowPlayerLabel* playerNameLabelWidget = playerNameToWidgetMap.Find(playerName)->Get();

	playerListScrollBox->RemoveChild(playerNameLabelWidget);
	playerListScrollBox->ScrollToEnd();

	// 맵에서 삭제
	playerNameToWidgetMap.Remove(playerName);
}


void UUI_MainRoom::AddRoom(const FString& roomNumberStr, const FString& roomName, const FString& roomPlayerCountStr, const FString& roomCurrentPlayerCountStr)
{
	int32 roomNumber = FCString::Atoi(*roomNumberStr);
	if (!roomNameLabelClass)
	{
		return;
	}
	bool find = roomNameToWidgetMap.Contains(roomNumber);

	// 플레이어가 리스트에 있는데 또다시 참가를 한 경우?
	if (true == find)
	{
		UUI_ShowRoomLabel* roomNameLabelWidget = roomNameToWidgetMap[roomNumber].Get();
		roomNameLabelWidget->SetRoomInfo(roomNumberStr, roomName, roomPlayerCountStr, roomCurrentPlayerCountStr);
		return;
	}

	// 기존 리스트에 해당 플레이어 이름이 없을 경우
	UUI_ShowRoomLabel* roomNameLabelWidget = CreateWidget<UUI_ShowRoomLabel>(GetWorld(), roomNameLabelClass);

	if (!roomNameLabelWidget)
	{
		UE_LOG(LogTemp, Error, TEXT("Do Not CreateWidget playerTextWidget"));
		return;
	}

	if (!roomListScrollBox)
	{
		UE_LOG(LogTemp, Error, TEXT("RoomListScrollBox is not Exist"));
		return;
	}

	roomNameLabelWidget->Init();

	roomNameLabelWidget->SetRoomInfo(roomNumberStr, roomName, roomPlayerCountStr, roomCurrentPlayerCountStr);

	roomNameLabelWidget->Fuc_DeleSingle_OneParam_DestroyRoom.BindUFunction(this, FName("RequestDestroyRoom"));
	roomNameLabelWidget->Fuc_DeleSingle_OneParam_JoinRoom.BindUFunction(this, FName("RequestJoinRoom"));

	roomListScrollBox->AddChild(roomNameLabelWidget);
	roomListScrollBox->ScrollToEnd();

	// 맵에 저장
	roomNameToWidgetMap.Emplace(roomNumber, TWeakObjectPtr<UUI_ShowRoomLabel>(roomNameLabelWidget));
}

void UUI_MainRoom::DestroyRoom(const FString& recvString)
{
	int32 roomNumber = FCString::Atoi(*GetRoomNumberFromRecvString(recvString));

	UE_LOG(LogTemp, Error, TEXT("%d"), roomNumber);

	// 여기까지 방 이름은 검색했다!

	if (!roomNameLabelClass)
	{
		return;
	}
	bool find = roomNameToWidgetMap.Contains(roomNumber);

	// 없던 맵이 삭제되는 경우
	if (false == find)
	{
		UE_LOG(LogTemp, Error, TEXT("[Bug] Non Room Name Exit"));
		return;
	}

	if (!roomListScrollBox)
	{
		UE_LOG(LogTemp, Error, TEXT("RoomListScrollBox is not Exist"));
		return;
	}

	UUI_ShowRoomLabel* playerNameLabelWidget = roomNameToWidgetMap.Find(roomNumber)->Get();

	roomListScrollBox->RemoveChild(playerNameLabelWidget);
	roomListScrollBox->ScrollToEnd();

	// 맵에서 삭제
	roomNameToWidgetMap.Remove(roomNumber);
}

void UUI_MainRoom::FindPlayerListFromMessage(const FString& recvString)
{
	//FString keyword = L"대화방 이용자";
	FString strMessage = recvString;
	
	/*  도착하는 명령어 형태
	* 
		[1] Main Room[4 / 1000]	\n
		====대화방 이용자====	\n
		[0] Player_1			\n
		[1] Player_2			\n
		[2] Player_3			\n
		[3] Test				\n
	>>

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

		FString lineString = "";
		for (int i = startIndex + 1; i < endIndex; ++i)
		{
			lineString.AppendChar(strMessage[i]);
		}
		lineString.TrimStartAndEndInline(); // 공백 제거
		lineString.TrimQuotesInline(); // 줄바꿈 제거

		FString roomName = GetRoomNameFromString(lineString);
		FString roomNumber = GetRoomNumberFromString(lineString);
		FString roomPlayerCount = GetRoomPlayerCountFromString(lineString);
		FString roomCurrentPlayerCount = GetRoomCurrentPlayerCountFromString(lineString);

		int32 number = FCString::Atoi(*roomNumber);
		if(number != 0 && number != 1)
			AddRoom(roomNumber, roomName, roomPlayerCount, roomCurrentPlayerCount);

		startIndex = endIndex;
	}

	return;
}

FString UUI_MainRoom::GetRoomNameFromRecvString(const FString& recvString)
{
	FString roomName = "";

	int32 startIndex, endIndex;
	startIndex = recvString.Find("[", ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromEnd);
	endIndex = recvString.Find("]", ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromEnd);

	for (int i = startIndex + 1; i < endIndex; ++i)
	{
		roomName.AppendChar(recvString[i]);
	}
	roomName.TrimStartAndEndInline(); // 공백 제거
	return roomName;
}

FString UUI_MainRoom::GetRoomNumberFromRecvString(const FString& recvString)
{
	FString roomNumber = "";

	int32 startIndex, endIndex;
	startIndex = recvString.Find("[", ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart);
	endIndex = recvString.Find("]", ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart);

	for (int i = startIndex + 1; i < endIndex; ++i)
	{
		roomNumber.AppendChar(recvString[i]);
	}
	roomNumber.TrimStartAndEndInline(); // 공백 제거
	return roomNumber;
}

FString UUI_MainRoom::GetRoomNameFromString(const FString& recvString)
{
	FString roomName = "";
	
	int startIndex, endIndex;
	startIndex = recvString.Find("]", ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart);
	endIndex = recvString.Find("[", ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromEnd);

	for (int i = startIndex + 1; i < endIndex; ++i)
	{
		roomName.AppendChar(recvString[i]);
	}
	roomName.TrimStartAndEndInline(); // 공백 제거

	return roomName;
}

FString UUI_MainRoom::GetRoomNumberFromString(const FString& recvString)
{
	FString roomNumber = "";

	int startIndex, endIndex;
	startIndex = recvString.Find("[", ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart);
	endIndex = recvString.Find("]", ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromStart);

	for (int i = startIndex + 1; i < endIndex; ++i)
	{
		roomNumber.AppendChar(recvString[i]);
	}
	roomNumber.TrimStartAndEndInline(); // 공백 제거

	return roomNumber;
}

FString UUI_MainRoom::GetRoomPlayerCountFromString(const FString& recvString)
{
	FString roomPlayerCount;

	int startIndex, endIndex;
	startIndex = recvString.Find("/", ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromEnd);
	endIndex = recvString.Find("]", ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromEnd);

	for (int i = startIndex + 1; i < endIndex; ++i)
	{
		roomPlayerCount.AppendChar(recvString[i]);
	}
	roomPlayerCount.TrimStartAndEndInline(); // 공백 제거

	return roomPlayerCount;
}

FString UUI_MainRoom::GetRoomCurrentPlayerCountFromString(const FString& recvString)
{
	FString roomPlayerCount;

	int startIndex, endIndex;
	startIndex = recvString.Find("[", ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromEnd);
	endIndex = recvString.Find("/", ESearchCase::Type::IgnoreCase, ESearchDir::Type::FromEnd);

	for (int i = startIndex + 1; i < endIndex; ++i)
	{
		roomPlayerCount.AppendChar(recvString[i]);
	}
	roomPlayerCount.TrimStartAndEndInline(); // 공백 제거

	return roomPlayerCount;
}

void UUI_MainRoom::CreateRoomButtonClickEvent()
{
	createRoomWidget->SetVisibility(ESlateVisibility::Visible);
	return;
}

void UUI_MainRoom::CloseButtonClickEvent()
{
	UE_LOG(LogTemp, Warning, TEXT("CloseButtonClick"));
	exit(1);
}

void UUI_MainRoom::ReadySendMessage(const FString& playerName)
{
	inputMessageText->SetText(FText::FromString(""));
	FString sendMessageString = "/t ";
	sendMessageString += playerName;
	sendMessageString += " ";
	inputMessageText->SetText(FText::FromString(sendMessageString));
}

void UUI_MainRoom::RefreshRoomButtonClickEvent()
{
	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	GINetwork->RequestRoomList();
}

void UUI_MainRoom::RequestJoinRoom(const int32& roomNumber)
{
	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	GINetwork->RequestJoinRoom(roomNumber);
}

void UUI_MainRoom::RequestDestroyRoom(const int32& roomNumber)
{
	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	GINetwork->RequestDestroyRoom(roomNumber);
}