// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/WarriorHUD.h"
#include "Widget/OverlayWidgetController.h"
#include "Widget/WarriorUserWidget.h"

void AWarriorHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(),OverlayClass);
	OverlayWidget = Cast<UWarriorUserWidget>(Widget);
	OverlayWidget->SetWidgetController(GetOverlayWidgetController(PS,PC,ASC,AS));
	
	Widget->AddToViewport();
}

UOverlayWidgetController* AWarriorHUD::GetOverlayWidgetController(APlayerState* PlayerState,
	APlayerController* PlayerController, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>();
		FWarriorWidgetControllerParams Params(PlayerState,ASC,PlayerController,AS);
		OverlayWidgetController->SetWidgetControllerParams(Params);
	}
	return OverlayWidgetController;
}

