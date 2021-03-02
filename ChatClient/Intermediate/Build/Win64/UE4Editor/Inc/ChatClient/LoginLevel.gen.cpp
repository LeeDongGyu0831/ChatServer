// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/LoginLevel.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLoginLevel() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_ALoginLevel_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_ALoginLevel();
	ENGINE_API UClass* Z_Construct_UClass_ALevelScriptActor();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
// End Cross Module References
	void ALoginLevel::StaticRegisterNativesALoginLevel()
	{
	}
	UClass* Z_Construct_UClass_ALoginLevel_NoRegister()
	{
		return ALoginLevel::StaticClass();
	}
	struct Z_Construct_UClass_ALoginLevel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_connectLoginClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_connectLoginClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALoginLevel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ALevelScriptActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALoginLevel_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "LoginLevel.h" },
		{ "ModuleRelativePath", "LoginLevel.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALoginLevel_Statics::NewProp_connectLoginClass_MetaData[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "LoginLevel.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ALoginLevel_Statics::NewProp_connectLoginClass = { "connectLoginClass", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALoginLevel, connectLoginClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ALoginLevel_Statics::NewProp_connectLoginClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALoginLevel_Statics::NewProp_connectLoginClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALoginLevel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALoginLevel_Statics::NewProp_connectLoginClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALoginLevel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALoginLevel>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALoginLevel_Statics::ClassParams = {
		&ALoginLevel::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ALoginLevel_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ALoginLevel_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_ALoginLevel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ALoginLevel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALoginLevel()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALoginLevel_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALoginLevel, 1893870794);
	template<> CHATCLIENT_API UClass* StaticClass<ALoginLevel>()
	{
		return ALoginLevel::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALoginLevel(Z_Construct_UClass_ALoginLevel, &ALoginLevel::StaticClass, TEXT("/Script/ChatClient"), TEXT("ALoginLevel"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALoginLevel);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
