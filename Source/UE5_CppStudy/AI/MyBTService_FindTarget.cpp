// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTService_FindTarget.h"
#include "Character/MyCharacter.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AI/MyAIController.h"

UMyBTService_FindTarget::UMyBTService_FindTarget()
{
	NodeName = TEXT("FindTargetService");
	Interval = 0.5f;
}

void UMyBTService_FindTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* LocalPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (LocalPawn == nullptr)
	{
		return;
	}

	UWorld* World = LocalPawn->GetWorld();
	if (World == nullptr)
	{
		return;
	}


	FVector Location = LocalPawn->GetActorLocation();
	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, LocalPawn);

	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Location,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(SearchRadius),
		CollisionQueryParam
	);

	if (bResult)
	{
		for (FOverlapResult& OverlapResult : OverlapResults)
		{
			AMyCharacter* MyCharacter = Cast<AMyCharacter>(OverlapResult.GetActor());
			if (MyCharacter)
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(TargetKey.SelectedKeyName, MyCharacter);
				DrawDebugSphere(World, Location, SearchRadius, 16, FColor::Green, false, 0.2f);
				return;
			}
		}
	}
	OwnerComp.GetBlackboardComponent()->SetValueAsObject(TargetKey.SelectedKeyName, nullptr);
	DrawDebugSphere(World, Location, SearchRadius, 16, FColor::Red, false, 0.2f);
}
