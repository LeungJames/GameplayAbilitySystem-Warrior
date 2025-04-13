// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/WarriorEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

AWarriorEffectActor::AWarriorEffectActor()
{
	PrimaryActorTick.bCanEverTick = true;
	Level = 1;
}

void AWarriorEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWarriorEffectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWarriorEffectActor::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	if(UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target))
	{
		FGameplayEffectContextHandle EffectContext = TargetASC->MakeEffectContext();
		EffectContext.AddSourceObject(this);
		FGameplayEffectSpecHandle Handle = TargetASC->MakeOutgoingSpec(GameplayEffectClass,Level,EffectContext);
		TargetASC->ApplyGameplayEffectSpecToSelf(*Handle.Data);
	}
}

