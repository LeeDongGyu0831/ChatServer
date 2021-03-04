// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/UI_ChatRoom.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_ChatRoom() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_ChatRoom_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_ChatRoom();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UUI_ChatRoom::execRequestDestroyRoom)
	{
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_roomNumber);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RequestDestroyRoom(Z_Param_Out_roomNumber);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_ChatRoom::execRequestLeaveRoom)
	{
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_roomNumber);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RequestLeaveRoom(Z_Param_Out_roomNumber);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_ChatRoom::execReadySendMessage)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_playerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ReadySendMessage(Z_Param_playerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_ChatRoom::execDestroyRoomButtonClickEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DestroyRoomButtonClickEvent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_ChatRoom::execCloseButtonClickEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CloseButtonClickEvent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_ChatRoom::execLeaveRoomButtonClickEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->LeaveRoomButtonClickEvent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_ChatRoom::execRefreshPlayerButtonClickEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RefreshPlayerButtonClickEvent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_ChatRoom::execRecvButtonClickEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RecvButtonClickEvent();
		P_NATIVE_END;
	}
	void UUI_ChatRoom::StaticRegisterNativesUUI_ChatRoom()
	{
		UClass* Class = UUI_ChatRoom::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CloseButtonClickEvent", &UUI_ChatRoom::execCloseButtonClickEvent },
			{ "DestroyRoomButtonClickEvent", &UUI_ChatRoom::execDestroyRoomButtonClickEvent },
			{ "LeaveRoomButtonClickEvent", &UUI_ChatRoom::execLeaveRoomButtonClickEvent },
			{ "ReadySendMessage", &UUI_ChatRoom::execReadySendMessage },
			{ "RecvButtonClickEvent", &UUI_ChatRoom::execRecvButtonClickEvent },
			{ "RefreshPlayerButtonClickEvent", &UUI_ChatRoom::execRefreshPlayerButtonClickEvent },
			{ "RequestDestroyRoom", &UUI_ChatRoom::execRequestDestroyRoom },
			{ "RequestLeaveRoom", &UUI_ChatRoom::execRequestLeaveRoom },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UUI_ChatRoom_CloseButtonClickEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_ChatRoom_CloseButtonClickEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_ChatRoom.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_ChatRoom_CloseButtonClickEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_ChatRoom, nullptr, "CloseButtonClickEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_ChatRoom_CloseButtonClickEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_ChatRoom_CloseButtonClickEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_ChatRoom_CloseButtonClickEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_ChatRoom_CloseButtonClickEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_ChatRoom_DestroyRoomButtonClickEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_ChatRoom_DestroyRoomButtonClickEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_ChatRoom.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_ChatRoom_DestroyRoomButtonClickEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_ChatRoom, nullptr, "DestroyRoomButtonClickEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_ChatRoom_DestroyRoomButtonClickEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_ChatRoom_DestroyRoomButtonClickEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_ChatRoom_DestroyRoomButtonClickEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_ChatRoom_DestroyRoomButtonClickEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_ChatRoom_LeaveRoomButtonClickEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_ChatRoom_LeaveRoomButtonClickEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_ChatRoom.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_ChatRoom_LeaveRoomButtonClickEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_ChatRoom, nullptr, "LeaveRoomButtonClickEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_ChatRoom_LeaveRoomButtonClickEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_ChatRoom_LeaveRoomButtonClickEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_ChatRoom_LeaveRoomButtonClickEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_ChatRoom_LeaveRoomButtonClickEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_ChatRoom_ReadySendMessage_Statics
	{
		struct UI_ChatRoom_eventReadySendMessage_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_ChatRoom_ReadySendMessage_Statics::NewProp_playerName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUI_ChatRoom_ReadySendMessage_Statics::NewProp_playerName = { "playerName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UI_ChatRoom_eventReadySendMessage_Parms, playerName), METADATA_PARAMS(Z_Construct_UFunction_UUI_ChatRoom_ReadySendMessage_Statics::NewProp_playerName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_ChatRoom_ReadySendMessage_Statics::NewProp_playerName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_ChatRoom_ReadySendMessage_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_ChatRoom_ReadySendMessage_Statics::NewProp_playerName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_ChatRoom_ReadySendMessage_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// Delegate\n// ??\xc6\xae??\xc5\xa9???? ?\xde\xbd??? ???? ??\xc3\xbb\n" },
		{ "ModuleRelativePath", "UI_ChatRoom.h" },
		{ "ToolTip", "Delegate\n??\xc6\xae??\xc5\xa9???? ?\xde\xbd??? ???? ??\xc3\xbb" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_ChatRoom_ReadySendMessage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_ChatRoom, nullptr, "ReadySendMessage", nullptr, nullptr, sizeof(UI_ChatRoom_eventReadySendMessage_Parms), Z_Construct_UFunction_UUI_ChatRoom_ReadySendMessage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_ChatRoom_ReadySendMessage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_ChatRoom_ReadySendMessage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_ChatRoom_ReadySendMessage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_ChatRoom_ReadySendMessage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_ChatRoom_ReadySendMessage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_ChatRoom_RecvButtonClickEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_ChatRoom_RecvButtonClickEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_ChatRoom.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_ChatRoom_RecvButtonClickEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_ChatRoom, nullptr, "RecvButtonClickEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_ChatRoom_RecvButtonClickEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_ChatRoom_RecvButtonClickEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_ChatRoom_RecvButtonClickEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_ChatRoom_RecvButtonClickEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_ChatRoom_RefreshPlayerButtonClickEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_ChatRoom_RefreshPlayerButtonClickEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_ChatRoom.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_ChatRoom_RefreshPlayerButtonClickEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_ChatRoom, nullptr, "RefreshPlayerButtonClickEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_ChatRoom_RefreshPlayerButtonClickEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_ChatRoom_RefreshPlayerButtonClickEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_ChatRoom_RefreshPlayerButtonClickEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_ChatRoom_RefreshPlayerButtonClickEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_ChatRoom_RequestDestroyRoom_Statics
	{
		struct UI_ChatRoom_eventRequestDestroyRoom_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_ChatRoom_RequestDestroyRoom_Statics::NewProp_roomNumber_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UUI_ChatRoom_RequestDestroyRoom_Statics::NewProp_roomNumber = { "roomNumber", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UI_ChatRoom_eventRequestDestroyRoom_Parms, roomNumber), METADATA_PARAMS(Z_Construct_UFunction_UUI_ChatRoom_RequestDestroyRoom_Statics::NewProp_roomNumber_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_ChatRoom_RequestDestroyRoom_Statics::NewProp_roomNumber_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_ChatRoom_RequestDestroyRoom_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_ChatRoom_RequestDestroyRoom_Statics::NewProp_roomNumber,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_ChatRoom_RequestDestroyRoom_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_ChatRoom.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_ChatRoom_RequestDestroyRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_ChatRoom, nullptr, "RequestDestroyRoom", nullptr, nullptr, sizeof(UI_ChatRoom_eventRequestDestroyRoom_Parms), Z_Construct_UFunction_UUI_ChatRoom_RequestDestroyRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_ChatRoom_RequestDestroyRoom_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_ChatRoom_RequestDestroyRoom_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_ChatRoom_RequestDestroyRoom_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_ChatRoom_RequestDestroyRoom()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_ChatRoom_RequestDestroyRoom_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_ChatRoom_RequestLeaveRoom_Statics
	{
		struct UI_ChatRoom_eventRequestLeaveRoom_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_ChatRoom_RequestLeaveRoom_Statics::NewProp_roomNumber_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UUI_ChatRoom_RequestLeaveRoom_Statics::NewProp_roomNumber = { "roomNumber", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UI_ChatRoom_eventRequestLeaveRoom_Parms, roomNumber), METADATA_PARAMS(Z_Construct_UFunction_UUI_ChatRoom_RequestLeaveRoom_Statics::NewProp_roomNumber_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_ChatRoom_RequestLeaveRoom_Statics::NewProp_roomNumber_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_ChatRoom_RequestLeaveRoom_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_ChatRoom_RequestLeaveRoom_Statics::NewProp_roomNumber,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_ChatRoom_RequestLeaveRoom_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_ChatRoom.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_ChatRoom_RequestLeaveRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_ChatRoom, nullptr, "RequestLeaveRoom", nullptr, nullptr, sizeof(UI_ChatRoom_eventRequestLeaveRoom_Parms), Z_Construct_UFunction_UUI_ChatRoom_RequestLeaveRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_ChatRoom_RequestLeaveRoom_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_ChatRoom_RequestLeaveRoom_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_ChatRoom_RequestLeaveRoom_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_ChatRoom_RequestLeaveRoom()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_ChatRoom_RequestLeaveRoom_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UUI_ChatRoom_NoRegister()
	{
		return UUI_ChatRoom::StaticClass();
	}
	struct Z_Construct_UClass_UUI_ChatRoom_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
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
	UObject* (*const Z_Construct_UClass_UUI_ChatRoom_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UUI_ChatRoom_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UUI_ChatRoom_CloseButtonClickEvent, "CloseButtonClickEvent" }, // 1690758048
		{ &Z_Construct_UFunction_UUI_ChatRoom_DestroyRoomButtonClickEvent, "DestroyRoomButtonClickEvent" }, // 3385946934
		{ &Z_Construct_UFunction_UUI_ChatRoom_LeaveRoomButtonClickEvent, "LeaveRoomButtonClickEvent" }, // 3431845259
		{ &Z_Construct_UFunction_UUI_ChatRoom_ReadySendMessage, "ReadySendMessage" }, // 849122340
		{ &Z_Construct_UFunction_UUI_ChatRoom_RecvButtonClickEvent, "RecvButtonClickEvent" }, // 3094658365
		{ &Z_Construct_UFunction_UUI_ChatRoom_RefreshPlayerButtonClickEvent, "RefreshPlayerButtonClickEvent" }, // 854867787
		{ &Z_Construct_UFunction_UUI_ChatRoom_RequestDestroyRoom, "RequestDestroyRoom" }, // 3817906563
		{ &Z_Construct_UFunction_UUI_ChatRoom_RequestLeaveRoom, "RequestLeaveRoom" }, // 1478836812
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_ChatRoom_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "UI_ChatRoom.h" },
		{ "ModuleRelativePath", "UI_ChatRoom.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_ChatRoom_Statics::NewProp_playerNameLabelClass_MetaData[] = {
		{ "Category", "Widgets" },
		{ "Comment", "// ?\xc3\xb7??\xcc\xbe? ??\xc5\xa9?\xd1\xb9\xda\xbd??? \xc7\xa5?\xc3\xb5? ?????? ???\xc3\xb8?\n" },
		{ "ModuleRelativePath", "UI_ChatRoom.h" },
		{ "ToolTip", "?\xc3\xb7??\xcc\xbe? ??\xc5\xa9?\xd1\xb9\xda\xbd??? \xc7\xa5?\xc3\xb5? ?????? ???\xc3\xb8?" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_ChatRoom_Statics::NewProp_playerNameLabelClass = { "playerNameLabelClass", nullptr, (EPropertyFlags)0x0044000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UUI_ChatRoom, playerNameLabelClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UUI_ChatRoom_Statics::NewProp_playerNameLabelClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_ChatRoom_Statics::NewProp_playerNameLabelClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_ChatRoom_Statics::NewProp_chatTextClass_MetaData[] = {
		{ "Category", "Widgets" },
		{ "Comment", "// \xc3\xa4??\xc3\xa2 ???? ???\xd9\xbf? ???? UI ???\xc3\xb8?\n" },
		{ "ModuleRelativePath", "UI_ChatRoom.h" },
		{ "ToolTip", "\xc3\xa4??\xc3\xa2 ???? ???\xd9\xbf? ???? UI ???\xc3\xb8?" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_ChatRoom_Statics::NewProp_chatTextClass = { "chatTextClass", nullptr, (EPropertyFlags)0x0044000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UUI_ChatRoom, chatTextClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UUI_ChatRoom_Statics::NewProp_chatTextClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_ChatRoom_Statics::NewProp_chatTextClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUI_ChatRoom_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_ChatRoom_Statics::NewProp_playerNameLabelClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_ChatRoom_Statics::NewProp_chatTextClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_ChatRoom_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_ChatRoom>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUI_ChatRoom_Statics::ClassParams = {
		&UUI_ChatRoom::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UUI_ChatRoom_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UUI_ChatRoom_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UUI_ChatRoom_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_ChatRoom_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_ChatRoom()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUI_ChatRoom_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUI_ChatRoom, 56542079);
	template<> CHATCLIENT_API UClass* StaticClass<UUI_ChatRoom>()
	{
		return UUI_ChatRoom::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUI_ChatRoom(Z_Construct_UClass_UUI_ChatRoom, &UUI_ChatRoom::StaticClass, TEXT("/Script/ChatClient"), TEXT("UUI_ChatRoom"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_ChatRoom);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
