// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MyMonster.h"

AMyMonster::AMyMonster()
{
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));
}

void AMyMonster::BeginPlay()
{
	Super::BeginPlay();
}

void AMyMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
