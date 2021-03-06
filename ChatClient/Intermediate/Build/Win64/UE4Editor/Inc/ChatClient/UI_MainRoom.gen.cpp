// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/UI_MainRoom.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_MainRoom() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_MainRoom_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_MainRoom();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UUI_MainRoom::execRequestDestroyRoom)
	{
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_roomNumber);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RequestDestroyRoom(Z_Param_Out_roomNumber);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_MainRoom::execRequestJoinRoom)
	{
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_roomNumber);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RequestJoinRoom(Z_Param_Out_roomNumber);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_MainRoom::execReadySendMessage)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_playerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ReadySendMessage(Z_Param_playerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_MainRoom::execCreateRoomButtonClickEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CreateRoomButtonClickEvent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_MainRoom::execCloseButtonClickEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CloseButtonClickEvent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_MainRoom::execRefreshRoomButtonClickEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RefreshRoomButtonClickEvent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_MainRoom::execRefreshPlayerButtonClickEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RefreshPlayerButtonClickEvent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_MainRoom::execRecvButtonClickEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RecvButtonClickEvent();
		P_NATIVE_END;
	}
	void UUI_MainRoom::StaticRegisterNativesUUI_MainRoom()
	{
		UClass* Class = UUI_MainRoom::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CloseButtonClickEvent", &UUI_MainRoom::execCloseButtonClickEvent },
			{ "CreateRoomButtonClickEvent", &UUI_MainRoom::execCreateRoomButtonClickEvent },
			{ "ReadySendMessage", &UUI_MainRoom::execReadySendMessage },
			{ "RecvButtonClickEvent", &UUI_MainRoom::execRecvButtonClickEvent },
			{ "RefreshPlayerButtonClickEvent", &UUI_MainRoom::execRefreshPlayerButtonClickEvent },
			{ "RefreshRoomButtonClickEvent", &UUI_MainRoom::execRefreshRoomButtonClickEvent },
			{ "RequestDestroyRoom", &UUI_MainRoom::execRequestDestroyRoom },
			{ "RequestJoinRoom", &UUI_MainRoom::execRequestJoinRoom },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UUI_MainRoom_CloseButtonClickEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_MainRoom_CloseButtonClickEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_MainRoom.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_MainRoom_CloseButtonClickEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_MainRoom, nullptr, "CloseButtonClickEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_MainRoom_CloseButtonClickEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_MainRoom_CloseButtonClickEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_MainRoom_CloseButtonClickEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_MainRoom_CloseButtonClickEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_MainRoom_CreateRoomButtonClickEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_MainRoom_CreateRoomButtonClickEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_MainRoom.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_MainRoom_CreateRoomButtonClickEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_MainRoom, nullptr, "CreateRoomButtonClickEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_MainRoom_CreateRoomButtonClickEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_MainRoom_CreateRoomButtonClickEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_MainRoom_CreateRoomButtonClickEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_MainRoom_CreateRoomButtonClickEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_MainRoom_ReadySendMessage_Statics
	{
		struct UI_MainRoom_eventReadySendMessage_Parms
		{
			FString playerName;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_playerName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_playerName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_MainRoom_ReadySendMessage_Statics::NewProp_playerName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_MainRoom_ReadySendMessage_Statics::NewProp_playerName = { "playerName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UI_MainRoom_eventReadySendMessage_Parms, playerName), METADATA_PARAMS(Z_Construct_UFunction_UUI_MainRoom_ReadySendMessage_Statics::NewProp_playerName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_MainRoom_ReadySendMessage_Statics::NewProp_playerName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_MainRoom_ReadySendMessage_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_MainRoom_ReadySendMessage_Statics::NewProp_playerName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_MainRoom_ReadySendMessage_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// Delegate\n// ??\xc6\xae??\xc5\xa9???? ?\xde\xbd??? ???? ??\xc3\xbb\n" },
		{ "ModuleRelativePath", "UI_MainRoom.h" },
		{ "ToolTip", "Delegate\n??\xc6\xae??\xc5\xa9???? ?\xde\xbd??? ???? ??\xc3\xbb" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_MainRoom_ReadySendMessage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_MainRoom, nullptr, "ReadySendMessage", nullptr, nullptr, sizeof(UI_MainRoom_eventReadySendMessage_Parms), Z_Construct_UFunction_UUI_MainRoom_ReadySendMessage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_MainRoom_ReadySendMessage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_MainRoom_ReadySendMessage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_MainRoom_ReadySendMessage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_MainRoom_ReadySendMessage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_MainRoom_ReadySendMessage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_MainRoom_RecvButtonClickEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_MainRoom_RecvButtonClickEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_MainRoom.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_MainRoom_RecvButtonClickEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_MainRoom, nullptr, "RecvButtonClickEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_MainRoom_RecvButtonClickEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_MainRoom_RecvButtonClickEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_MainRoom_RecvButtonClickEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_MainRoom_RecvButtonClickEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_MainRoom_RefreshPlayerButtonClickEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_MainRoom_RefreshPlayerButtonClickEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_MainRoom.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_MainRoom_RefreshPlayerButtonClickEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_MainRoom, nullptr, "RefreshPlayerButtonClickEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_MainRoom_RefreshPlayerButtonClickEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_MainRoom_RefreshPlayerButtonClickEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_MainRoom_RefreshPlayerButtonClickEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_MainRoom_RefreshPlayerButtonClickEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_MainRoom_RefreshRoomButtonClickEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_MainRoom_RefreshRoomButtonClickEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_MainRoom.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_MainRoom_RefreshRoomButtonClickEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_MainRoom, nullptr, "RefreshRoomButtonClickEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_MainRoom_RefreshRoomButtonClickEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_MainRoom_RefreshRoomButtonClickEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_MainRoom_RefreshRoomButtonClickEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_MainRoom_RefreshRoomButtonClickEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_MainRoom_RequestDestroyRoom_Statics
	{
		struct UI_MainRoom_eventRequestDestroyRoom_Parms
		{
			int32 roomNumber;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_roomNumber_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_roomNumber;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_MainRoom_RequestDestroyRoom_Statics::NewProp_roomNumber_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UUI_MainRoom_RequestDestroyRoom_Statics::NewProp_roomNumber = { "roomNumber", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UI_MainRoom_eventRequestDestroyRoom_Parms, roomNumber), METADATA_PARAMS(Z_Construct_UFunction_UUI_MainRoom_RequestDestroyRoom_Statics::NewProp_roomNumber_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_MainRoom_RequestDestroyRoom_Statics::NewProp_roomNumber_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_MainRoom_RequestDestroyRoom_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_MainRoom_RequestDestroyRoom_Statics::NewProp_roomNumber,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_MainRoom_RequestDestroyRoom_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_MainRoom.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_MainRoom_RequestDestroyRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_MainRoom, nullptr, "RequestDestroyRoom", nullptr, nullptr, sizeof(UI_MainRoom_eventRequestDestroyRoom_Parms), Z_Construct_UFunction_UUI_MainRoom_RequestDestroyRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_MainRoom_RequestDestroyRoom_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_MainRoom_RequestDestroyRoom_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_MainRoom_RequestDestroyRoom_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_MainRoom_RequestDestroyRoom()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_MainRoom_RequestDestroyRoom_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_MainRoom_RequestJoinRoom_Statics
	{
		struct UI_MainRoom_eventRequestJoinRoom_Parms
		{
			int32 roomNumber;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_roomNumber_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_roomNumber;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_MainRoom_RequestJoinRoom_Statics::NewProp_roomNumber_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UUI_MainRoom_RequestJoinRoom_Statics::NewProp_roomNumber = { "roomNumber", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UI_MainRoom_eventRequestJoinRoom_Parms, roomNumber), METADATA_PARAMS(Z_Construct_UFunction_UUI_MainRoom_RequestJoinRoom_Statics::NewProp_roomNumber_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_MainRoom_RequestJoinRoom_Statics::NewProp_roomNumber_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_MainRoom_RequestJoinRoom_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_MainRoom_RequestJoinRoom_Statics::NewProp_roomNumber,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_MainRoom_RequestJoinRoom_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_MainRoom.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_MainRoom_RequestJoinRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_MainRoom, nullptr, "RequestJoinRoom", nullptr, nullptr, sizeof(UI_MainRoom_eventRequestJoinRoom_Parms), Z_Construct_UFunction_UUI_MainRoom_RequestJoinRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_MainRoom_RequestJoinRoom_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_MainRoom_RequestJoinRoom_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_MainRoom_RequestJoinRoom_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_MainRoom_RequestJoinRoom()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_MainRoom_RequestJoinRoom_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UUI_MainRoom_NoRegister()
	{
		return UUI_MainRoom::StaticClass();
	}
	struct Z_Construct_UClass_UUI_MainRoom_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_createRoomWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_createRoomWidgetClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_roomNameLabelClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_roomNameLabelClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_playerNameLabelClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_playerNameLabelClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_chatTextClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_chatTextClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_MainRoom_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UUI_MainRoom_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UUI_MainRoom_CloseButtonClickEvent, "CloseButtonClickEvent" }, // 3133730557
		{ &Z_Construct_UFunction_UUI_MainRoom_CreateRoomButtonClickEvent, "CreateRoomButtonClickEvent" }, // 2058525764
		{ &Z_Construct_UFunction_UUI_MainRoom_ReadySendMessage, "ReadySendMessage" }, // 708890352
		{ &Z_Construct_UFunction_UUI_MainRoom_RecvButtonClickEvent, "RecvButtonClickEvent" }, // 402214869
		{ &Z_Construct_UFunction_UUI_MainRoom_RefreshPlayerButtonClickEvent, "RefreshPlayerButtonClickEvent" }, // 2985270702
		{ &Z_Construct_UFunction_UUI_MainRoom_RefreshRoomButtonClickEvent, "RefreshRoomButtonClickEvent" }, // 3235544521
		{ &Z_Construct_UFunction_UUI_MainRoom_RequestDestroyRoom, "RequestDestroyRoom" }, // 1320597132
		{ &Z_Construct_UFunction_UUI_MainRoom_RequestJoinRoom, "RequestJoinRoom" }, // 3923244717
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_MainRoom_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "UI_MainRoom.h" },
		{ "ModuleRelativePath", "UI_MainRoom.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_createRoomWidgetClass_MetaData[] = {
		{ "Category", "Widgets" },
		{ "Comment", "// ?? ???? ??\xc6\xb0 \xc5\xac???? ?\xcb\xbe???\xc5\xb3 ?? ???? UI ????\n" },
		{ "ModuleRelativePath", "UI_MainRoom.h" },
		{ "ToolTip", "?? ???? ??\xc6\xb0 \xc5\xac???? ?\xcb\xbe???\xc5\xb3 ?? ???? UI ????" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_createRoomWidgetClass = { "createRoomWidgetClass", nullptr, (EPropertyFlags)0x0044000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UUI_MainRoom, createRoomWidgetClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_createRoomWidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_createRoomWidgetClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_roomNameLabelClass_MetaData[] = {
		{ "Category", "Widgets" },
		{ "Comment", "// ?? ???? ??\xc5\xa9?? ?\xda\xbd??? ?\xdf\xb0??\xc7\xb4? ?????? ???\xc3\xb8?\n" },
		{ "ModuleRelativePath", "UI_MainRoom.h" },
		{ "ToolTip", "?? ???? ??\xc5\xa9?? ?\xda\xbd??? ?\xdf\xb0??\xc7\xb4? ?????? ???\xc3\xb8?" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_roomNameLabelClass = { "roomNameLabelClass", nullptr, (EPropertyFlags)0x0044000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UUI_MainRoom, roomNameLabelClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_roomNameLabelClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_roomNameLabelClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_playerNameLabelClass_MetaData[] = {
		{ "Category", "Widgets" },
		{ "Comment", "// ?\xc3\xb7??\xcc\xbe? ??\xc5\xa9?\xd1\xb9\xda\xbd??? \xc7\xa5?\xc3\xb5? ?????? ???\xc3\xb8?\n" },
		{ "ModuleRelativePath", "UI_MainRoom.h" },
		{ "ToolTip", "?\xc3\xb7??\xcc\xbe? ??\xc5\xa9?\xd1\xb9\xda\xbd??? \xc7\xa5?\xc3\xb5? ?????? ???\xc3\xb8?" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_playerNameLabelClass = { "playerNameLabelClass", nullptr, (EPropertyFlags)0x0044000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UUI_MainRoom, playerNameLabelClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_playerNameLabelClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_playerNameLabelClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_chatTextClass_MetaData[] = {
		{ "Category", "Widgets" },
		{ "Comment", "// \xc3\xa4??\xc3\xa2 ???? ???\xd9\xbf? ???? UI ???\xc3\xb8?\n" },
		{ "ModuleRelativePath", "UI_MainRoom.h" },
		{ "ToolTip", "\xc3\xa4??\xc3\xa2 ???? ???\xd9\xbf? ???? UI ???\xc3\xb8?" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_chatTextClass = { "chatTextClass", nullptr, (EPropertyFlags)0x0044000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UUI_MainRoom, chatTextClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_chatTextClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_chatTextClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUI_MainRoom_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_createRoomWidgetClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_roomNameLabelClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_playerNameLabelClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_chatTextClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_MainRoom_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_MainRoom>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUI_MainRoom_Statics::ClassParams = {
		&UUI_MainRoom::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UUI_MainRoom_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UUI_MainRoom_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UUI_MainRoom_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_MainRoom_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_MainRoom()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUI_MainRoom_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUI_MainRoom, 2177323063);
	template<> CHATCLIENT_API UClass* StaticClass<UUI_MainRoom>()
	{
		return UUI_MainRoom::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUI_MainRoom(Z_Construct_UClass_UUI_MainRoom, &UUI_MainRoom::StaticClass, TEXT("/Script/ChatClient"), TEXT("UUI_MainRoom"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_MainRoom);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
