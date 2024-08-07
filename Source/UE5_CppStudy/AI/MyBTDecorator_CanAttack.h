// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "MyBTDecorator_CanAttack.generated.h"

/**
 * 
 */
UCLASS()
class UE5_CPPSTUDY_API UMyBTDecorator_CanAttack : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UMyBTDecorator_CanAttack();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	UPROPERTY(EditAnywhere, Category = Blackboard)
	FBlackboardKeySelector TargetKey;

};
