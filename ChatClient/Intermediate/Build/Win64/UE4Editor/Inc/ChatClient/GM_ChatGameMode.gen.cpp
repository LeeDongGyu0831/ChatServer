// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/GM_ChatGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGM_ChatGameMode() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_AGM_ChatGameMode_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_AGM_ChatGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
// End Cross Module References
	void AGM_ChatGameMode::StaticRegisterNativesAGM_ChatGameMode()
	{
	}
	UClass* Z_Construct_UClass_AGM_ChatGameMode_NoRegister()
	{
		return AGM_ChatGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AGM_ChatGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGM_ChatGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGM_ChatGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "GM_ChatGameMode.h" },
		{ "ModuleRelativePath", "GM_ChatGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGM_ChatGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGM_ChatGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGM_ChatGameMode_Statics::ClassParams = {
		&AGM_ChatGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AGM_ChatGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGM_ChatGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGM_ChatGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGM_ChatGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGM_ChatGameMode, 3518006139);
	template<> CHATCLIENT_API UClass* StaticClass<AGM_ChatGameMode>()
	{
		return AGM_ChatGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGM_ChatGameMode(Z_Construct_UClass_AGM_ChatGameMode, &AGM_ChatGameMode::StaticClass, TEXT("/Script/ChatClient"), TEXT("AGM_ChatGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGM_ChatGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
