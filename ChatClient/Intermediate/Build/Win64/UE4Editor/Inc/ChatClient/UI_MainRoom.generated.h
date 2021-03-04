// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CHATCLIENT_UI_MainRoom_generated_h
#error "UI_MainRoom.generated.h already included, missing '#pragma once' in UI_MainRoom.h"
#endif
#define CHATCLIENT_UI_MainRoom_generated_h

#define ChatClient_Source_ChatClient_UI_MainRoom_h_22_SPARSE_DATA
#define ChatClient_Source_ChatClient_UI_MainRoom_h_22_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execRequestDestroyRoom); \
	DECLARE_FUNCTION(execRequestJoinRoom); \
	DECLARE_FUNCTION(execReadySendMessage); \
	DECLARE_FUNCTION(execCreateRoomButtonClickEvent); \
	DECLARE_FUNCTION(execCloseButtonClickEvent); \
	DECLARE_FUNCTION(execRefreshRoomButtonClickEvent); \
	DECLARE_FUNCTION(execRefreshPlayerButtonClickEvent); \
	DECLARE_FUNCTION(execRecvButtonClickEvent);


#define ChatClient_Source_ChatClient_UI_MainRoom_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRequestDestroyRoom); \
	DECLARE_FUNCTION(execRequestJoinRoom); \
	DECLARE_FUNCTION(execReadySendMessage); \
	DECLARE_FUNCTION(execCreateRoomButtonClickEvent); \
	DECLARE_FUNCTION(execCloseButtonClickEvent); \
	DECLARE_FUNCTION(execRefreshRoomButtonClickEvent); \
	DECLARE_FUNCTION(execRefreshPlayerButtonClickEvent); \
	DECLARE_FUNCTION(execRecvButtonClickEvent);


#define ChatClient_Source_ChatClient_UI_MainRoom_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUUI_MainRoom(); \
	friend struct Z_Construct_UClass_UUI_MainRoom_Statics; \
public: \
	DECLARE_CLASS(UUI_MainRoom, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(UUI_MainRoom)


#define ChatClient_Source_ChatClient_UI_MainRoom_h_22_INCLASS \
private: \
	static void StaticRegisterNativesUUI_MainRoom(); \
	friend struct Z_Construct_UClass_UUI_MainRoom_Statics; \
public: \
	DECLARE_CLASS(UUI_MainRoom, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(UUI_MainRoom)


#define ChatClient_Source_ChatClient_UI_MainRoom_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UUI_MainRoom(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUI_MainRoom) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUI_MainRoom); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUI_MainRoom); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UUI_MainRoom(UUI_MainRoom&&); \
	NO_API UUI_MainRoom(const UUI_MainRoom&); \
public:


#define ChatClient_Source_ChatClient_UI_MainRoom_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UUI_MainRoom(UUI_MainRoom&&); \
	NO_API UUI_MainRoom(const UUI_MainRoom&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUI_MainRoom); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUI_MainRoom); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUI_MainRoom)


#define ChatClient_Source_ChatClient_UI_MainRoom_h_22_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__chatTextClass() { return STRUCT_OFFSET(UUI_MainRoom, chatTextClass); } \
	FORCEINLINE static uint32 __PPO__playerNameLabelClass() { return STRUCT_OFFSET(UUI_MainRoom, playerNameLabelClass); } \
	FORCEINLINE static uint32 __PPO__roomNameLabelClass() { return STRUCT_OFFSET(UUI_MainRoom, roomNameLabelClass); } \
	FORCEINLINE static uint32 __PPO__createRoomWidgetClass() { return STRUCT_OFFSET(UUI_MainRoom, createRoomWidgetClass); }


#define ChatClient_Source_ChatClient_UI_MainRoom_h_19_PROLOG
#define ChatClient_Source_ChatClient_UI_MainRoom_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_UI_MainRoom_h_22_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_UI_MainRoom_h_22_SPARSE_DATA \
	ChatClient_Source_ChatClient_UI_MainRoom_h_22_RPC_WRAPPERS \
	ChatClient_Source_ChatClient_UI_MainRoom_h_22_INCLASS \
	ChatClient_Source_ChatClient_UI_MainRoom_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ChatClient_Source_ChatClient_UI_MainRoom_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_UI_MainRoom_h_22_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_UI_MainRoom_h_22_SPARSE_DATA \
	ChatClient_Source_ChatClient_UI_MainRoom_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_UI_MainRoom_h_22_INCLASS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_UI_MainRoom_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHATCLIENT_API UClass* StaticClass<class UUI_MainRoom>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ChatClient_Source_ChatClient_UI_MainRoom_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
