// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.h"
#include "MainActor.generated.h"


UCLASS()
class UE5_CPPSTUDY_API AMainActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY()
	TObjectPtr<AMyActor> MyActor;

	// MyActor를 상속받은 클래스 정보를 담을 수 있는 타입
	UPROPERTY()
	TSubclassOf<AMyActor> MyActorClass;
};
