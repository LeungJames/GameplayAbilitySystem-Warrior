// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WarriorBaseCharacter.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"

AWarriorBaseCharacter::AWarriorBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWarriorBaseCharacter::InitAbilityActorInfo()
{
	UE_LOG(LogTemp, Warning, TEXT("InitAbilityActorInfo should not be called in base character class"));
}

void AWarriorBaseCharacter::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> EffectClass)
{
	FGameplayEffectContextHandle ContextHandle = WarriorAbilitySystemComponent->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	FGameplayEffectSpecHandle EffectSpecHandle = WarriorAbilitySystemComponent->MakeOutgoingSpec(EffectClass,1,ContextHandle);

	WarriorAbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*EffectSpecHandle.Data,WarriorAbilitySystemComponent);
}

void AWarriorBaseCharacter::InitPrimaryAttribute()
{
	check(InitPrimaryAttributeEffectClass);
	ApplyEffectToSelf(InitPrimaryAttributeEffectClass);
}

void AWarriorBaseCharacter::InitVitalAttribute()
{
	check(InitVitalAttributeEffectClass)
	ApplyEffectToSelf(InitVitalAttributeEffectClass);
}

void AWarriorBaseCharacter::ApplyEffectToHandleSecondaryAttribute()
{
	check(CalSecondaryAttributeEffectClass);
	ApplyEffectToSelf(CalSecondaryAttributeEffectClass);
}

UAbilitySystemComponent* AWarriorBaseCharacter::GetAbilitySystemComponent() const
{
	return WarriorAbilitySystemComponent;
}

int32 AWarriorBaseCharacter::GetPlayerLevel() const
{
	return  1;
}

void AWarriorBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

