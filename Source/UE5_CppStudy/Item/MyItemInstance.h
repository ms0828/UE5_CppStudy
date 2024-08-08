// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyDefine.h"
#include "UObject/NoExportTypes.h"
#include "MyItemInstance.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class UE5_CPPSTUDY_API UMyItemInstance : public UObject
{
	GENERATED_BODY()
public:
	UMyItemInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
public:
	void Init(int32 InItemID);


public:
	UPROPERTY()
	int32 ItemID = 0;

	UPROPERTY()
	EItemRarity ItemRarity = EItemRarity::Junk;

};
