// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MyHpBarWidget.h"
#include "Components/ProgressBar.h"
UMyHpBarWidget::UMyHpBarWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UMyHpBarWidget::NativeConstruct()
{
	Super::NativeConstruct();

}

void UMyHpBarWidget::SetHpRatio(float Ratio)
{
	if (HpBar)
	{
		HpBar->SetPercent(Ratio);
	}
}
