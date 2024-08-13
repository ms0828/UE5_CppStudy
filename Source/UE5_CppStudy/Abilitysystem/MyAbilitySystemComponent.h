// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "MyAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class UE5_CPPSTUDY_API UMyAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	void AddCharacterAbilities(const TArray<TSubclassOf<class UGameplayAbility>>& StartupAbilities);

	TArray<FGameplayAbilitySpecHandle> SpecHandles;

	void ActivateAbility(FGameplayTag AbilityTag);
};
