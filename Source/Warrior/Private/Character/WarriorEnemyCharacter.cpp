// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WarriorEnemyCharacter.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/WarriorAttributeSet.h"

AWarriorEnemyCharacter::AWarriorEnemyCharacter()
{
	WarriorAbilitySystemComponent = CreateDefaultSubobject<UWarriorAbilitySystemComponent>("WarriorAbilitySystemComponent");
	WarriorAbilitySet = CreateDefaultSubobject<UWarriorAttributeSet>("WarriorAbilityAttributeSet");
}

void AWarriorEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();
}

void AWarriorEnemyCharacter::InitAbilityActorInfo()
{
	WarriorAbilitySystemComponent->InitAbilityActorInfo(this, this);
	WarriorAbilitySystemComponent->AbilityActorInfoSet();
}
