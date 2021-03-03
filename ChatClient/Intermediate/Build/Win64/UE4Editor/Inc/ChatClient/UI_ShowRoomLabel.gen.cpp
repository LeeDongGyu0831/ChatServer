// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatClient/UI_ShowRoomLabel.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_ShowRoomLabel() {}
// Cross Module References
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_ShowRoomLabel_NoRegister();
	CHATCLIENT_API UClass* Z_Construct_UClass_UUI_ShowRoomLabel();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_ChatClient();
// End Cross Module References
	DEFINE_FUNCTION(UUI_ShowRoomLabel::execJoinButtonClickEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->JoinButtonClickEvent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_ShowRoomLabel::execDestroyButtonClickEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DestroyButtonClickEvent();
		P_NATIVE_END;
	}
	void UUI_ShowRoomLabel::StaticRegisterNativesUUI_ShowRoomLabel()
	{
		UClass* Class = UUI_ShowRoomLabel::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DestroyButtonClickEvent", &UUI_ShowRoomLabel::execDestroyButtonClickEvent },
			{ "JoinButtonClickEvent", &UUI_ShowRoomLabel::execJoinButtonClickEvent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UUI_ShowRoomLabel_DestroyButtonClickEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_ShowRoomLabel_DestroyButtonClickEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_ShowRoomLabel.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_ShowRoomLabel_DestroyButtonClickEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_ShowRoomLabel, nullptr, "DestroyButtonClickEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_ShowRoomLabel_DestroyButtonClickEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_ShowRoomLabel_DestroyButtonClickEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_ShowRoomLabel_DestroyButtonClickEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_ShowRoomLabel_DestroyButtonClickEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_ShowRoomLabel_JoinButtonClickEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_ShowRoomLabel_JoinButtonClickEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI_ShowRoomLabel.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_ShowRoomLabel_JoinButtonClickEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_ShowRoomLabel, nullptr, "JoinButtonClickEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUI_ShowRoomLabel_JoinButtonClickEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_ShowRoomLabel_JoinButtonClickEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUI_ShowRoomLabel_JoinButtonClickEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUI_ShowRoomLabel_JoinButtonClickEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UUI_ShowRoomLabel_NoRegister()
	{
		return UUI_ShowRoomLabel::StaticClass();
	}
	struct Z_Construct_UClass_UUI_ShowRoomLabel_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_ShowRoomLabel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_ChatClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UUI_ShowRoomLabel_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UUI_ShowRoomLabel_DestroyButtonClickEvent, "DestroyButtonClickEvent" }, // 980601432
		{ &Z_Construct_UFunction_UUI_ShowRoomLabel_JoinButtonClickEvent, "JoinButtonClickEvent" }, // 3633392038
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_ShowRoomLabel_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "UI_ShowRoomLabel.h" },
		{ "ModuleRelativePath", "UI_ShowRoomLabel.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_ShowRoomLabel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_ShowRoomLabel>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUI_ShowRoomLabel_Statics::ClassParams = {
		&UUI_ShowRoomLabel::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UUI_ShowRoomLabel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_ShowRoomLabel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_ShowRoomLabel()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUI_ShowRoomLabel_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUI_ShowRoomLabel, 2362155677);
	template<> CHATCLIENT_API UClass* StaticClass<UUI_ShowRoomLabel>()
	{
		return UUI_ShowRoomLabel::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUI_ShowRoomLabel(Z_Construct_UClass_UUI_ShowRoomLabel, &UUI_ShowRoomLabel::StaticClass, TEXT("/Script/ChatClient"), TEXT("UUI_ShowRoomLabel"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_ShowRoomLabel);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
