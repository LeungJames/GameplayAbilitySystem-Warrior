// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerState/WarriorPlayerState.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/WarriorAttributeSet.h"

AWarriorPlayerState::AWarriorPlayerState()
{
	WarriorAbilitySystemComponent = CreateDefaultSubobject<UWarriorAbilitySystemComponent>("WarriorAbilitySystemComponent");
	WarriorAbilitySet = CreateDefaultSubobject<UWarriorAttributeSet>("WarriorAbilityAttributeSet");
}

UAbilitySystemComponent* AWarriorPlayerState::GetAbilitySystemComponent() const
{
	return WarriorAbilitySystemComponent;
}

UWarriorAbilitySystemComponent* AWarriorPlayerState::GetWarriorAbilitySystemComponent() const
{
	return WarriorAbilitySystemComponent;
}

UWarriorAttributeSet* AWarriorPlayerState::GetWarriorAttributeSet() const
{
	return WarriorAbilitySet;
}

