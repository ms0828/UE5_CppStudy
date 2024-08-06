// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "Navigation/PathFollowingComponent.h"

AMyAIController::AMyAIController(const FObjectInitializer& ObjectInitializer)
{

}

void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	
	/*FVector Dest = {0,0,0};
	FAIMoveRequest MoveRequest;
	MoveRequest.SetGoalLocation(Dest);
	MoveRequest.SetAcceptanceRadius(15.f);

	FNavPathSharedPtr NavPath;
	MoveTo(MoveRequest, OUT &NavPath);
	
	if (NavPath.IsValid())
	{
		TArray<FNavPathPoint>& PathPoints = NavPath->GetPathPoints();
		for (const auto& Point : PathPoints)
		{
			const FVector& Location = Point.Location;
			DrawDebugSphere(GetWorld(), Location, 12.f, 12, FColor::Green, false, 10.0f);
		}
		
	}*/

}

void AMyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
