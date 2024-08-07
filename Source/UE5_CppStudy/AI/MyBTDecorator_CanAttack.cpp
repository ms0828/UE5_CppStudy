// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTDecorator_CanAttack.h"
#include "MyAIController.h"
#include "Character/MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UMyBTDecorator_CanAttack::UMyBTDecorator_CanAttack()
{
	NodeName = TEXT("CanAttack");
}

bool UMyBTDecorator_CanAttack::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (ControllingPawn == nullptr)
	{
		return false;
	}

	AMyCharacter* Target = Cast<AMyCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(TargetKey.SelectedKeyName));
	if (Target == nullptr)
	{
		return false;
	}

	return (Target->GetDistanceTo(ControllingPawn) <= 200);

}
