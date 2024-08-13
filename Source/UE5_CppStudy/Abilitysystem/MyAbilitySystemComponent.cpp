// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilitysystem/MyAbilitySystemComponent.h"

void UMyAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<class UGameplayAbility>>& StartupAbilities)
{
	for (auto& AbilityClass : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		FGameplayAbilitySpecHandle SpecHandle = GiveAbility(AbilitySpec);

		//TryActivateAbility(SpecHandle);
		SpecHandles.Add(SpecHandle);
	}

}

void UMyAbilitySystemComponent::ActivateAbility(FGameplayTag AbilityTag)
{
	for (FGameplayAbilitySpecHandle& SpecHandle : SpecHandles)
	{
		TryActivateAbility(SpecHandle);
	}
}
