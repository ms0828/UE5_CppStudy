// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInventorySubsystem.h"
#include "Item/MyItemInstance.h"

void UMyInventorySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UMyInventorySubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UMyInventorySubsystem::AddDefaultItems()
{
	TObjectPtr<UMyItemInstance> Item = NewObject<UMyItemInstance>();
	Item->Init(100);
	Items.Add(Item);
}
