// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MyMonster.h"
#include "Attributes/MyMonsterSet.h"
#include "AbilitySystem/MyAbilitySystemComponent.h"

AMyMonster::AMyMonster()
{
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));
	AbilitySystemComponent = CreateDefaultSubobject<UMyAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSet = CreateDefaultSubobject<UMyMonsterSet>("MonsterSet");
	
}

void AMyMonster::BeginPlay()
{
	Super::BeginPlay();
	InitAbilitySystem();
}

void AMyMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyMonster::InitAbilitySystem()
{
	Super::InitAbilitySystem();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
