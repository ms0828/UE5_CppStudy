// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "MyDragDropOperation.generated.h"

/**
 * 
 */
class UMyItemInstance;

UCLASS()
class UE5_CPPSTUDY_API UMyDragDropOperation : public UDragDropOperation
{
	GENERATED_BODY()
public:
	UMyDragDropOperation(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	FIntPoint FromItemSlotPos = FIntPoint::ZeroValue;
	
public:
	UPROPERTY()
	TObjectPtr<UMyItemInstance> ItemInstance;

	FVector2D DeltaWidgetPos = FVector2D::ZeroVector;
};
