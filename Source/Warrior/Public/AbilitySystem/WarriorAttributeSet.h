// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "WarriorAttributeSet.generated.h"


class AController;
class ACharacter;

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()
 
	FEffectProperties(){}
 
	FGameplayEffectContextHandle EffectContextHandle;
 
	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;
 
	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;
 
	UPROPERTY()
	AController* SourceController = nullptr;
 
	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;
 
	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;
 
	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;
 
	UPROPERTY()
	AController* TargetController = nullptr;
 
	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UWarriorAttributeSet();


	/*
	 * Primary Attributes
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, Strength);
 
	UPROPERTY(BlueprintReadOnly, Category = "Primary Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, Intelligence);
 
	UPROPERTY(BlueprintReadOnly, Category = "Primary Attributes")
	FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, Resilience);
 
	UPROPERTY(BlueprintReadOnly, Category = "Primary Attributes")
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, Vigor);

	/*
	 *	Vital Attributes
	 */
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

	/*
	 * Secondary Attributes
	 */
	UPROPERTY(BlueprintReadOnly,Category = "Secondary Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, Armor);
 
	UPROPERTY(BlueprintReadOnly,Category = "Secondary Attributes")
	FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, ArmorPenetration);
 
	UPROPERTY(BlueprintReadOnly,Category = "Secondary Attributes")
	FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, BlockChance);
 
	UPROPERTY(BlueprintReadOnly,Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, CriticalHitChance);
 
	UPROPERTY(BlueprintReadOnly,Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, CriticalHitDamage);
 
	UPROPERTY(BlueprintReadOnly,Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitResistance;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, CriticalHitResistance);
 
	UPROPERTY(BlueprintReadOnly,Category = "Secondary Attributes")
	FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, HealthRegeneration);
 
	UPROPERTY(BlueprintReadOnly,Category = "Secondary Attributes")
	FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, ManaRegeneration);

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};
