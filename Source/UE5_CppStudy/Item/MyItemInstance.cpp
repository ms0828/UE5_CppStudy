// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/MyItemInstance.h"

UMyItemInstance::UMyItemInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UMyItemInstance::Init(int32 InItemID)
{
	if (InItemID <= 0)
		return;

	ItemID = InItemID;
	ItemRarity = EItemRarity::Common;
}
