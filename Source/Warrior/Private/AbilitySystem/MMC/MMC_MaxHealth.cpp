// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MMC/MMC_MaxHealth.h"
#include "AbilitySystem/WarriorAttributeSet.h"
#include "Interface/CombatInterface.h"

UMMC_MaxHealth::UMMC_MaxHealth()
{
	VigorDef.AttributeToCapture = UWarriorAttributeSet::GetVigorAttribute();
	VigorDef.bSnapshot = false;
	VigorDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;

	RelevantAttributesToCapture.Add(VigorDef);
}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluateParams;
	EvaluateParams.SourceTags = SourceTags;
	EvaluateParams.TargetTags = TargetTags;

	float Vigor = 0;
	GetCapturedAttributeMagnitude(VigorDef,Spec,EvaluateParams,Vigor);
	
	int32 PlayerLevel = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject())->GetPlayerLevel();
	return 80.f + 2.5f * Vigor + 10.f * PlayerLevel;
}
