// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interface/CombatInterface.h"
#include "WarriorBaseCharacter.generated.h"

class UGameplayEffect;
class UWarriorAttributeSet;
class UWarriorAbilitySystemComponent;

UCLASS()
class WARRIOR_API AWarriorBaseCharacter : public ACharacter,public IAbilitySystemInterface,public ICombatInterface
{
	GENERATED_BODY()

public:
	AWarriorBaseCharacter();

protected:

	virtual void InitAbilityActorInfo();

	virtual void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> EffectClass);

	virtual void InitPrimaryAttribute();

	virtual void InitVitalAttribute();

	virtual void ApplyEffectToHandleSecondaryAttribute();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UWarriorAbilitySystemComponent> WarriorAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UWarriorAttributeSet> WarriorAbilitySet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AbilitySystem|Attribute")
	TSubclassOf<UGameplayEffect> InitPrimaryAttributeEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AbilitySystem|Attribute")
	TSubclassOf<UGameplayEffect> InitVitalAttributeEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AbilitySystem|Attribute")
	TSubclassOf<UGameplayEffect> CalSecondaryAttributeEffectClass;

public:	

	// From IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface

	// From ICombatInterface
	virtual int32 GetPlayerLevel() const override;
	// ~ End ICombatInterface
	
	FORCEINLINE UWarriorAbilitySystemComponent* GetWarriorAbilitySystemComponent() const {return WarriorAbilitySystemComponent;};
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
