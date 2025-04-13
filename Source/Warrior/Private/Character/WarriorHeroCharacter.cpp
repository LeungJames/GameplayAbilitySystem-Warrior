// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WarriorHeroCharacter.h"

#include "AbilitySystemComponent.h"
#include "PlayerState/WarriorPlayerState.h"

void AWarriorHeroCharacter::InitAbilityActorInfo()
{
	if (AWarriorPlayerState* WarriorPlayerState = GetPlayerState<AWarriorPlayerState>())
	{
		WarriorPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(WarriorPlayerState,this);
		WarriorAbilitySet = WarriorPlayerState->GetWarriorAttributeSet();
		WarriorAbilitySystemComponent = WarriorPlayerState->GetWarriorAbilitySystemComponent();
	}
}

void AWarriorHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilityActorInfo();
}
