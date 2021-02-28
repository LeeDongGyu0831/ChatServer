// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/ChatPawn.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChatPawn() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_AChatPawn_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_AChatPawn();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
// End Cross Module References
	void AChatPawn::StaticRegisterNativesAChatPawn()
	{
	}
	UClass* Z_Construct_UClass_AChatPawn_NoRegister()
	{
		return AChatPawn::StaticClass();
	}
	struct Z_Construct_UClass_AChatPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AChatPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChatPawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ChatPawn.h" },
		{ "ModuleRelativePath", "ChatPawn.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AChatPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AChatPawn>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AChatPawn_Statics::ClassParams = {
		&AChatPawn::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AChatPawn_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AChatPawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AChatPawn()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AChatPawn_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AChatPawn, 641845911);
	template<> CHATCLIENT_API UClass* StaticClass<AChatPawn>()
	{
		return AChatPawn::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AChatPawn(Z_Construct_UClass_AChatPawn, &AChatPawn::StaticClass, TEXT("/Script/ChatClient"), TEXT("AChatPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AChatPawn);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
