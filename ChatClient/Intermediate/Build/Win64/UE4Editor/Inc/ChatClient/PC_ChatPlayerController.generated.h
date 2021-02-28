// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CHATCLIENT_PC_ChatPlayerController_generated_h
#error "PC_ChatPlayerController.generated.h already included, missing '#pragma once' in PC_ChatPlayerController.h"
#endif
#define CHATCLIENT_PC_ChatPlayerController_generated_h

#define ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_SPARSE_DATA
#define ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_RPC_WRAPPERS
#define ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPC_ChatPlayerController(); \
	friend struct Z_Construct_UClass_APC_ChatPlayerController_Statics; \
public: \
	DECLARE_CLASS(APC_ChatPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(APC_ChatPlayerController)


#define ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAPC_ChatPlayerController(); \
	friend struct Z_Construct_UClass_APC_ChatPlayerController_Statics; \
public: \
	DECLARE_CLASS(APC_ChatPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ChatClient"), NO_API) \
	DECLARE_SERIALIZER(APC_ChatPlayerController)


#define ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APC_ChatPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APC_ChatPlayerController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APC_ChatPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APC_ChatPlayerController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APC_ChatPlayerController(APC_ChatPlayerController&&); \
	NO_API APC_ChatPlayerController(const APC_ChatPlayerController&); \
public:


#define ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APC_ChatPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APC_ChatPlayerController(APC_ChatPlayerController&&); \
	NO_API APC_ChatPlayerController(const APC_ChatPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APC_ChatPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APC_ChatPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APC_ChatPlayerController)


#define ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_PRIVATE_PROPERTY_OFFSET
#define ChatClient_Source_ChatClient_PC_ChatPlayerController_h_12_PROLOG
#define ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_SPARSE_DATA \
	ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_RPC_WRAPPERS \
	ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_INCLASS \
	ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_PRIVATE_PROPERTY_OFFSET \
	ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_SPARSE_DATA \
	ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_INCLASS_NO_PURE_DECLS \
	ChatClient_Source_ChatClient_PC_ChatPlayerController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHATCLIENT_API UClass* StaticClass<class APC_ChatPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ChatClient_Source_ChatClient_PC_ChatPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
