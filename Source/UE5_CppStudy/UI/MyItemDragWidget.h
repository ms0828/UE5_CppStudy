// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/MyUserWidget.h"
#include "MyItemDragWidget.generated.h"


class USizeBox;
class UTextBlock;
class UImage;
class UTexture2D;
class UMyInventorySlotsWidget;
class UMyItemInstance;

UCLASS()
class UE5_CPPSTUDY_API UMyItemDragWidget : public UMyUserWidget
{
	GENERATED_BODY()
	
	
public:
	UMyItemDragWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
	void Init(const FVector2D& InWidgetSize, UTexture2D* InItemIcon, int32 InItemCount);

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USizeBox> SizeBox_Root;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Text_Count;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_Icon;

};
