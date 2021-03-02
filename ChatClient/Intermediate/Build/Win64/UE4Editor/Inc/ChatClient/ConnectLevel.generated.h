// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CHATCLIENT_ConnectLevel_generated_h
#error "ConnectLevel.generated.h already included, missing '#pragma once' in ConnectLevel.h"
#endif
#define CHATCLIENT_ConnectLevel_generated_h

#define ChatClient_Source_ChatClient_ConnectLevel_h_17_SPARSE_DATA
#define ChatClient_Source_ChatClient_ConnectLevel_h_17_RPC_WRAPPERS
#define ChatClient_Source_ChatClient_ConnectLevel_h_17_RPC_WRAPPERS_NO_PURE_DECLS
#define ChatClient_Source_ChatClient_ConnectLevel_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAConnectLevel(); \
	friend struct Z_Construct_UClass_AConnectLevel_Statics; \
public: \
	DECLARE_CLASS(AConnectLevel, ALevelScriptActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(AConnectLevel)


#define ChatClient_Source_ChatClient_ConnectLevel_h_17_INCLASS \
private: \
	static void StaticRegisterNativesAConnectLevel(); \
	friend struct Z_Construct_UClass_AConnectLevel_Statics; \
public: \
	DECLARE_CLASS(AConnectLevel, ALevelScriptActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(AConnectLevel)


#define ChatClient_Source_ChatClient_ConnectLevel_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AConnectLevel(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AConnectLevel) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AConnectLevel); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AConnectLevel); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AConnectLevel(AConnectLevel&&); \
	NO_API AConnectLevel(const AConnectLevel&); \
public:


#define ChatClient_Source_ChatClient_ConnectLevel_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AConnectLevel(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AConnectLevel(AConnectLevel&&); \
	NO_API AConnectLevel(const AConnectLevel&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AConnectLevel); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AConnectLevel); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AConnectLevel)


#define ChatClient_Source_ChatClient_ConnectLevel_h_17_PRIVATE_PROPERTY_OFFSET
#define ChatClient_Source_ChatClient_ConnectLevel_h_14_PROLOG
#define ChatClient_Source_ChatClient_ConnectLevel_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_ConnectLevel_h_17_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_ConnectLevel_h_17_SPARSE_DATA \
	ChatClient_Source_ChatClient_ConnectLevel_h_17_RPC_WRAPPERS \
	ChatClient_Source_ChatClient_ConnectLevel_h_17_INCLASS \
	ChatClient_Source_ChatClient_ConnectLevel_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ChatClient_Source_ChatClient_ConnectLevel_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_ConnectLevel_h_17_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_ConnectLevel_h_17_SPARSE_DATA \
	ChatClient_Source_ChatClient_ConnectLevel_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_ConnectLevel_h_17_INCLASS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_ConnectLevel_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHATCLIENT_API UClass* StaticClass<class AConnectLevel>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ChatClient_Source_ChatClient_ConnectLevel_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
