// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CHATCLIENT_UI_ChatRoom_generated_h
#error "UI_ChatRoom.generated.h already included, missing '#pragma once' in UI_ChatRoom.h"
#endif
#define CHATCLIENT_UI_ChatRoom_generated_h

#define ChatClient_Source_ChatClient_UI_ChatRoom_h_23_SPARSE_DATA
#define ChatClient_Source_ChatClient_UI_ChatRoom_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execRequestDestroyRoom); \
	DECLARE_FUNCTION(execRequestLeaveRoom); \
	DECLARE_FUNCTION(execReadySendMessage); \
	DECLARE_FUNCTION(execDestroyRoomButtonClickEvent); \
	DECLARE_FUNCTION(execCloseButtonClickEvent); \
	DECLARE_FUNCTION(execLeaveRoomButtonClickEvent); \
	DECLARE_FUNCTION(execRefreshPlayerButtonClickEvent); \
	DECLARE_FUNCTION(execRecvButtonClickEvent);


#define ChatClient_Source_ChatClient_UI_ChatRoom_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRequestDestroyRoom); \
	DECLARE_FUNCTION(execRequestLeaveRoom); \
	DECLARE_FUNCTION(execReadySendMessage); \
	DECLARE_FUNCTION(execDestroyRoomButtonClickEvent); \
	DECLARE_FUNCTION(execCloseButtonClickEvent); \
	DECLARE_FUNCTION(execLeaveRoomButtonClickEvent); \
	DECLARE_FUNCTION(execRefreshPlayerButtonClickEvent); \
	DECLARE_FUNCTION(execRecvButtonClickEvent);


#define ChatClient_Source_ChatClient_UI_ChatRoom_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUUI_ChatRoom(); \
	friend struct Z_Construct_UClass_UUI_ChatRoom_Statics; \
public: \
	DECLARE_CLASS(UUI_ChatRoom, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(UUI_ChatRoom)


#define ChatClient_Source_ChatClient_UI_ChatRoom_h_23_INCLASS \
private: \
	static void StaticRegisterNativesUUI_ChatRoom(); \
	friend struct Z_Construct_UClass_UUI_ChatRoom_Statics; \
public: \
	DECLARE_CLASS(UUI_ChatRoom, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(UUI_ChatRoom)


#define ChatClient_Source_ChatClient_UI_ChatRoom_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UUI_ChatRoom(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUI_ChatRoom) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUI_ChatRoom); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUI_ChatRoom); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UUI_ChatRoom(UUI_ChatRoom&&); \
	NO_API UUI_ChatRoom(const UUI_ChatRoom&); \
public:


#define ChatClient_Source_ChatClient_UI_ChatRoom_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UUI_ChatRoom(UUI_ChatRoom&&); \
	NO_API UUI_ChatRoom(const UUI_ChatRoom&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUI_ChatRoom); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUI_ChatRoom); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUI_ChatRoom)


#define ChatClient_Source_ChatClient_UI_ChatRoom_h_23_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__chatTextClass() { return STRUCT_OFFSET(UUI_ChatRoom, chatTextClass); } \
	FORCEINLINE static uint32 __PPO__playerNameLabelClass() { return STRUCT_OFFSET(UUI_ChatRoom, playerNameLabelClass); }


#define ChatClient_Source_ChatClient_UI_ChatRoom_h_20_PROLOG
#define ChatClient_Source_ChatClient_UI_ChatRoom_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_UI_ChatRoom_h_23_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_UI_ChatRoom_h_23_SPARSE_DATA \
	ChatClient_Source_ChatClient_UI_ChatRoom_h_23_RPC_WRAPPERS \
	ChatClient_Source_ChatClient_UI_ChatRoom_h_23_INCLASS \
	ChatClient_Source_ChatClient_UI_ChatRoom_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ChatClient_Source_ChatClient_UI_ChatRoom_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_UI_ChatRoom_h_23_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_UI_ChatRoom_h_23_SPARSE_DATA \
	ChatClient_Source_ChatClient_UI_ChatRoom_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_UI_ChatRoom_h_23_INCLASS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_UI_ChatRoom_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHATCLIENT_API UClass* StaticClass<class UUI_ChatRoom>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ChatClient_Source_ChatClient_UI_ChatRoom_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
