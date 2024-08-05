// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MyCharacter.h"
#include "MyAnimNotify_SendGameplayEvent.h"

UMyAnimNotify_SendGameplayEvent::UMyAnimNotify_SendGameplayEvent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UMyAnimNotify_SendGameplayEvent::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	AMyCharacter* LocalCharacter = Cast<AMyCharacter>(MeshComp->GetOwner());
	if (LocalCharacter)
	{
		LocalCharacter->HandleGameplayEvent(EventTag);
	}
}
