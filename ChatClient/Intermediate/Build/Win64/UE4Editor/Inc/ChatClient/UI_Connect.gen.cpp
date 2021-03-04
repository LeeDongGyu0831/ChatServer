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
	DEFINE_FUNCTION(UUI_Connect::execInputPortEvent)
	{
		P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InText);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InputPortEvent(Z_Param_Out_InText);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Connect::execInputIPEvent)
	{
		P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InText);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InputIPEvent(Z_Param_Out_InText);
		P_NATIVE_END;
	}
	void UUI_Connect::StaticRegisterNativesUUI_Connect()
	{
		UClass* Class = UUI_Connect::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ButtonClick", &UUI_Connect::execButtonClick },
			{ "InputIPEvent", &UUI_Connect::execInputIPEvent },
			{ "InputPortEvent", &UUI_Connect::execInputPortEvent },
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
	struct Z_Construct_UFunction_UUI_Connect_InputIPEvent_Statics
	{
		struct UI_Connect_eventInputIPEvent_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Connect_InputIPEvent_Statics::NewProp_InText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UUI_Connect_InputIPEvent_Statics::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UI_Connect_eventInputIPEvent_Parms, InText), METADATA_PARAMS(Z_Construct_UFunction_UUI_Connect_InputIPEvent_Statics::NewProp_InText_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Connect_InputIPEvent_Statics::NewProp_InText_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Connect_InputIPEvent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Connect_InputIPEvent_Statics::NewProp_InText,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Connect_InputIPEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_Connect.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Connect_InputIPEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Connect, nullptr, "InputIPEvent", nullptr, nullptr, sizeof(UI_Connect_eventInputIPEvent_Parms), Z_Construct_UFunction_UUI_Connect_InputIPEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Connect_InputIPEvent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_Connect_InputIPEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Connect_InputIPEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_Connect_InputIPEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_Connect_InputIPEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Connect_InputPortEvent_Statics
	{
		struct UI_Connect_eventInputPortEvent_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Connect_InputPortEvent_Statics::NewProp_InText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UUI_Connect_InputPortEvent_Statics::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UI_Connect_eventInputPortEvent_Parms, InText), METADATA_PARAMS(Z_Construct_UFunction_UUI_Connect_InputPortEvent_Statics::NewProp_InText_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Connect_InputPortEvent_Statics::NewProp_InText_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Connect_InputPortEvent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Connect_InputPortEvent_Statics::NewProp_InText,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Connect_InputPortEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_Connect.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Connect_InputPortEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Connect, nullptr, "InputPortEvent", nullptr, nullptr, sizeof(UI_Connect_eventInputPortEvent_Parms), Z_Construct_UFunction_UUI_Connect_InputPortEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Connect_InputPortEvent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_Connect_InputPortEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Connect_InputPortEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_Connect_InputPortEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_Connect_InputPortEvent_Statics::FuncParams);
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
		{ &Z_Construct_UFunction_UUI_Connect_InputIPEvent, "InputIPEvent" }, // 3830440736
		{ &Z_Construct_UFunction_UUI_Connect_InputPortEvent, "InputPortEvent" }, // 3456011895
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
	IMPLEMENT_CLASS(UUI_Connect, 329918474);
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
