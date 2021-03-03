// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/UI_MainRoom.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_MainRoom() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_MainRoom_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_MainRoom();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UUI_MainRoom::execRefreshButtonClickEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RefreshButtonClickEvent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_MainRoom::execRecvButtonClickEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RecvButtonClickEvent();
		P_NATIVE_END;
	}
	void UUI_MainRoom::StaticRegisterNativesUUI_MainRoom()
	{
		UClass* Class = UUI_MainRoom::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "RecvButtonClickEvent", &UUI_MainRoom::execRecvButtonClickEvent },
			{ "RefreshButtonClickEvent", &UUI_MainRoom::execRefreshButtonClickEvent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UUI_MainRoom_RecvButtonClickEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_MainRoom_RecvButtonClickEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_MainRoom.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_MainRoom_RecvButtonClickEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_MainRoom, nullptr, "RecvButtonClickEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_MainRoom_RecvButtonClickEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_MainRoom_RecvButtonClickEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_MainRoom_RecvButtonClickEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_MainRoom_RecvButtonClickEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_MainRoom_RefreshButtonClickEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_MainRoom_RefreshButtonClickEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_MainRoom.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_MainRoom_RefreshButtonClickEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_MainRoom, nullptr, "RefreshButtonClickEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_MainRoom_RefreshButtonClickEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_MainRoom_RefreshButtonClickEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_MainRoom_RefreshButtonClickEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_MainRoom_RefreshButtonClickEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UUI_MainRoom_NoRegister()
	{
		return UUI_MainRoom::StaticClass();
	}
	struct Z_Construct_UClass_UUI_MainRoom_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_chatTextClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_chatTextClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_MainRoom_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UUI_MainRoom_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UUI_MainRoom_RecvButtonClickEvent, "RecvButtonClickEvent" }, // 402214869
		{ &Z_Construct_UFunction_UUI_MainRoom_RefreshButtonClickEvent, "RefreshButtonClickEvent" }, // 4027795369
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_MainRoom_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "UI_MainRoom.h" },
		{ "ModuleRelativePath", "UI_MainRoom.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_chatTextClass_MetaData[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "UI_MainRoom.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_chatTextClass = { "chatTextClass", nullptr, (EPropertyFlags)0x0044000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UUI_MainRoom, chatTextClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_chatTextClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_chatTextClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUI_MainRoom_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_MainRoom_Statics::NewProp_chatTextClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_MainRoom_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_MainRoom>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUI_MainRoom_Statics::ClassParams = {
		&UUI_MainRoom::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UUI_MainRoom_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UUI_MainRoom_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UUI_MainRoom_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_MainRoom_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_MainRoom()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUI_MainRoom_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUI_MainRoom, 1320356716);
	template<> CHATCLIENT_API UClass* StaticClass<UUI_MainRoom>()
	{
		return UUI_MainRoom::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUI_MainRoom(Z_Construct_UClass_UUI_MainRoom, &UUI_MainRoom::StaticClass, TEXT("/Script/ChatClient"), TEXT("UUI_MainRoom"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_MainRoom);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
