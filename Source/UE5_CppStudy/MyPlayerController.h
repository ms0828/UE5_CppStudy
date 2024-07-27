// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

struct FInputActionValue;
/**
 * 
 */
UCLASS()
class UE5_CPPSTUDY_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMyPlayerController(const FObjectInitializer& ObjectInitializer);
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	

private:
	void Input_Move(const FInputActionValue& InputValue);
	void Input_Turn(const FInputActionValue& InputValue);
	void Input_Jump(const FInputActionValue& InputValue);
	void Input_Attack(const FInputActionValue& InputValue);

protected:
	

};
