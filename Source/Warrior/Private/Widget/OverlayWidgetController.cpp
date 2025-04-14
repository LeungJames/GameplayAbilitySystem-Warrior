// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/OverlayWidgetController.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/WarriorAttributeSet.h"

void UOverlayWidgetController::BindCallbacks()
{
	UWarriorAttributeSet* WarriorAttributeSet = CastChecked<UWarriorAttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WarriorAttributeSet->GetHealthAttribute()).AddUObject(this,&ThisClass::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WarriorAttributeSet->GetMaxHealthAttribute()).AddUObject(this,&ThisClass::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WarriorAttributeSet->GetManaAttribute()).AddUObject(this,&ThisClass::ManaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(WarriorAttributeSet->GetMaxManaAttribute()).AddUObject(this,&ThisClass::MaxManaChanged);

	UWarriorAbilitySystemComponent* WarriorAbilitySystemComponent = CastChecked<UWarriorAbilitySystemComponent>(AbilitySystemComponent);

	WarriorAbilitySystemComponent->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, Msg);
			}
		});
}


void UOverlayWidgetController::BroadcastInitValues() const 
{
	UWarriorAttributeSet* WarriorAttributeSet = CastChecked<UWarriorAttributeSet>(AttributeSet);
	OnHealthChanged.Broadcast(WarriorAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(WarriorAttributeSet->GetMaxHealth());

	OnManaChanged.Broadcast(WarriorAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(WarriorAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}




