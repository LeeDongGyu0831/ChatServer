// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CHATCLIENT_UI_Login_generated_h
#error "UI_Login.generated.h already included, missing '#pragma once' in UI_Login.h"
#endif
#define CHATCLIENT_UI_Login_generated_h

#define ChatClient_Source_ChatClient_UI_Login_h_18_SPARSE_DATA
#define ChatClient_Source_ChatClient_UI_Login_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execConnectButtonClick); \
	DECLARE_FUNCTION(execInputIDEvent);


#define ChatClient_Source_ChatClient_UI_Login_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execConnectButtonClick); \
	DECLARE_FUNCTION(execInputIDEvent);


#define ChatClient_Source_ChatClient_UI_Login_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUUI_Login(); \
	friend struct Z_Construct_UClass_UUI_Login_Statics; \
public: \
	DECLARE_CLASS(UUI_Login, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(UUI_Login)


#define ChatClient_Source_ChatClient_UI_Login_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUUI_Login(); \
	friend struct Z_Construct_UClass_UUI_Login_Statics; \
public: \
	DECLARE_CLASS(UUI_Login, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(UUI_Login)


#define ChatClient_Source_ChatClient_UI_Login_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UUI_Login(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUI_Login) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUI_Login); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUI_Login); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UUI_Login(UUI_Login&&); \
	NO_API UUI_Login(const UUI_Login&); \
public:


#define ChatClient_Source_ChatClient_UI_Login_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UUI_Login(UUI_Login&&); \
	NO_API UUI_Login(const UUI_Login&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUI_Login); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUI_Login); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUI_Login)


#define ChatClient_Source_ChatClient_UI_Login_h_18_PRIVATE_PROPERTY_OFFSET
#define ChatClient_Source_ChatClient_UI_Login_h_15_PROLOG
#define ChatClient_Source_ChatClient_UI_Login_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_UI_Login_h_18_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_UI_Login_h_18_SPARSE_DATA \
	ChatClient_Source_ChatClient_UI_Login_h_18_RPC_WRAPPERS \
	ChatClient_Source_ChatClient_UI_Login_h_18_INCLASS \
	ChatClient_Source_ChatClient_UI_Login_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ChatClient_Source_ChatClient_UI_Login_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_UI_Login_h_18_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_UI_Login_h_18_SPARSE_DATA \
	ChatClient_Source_ChatClient_UI_Login_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_UI_Login_h_18_INCLASS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_UI_Login_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHATCLIENT_API UClass* StaticClass<class UUI_Login>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ChatClient_Source_ChatClient_UI_Login_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
