// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Interface/MyHighlightInterface.h"
#include "MyDefine.h"
#include "GameplayTagContainer.h"
#include "AbilitySystemInterface.h"
#include "MyCharacter.generated.h"
UCLASS()
class UE5_CPPSTUDY_API AMyCharacter : public ACharacter, public IMyHighlightInterface, public IAbilitySystemInterface
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
	
public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void InitAbilitySystem();
protected:
	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;

public:
	UPROPERTY(BlueprintReadWrite)
	ECreatureState CreatureState = ECreatureState::Moving;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UWidgetComponent> HpBarComponent;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class UMyAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class UMyAttributeSet> AttributeSet;

public:
	void AddCharacterAbilities();

	UPROPERTY(EditAnywhere, Category=Abilities)
	TArray<TSubclassOf<class UGameplayAbility>> StartupAbilities;

};
