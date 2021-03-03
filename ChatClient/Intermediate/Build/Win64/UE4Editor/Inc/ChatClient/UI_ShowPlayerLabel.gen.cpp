// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/UI_ShowPlayerLabel.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_ShowPlayerLabel() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_ShowPlayerLabel_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_ShowPlayerLabel();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
// End Cross Module References
	DEFINE_FUNCTION(UUI_ShowPlayerLabel::execSendMessageButton)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SendMessageButton();
		P_NATIVE_END;
	}
	void UUI_ShowPlayerLabel::StaticRegisterNativesUUI_ShowPlayerLabel()
	{
		UClass* Class = UUI_ShowPlayerLabel::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SendMessageButton", &UUI_ShowPlayerLabel::execSendMessageButton },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UUI_ShowPlayerLabel_SendMessageButton_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_ShowPlayerLabel_SendMessageButton_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_ShowPlayerLabel.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_ShowPlayerLabel_SendMessageButton_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_ShowPlayerLabel, nullptr, "SendMessageButton", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_ShowPlayerLabel_SendMessageButton_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_ShowPlayerLabel_SendMessageButton_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_ShowPlayerLabel_SendMessageButton()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_ShowPlayerLabel_SendMessageButton_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UUI_ShowPlayerLabel_NoRegister()
	{
		return UUI_ShowPlayerLabel::StaticClass();
	}
	struct Z_Construct_UClass_UUI_ShowPlayerLabel_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_ShowPlayerLabel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UUI_ShowPlayerLabel_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UUI_ShowPlayerLabel_SendMessageButton, "SendMessageButton" }, // 3082420008
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_ShowPlayerLabel_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "UI_ShowPlayerLabel.h" },
		{ "ModuleRelativePath", "UI_ShowPlayerLabel.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_ShowPlayerLabel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_ShowPlayerLabel>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUI_ShowPlayerLabel_Statics::ClassParams = {
		&UUI_ShowPlayerLabel::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UUI_ShowPlayerLabel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_ShowPlayerLabel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_ShowPlayerLabel()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUI_ShowPlayerLabel_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUI_ShowPlayerLabel, 2768195133);
	template<> CHATCLIENT_API UClass* StaticClass<UUI_ShowPlayerLabel>()
	{
		return UUI_ShowPlayerLabel::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUI_ShowPlayerLabel(Z_Construct_UClass_UUI_ShowPlayerLabel, &UUI_ShowPlayerLabel::StaticClass, TEXT("/Script/ChatClient"), TEXT("UUI_ShowPlayerLabel"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_ShowPlayerLabel);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
