// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class MSG_TYPE : uint8;
#ifdef CHATCLIENT_GI_Network_generated_h
#error "GI_Network.generated.h already included, missing '#pragma once' in GI_Network.h"
#endif
#define CHATCLIENT_GI_Network_generated_h

#define ChatClient_Source_ChatClient_GI_Network_h_32_SPARSE_DATA
#define ChatClient_Source_ChatClient_GI_Network_h_32_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCheckMessage); \
	DECLARE_FUNCTION(execTrimMessage); \
	DECLARE_FUNCTION(execSend); \
	DECLARE_FUNCTION(execRecv); \
	DECLARE_FUNCTION(execLoginToServer); \
	DECLARE_FUNCTION(execConnectToServer); \
	DECLARE_FUNCTION(execRecvData);


#define ChatClient_Source_ChatClient_GI_Network_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCheckMessage); \
	DECLARE_FUNCTION(execTrimMessage); \
	DECLARE_FUNCTION(execSend); \
	DECLARE_FUNCTION(execRecv); \
	DECLARE_FUNCTION(execLoginToServer); \
	DECLARE_FUNCTION(execConnectToServer); \
	DECLARE_FUNCTION(execRecvData);


#define ChatClient_Source_ChatClient_GI_Network_h_32_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGI_Network(); \
	friend struct Z_Construct_UClass_UGI_Network_Statics; \
public: \
	DECLARE_CLASS(UGI_Network, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(UGI_Network)


#define ChatClient_Source_ChatClient_GI_Network_h_32_INCLASS \
private: \
	static void StaticRegisterNativesUGI_Network(); \
	friend struct Z_Construct_UClass_UGI_Network_Statics; \
public: \
	DECLARE_CLASS(UGI_Network, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(UGI_Network)


#define ChatClient_Source_ChatClient_GI_Network_h_32_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGI_Network(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGI_Network) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGI_Network); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGI_Network); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGI_Network(UGI_Network&&); \
	NO_API UGI_Network(const UGI_Network&); \
public:


#define ChatClient_Source_ChatClient_GI_Network_h_32_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGI_Network(UGI_Network&&); \
	NO_API UGI_Network(const UGI_Network&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGI_Network); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGI_Network); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGI_Network)


#define ChatClient_Source_ChatClient_GI_Network_h_32_PRIVATE_PROPERTY_OFFSET
#define ChatClient_Source_ChatClient_GI_Network_h_29_PROLOG
#define ChatClient_Source_ChatClient_GI_Network_h_32_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_GI_Network_h_32_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_GI_Network_h_32_SPARSE_DATA \
	ChatClient_Source_ChatClient_GI_Network_h_32_RPC_WRAPPERS \
	ChatClient_Source_ChatClient_GI_Network_h_32_INCLASS \
	ChatClient_Source_ChatClient_GI_Network_h_32_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ChatClient_Source_ChatClient_GI_Network_h_32_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_GI_Network_h_32_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_GI_Network_h_32_SPARSE_DATA \
	ChatClient_Source_ChatClient_GI_Network_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_GI_Network_h_32_INCLASS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_GI_Network_h_32_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHATCLIENT_API UClass* StaticClass<class UGI_Network>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ChatClient_Source_ChatClient_GI_Network_h


#define FOREACH_ENUM_MSG_TYPE(op) \
	op(MSG_TYPE::JOIN) \
	op(MSG_TYPE::CHAT) \
	op(MSG_TYPE::EXIT) \
	op(MSG_TYPE::PLAYERLIST) 

enum class MSG_TYPE : uint8;
template<> CHATCLIENT_API UEnum* StaticEnum<MSG_TYPE>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
