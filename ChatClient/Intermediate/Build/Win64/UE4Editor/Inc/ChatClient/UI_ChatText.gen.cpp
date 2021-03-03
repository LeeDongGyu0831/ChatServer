// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/UI_ChatText.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_ChatText() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_ChatText_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_ChatText();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
// End Cross Module References
	void UUI_ChatText::StaticRegisterNativesUUI_ChatText()
	{
	}
	UClass* Z_Construct_UClass_UUI_ChatText_NoRegister()
	{
		return UUI_ChatText::StaticClass();
	}
	struct Z_Construct_UClass_UUI_ChatText_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_ChatText_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_ChatText_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "UI_ChatText.h" },
		{ "ModuleRelativePath", "UI_ChatText.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_ChatText_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_ChatText>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUI_ChatText_Statics::ClassParams = {
		&UUI_ChatText::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UUI_ChatText_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_ChatText_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_ChatText()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUI_ChatText_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUI_ChatText, 3386405977);
	template<> CHATCLIENT_API UClass* StaticClass<UUI_ChatText>()
	{
		return UUI_ChatText::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUI_ChatText(Z_Construct_UClass_UUI_ChatText, &UUI_ChatText::StaticClass, TEXT("/Script/ChatClient"), TEXT("UUI_ChatText"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_ChatText);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
