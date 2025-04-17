// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MMC/MMC_MaxMana.h"

#include "AbilitySystem/WarriorAttributeSet.h"
#include "Interface/CombatInterface.h"

UMMC_MaxMana::UMMC_MaxMana()
{
	IntelDef.AttributeToCapture = UWarriorAttributeSet::GetIntelligenceAttribute();
	IntelDef.bSnapshot = false;
	IntelDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;

	RelevantAttributesToCapture.Add(IntelDef);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer * SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer * TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();
	
	float Intel = 0;
	FAggregatorEvaluateParameters EvaluateParams;
	EvaluateParams.SourceTags = SourceTags;
	EvaluateParams.TargetTags = TargetTags;
	
	GetCapturedAttributeMagnitude(IntelDef,Spec,EvaluateParams,Intel);

	int32 PlayerLevel = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject())->GetPlayerLevel();
	return 50.f + 2.5f * Intel + 15.f * PlayerLevel;
}
