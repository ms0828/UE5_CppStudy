// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "MyBTService_FindTarget.generated.h"

/**
 * 
 */
UCLASS()
class UE5_CPPSTUDY_API UMyBTService_FindTarget : public UBTService
{
	GENERATED_BODY()
	
public:
	UMyBTService_FindTarget();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SearchRadius = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBlackboardKeySelector TargetKey;

};
