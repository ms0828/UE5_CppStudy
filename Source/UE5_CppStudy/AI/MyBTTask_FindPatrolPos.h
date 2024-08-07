// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "MyBTTask_FindPatrolPos.generated.h"

/**
 * 
 */
UCLASS()
class UE5_CPPSTUDY_API UMyBTTask_FindPatrolPos : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UMyBTTask_FindPatrolPos();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	UPROPERTY(EditAnywhere, Category = Blackboard)
	FBlackboardKeySelector PatrolPosKey;

	UPROPERTY(EditAnywhere, Category = Blackboard)
	float SearchRadius = 300.f;
};
