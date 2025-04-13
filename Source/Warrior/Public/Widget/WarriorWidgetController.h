// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "UObject/NoExportTypes.h"
#include "WarriorWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class APlayerState;

USTRUCT(BlueprintType)
struct FWarriorWidgetControllerParams
{
	GENERATED_BODY()

	FWarriorWidgetControllerParams(){};
	
	FWarriorWidgetControllerParams(APlayerState* InPlayerState,UAbilitySystemComponent* InAbilitySystemComp,APlayerController* InPlayerController, UAttributeSet* InAttributeSet):
	PS(InPlayerState),ASC(InAbilitySystemComp),PC(InPlayerController),AS(InAttributeSet)
	{
	}
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<APlayerState> PS;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> ASC;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<APlayerController> PC;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<UAttributeSet> AS;
};
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorWidgetController : public UObject
{
	GENERATED_BODY()

public:
	void SetWidgetControllerParams(const FWarriorWidgetControllerParams& InWidgetControllerParams);
	
protected:
 
	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<APlayerController> PlayerController;
 
	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<APlayerState> PlayerState;
 
	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
 
	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
