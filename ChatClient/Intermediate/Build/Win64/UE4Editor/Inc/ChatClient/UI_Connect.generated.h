// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CHATCLIENT_UI_Connect_generated_h
#error "UI_Connect.generated.h already included, missing '#pragma once' in UI_Connect.h"
#endif
#define CHATCLIENT_UI_Connect_generated_h

#define ChatClient_Source_ChatClient_UI_Connect_h_18_SPARSE_DATA
#define ChatClient_Source_ChatClient_UI_Connect_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execButtonClick);


#define ChatClient_Source_ChatClient_UI_Connect_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execButtonClick);


#define ChatClient_Source_ChatClient_UI_Connect_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUUI_Connect(); \
	friend struct Z_Construct_UClass_UUI_Connect_Statics; \
public: \
	DECLARE_CLASS(UUI_Connect, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(UUI_Connect)


#define ChatClient_Source_ChatClient_UI_Connect_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUUI_Connect(); \
	friend struct Z_Construct_UClass_UUI_Connect_Statics; \
public: \
	DECLARE_CLASS(UUI_Connect, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(UUI_Connect)


#define ChatClient_Source_ChatClient_UI_Connect_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UUI_Connect(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUI_Connect) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUI_Connect); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUI_Connect); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UUI_Connect(UUI_Connect&&); \
	NO_API UUI_Connect(const UUI_Connect&); \
public:


#define ChatClient_Source_ChatClient_UI_Connect_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UUI_Connect(UUI_Connect&&); \
	NO_API UUI_Connect(const UUI_Connect&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUI_Connect); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUI_Connect); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUI_Connect)


#define ChatClient_Source_ChatClient_UI_Connect_h_18_PRIVATE_PROPERTY_OFFSET
#define ChatClient_Source_ChatClient_UI_Connect_h_15_PROLOG
#define ChatClient_Source_ChatClient_UI_Connect_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_UI_Connect_h_18_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_UI_Connect_h_18_SPARSE_DATA \
	ChatClient_Source_ChatClient_UI_Connect_h_18_RPC_WRAPPERS \
	ChatClient_Source_ChatClient_UI_Connect_h_18_INCLASS \
	ChatClient_Source_ChatClient_UI_Connect_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ChatClient_Source_ChatClient_UI_Connect_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_UI_Connect_h_18_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_UI_Connect_h_18_SPARSE_DATA \
	ChatClient_Source_ChatClient_UI_Connect_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_UI_Connect_h_18_INCLASS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_UI_Connect_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHATCLIENT_API UClass* StaticClass<class UUI_Connect>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ChatClient_Source_ChatClient_UI_Connect_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
