// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "WarriorPlayerState.generated.h"

class UWarriorAbilitySystemComponent;
class UWarriorAttributeSet;
/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorPlayerState : public APlayerState,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AWarriorPlayerState();

	// From IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface

	UWarriorAbilitySystemComponent* GetWarriorAbilitySystemComponent() const;
	UWarriorAttributeSet* GetWarriorAttributeSet() const;

	FORCEINLINE int32 GetPlayerLevel() const { return PlayerLevel; }

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem",meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UWarriorAbilitySystemComponent> WarriorAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem",meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UWarriorAttributeSet> WarriorAbilitySet;

	UPROPERTY(VisibleAnywhere)
	int32 PlayerLevel;
};
