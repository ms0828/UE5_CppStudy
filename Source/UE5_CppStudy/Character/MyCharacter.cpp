// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "MyDefine.h"
// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyCharacter::HandleGameplayEvent(FGameplayTag EventTag)
{

}

void AMyCharacter::Highlight()
{
	bHighlighted = true;
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(250);
}

void AMyCharacter::UnHighlight()
{
	bHighlighted = false;
	GetMesh()->SetRenderCustomDepth(false);
}

void AMyCharacter::OnDamage(int32 Damage, TObjectPtr<AMyCharacter> Attacker)
{
	Hp = FMath::Clamp(Hp - Damage, 0, MaxHp);
	if (Hp == 0)
	{
		OnDead(Attacker);
	}
	
	D(FString::Printf(TEXT("%d"), Hp));
}

void AMyCharacter::OnDead(TObjectPtr<AMyCharacter> Attacker)
{
	if (CreatureState == ECreatureState::Dead)
	{
		return;
	}
	CreatureState = ECreatureState::Dead;
}


