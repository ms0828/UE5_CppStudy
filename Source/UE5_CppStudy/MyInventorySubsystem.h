// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "MyInventorySubsystem.generated.h"

/**
 * 
 */

class UMyItemInstance;
UCLASS()
class UE5_CPPSTUDY_API UMyInventorySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	const TArray<TObjectPtr<UMyItemInstance>>& GetItems() { return Items; }

	// for test
	void AddDefaultItems();

protected:
	UPROPERTY()
	TArray<TObjectPtr<UMyItemInstance>> Items;
};
