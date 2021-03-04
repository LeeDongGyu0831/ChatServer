// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/UI_Connect.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_Connect() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_Connect_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_Connect();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
// End Cross Module References
	DEFINE_FUNCTION(UUI_Connect::execButtonClick)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ButtonClick();
		P_NATIVE_END;
	}
	void UUI_Connect::StaticRegisterNativesUUI_Connect()
	{
		UClass* Class = UUI_Connect::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ButtonClick", &UUI_Connect::execButtonClick },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UUI_Connect_ButtonClick_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Connect_ButtonClick_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_Connect.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Connect_ButtonClick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Connect, nullptr, "ButtonClick", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_Connect_ButtonClick_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Connect_ButtonClick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_Connect_ButtonClick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_Connect_ButtonClick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UUI_Connect_NoRegister()
	{
		return UUI_Connect::StaticClass();
	}
	struct Z_Construct_UClass_UUI_Connect_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_Connect_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UUI_Connect_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UUI_Connect_ButtonClick, "ButtonClick" }, // 3856487418
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Connect_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "UI_Connect.h" },
		{ "ModuleRelativePath", "UI_Connect.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_Connect_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_Connect>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUI_Connect_Statics::ClassParams = {
		&UUI_Connect::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UUI_Connect_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Connect_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_Connect()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUI_Connect_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUI_Connect, 1230666157);
	template<> CHATCLIENT_API UClass* StaticClass<UUI_Connect>()
	{
		return UUI_Connect::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUI_Connect(Z_Construct_UClass_UUI_Connect, &UUI_Connect::StaticClass, TEXT("/Script/ChatClient"), TEXT("UUI_Connect"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_Connect);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
