// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CHATCLIENT_ChatRoomLevel_generated_h
#error "ChatRoomLevel.generated.h already included, missing '#pragma once' in ChatRoomLevel.h"
#endif
#define CHATCLIENT_ChatRoomLevel_generated_h

#define ChatClient_Source_ChatClient_ChatRoomLevel_h_18_SPARSE_DATA
#define ChatClient_Source_ChatClient_ChatRoomLevel_h_18_RPC_WRAPPERS
#define ChatClient_Source_ChatClient_ChatRoomLevel_h_18_RPC_WRAPPERS_NO_PURE_DECLS
#define ChatClient_Source_ChatClient_ChatRoomLevel_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAChatRoomLevel(); \
	friend struct Z_Construct_UClass_AChatRoomLevel_Statics; \
public: \
	DECLARE_CLASS(AChatRoomLevel, ALevelScriptActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(AChatRoomLevel)


#define ChatClient_Source_ChatClient_ChatRoomLevel_h_18_INCLASS \
private: \
	static void StaticRegisterNativesAChatRoomLevel(); \
	friend struct Z_Construct_UClass_AChatRoomLevel_Statics; \
public: \
	DECLARE_CLASS(AChatRoomLevel, ALevelScriptActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(AChatRoomLevel)


#define ChatClient_Source_ChatClient_ChatRoomLevel_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AChatRoomLevel(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AChatRoomLevel) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AChatRoomLevel); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AChatRoomLevel); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AChatRoomLevel(AChatRoomLevel&&); \
	NO_API AChatRoomLevel(const AChatRoomLevel&); \
public:


#define ChatClient_Source_ChatClient_ChatRoomLevel_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AChatRoomLevel(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AChatRoomLevel(AChatRoomLevel&&); \
	NO_API AChatRoomLevel(const AChatRoomLevel&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AChatRoomLevel); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AChatRoomLevel); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AChatRoomLevel)


#define ChatClient_Source_ChatClient_ChatRoomLevel_h_18_PRIVATE_PROPERTY_OFFSET
#define ChatClient_Source_ChatClient_ChatRoomLevel_h_15_PROLOG
#define ChatClient_Source_ChatClient_ChatRoomLevel_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_ChatRoomLevel_h_18_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_ChatRoomLevel_h_18_SPARSE_DATA \
	ChatClient_Source_ChatClient_ChatRoomLevel_h_18_RPC_WRAPPERS \
	ChatClient_Source_ChatClient_ChatRoomLevel_h_18_INCLASS \
	ChatClient_Source_ChatClient_ChatRoomLevel_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ChatClient_Source_ChatClient_ChatRoomLevel_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_ChatRoomLevel_h_18_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_ChatRoomLevel_h_18_SPARSE_DATA \
	ChatClient_Source_ChatClient_ChatRoomLevel_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_ChatRoomLevel_h_18_INCLASS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_ChatRoomLevel_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHATCLIENT_API UClass* StaticClass<class AChatRoomLevel>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ChatClient_Source_ChatClient_ChatRoomLevel_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
