// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/UI_ChatRoom.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_ChatRoom() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_ChatRoom_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_ChatRoom();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
// End Cross Module References
	void UUI_ChatRoom::StaticRegisterNativesUUI_ChatRoom()
	{
	}
	UClass* Z_Construct_UClass_UUI_ChatRoom_NoRegister()
	{
		return UUI_ChatRoom::StaticClass();
	}
	struct Z_Construct_UClass_UUI_ChatRoom_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_ChatRoom_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_ChatRoom_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "UI_ChatRoom.h" },
		{ "ModuleRelativePath", "UI_ChatRoom.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_ChatRoom_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_ChatRoom>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUI_ChatRoom_Statics::ClassParams = {
		&UUI_ChatRoom::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UUI_ChatRoom_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_ChatRoom_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_ChatRoom()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUI_ChatRoom_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUI_ChatRoom, 4039861303);
	template<> CHATCLIENT_API UClass* StaticClass<UUI_ChatRoom>()
	{
		return UUI_ChatRoom::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUI_ChatRoom(Z_Construct_UClass_UUI_ChatRoom, &UUI_ChatRoom::StaticClass, TEXT("/Script/ChatClient"), TEXT("UUI_ChatRoom"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_ChatRoom);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
