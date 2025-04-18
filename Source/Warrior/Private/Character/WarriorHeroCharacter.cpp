// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WarriorHeroCharacter.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/WarriorAttributeSet.h"
#include "PlayerState/WarriorPlayerState.h"
#include "Widget/WarriorHUD.h"

int32 AWarriorHeroCharacter::GetPlayerLevel() const
{
	AWarriorPlayerState* WarriorPlayerState = GetPlayerState<AWarriorPlayerState>();
	check(WarriorPlayerState);
	return WarriorPlayerState->GetPlayerLevel();
}

void AWarriorHeroCharacter::InitAbilityActorInfo() 
{
	AWarriorPlayerState* WarriorPlayerState = GetPlayerState<AWarriorPlayerState>();
	if (WarriorPlayerState)
	{
		WarriorPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(WarriorPlayerState,this);
		
		WarriorAbilitySet = WarriorPlayerState->GetWarriorAttributeSet();
		WarriorAbilitySystemComponent = WarriorPlayerState->GetWarriorAbilitySystemComponent();
		WarriorAbilitySystemComponent->AbilityActorInfoSet();
	}
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	AWarriorHUD* WarriorHUD = PlayerController->GetHUD<AWarriorHUD>();
	WarriorHUD->InitOverlay(PlayerController,WarriorPlayerState,WarriorPlayerState->GetAbilitySystemComponent(),WarriorAbilitySet);
}

void AWarriorHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilityActorInfo();

	InitPrimaryAttribute();
	ApplyEffectToHandleSecondaryAttribute();
	InitVitalAttribute();
}
