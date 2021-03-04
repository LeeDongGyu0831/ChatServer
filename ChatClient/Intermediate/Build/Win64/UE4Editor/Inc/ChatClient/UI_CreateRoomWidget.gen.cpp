// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/UI_CreateRoomWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_CreateRoomWidget() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_CreateRoomWidget_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_CreateRoomWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
// End Cross Module References
	DEFINE_FUNCTION(UUI_CreateRoomWidget::execCancleButtonClickEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CancleButtonClickEvent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_CreateRoomWidget::execCreateButtonClickEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CreateButtonClickEvent();
		P_NATIVE_END;
	}
	void UUI_CreateRoomWidget::StaticRegisterNativesUUI_CreateRoomWidget()
	{
		UClass* Class = UUI_CreateRoomWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CancleButtonClickEvent", &UUI_CreateRoomWidget::execCancleButtonClickEvent },
			{ "CreateButtonClickEvent", &UUI_CreateRoomWidget::execCreateButtonClickEvent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UUI_CreateRoomWidget_CancleButtonClickEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_CreateRoomWidget_CancleButtonClickEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_CreateRoomWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_CreateRoomWidget_CancleButtonClickEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_CreateRoomWidget, nullptr, "CancleButtonClickEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_CreateRoomWidget_CancleButtonClickEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_CreateRoomWidget_CancleButtonClickEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_CreateRoomWidget_CancleButtonClickEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_CreateRoomWidget_CancleButtonClickEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_CreateRoomWidget_CreateButtonClickEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_CreateRoomWidget_CreateButtonClickEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_CreateRoomWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_CreateRoomWidget_CreateButtonClickEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_CreateRoomWidget, nullptr, "CreateButtonClickEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_CreateRoomWidget_CreateButtonClickEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_CreateRoomWidget_CreateButtonClickEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_CreateRoomWidget_CreateButtonClickEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_CreateRoomWidget_CreateButtonClickEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UUI_CreateRoomWidget_NoRegister()
	{
		return UUI_CreateRoomWidget::StaticClass();
	}
	struct Z_Construct_UClass_UUI_CreateRoomWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_CreateRoomWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UUI_CreateRoomWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UUI_CreateRoomWidget_CancleButtonClickEvent, "CancleButtonClickEvent" }, // 3664032661
		{ &Z_Construct_UFunction_UUI_CreateRoomWidget_CreateButtonClickEvent, "CreateButtonClickEvent" }, // 3888114299
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_CreateRoomWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "UI_CreateRoomWidget.h" },
		{ "ModuleRelativePath", "UI_CreateRoomWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_CreateRoomWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_CreateRoomWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUI_CreateRoomWidget_Statics::ClassParams = {
		&UUI_CreateRoomWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UUI_CreateRoomWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_CreateRoomWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_CreateRoomWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUI_CreateRoomWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUI_CreateRoomWidget, 4266015409);
	template<> CHATCLIENT_API UClass* StaticClass<UUI_CreateRoomWidget>()
	{
		return UUI_CreateRoomWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUI_CreateRoomWidget(Z_Construct_UClass_UUI_CreateRoomWidget, &UUI_CreateRoomWidget::StaticClass, TEXT("/Script/ChatClient"), TEXT("UUI_CreateRoomWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_CreateRoomWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
