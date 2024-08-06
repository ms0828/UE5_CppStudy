// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Character/MyPlayer.h"

UMyAnimInstance::UMyAnimInstance(const FObjectInitializer& ObjectInitializer)
{
}

void UMyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Character = Cast<AMyCharacter>(TryGetPawnOwner());

	if (Character)
		MovementComponent = Character->GetCharacterMovement();
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (Character == nullptr)
		return;
	if (MovementComponent == nullptr)
		return;

	Velocity = MovementComponent->Velocity;
	GroundSpeed = Velocity.Size2D();

	bShouldMove = (GroundSpeed > 3.f && MovementComponent->GetCurrentAcceleration() != FVector::ZeroVector);
	bIsFalling = MovementComponent->IsFalling();
}
