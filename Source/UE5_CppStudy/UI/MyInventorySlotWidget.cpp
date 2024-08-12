// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MyInventorySlotWidget.h"
#include "Components/SizeBox.h"
UMyInventorySlotWidget::UMyInventorySlotWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UMyInventorySlotWidget::NativeConstruct()
{
	Super::NativeConstruct();
	SizeBox_Root->SetWidthOverride(50);
	SizeBox_Root->SetHeightOverride(50);
}

