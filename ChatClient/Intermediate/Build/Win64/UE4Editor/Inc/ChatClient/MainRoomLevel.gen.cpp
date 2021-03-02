// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/MainRoomLevel.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMainRoomLevel() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_AMainRoomLevel_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_AMainRoomLevel();
	ENGINE_API UClass* Z_Construct_UClass_ALevelScriptActor();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
// End Cross Module References
	void AMainRoomLevel::StaticRegisterNativesAMainRoomLevel()
	{
	}
	UClass* Z_Construct_UClass_AMainRoomLevel_NoRegister()
	{
		return AMainRoomLevel::StaticClass();
	}
	struct Z_Construct_UClass_AMainRoomLevel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMainRoomLevel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ALevelScriptActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainRoomLevel_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "MainRoomLevel.h" },
		{ "ModuleRelativePath", "MainRoomLevel.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMainRoomLevel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMainRoomLevel>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMainRoomLevel_Statics::ClassParams = {
		&AMainRoomLevel::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AMainRoomLevel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMainRoomLevel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMainRoomLevel()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMainRoomLevel_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMainRoomLevel, 883330048);
	template<> CHATCLIENT_API UClass* StaticClass<AMainRoomLevel>()
	{
		return AMainRoomLevel::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMainRoomLevel(Z_Construct_UClass_AMainRoomLevel, &AMainRoomLevel::StaticClass, TEXT("/Script/ChatClient"), TEXT("AMainRoomLevel"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMainRoomLevel);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
