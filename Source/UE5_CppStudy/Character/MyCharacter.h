// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Interface/MyHighlightInterface.h"
#include "MyDefine.h"
#include "GameplayTagContainer.h"
#include "MyCharacter.generated.h"

UCLASS()
class UE5_CPPSTUDY_API AMyCharacter : public ACharacter, public IMyHighlightInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void HandleGameplayEvent(FGameplayTag EventTag);

public:
	virtual void Highlight() override;
	virtual void UnHighlight() override;

	virtual void OnDamage(int32 Damage, TObjectPtr<AMyCharacter> Attacker);
	virtual void OnDead(TObjectPtr<AMyCharacter> Attacker);

	void RefreshHpBarRatio();
	
protected:
	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;

public:
	UPROPERTY(BlueprintReadWrite)
	ECreatureState CreatureState = ECreatureState::Moving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxHp = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Hp = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 FinalDamage = 10;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UWidgetComponent> HpBarComponent;
};
