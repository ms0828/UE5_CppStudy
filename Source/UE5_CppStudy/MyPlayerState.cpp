// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerState.h"
#include "Attributes/MyPlayerSet.h"
#include "AbilitySystem/MyAbilitySystemComponent.h"
AMyPlayerState::AMyPlayerState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	AbilitySystemComponent = CreateDefaultSubobject<UMyAbilitySystemComponent>("AbilitySystemComponent");
	PlayerSet = CreateDefaultSubobject<UMyPlayerSet>("PlayerSet");
}

UAbilitySystemComponent* AMyPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UMyAbilitySystemComponent* AMyPlayerState::GetMyAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UMyPlayerSet* AMyPlayerState::GetMyPlayerSet() const
{
	return PlayerSet;
}


