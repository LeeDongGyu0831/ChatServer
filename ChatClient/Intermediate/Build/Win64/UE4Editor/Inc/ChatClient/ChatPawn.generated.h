// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CHATCLIENT_ChatPawn_generated_h
#error "ChatPawn.generated.h already included, missing '#pragma once' in ChatPawn.h"
#endif
#define CHATCLIENT_ChatPawn_generated_h

#define ChatClient_Source_ChatClient_ChatPawn_h_12_SPARSE_DATA
#define ChatClient_Source_ChatClient_ChatPawn_h_12_RPC_WRAPPERS
#define ChatClient_Source_ChatClient_ChatPawn_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define ChatClient_Source_ChatClient_ChatPawn_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAChatPawn(); \
	friend struct Z_Construct_UClass_AChatPawn_Statics; \
public: \
	DECLARE_CLASS(AChatPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(AChatPawn)


#define ChatClient_Source_ChatClient_ChatPawn_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAChatPawn(); \
	friend struct Z_Construct_UClass_AChatPawn_Statics; \
public: \
	DECLARE_CLASS(AChatPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(AChatPawn)


#define ChatClient_Source_ChatClient_ChatPawn_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AChatPawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AChatPawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AChatPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AChatPawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AChatPawn(AChatPawn&&); \
	NO_API AChatPawn(const AChatPawn&); \
public:


#define ChatClient_Source_ChatClient_ChatPawn_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AChatPawn(AChatPawn&&); \
	NO_API AChatPawn(const AChatPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AChatPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AChatPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AChatPawn)


#define ChatClient_Source_ChatClient_ChatPawn_h_12_PRIVATE_PROPERTY_OFFSET
#define ChatClient_Source_ChatClient_ChatPawn_h_9_PROLOG
#define ChatClient_Source_ChatClient_ChatPawn_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_ChatPawn_h_12_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_ChatPawn_h_12_SPARSE_DATA \
	ChatClient_Source_ChatClient_ChatPawn_h_12_RPC_WRAPPERS \
	ChatClient_Source_ChatClient_ChatPawn_h_12_INCLASS \
	ChatClient_Source_ChatClient_ChatPawn_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ChatClient_Source_ChatClient_ChatPawn_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_ChatPawn_h_12_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_ChatPawn_h_12_SPARSE_DATA \
	ChatClient_Source_ChatClient_ChatPawn_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_ChatPawn_h_12_INCLASS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_ChatPawn_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHATCLIENT_API UClass* StaticClass<class AChatPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ChatClient_Source_ChatClient_ChatPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
