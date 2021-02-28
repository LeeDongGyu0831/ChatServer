// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/PC_ChatPlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePC_ChatPlayerController() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_APC_ChatPlayerController_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_APC_ChatPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
// End Cross Module References
	void APC_ChatPlayerController::StaticRegisterNativesAPC_ChatPlayerController()
	{
	}
	UClass* Z_Construct_UClass_APC_ChatPlayerController_NoRegister()
	{
		return APC_ChatPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_APC_ChatPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APC_ChatPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APC_ChatPlayerController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "PC_ChatPlayerController.h" },
		{ "ModuleRelativePath", "PC_ChatPlayerController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APC_ChatPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APC_ChatPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APC_ChatPlayerController_Statics::ClassParams = {
		&APC_ChatPlayerController::StaticClass,
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
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_APC_ChatPlayerController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APC_ChatPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APC_ChatPlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APC_ChatPlayerController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APC_ChatPlayerController, 484849055);
	template<> CHATCLIENT_API UClass* StaticClass<APC_ChatPlayerController>()
	{
		return APC_ChatPlayerController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APC_ChatPlayerController(Z_Construct_UClass_APC_ChatPlayerController, &APC_ChatPlayerController::StaticClass, TEXT("/Script/ChatClient"), TEXT("APC_ChatPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APC_ChatPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
