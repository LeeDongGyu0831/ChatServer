// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/GI_Network.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGI_Network() {}
// Cross Module References
	CHATCLIENT_API UEnum* Z_Construct_UEnum_ChatClient_MSG_TYPE();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
	CHATCLIENT_API UClass* Z_Construct_UClass_UGI_Network_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_UGI_Network();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
// End Cross Module References
	static UEnum* MSG_TYPE_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ChatClient_MSG_TYPE, Z_Construct_UPackage__Script_ChatClient(), TEXT("MSG_TYPE"));
		}
		return Singleton;
	}
	template<> CHATCLIENT_API UEnum* StaticEnum<MSG_TYPE>()
	{
		return MSG_TYPE_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_MSG_TYPE(MSG_TYPE_StaticEnum, TEXT("/Script/ChatClient"), TEXT("MSG_TYPE"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ChatClient_MSG_TYPE_Hash() { return 298377558U; }
	UEnum* Z_Construct_UEnum_ChatClient_MSG_TYPE()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ChatClient();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("MSG_TYPE"), 0, Get_Z_Construct_UEnum_ChatClient_MSG_TYPE_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "MSG_TYPE::JOIN", (int64)MSG_TYPE::JOIN },
				{ "MSG_TYPE::CHAT", (int64)MSG_TYPE::CHAT },
				{ "MSG_TYPE::EXIT", (int64)MSG_TYPE::EXIT },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "CHAT.DisplayName", "CHAT" },
				{ "CHAT.Name", "MSG_TYPE::CHAT" },
				{ "Comment", "/**\n * \xec\x82\xac\xec\x9a\xa9\xec\x9e\x90 \xec\xa0\x95\xec\x9d\x98 \xea\xb2\x8c\xec\x9e\x84 \xec\x9d\xb8\xec\x8a\xa4\xed\x84\xb4\xec\x8a\xa4\n * \xec\x9d\xb4\xea\xb3\xb3\xec\x97\x90\xec\x84\x9c \xeb\x84\xa4\xed\x8a\xb8\xec\x9b\x8c\xed\x81\xac \xec\x97\xb0\xea\xb2\xb0\xec\x9d\x84 \xea\xb4\x80\xeb\xa6\xac\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4.\n */// \xeb\xa9\x94\xec\x8b\x9c\xec\xa7\x80\xeb\xa5\xbc \xeb\xb6\x84\xec\x84\x9d\xed\x95\x98\xea\xb3\xa0\xeb\x82\x9c \xed\x9b\x84 \xed\x95\xb4\xeb\x8b\xb9 \xeb\xa9\x94\xec\x8b\x9c\xec\xa7\x80\xea\xb0\x80 \xec\x84\x9c\xeb\xb2\x84 \xeb\xaa\x85\xeb\xa0\xb9\xec\x9d\xb8\xec\xa7\x80 \xec\xb1\x84\xed\x8c\x85\xec\x9d\xb8\xec\xa7\x80 \xea\xb5\xac\xeb\xb6\x84\xed\x95\x98\xea\xb8\xb0 \xec\x9c\x84\xed\x95\xa8\n" },
				{ "EXIT.DisplayName", "EXIT" },
				{ "EXIT.Name", "MSG_TYPE::EXIT" },
				{ "JOIN.DisplayName", "JOIN" },
				{ "JOIN.Name", "MSG_TYPE::JOIN" },
				{ "ModuleRelativePath", "GI_Network.h" },
				{ "ToolTip", "\xec\x82\xac\xec\x9a\xa9\xec\x9e\x90 \xec\xa0\x95\xec\x9d\x98 \xea\xb2\x8c\xec\x9e\x84 \xec\x9d\xb8\xec\x8a\xa4\xed\x84\xb4\xec\x8a\xa4\n\xec\x9d\xb4\xea\xb3\xb3\xec\x97\x90\xec\x84\x9c \xeb\x84\xa4\xed\x8a\xb8\xec\x9b\x8c\xed\x81\xac \xec\x97\xb0\xea\xb2\xb0\xec\x9d\x84 \xea\xb4\x80\xeb\xa6\xac\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4.\n // \xeb\xa9\x94\xec\x8b\x9c\xec\xa7\x80\xeb\xa5\xbc \xeb\xb6\x84\xec\x84\x9d\xed\x95\x98\xea\xb3\xa0\xeb\x82\x9c \xed\x9b\x84 \xed\x95\xb4\xeb\x8b\xb9 \xeb\xa9\x94\xec\x8b\x9c\xec\xa7\x80\xea\xb0\x80 \xec\x84\x9c\xeb\xb2\x84 \xeb\xaa\x85\xeb\xa0\xb9\xec\x9d\xb8\xec\xa7\x80 \xec\xb1\x84\xed\x8c\x85\xec\x9d\xb8\xec\xa7\x80 \xea\xb5\xac\xeb\xb6\x84\xed\x95\x98\xea\xb8\xb0 \xec\x9c\x84\xed\x95\xa8" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ChatClient,
				nullptr,
				"MSG_TYPE",
				"MSG_TYPE",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	DEFINE_FUNCTION(UGI_Network::execCheckMessage)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_originString);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(MSG_TYPE*)Z_Param__Result=P_THIS->CheckMessage(Z_Param_originString);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGI_Network::execTrimMessage)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_originString);
		P_GET_PROPERTY(FStrProperty,Z_Param_subString);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->TrimMessage(Z_Param_originString,Z_Param_subString);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGI_Network::execSend)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_data);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Send(Z_Param_data);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGI_Network::execRecv)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->Recv();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGI_Network::execLoginToServer)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->LoginToServer();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGI_Network::execConnectToServer)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->ConnectToServer();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGI_Network::execRecvData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RecvData();
		P_NATIVE_END;
	}
	void UGI_Network::StaticRegisterNativesUGI_Network()
	{
		UClass* Class = UGI_Network::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CheckMessage", &UGI_Network::execCheckMessage },
			{ "ConnectToServer", &UGI_Network::execConnectToServer },
			{ "LoginToServer", &UGI_Network::execLoginToServer },
			{ "Recv", &UGI_Network::execRecv },
			{ "RecvData", &UGI_Network::execRecvData },
			{ "Send", &UGI_Network::execSend },
			{ "TrimMessage", &UGI_Network::execTrimMessage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGI_Network_CheckMessage_Statics
	{
		struct GI_Network_eventCheckMessage_Parms
		{
			FString originString;
			MSG_TYPE ReturnValue;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_originString;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UGI_Network_CheckMessage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GI_Network_eventCheckMessage_Parms, ReturnValue), Z_Construct_UEnum_ChatClient_MSG_TYPE, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UGI_Network_CheckMessage_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGI_Network_CheckMessage_Statics::NewProp_originString = { "originString", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GI_Network_eventCheckMessage_Parms, originString), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGI_Network_CheckMessage_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGI_Network_CheckMessage_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGI_Network_CheckMessage_Statics::NewProp_ReturnValue_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGI_Network_CheckMessage_Statics::NewProp_originString,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGI_Network_CheckMessage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Socket" },
		{ "Comment", "// \xea\xb0\x80\xec\x9e\xa5 \xec\x95\x9e\xec\x97\x90 /\xea\xb0\x80 \xeb\xb6\x99\xec\x96\xb4\xec\x9e\x88\xeb\x8a\x94 \xeb\xa9\x94\xec\x8b\x9c\xec\xa7\x80\xec\x9d\xb8\xec\xa7\x80 /\xea\xb0\x80 \xeb\xb6\x99\xec\x96\xb4\xec\x9e\x88\xeb\x8a\x94 \xeb\xa9\x94\xec\x8b\x9c\xec\xa7\x80\xeb\x9d\xbc\xeb\xa9\xb4 \xec\x9d\xbc\xeb\xb0\x98 \xec\xb1\x84\xed\x8c\x85 \xeb\xa9\x94\xec\x8b\x9c\xec\xa7\x80\xea\xb0\x80 \xec\x95\x84\xeb\x8b\x98\n" },
		{ "ModuleRelativePath", "GI_Network.h" },
		{ "ToolTip", "\xea\xb0\x80\xec\x9e\xa5 \xec\x95\x9e\xec\x97\x90 /\xea\xb0\x80 \xeb\xb6\x99\xec\x96\xb4\xec\x9e\x88\xeb\x8a\x94 \xeb\xa9\x94\xec\x8b\x9c\xec\xa7\x80\xec\x9d\xb8\xec\xa7\x80 /\xea\xb0\x80 \xeb\xb6\x99\xec\x96\xb4\xec\x9e\x88\xeb\x8a\x94 \xeb\xa9\x94\xec\x8b\x9c\xec\xa7\x80\xeb\x9d\xbc\xeb\xa9\xb4 \xec\x9d\xbc\xeb\xb0\x98 \xec\xb1\x84\xed\x8c\x85 \xeb\xa9\x94\xec\x8b\x9c\xec\xa7\x80\xea\xb0\x80 \xec\x95\x84\xeb\x8b\x98" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGI_Network_CheckMessage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGI_Network, nullptr, "CheckMessage", nullptr, nullptr, sizeof(GI_Network_eventCheckMessage_Parms), Z_Construct_UFunction_UGI_Network_CheckMessage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_CheckMessage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGI_Network_CheckMessage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_CheckMessage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGI_Network_CheckMessage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGI_Network_CheckMessage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics
	{
		struct GI_Network_eventConnectToServer_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((GI_Network_eventConnectToServer_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(GI_Network_eventConnectToServer_Parms), &Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::Function_MetaDataParams[] = {
		{ "Category", "Socket" },
		{ "ModuleRelativePath", "GI_Network.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGI_Network, nullptr, "ConnectToServer", nullptr, nullptr, sizeof(GI_Network_eventConnectToServer_Parms), Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGI_Network_ConnectToServer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGI_Network_LoginToServer_Statics
	{
		struct GI_Network_eventLoginToServer_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UGI_Network_LoginToServer_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((GI_Network_eventLoginToServer_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGI_Network_LoginToServer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(GI_Network_eventLoginToServer_Parms), &Z_Construct_UFunction_UGI_Network_LoginToServer_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGI_Network_LoginToServer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGI_Network_LoginToServer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGI_Network_LoginToServer_Statics::Function_MetaDataParams[] = {
		{ "Category", "Socket" },
		{ "ModuleRelativePath", "GI_Network.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGI_Network_LoginToServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGI_Network, nullptr, "LoginToServer", nullptr, nullptr, sizeof(GI_Network_eventLoginToServer_Parms), Z_Construct_UFunction_UGI_Network_LoginToServer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_LoginToServer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGI_Network_LoginToServer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_LoginToServer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGI_Network_LoginToServer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGI_Network_LoginToServer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGI_Network_Recv_Statics
	{
		struct GI_Network_eventRecv_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGI_Network_Recv_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GI_Network_eventRecv_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGI_Network_Recv_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGI_Network_Recv_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGI_Network_Recv_Statics::Function_MetaDataParams[] = {
		{ "Category", "Socket" },
		{ "ModuleRelativePath", "GI_Network.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGI_Network_Recv_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGI_Network, nullptr, "Recv", nullptr, nullptr, sizeof(GI_Network_eventRecv_Parms), Z_Construct_UFunction_UGI_Network_Recv_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_Recv_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGI_Network_Recv_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_Recv_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGI_Network_Recv()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGI_Network_Recv_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGI_Network_RecvData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGI_Network_RecvData_Statics::Function_MetaDataParams[] = {
		{ "Category", "Socket" },
		{ "ModuleRelativePath", "GI_Network.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGI_Network_RecvData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGI_Network, nullptr, "RecvData", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGI_Network_RecvData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_RecvData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGI_Network_RecvData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGI_Network_RecvData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGI_Network_Send_Statics
	{
		struct GI_Network_eventSend_Parms
		{
			FString data;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_data_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_data;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UGI_Network_Send_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((GI_Network_eventSend_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGI_Network_Send_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(GI_Network_eventSend_Parms), &Z_Construct_UFunction_UGI_Network_Send_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGI_Network_Send_Statics::NewProp_data_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGI_Network_Send_Statics::NewProp_data = { "data", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GI_Network_eventSend_Parms, data), METADATA_PARAMS(Z_Construct_UFunction_UGI_Network_Send_Statics::NewProp_data_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_Send_Statics::NewProp_data_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGI_Network_Send_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGI_Network_Send_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGI_Network_Send_Statics::NewProp_data,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGI_Network_Send_Statics::Function_MetaDataParams[] = {
		{ "Category", "Socket" },
		{ "ModuleRelativePath", "GI_Network.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGI_Network_Send_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGI_Network, nullptr, "Send", nullptr, nullptr, sizeof(GI_Network_eventSend_Parms), Z_Construct_UFunction_UGI_Network_Send_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_Send_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGI_Network_Send_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_Send_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGI_Network_Send()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGI_Network_Send_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGI_Network_TrimMessage_Statics
	{
		struct GI_Network_eventTrimMessage_Parms
		{
			FString originString;
			FString subString;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_subString_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_subString;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_originString_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_originString;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GI_Network_eventTrimMessage_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::NewProp_subString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::NewProp_subString = { "subString", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GI_Network_eventTrimMessage_Parms, subString), METADATA_PARAMS(Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::NewProp_subString_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::NewProp_subString_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::NewProp_originString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::NewProp_originString = { "originString", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GI_Network_eventTrimMessage_Parms, originString), METADATA_PARAMS(Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::NewProp_originString_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::NewProp_originString_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::NewProp_subString,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::NewProp_originString,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Socket" },
		{ "Comment", "// \xec\x95\x9e \xeb\x92\xa4 \xea\xb3\xb5\xeb\xb0\xb1 + \xec\xa4\x84\xeb\xb0\x94\xea\xbf\x88 \xeb\xac\xb8\xec\x9e\x90 + >> \xeb\xac\xb8\xec\x9e\x90 \xec\xa0\x9c\xea\xb1\xb0\xec\x9a\xa9\n" },
		{ "ModuleRelativePath", "GI_Network.h" },
		{ "ToolTip", "\xec\x95\x9e \xeb\x92\xa4 \xea\xb3\xb5\xeb\xb0\xb1 + \xec\xa4\x84\xeb\xb0\x94\xea\xbf\x88 \xeb\xac\xb8\xec\x9e\x90 + >> \xeb\xac\xb8\xec\x9e\x90 \xec\xa0\x9c\xea\xb1\xb0\xec\x9a\xa9" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGI_Network, nullptr, "TrimMessage", nullptr, nullptr, sizeof(GI_Network_eventTrimMessage_Parms), Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGI_Network_TrimMessage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGI_Network_TrimMessage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UGI_Network_NoRegister()
	{
		return UGI_Network::StaticClass();
	}
	struct Z_Construct_UClass_UGI_Network_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGI_Network_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGI_Network_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGI_Network_CheckMessage, "CheckMessage" }, // 2304153383
		{ &Z_Construct_UFunction_UGI_Network_ConnectToServer, "ConnectToServer" }, // 3721457483
		{ &Z_Construct_UFunction_UGI_Network_LoginToServer, "LoginToServer" }, // 4128830343
		{ &Z_Construct_UFunction_UGI_Network_Recv, "Recv" }, // 2730677776
		{ &Z_Construct_UFunction_UGI_Network_RecvData, "RecvData" }, // 606035206
		{ &Z_Construct_UFunction_UGI_Network_Send, "Send" }, // 1992597702
		{ &Z_Construct_UFunction_UGI_Network_TrimMessage, "TrimMessage" }, // 2442498341
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGI_Network_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GI_Network.h" },
		{ "ModuleRelativePath", "GI_Network.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGI_Network_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGI_Network>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGI_Network_Statics::ClassParams = {
		&UGI_Network::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UGI_Network_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGI_Network_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGI_Network()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGI_Network_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGI_Network, 1450948283);
	template<> CHATCLIENT_API UClass* StaticClass<UGI_Network>()
	{
		return UGI_Network::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGI_Network(Z_Construct_UClass_UGI_Network, &UGI_Network::StaticClass, TEXT("/Script/ChatClient"), TEXT("UGI_Network"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGI_Network);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
