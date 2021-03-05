// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_ChatRoom.h"

#include "GI_Network.h"
#include "UI_ChatText.h"
#include "UI_ShowPlayerLabel.h"
#include "UI_CreateRoomWidget.h"

UUI_ChatRoom::UUI_ChatRoom(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UUI_ChatRoom::NativeConstruct()
{
	Super::NativeConstruct();

	UE_LOG(LogTemp, Error, TEXT("Constructing UI_ChatRoom..."));

	chatListScrollBox = Cast<UScrollBox>(WidgetTree->FindWidget("ChatScroll"));
	playerListScrollBox = Cast<UScrollBox>(WidgetTree->FindWidget("PlayerList"));
	inputMessageText = Cast<UEditableText>(WidgetTree->FindWidget("Input"));
	recvButton = Cast<UButton>(WidgetTree->FindWidget("SendButton"));
	refreshPlayerButton = Cast<UButton>(WidgetTree->FindWidget("RefreshPlayerBt"));
	destroyRoomButton = Cast<UButton>(WidgetTree->FindWidget("DestroyRoomBt"));
	leaveRoomButton = Cast<UButton>(WidgetTree->FindWidget("LeaveRoomBt"));
	closeButton = Cast<UButton>(WidgetTree->FindWidget("CloseBt"));

	roomNameText = Cast<UTextBlock>(WidgetTree->FindWidget("RoomName"));

	if (nullptr == chatListScrollBox ||
		nullptr == playerListScrollBox ||
		nullptr == recvButton ||
		nullptr == refreshPlayerButton ||
		nullptr == destroyRoomButton ||
		nullptr == leaveRoomButton ||
		nullptr == closeButton ||
		nullptr == inputMessageText ||
		nullptr == roomNameText
		)
	{
		UE_LOG(LogTemp, Error, TEXT("Do Not Construct UI_ChatRoom"));
		return;
	}

	recvButton->OnClicked.AddDynamic(this, &UUI_ChatRoom::RecvButtonClickEvent);
	refreshPlayerButton->OnClicked.AddDynamic(this, &UUI_ChatRoom::RefreshPlayerButtonClickEvent);
	destroyRoomButton->OnClicked.AddDynamic(this, &UUI_ChatRoom::DestroyRoomButtonClickEvent);
	leaveRoomButton->OnClicked.AddDynamic(this, &UUI_ChatRoom::LeaveRoomButtonClickEvent);
	closeButton->OnClicked.AddDynamic(this, &UUI_ChatRoom::CloseButtonClickEvent);

	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	AddPlayer(GINetwork->GetID());

	int32 index = GetWorld()->GetActiveLevelCollectionIndex();
	GetWorld()->GetLevel(index)->GetLevelScriptActor()->SetActorTickEnabled(true);
	UE_LOG(LogTemp, Error, TEXT("Construct UI_ChatRoom..."));
}

void UUI_ChatRoom::BeginDestroy()
{
	//recvButton->OnClicked.RemoveDynamic(this, &UUI_MainRoom::RecvButtonClickEvent);
	//refreshPlayerButton->OnClicked.RemoveDynamic(this, &UUI_MainRoom::RefreshPlayerButtonClickEvent);
	//refreshRoomButton->OnClicked.RemoveDynamic(this, &UUI_MainRoom::RefreshRoomButtonClickEvent);
	//createRoomButton->OnClicked.RemoveDynamic(this, &UUI_MainRoom::CreateRoomButtonClickEvent);
	//closeButton->OnClicked.RemoveDynamic(this, &UUI_MainRoom::CloseButtonClickEvent);

	Super::BeginDestroy();
}

void UUI_ChatRoom::RecvButtonClickEvent()
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

void UUI_ChatRoom::SetInfo(const FString& roomName, const int32& roomNumber)
{
	FString name = "[";
	name += FString::FromInt(roomNumber);
	name += "] ";
	name += roomName;
	_roomName = roomName;
	_roomNumber = roomNumber;
	roomNameText->SetText(FText::FromString(name));
}

void UUI_ChatRoom::RefreshPlayerButtonClickEvent()
{
	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	// GINetwork->RequestPlayerList(1);
}

void UUI_ChatRoom::AddChatting(const FString& chatMessage)
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
	if (chatTextWidget)
		chatTextWidget->SetChatMessage(chatMessage);

	// 스크롤 박스에 연결
	if (chatListScrollBox)
	{
		chatListScrollBox->AddChild(chatTextWidget);
		chatListScrollBox->ScrollToEnd();

		int32 chatListCount = chatListScrollBox->GetChildrenCount();
		if (chatListCount > MAX_SHOW_CHAT)
			chatListScrollBox->RemoveChildAt(0);
	}
}

void UUI_ChatRoom::AddPlayer(const FString& playerName)
{
	if (!playerNameLabelClass)
	{
		return;
	}
	bool find = playerNameToWidgetMap.Contains(playerName);

	// 플레이어가 리스트에 있는데 또다시 참가를 한 경우?
	if (true == find)
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

void UUI_ChatRoom::ExitPlayer(const FString& playerName)
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

void UUI_ChatRoom::FindPlayerListFromMessage(const FString& recvString)
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

void UUI_ChatRoom::DestroyRoomButtonClickEvent()
{
	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	GINetwork->SetCurrentRoomName("Main Room");
	GINetwork->SetCurrentRoomNumber(1);
	GINetwork->RequestDestroyRoom(_roomNumber);

	UGameplayStatics::OpenLevel(this, "MainLevel");

	UE_LOG(LogTemp, Warning, TEXT("DestroyButtonClick"));
	return;
}

void UUI_ChatRoom::LeaveRoomButtonClickEvent()
{
	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	GINetwork->SetCurrentRoomName("Main Room");
	GINetwork->SetCurrentRoomNumber(1);
	GINetwork->RequestJoinRoom(1);

	UGameplayStatics::OpenLevel(this, "MainLevel");

	UE_LOG(LogTemp, Warning, TEXT("LeaveButtonClick"));
	return;
}

void UUI_ChatRoom::CloseButtonClickEvent()
{
	UE_LOG(LogTemp, Warning, TEXT("CloseButtonClick"));
	exit(1);
}


void UUI_ChatRoom::ReadySendMessage(const FString& playerName)
{
	inputMessageText->SetText(FText::FromString(""));
	FString sendMessageString = "/t ";
	sendMessageString += playerName;
	sendMessageString += " ";
	inputMessageText->SetText(FText::FromString(sendMessageString));
}

void UUI_ChatRoom::RequestDestroyRoom(const int32& roomNumber)
{
	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	GINetwork->RequestDestroyRoom(roomNumber);
}

void UUI_ChatRoom::RequestLeaveRoom(const int32& roomNumber)
{
	auto GINetwork = Cast<UGI_Network>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (NULL == GINetwork)
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance is not GI_Network!!"));
		return;
	}
	//GINetwork->RequestLeaveRoom(roomNumber);
}