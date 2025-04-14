// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "WarriorAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UWarriorAttributeSet();

 
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, Health);
	
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, MaxHealth);
	
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, Mana);
	
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, MaxMana);

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
};
