// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/WarriorHUD.h"
#include "Widget/OverlayWidgetController.h"
#include "Widget/WarriorUserWidget.h"

void AWarriorHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(),OverlayClass);
	OverlayWidget = Cast<UWarriorUserWidget>(Widget);
	
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(PS,PC,ASC,AS);
	OverlayWidget->SetWidgetController(WidgetController);
	
	OverlayWidget->AddToViewport();
	OverlayWidgetController->BroadcastInitValues();
}

UOverlayWidgetController* AWarriorHUD::GetOverlayWidgetController(APlayerState* PlayerState,
	APlayerController* PlayerController, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this,OverlayWidgetControllerClass);
		const FWarriorWidgetControllerParams Params(PlayerState,ASC,PlayerController,AS);
		OverlayWidgetController->SetWidgetControllerParams(Params);
		
		OverlayWidgetController->BindCallbacks();
	}
	return OverlayWidgetController;
}

