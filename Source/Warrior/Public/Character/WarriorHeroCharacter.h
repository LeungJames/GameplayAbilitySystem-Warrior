// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/WarriorBaseCharacter.h"
#include "WarriorHeroCharacter.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorHeroCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

public:
	virtual int32 GetPlayerLevel() const override;
protected:
	virtual void InitAbilityActorInfo() override;
	virtual void PossessedBy(AController* NewController) override;
};
