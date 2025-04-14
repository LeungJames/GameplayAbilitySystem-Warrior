// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/WarriorWidgetController.h"
#include "OverlayWidgetController.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedDelegate, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedDelegate, float, NewMaxHealth);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedDelegate, float, NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedDelegate, float, NewMaxMana);

UCLASS(BlueprintType,Blueprintable)
class WARRIOR_API UOverlayWidgetController : public UWarriorWidgetController
{
	GENERATED_BODY()

public:
	virtual void BindCallbacks() override;
	virtual void BroadcastInitValues() const override;
	
	
	UPROPERTY(BlueprintAssignable)
	FOnHealthChangedDelegate OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMaxHealthChangedDelegate OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnManaChangedDelegate OnManaChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMaxManaChangedDelegate OnMaxManaChanged;

	
private:
	void HealthChanged(const FOnAttributeChangeData& Data) const;
	void MaxHealthChanged(const FOnAttributeChangeData& Data) const;

	void ManaChanged(const FOnAttributeChangeData& Data) const;
	void MaxManaChanged(const FOnAttributeChangeData& Data) const;
};
