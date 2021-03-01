// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/PS_ChatState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePS_ChatState() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_APS_ChatState_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_APS_ChatState();
	ENGINE_API UClass* Z_Construct_UClass_APlayerState();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
// End Cross Module References
	void APS_ChatState::StaticRegisterNativesAPS_ChatState()
	{
	}
	UClass* Z_Construct_UClass_APS_ChatState_NoRegister()
	{
		return APS_ChatState::StaticClass();
	}
	struct Z_Construct_UClass_APS_ChatState_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APS_ChatState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerState,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APS_ChatState_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "PS_ChatState.h" },
		{ "ModuleRelativePath", "PS_ChatState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APS_ChatState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APS_ChatState>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APS_ChatState_Statics::ClassParams = {
		&APS_ChatState::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_APS_ChatState_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APS_ChatState_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APS_ChatState()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APS_ChatState_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APS_ChatState, 127467839);
	template<> CHATCLIENT_API UClass* StaticClass<APS_ChatState>()
	{
		return APS_ChatState::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APS_ChatState(Z_Construct_UClass_APS_ChatState, &APS_ChatState::StaticClass, TEXT("/Script/ChatClient"), TEXT("APS_ChatState"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APS_ChatState);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
