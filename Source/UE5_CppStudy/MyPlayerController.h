// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyDefine.h"
#include "GameplayTagContainer.h"
#include "MyPlayerController.generated.h"

struct FInputActionValue;
class UNiagaraSystem;
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
	virtual void PlayerTick(float DeltaTime) override;

public:
	virtual void HandleGameplayEvent(FGameplayTag EventTag);
private:
	void TickCursorTrace();
	void ChaseTargetAndAttack();
private:
	void OnInputStarted();
	void OnSetDestinationTriggered();
	void OnSetDestinationReleased();
	ECreatureState GetCreatureState();
	void SetCreatureState(ECreatureState InState);


public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ShortPressThreshold = 0.3f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UNiagaraSystem> FXCursor;
	
private:
	FVector CachedDestination;
	float FollowTime;
	bool bMousePressed = false;

protected:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<class AMyCharacter> TargetActor;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<class AMyCharacter> HighlightActor;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<class AMyPlayer> MyPlayer;

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UAnimMontage> AttackMontage;

};
