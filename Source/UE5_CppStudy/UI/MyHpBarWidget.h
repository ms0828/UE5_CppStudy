// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyHpBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class UE5_CPPSTUDY_API UMyHpBarWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UMyHpBarWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void NativeConstruct() override;

public:
	void SetHpRatio(float Ratio);

protected:
	UPROPERTY(meta=(BindWidget), BlueprintReadWrite)
	TObjectPtr<class UProgressBar> HpBar;
};
