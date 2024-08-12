// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/MyUserWidget.h"
#include "MyInventoryEntryWidget.generated.h"

/**
 * 
 */
class USizeBox;
class UTextBlock;
class UImage;
class UMyInventorySlotsWidget;
class UMyItemInstance;
class UMyItemDragWidget;

UCLASS()
class UE5_CPPSTUDY_API UMyInventoryEntryWidget : public UMyUserWidget
{
	GENERATED_BODY()
	
public:
	UMyInventoryEntryWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
	virtual void NativeConstruct() override;
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	virtual void NativeOnDragCancelled(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

	void RefreshWidgetOpacity(bool bClearlyVisible);
	void RefreshItemCount(int32 NewItemCount);

	void Init(UMyInventorySlotsWidget* InSlotsWidget, UMyItemInstance* InItemInstace, int32 InItemCount);

private:
	FIntPoint CachedFromSlotPos = FIntPoint::ZeroValue;
	FVector2D CachedDeltaWidgetPos = FVector2D::ZeroVector;
	int32 ItemCount = 0;

protected:
	UPROPERTY()
	TObjectPtr<UMyInventorySlotsWidget> SlotsWidget;

	UPROPERTY()
	TObjectPtr<UMyItemInstance> ItemInstance;

	UPROPERTY()
	TSubclassOf<UMyItemDragWidget> DragWidgetClass;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USizeBox> SizeBox_Root;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Text_Count;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_Icon;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_Hover;
};
