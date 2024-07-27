// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "System/MyAssetManager.h"

UMyGameInstance::UMyGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UMyGameInstance::Init()
{
	Super::Init();

	UMyAssetManager::Initialize();
}

void UMyGameInstance::Shutdown()
{
	Super::Shutdown();
}
