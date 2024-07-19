// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMyActor::AMyActor()
{
	// 한국어 인코딩 테스트
	PrimaryActorTick.bCanEverTick = true;

	// CDO와 연관되어 있는 코드가 생성자에 들어감
	/*Box = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Engine/EngineMeshes/Cube.Cube'"));
	if (FindMesh.Succeeded())
	{
		Box->SetStaticMesh(FindMesh.Object);
	}*/


	// c++로 계층구조 컴포넌트 만들기
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	RootComponent = Body;
	Body->SetRelativeScale3D(FVector(2, 3, 0.5f));

	Wing = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wing"));
	Wing->SetupAttachment(Body);
	Wing->SetRelativeLocationAndRotation(FVector(0, 0, 0), FRotator(0, 90, 0));
	Wing->SetRelativeScale3D(FVector(3.75f, 0.25f, 0.5f));

	Head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	Head->SetupAttachment(Body);
	Head->SetRelativeLocationAndRotation(FVector(155, 0, 40), FRotator(0, 0, 0));
	Head->SetRelativeScale3D(FVector(0.25f, 0.25f, 0.25f));


	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Engine/EngineMeshes/Cube.Cube'"));
	if (FindMesh.Succeeded())
	{
		Body->SetStaticMesh(FindMesh.Object);
		Wing->SetStaticMesh(FindMesh.Object);
		Head->SetStaticMesh(FindMesh.Object);
	}

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

