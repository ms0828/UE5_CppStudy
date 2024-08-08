// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/MyUserWidget.h"
#include "MyInventorySlotsWidget.generated.h"


class UUniformGridPanel;
class UMyInventorySlotWidget;

UCLASS()
class UE5_CPPSTUDY_API UMyInventorySlotsWidget : public UMyUserWidget
{
	GENERATED_BODY()
	
public:
	UMyInventorySlotsWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void NativeConstruct() override;

protected:

	UPROPERTY()
	TSubclassOf<UMyInventorySlotWidget> SlotWidgetClass;	//TSubclassOf - Not Instance, is Class Info (Static Class)

	UPROPERTY()
	TArray<TObjectPtr<UMyInventorySlotWidget>> SlotWidgets;		// one of Pattern, for Management -> slots in grid pannel 

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UUniformGridPanel> GridPanel_Slots;


};
