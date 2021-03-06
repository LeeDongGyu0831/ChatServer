// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/UI_Login.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_Login() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_Login_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_Login();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
// End Cross Module References
	DEFINE_FUNCTION(UUI_Login::execConnectButtonClick)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ConnectButtonClick();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Login::execInputIDEvent)
	{
		P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InText);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InputIDEvent(Z_Param_Out_InText);
		P_NATIVE_END;
	}
	void UUI_Login::StaticRegisterNativesUUI_Login()
	{
		UClass* Class = UUI_Login::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ConnectButtonClick", &UUI_Login::execConnectButtonClick },
			{ "InputIDEvent", &UUI_Login::execInputIDEvent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UUI_Login_ConnectButtonClick_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Login_ConnectButtonClick_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_Login.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Login_ConnectButtonClick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Login, nullptr, "ConnectButtonClick", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_Login_ConnectButtonClick_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Login_ConnectButtonClick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_Login_ConnectButtonClick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_Login_ConnectButtonClick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Login_InputIDEvent_Statics
	{
		struct UI_Login_eventInputIDEvent_Parms
		{
			FText InText;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InText_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_InText;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Login_InputIDEvent_Statics::NewProp_InText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UUI_Login_InputIDEvent_Statics::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UI_Login_eventInputIDEvent_Parms, InText), METADATA_PARAMS(Z_Construct_UFunction_UUI_Login_InputIDEvent_Statics::NewProp_InText_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Login_InputIDEvent_Statics::NewProp_InText_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Login_InputIDEvent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Login_InputIDEvent_Statics::NewProp_InText,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Login_InputIDEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_Login.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Login_InputIDEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Login, nullptr, "InputIDEvent", nullptr, nullptr, sizeof(UI_Login_eventInputIDEvent_Parms), Z_Construct_UFunction_UUI_Login_InputIDEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Login_InputIDEvent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_Login_InputIDEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Login_InputIDEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_Login_InputIDEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_Login_InputIDEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UUI_Login_NoRegister()
	{
		return UUI_Login::StaticClass();
	}
	struct Z_Construct_UClass_UUI_Login_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_Login_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UUI_Login_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UUI_Login_ConnectButtonClick, "ConnectButtonClick" }, // 567487988
		{ &Z_Construct_UFunction_UUI_Login_InputIDEvent, "InputIDEvent" }, // 4034130797
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Login_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "UI_Login.h" },
		{ "ModuleRelativePath", "UI_Login.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_Login_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_Login>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUI_Login_Statics::ClassParams = {
		&UUI_Login::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UUI_Login_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Login_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_Login()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUI_Login_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUI_Login, 2223058957);
	template<> CHATCLIENT_API UClass* StaticClass<UUI_Login>()
	{
		return UUI_Login::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUI_Login(Z_Construct_UClass_UUI_Login, &UUI_Login::StaticClass, TEXT("/Script/ChatClient"), TEXT("UUI_Login"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_Login);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
