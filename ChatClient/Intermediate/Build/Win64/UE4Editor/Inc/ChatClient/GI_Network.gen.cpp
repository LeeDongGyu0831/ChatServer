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
	CHATCLIENT_API UClass* Z_Construct_UClass_UGI_Network_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_UGI_Network();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
// End Cross Module References
	DEFINE_FUNCTION(UGI_Network::execConnectToServer)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strIP);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_nPort);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ConnectToServer(Z_Param_strIP,Z_Param_Out_nPort);
		P_NATIVE_END;
	}
	void UGI_Network::StaticRegisterNativesUGI_Network()
	{
		UClass* Class = UGI_Network::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ConnectToServer", &UGI_Network::execConnectToServer },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics
	{
		struct GI_Network_eventConnectToServer_Parms
		{
			FString strIP;
			int32 nPort;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_nPort_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_nPort;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_strIP_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_strIP;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::NewProp_nPort_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::NewProp_nPort = { "nPort", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GI_Network_eventConnectToServer_Parms, nPort), METADATA_PARAMS(Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::NewProp_nPort_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::NewProp_nPort_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::NewProp_strIP_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::NewProp_strIP = { "strIP", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GI_Network_eventConnectToServer_Parms, strIP), METADATA_PARAMS(Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::NewProp_strIP_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::NewProp_strIP_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::NewProp_nPort,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::NewProp_strIP,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::Function_MetaDataParams[] = {
		{ "Category", "Socket" },
		{ "ModuleRelativePath", "GI_Network.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGI_Network, nullptr, "ConnectToServer", nullptr, nullptr, sizeof(GI_Network_eventConnectToServer_Parms), Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGI_Network_ConnectToServer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGI_Network_ConnectToServer_Statics::FuncParams);
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
		{ &Z_Construct_UFunction_UGI_Network_ConnectToServer, "ConnectToServer" }, // 1637710719
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGI_Network_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
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
	IMPLEMENT_CLASS(UGI_Network, 1956458403);
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
