// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WarriorHUD.generated.h"

class UWarriorUserWidget;
class UUserWidget;
class UAttributeSet;
class UAbilitySystemComponent;
class UOverlayWidgetController;
class APlayerState;
/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorHUD : public AHUD
{
	GENERATED_BODY()

public:
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
	UOverlayWidgetController* GetOverlayWidgetController(APlayerState* PlayerState,APlayerController* PlayerController,UAbilitySystemComponent* ASC,UAttributeSet* AS);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HUD)
	TSubclassOf<UUserWidget> OverlayClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HUD)
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

public:
	UPROPERTY()
	TObjectPtr<UWarriorUserWidget>  OverlayWidget;
};
