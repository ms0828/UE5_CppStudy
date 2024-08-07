// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTask_FindPatrolPos.h"
#include "AI/MyAIController.h"
#include "Character/MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "NavigationSystem.h"

UMyBTTask_FindPatrolPos::UMyBTTask_FindPatrolPos()
{
	NodeName = TEXT("FindPatrolPos");
}

EBTNodeResult::Type UMyBTTask_FindPatrolPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (ControllingPawn == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(ControllingPawn->GetWorld());
	if (NavSystem == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	
	FNavLocation NextPatrol;
	if (NavSystem->GetRandomPointInNavigableRadius(ControllingPawn->GetActorLocation(), SearchRadius, OUT NextPatrol))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(PatrolPosKey.SelectedKeyName, NextPatrol);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
