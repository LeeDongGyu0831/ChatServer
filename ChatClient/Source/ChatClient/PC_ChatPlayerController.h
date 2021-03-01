// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC_ChatPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CHATCLIENT_API APC_ChatPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APC_ChatPlayerController();

	virtual void PostInitializeComponents() override;
	virtual void OnPossess(APawn* aPawn) override;

	//class UUI_Login* GetLoginUI() const;
	//
	//protected:
	//	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	//	TSubclassOf<class UUI_Login> LoginWidgetClass;
	//
	//private:
	//	UPROPERTY()
	//	class UUI_Login* LoginWidget;
};
