// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"
#include "System/MyAssetManager.h"
#include "Data/MyInputData.h"
#include "MyGameplayTags.h"
#include "Character/MyPlayer.h"
#include "Character/MyCharacter.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"

AMyPlayerController::AMyPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;
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

	MyPlayer = Cast<AMyPlayer>(GetCharacter());

}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (const UMyInputData* InputData = UMyAssetManager::GetAssetByName<UMyInputData>("InputData"))
	{
		UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

		auto Action1 = InputData->FindInputActionByTag(MyGameplayTags::Input_Action_SetDestination);

		EnhancedInputComponent->BindAction(Action1, ETriggerEvent::Started, this, &ThisClass::OnInputStarted);
		EnhancedInputComponent->BindAction(Action1, ETriggerEvent::Triggered, this, &ThisClass::OnSetDestinationTriggered);
		EnhancedInputComponent->BindAction(Action1, ETriggerEvent::Completed, this, &ThisClass::OnSetDestinationReleased);
		EnhancedInputComponent->BindAction(Action1, ETriggerEvent::Canceled, this, &ThisClass::OnSetDestinationReleased);

	}
}

void AMyPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	TickCursorTrace();
	if (GetCharacter()->GetMesh()->GetAnimInstance()->Montage_IsPlaying(nullptr) == false)
	{
		SetCreatureState(ECreatureState::Moving);
	}

	ChaseTargetAndAttack();
}

void AMyPlayerController::HandleGameplayEvent(FGameplayTag EventTag)
{
	if (EventTag.MatchesTag(MyGameplayTags::Event_Montage_Attack))
	{
		if (TargetActor)
		{
			TargetActor->OnDamage(MyPlayer->FinalDamage, MyPlayer);
		}
	}
}

void AMyPlayerController::TickCursorTrace()
{
	if (bMousePressed)
	{
		return;
	}

	FHitResult OutCursorHit;
	if (GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, OUT OutCursorHit) == false)
	{
		return;
	}

	AMyCharacter* LocalHighlightActor = Cast<AMyCharacter>(OutCursorHit.GetActor());
	if (LocalHighlightActor == nullptr)
	{
		// 있었는데 없어지는 경우.
		if (HighlightActor)
		{
			HighlightActor->UnHighlight();
		}
	}
	else
	{
		if (HighlightActor)
		{
			// 기존 하이라이트와 다른 캐릭터를 선택한 경우
			if (HighlightActor != LocalHighlightActor)
			{
				HighlightActor->UnHighlight();
				LocalHighlightActor->Highlight();
			}
		}
		else
		{
			LocalHighlightActor->Highlight();
		}
	}

	HighlightActor = LocalHighlightActor;

}

void AMyPlayerController::ChaseTargetAndAttack()
{
	if (TargetActor == nullptr)
	{
		return;
	}

	if (GetCreatureState() == ECreatureState::Skill)
	{
		return;
	}

	FVector Direction = TargetActor->GetActorLocation() - MyPlayer->GetActorLocation();
	if (Direction.Length() < 250.f)
	{
		GEngine->AddOnScreenDebugMessage(0, 1.f, FColor::Cyan, TEXT("Attack"));
		

		if (AttackMontage)
		{
			if (bMousePressed)
			{
				//if (GetCharacter()->GetMesh()->GetAnimInstance()->Montage_IsPlaying(nullptr) == false)
				//TargetActor->OnDamage(MyPlayer->FinalDamage, MyPlayer);

				FRotator Rotator = UKismetMathLibrary::FindLookAtRotation(MyPlayer->GetActorLocation(), TargetActor->GetActorLocation());
				MyPlayer->SetActorRotation(Rotator);

				GetCharacter()->PlayAnimMontage(AttackMontage);
				SetCreatureState(ECreatureState::Skill);

				TargetActor = HighlightActor;
			}
			else
			{
				TargetActor = nullptr;
			}

		}


		
	}
	else
	{
		FVector WorldDirection = Direction.GetSafeNormal();
		MyPlayer->AddMovementInput(WorldDirection, 1.0, false);
	}
}

void AMyPlayerController::OnInputStarted()
{
	StopMovement();
	bMousePressed = true;
	TargetActor = HighlightActor;
}

void AMyPlayerController::OnSetDestinationTriggered()
{
	if (GetCreatureState() == ECreatureState::Skill)
	{
		return;
	}

	if (TargetActor)
	{
		return;
	}

	FollowTime += GetWorld()->GetDeltaSeconds();

	FHitResult Hit;
	bool bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, OUT Hit);

	if (bHitSuccessful)
	{
		CachedDestination = Hit.Location;
	}

	if (MyPlayer)
	{
		FVector WorldDirection = (CachedDestination - MyPlayer->GetActorLocation()).GetSafeNormal();
		MyPlayer->AddMovementInput(WorldDirection, 1.0, false);
	}
}

void AMyPlayerController::OnSetDestinationReleased()
{
	bMousePressed = false;

	if (GetCreatureState() == ECreatureState::Skill)
	{
		return;
	}

	if (FollowTime <= ShortPressThreshold)
	{
		if (TargetActor == nullptr)
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
		}
	}

	FollowTime = 0.f;
}

ECreatureState AMyPlayerController::GetCreatureState()
{
	if (MyPlayer)
	{
		return MyPlayer->CreatureState;
	}
	return ECreatureState::None;
}

void AMyPlayerController::SetCreatureState(ECreatureState InState)
{
	if (MyPlayer)
	{
		MyPlayer->CreatureState = InState;
	}
}
