// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"
#include "System/MyAssetManager.h"
#include "Data/MyInputData.h"
#include "MyGameplayTags.h"
#include "Character/MyCharacter.h"
AMyPlayerController::AMyPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (const UMyInputData* InputData = UMyAssetManager::GetAssetByName<UMyInputData>("InputData"))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputData->InputMappingContext, 0);
		}
	}

}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (const UMyInputData* InputData = UMyAssetManager::GetAssetByName<UMyInputData>("InputData"))
	{
		UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

		auto Action1 = InputData->FindInputActionByTag(MyGameplayTags::Input_Action_Move);
		EnhancedInputComponent->BindAction(Action1, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);

		auto Action2 = InputData->FindInputActionByTag(MyGameplayTags::Input_Action_Turn);
		EnhancedInputComponent->BindAction(Action2, ETriggerEvent::Triggered, this, &ThisClass::Input_Turn);

		auto Action3 = InputData->FindInputActionByTag(MyGameplayTags::Input_Action_Jump);
		EnhancedInputComponent->BindAction(Action3, ETriggerEvent::Triggered, this, &ThisClass::Input_Jump);

		auto Action4 = InputData->FindInputActionByTag(MyGameplayTags::Input_Action_Attack);
		EnhancedInputComponent->BindAction(Action4, ETriggerEvent::Triggered, this, &ThisClass::Input_Attack);

		//EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
		//EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &ThisClass::Input_Turn);
	}
}


void AMyPlayerController::Input_Move(const FInputActionValue& InputValue)
{
	FVector2D MovementVector = InputValue.Get<FVector2D>();
	if (MovementVector.X != 0)
	{
		//FVector Direction = FVector::ForwardVector * MovementVector.X;
		//GetPawn()->AddActorWorldOffset(Direction * 50.f);
		FRotator Rotator = GetControlRotation();
		FVector Direction = UKismetMathLibrary::GetForwardVector(FRotator(0, Rotator.Yaw, 0));
		GetPawn()->AddMovementInput(Direction, MovementVector.X);
	}
	if (MovementVector.Y != 0)
	{
		//FVector Direction = FVector::RightVector * MovementVector.Y;
		//GetPawn()->AddActorWorldOffset(Direction * 50.f);
		FRotator Rotator = GetControlRotation();
		FVector Direction = UKismetMathLibrary::GetRightVector(FRotator(0, Rotator.Yaw, 0));
		GetPawn()->AddMovementInput(Direction, MovementVector.Y);
	}
}

void AMyPlayerController::Input_Turn(const FInputActionValue& InputValue)
{
	float Val = InputValue.Get<float>();
	AddYawInput(Val);
}

void AMyPlayerController::Input_Jump(const FInputActionValue& InputValue)
{
	if (AMyCharacter* Char = Cast<AMyCharacter>(GetPawn()))
	{
		Char->Jump();
	}
}

void AMyPlayerController::Input_Attack(const FInputActionValue& InputValue)
{
	UE_LOG(LogTemp, Log, TEXT("ATTACK"));
}
