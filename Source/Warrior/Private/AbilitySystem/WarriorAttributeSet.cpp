// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/WarriorAttributeSet.h"

UWarriorAttributeSet::UWarriorAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
	InitMana(30.f);
	InitMaxMana(50.f);
}

void UWarriorAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0, GetMaxHealth());
	}

	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0, GetMaxMana());
	}
}
