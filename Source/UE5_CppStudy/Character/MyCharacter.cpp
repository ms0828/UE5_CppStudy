// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "MyDefine.h"
#include "Components/WidgetComponent.h"
#include "Attributes/MyAttributeSet.h"
#include "UI/MyHpBarWidget.h"
#include "AbilitySystem/MyAbilitySystemComponent.h"
// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	HpBarComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthBar"));
	HpBarComponent->SetupAttachment(GetRootComponent());

	ConstructorHelpers::FClassFinder<UUserWidget> HealthBarWidgetClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrints/UI/WBP_HpBar.WBP_HpBar_C'"));
	if (HealthBarWidgetClass.Succeeded())
	{
		HpBarComponent->SetWidgetClass(HealthBarWidgetClass.Class);
		HpBarComponent->SetWidgetSpace(EWidgetSpace::Screen);
		HpBarComponent->SetDrawAtDesiredSize(true);
		HpBarComponent->SetRelativeLocation(FVector(0, 0, 120));
	}
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	RefreshHpBarRatio();
	AddCharacterAbilities();
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyCharacter::HandleGameplayEvent(FGameplayTag EventTag)
{

}

void AMyCharacter::Highlight()
{
	bHighlighted = true;
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(250);
}

void AMyCharacter::UnHighlight()
{
	bHighlighted = false;
	GetMesh()->SetRenderCustomDepth(false);
}

void AMyCharacter::OnDamage(int32 Damage, TObjectPtr<AMyCharacter> Attacker)
{
	float Hp = AttributeSet->GetHealth();
	float MaxHp = AttributeSet->GetMaxHealth();
	Hp = FMath::Clamp(Hp - Damage, 0, MaxHp);
	AttributeSet->SetHealth(Hp);
	if (Hp == 0)
	{
		OnDead(Attacker);
	}
	
	RefreshHpBarRatio();
	//D(FString::Printf(TEXT("%d"), Hp));
}

void AMyCharacter::OnDead(TObjectPtr<AMyCharacter> Attacker)
{
	if (CreatureState == ECreatureState::Dead)
	{
		return;
	}
	CreatureState = ECreatureState::Dead;
}

void AMyCharacter::RefreshHpBarRatio()
{
	if (HpBarComponent && AttributeSet)
	{
		float Hp = AttributeSet->GetHealth();
		float MaxHp = AttributeSet->GetMaxHealth();
		float Ratio = static_cast<float>(Hp) / MaxHp;
		UMyHpBarWidget* HpBar = Cast<UMyHpBarWidget>(HpBarComponent->GetUserWidgetObject());
		HpBar->SetHpRatio(Ratio);
	}
	
}

UAbilitySystemComponent* AMyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AMyCharacter::InitAbilitySystem()
{

}

void AMyCharacter::AddCharacterAbilities()
{
	UMyAbilitySystemComponent* ASC = Cast<UMyAbilitySystemComponent>(AbilitySystemComponent);
	if (ASC == nullptr)
	{
		return;
	}

	ASC->AddCharacterAbilities(StartupAbilities);
}


