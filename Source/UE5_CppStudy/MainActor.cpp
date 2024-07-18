// Fill out your copyright notice in the Description page of Project Settings.


#include "MainActor.h"
#include "MyActor.h"
// Sets default values
AMainActor::AMainActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 블루 프린트 클래스 타입의 경로는 마지막에 _C 붙여야함
	ConstructorHelpers::FClassFinder<AMyActor> FindClass(TEXT("/Script/Engine.Blueprint'/Game/BluePrints/BP_MyActor.BP_MyActor_C'"));
	if (FindClass.Succeeded())
	{
		MyActorClass = FindClass.Class;
	}
}

// Called when the game starts or when spawned
void AMainActor::BeginPlay()
{
	Super::BeginPlay();

	FVector Location(0, 0, 0);
	FRotator Rotation(0, 0, 0);

	//MyActor = GetWorld()->SpawnActor<AMyActor>(Location, Rotation);
	//GetWorld()->DestroyActor(MyActor);

	MyActor = Cast<AMyActor>(GetWorld()->SpawnActor(MyActorClass));
}

// Called every frame
void AMainActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

