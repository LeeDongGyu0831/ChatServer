// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/ConnectLevel.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConnectLevel() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_AConnectLevel_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_AConnectLevel();
	ENGINE_API UClass* Z_Construct_UClass_ALevelScriptActor();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
// End Cross Module References
	void AConnectLevel::StaticRegisterNativesAConnectLevel()
	{
	}
	UClass* Z_Construct_UClass_AConnectLevel_NoRegister()
	{
		return AConnectLevel::StaticClass();
	}
	struct Z_Construct_UClass_AConnectLevel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_connectWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_connectWidgetClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AConnectLevel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ALevelScriptActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AConnectLevel_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * ???????? ?????? ?\xc3\xb5??\xcf\xb4? ????\n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "ConnectLevel.h" },
		{ "ModuleRelativePath", "ConnectLevel.h" },
		{ "ToolTip", "???????? ?????? ?\xc3\xb5??\xcf\xb4? ????" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AConnectLevel_Statics::NewProp_connectWidgetClass_MetaData[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "ConnectLevel.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AConnectLevel_Statics::NewProp_connectWidgetClass = { "connectWidgetClass", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AConnectLevel, connectWidgetClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AConnectLevel_Statics::NewProp_connectWidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AConnectLevel_Statics::NewProp_connectWidgetClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AConnectLevel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AConnectLevel_Statics::NewProp_connectWidgetClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AConnectLevel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AConnectLevel>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AConnectLevel_Statics::ClassParams = {
		&AConnectLevel::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AConnectLevel_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AConnectLevel_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AConnectLevel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AConnectLevel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AConnectLevel()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AConnectLevel_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AConnectLevel, 3140397268);
	template<> CHATCLIENT_API UClass* StaticClass<AConnectLevel>()
	{
		return AConnectLevel::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AConnectLevel(Z_Construct_UClass_AConnectLevel, &AConnectLevel::StaticClass, TEXT("/Script/ChatClient"), TEXT("AConnectLevel"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AConnectLevel);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
