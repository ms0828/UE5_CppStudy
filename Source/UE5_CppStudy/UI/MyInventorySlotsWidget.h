// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/MyUserWidget.h"
#include "MyInventorySlotsWidget.generated.h"


class UUniformGridPanel;
class UMyInventorySlotWidget;
class UMyInventoryEntryWidget;
class UMyItemInstance;
class UCanvasPanel;

UCLASS()
class UE5_CPPSTUDY_API UMyInventorySlotsWidget : public UMyUserWidget
{
	GENERATED_BODY()
	
public:
	UMyInventorySlotsWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	void FinishDrag();

protected:
	virtual void NativeConstruct() override;

	void OnInventoryEntryChanged(const FIntPoint& InItemSlotPos, TObjectPtr<UMyItemInstance> Item);

	virtual bool NativeOnDragOver(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	virtual void NativeOnDragLeave(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
protected:

	UPROPERTY()
	TSubclassOf<UMyInventorySlotWidget> SlotWidgetClass;	//TSubclassOf - Not Instance, is Class Info (Static Class)

	UPROPERTY()
	TArray<TObjectPtr<UMyInventorySlotWidget>> SlotWidgets;		// one of Pattern, for Management -> slots in grid pannel 

	UPROPERTY()
	TSubclassOf<UMyInventoryEntryWidget> EntryWidgetClass;

	UPROPERTY()
	TArray<TObjectPtr<UMyInventoryEntryWidget>> EntryWidgets;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UUniformGridPanel> GridPanel_Slots;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCanvasPanel> CanvasPanel_Entries;

private:
	FIntPoint PrevDragOverSlotPos = FIntPoint(-1, -1);
	const int X_COUNT = 10;
	const int Y_COUNT = 5;
};
