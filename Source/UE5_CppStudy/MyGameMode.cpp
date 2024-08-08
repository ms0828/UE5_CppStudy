// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
#include "MyInventorySubsystem.h"
#include "Subsystems/SubsystemBlueprintLibrary.h"
void AMyGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	UMyInventorySubsystem* Inventory = Cast<UMyInventorySubsystem>(USubsystemBlueprintLibrary::GetWorldSubsystem(this, UMyInventorySubsystem::StaticClass()));
	if (Inventory)
	{
		Inventory->AddDefaultItems();
	}
}
