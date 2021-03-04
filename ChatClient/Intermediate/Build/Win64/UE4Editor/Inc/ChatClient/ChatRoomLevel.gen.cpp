// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/ChatRoomLevel.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChatRoomLevel() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_AChatRoomLevel_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_AChatRoomLevel();
	ENGINE_API UClass* Z_Construct_UClass_ALevelScriptActor();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
// End Cross Module References
	void AChatRoomLevel::StaticRegisterNativesAChatRoomLevel()
	{
	}
	UClass* Z_Construct_UClass_AChatRoomLevel_NoRegister()
	{
		return AChatRoomLevel::StaticClass();
	}
	struct Z_Construct_UClass_AChatRoomLevel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_chatRoomClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_chatRoomClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AChatRoomLevel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ALevelScriptActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChatRoomLevel_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "ChatRoomLevel.h" },
		{ "ModuleRelativePath", "ChatRoomLevel.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChatRoomLevel_Statics::NewProp_chatRoomClass_MetaData[] = {
		{ "Category", "Widgets" },
		{ "Comment", "// ???? ?? ???????? \xc7\xa5???? UI ????\n" },
		{ "ModuleRelativePath", "ChatRoomLevel.h" },
		{ "ToolTip", "???? ?? ???????? \xc7\xa5???? UI ????" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AChatRoomLevel_Statics::NewProp_chatRoomClass = { "chatRoomClass", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AChatRoomLevel, chatRoomClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AChatRoomLevel_Statics::NewProp_chatRoomClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AChatRoomLevel_Statics::NewProp_chatRoomClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AChatRoomLevel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChatRoomLevel_Statics::NewProp_chatRoomClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AChatRoomLevel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AChatRoomLevel>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AChatRoomLevel_Statics::ClassParams = {
		&AChatRoomLevel::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AChatRoomLevel_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AChatRoomLevel_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AChatRoomLevel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AChatRoomLevel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AChatRoomLevel()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AChatRoomLevel_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AChatRoomLevel, 1637342630);
	template<> CHATCLIENT_API UClass* StaticClass<AChatRoomLevel>()
	{
		return AChatRoomLevel::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AChatRoomLevel(Z_Construct_UClass_AChatRoomLevel, &AChatRoomLevel::StaticClass, TEXT("/Script/ChatClient"), TEXT("AChatRoomLevel"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AChatRoomLevel);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
