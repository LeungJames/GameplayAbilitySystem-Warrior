// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WarriorBaseCharacter.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"

AWarriorBaseCharacter::AWarriorBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AWarriorBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWarriorBaseCharacter::InitAbilityActorInfo()
{
}

UAbilitySystemComponent* AWarriorBaseCharacter::GetAbilitySystemComponent() const
{
	return WarriorAbilitySystemComponent;
}


void AWarriorBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWarriorBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

