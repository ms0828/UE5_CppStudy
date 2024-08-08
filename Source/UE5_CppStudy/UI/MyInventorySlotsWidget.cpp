// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MyInventorySlotsWidget.h"
#include "Components/UniformGridPanel.h"
#include "UI/MyInventorySlotWidget.h"
UMyInventorySlotsWidget::UMyInventorySlotsWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UMyInventorySlotWidget> FindSlotWidgetClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/Item/Inventory/WBP_InventorySlot.WBP_InventorySlot_C'"));
	if (FindSlotWidgetClass.Succeeded())
	{
		SlotWidgetClass = FindSlotWidgetClass.Class;
	}
}

void UMyInventorySlotsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	const int X_COUNT = 10;
	const int Y_COUNT = 5;

	SlotWidgets.SetNum(X_COUNT * Y_COUNT);
	for (int32 y = 0; y < Y_COUNT; y++)
	{
		for (int32 x = 0; x < X_COUNT; x++)
		{
			int32 index = y * X_COUNT + x;

			UMyInventorySlotWidget* SlotWidget = CreateWidget<UMyInventorySlotWidget>(GetOwningPlayer(), SlotWidgetClass);
			SlotWidgets[index] = SlotWidget;
			GridPanel_Slots->AddChildToUniformGrid(SlotWidget, y, x);
		}
	}
}
