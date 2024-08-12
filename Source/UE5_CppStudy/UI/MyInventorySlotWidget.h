// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/MyUserWidget.h"
#include "MyInventorySlotWidget.generated.h"
class UImage;
class USizeBox;
/**
 * 
 */
UCLASS()
class UE5_CPPSTUDY_API UMyInventorySlotWidget : public UMyUserWidget
{
	GENERATED_BODY()
public:
	UMyInventorySlotWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USizeBox> SizeBox_Root;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_Slot;
};
