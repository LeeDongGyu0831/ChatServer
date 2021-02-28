// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CHATCLIENT_GI_Network_generated_h
#error "GI_Network.generated.h already included, missing '#pragma once' in GI_Network.h"
#endif
#define CHATCLIENT_GI_Network_generated_h

#define ChatClient_Source_ChatClient_GI_Network_h_20_SPARSE_DATA
#define ChatClient_Source_ChatClient_GI_Network_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execConnectToServer);


#define ChatClient_Source_ChatClient_GI_Network_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execConnectToServer);


#define ChatClient_Source_ChatClient_GI_Network_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGI_Network(); \
	friend struct Z_Construct_UClass_UGI_Network_Statics; \
public: \
	DECLARE_CLASS(UGI_Network, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(UGI_Network)


#define ChatClient_Source_ChatClient_GI_Network_h_20_INCLASS \
private: \
	static void StaticRegisterNativesUGI_Network(); \
	friend struct Z_Construct_UClass_UGI_Network_Statics; \
public: \
	DECLARE_CLASS(UGI_Network, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(UGI_Network)


#define ChatClient_Source_ChatClient_GI_Network_h_20_STANDARD_CONSTRUCTORS \
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


#define ChatClient_Source_ChatClient_GI_Network_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGI_Network(UGI_Network&&); \
	NO_API UGI_Network(const UGI_Network&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGI_Network); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGI_Network); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGI_Network)


#define ChatClient_Source_ChatClient_GI_Network_h_20_PRIVATE_PROPERTY_OFFSET
#define ChatClient_Source_ChatClient_GI_Network_h_17_PROLOG
#define ChatClient_Source_ChatClient_GI_Network_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_GI_Network_h_20_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_GI_Network_h_20_SPARSE_DATA \
	ChatClient_Source_ChatClient_GI_Network_h_20_RPC_WRAPPERS \
	ChatClient_Source_ChatClient_GI_Network_h_20_INCLASS \
	ChatClient_Source_ChatClient_GI_Network_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ChatClient_Source_ChatClient_GI_Network_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_GI_Network_h_20_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_GI_Network_h_20_SPARSE_DATA \
	ChatClient_Source_ChatClient_GI_Network_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_GI_Network_h_20_INCLASS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_GI_Network_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHATCLIENT_API UClass* StaticClass<class UGI_Network>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ChatClient_Source_ChatClient_GI_Network_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
