// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/WarriorWidgetController.h"

void UWarriorWidgetController::SetWidgetControllerParams(const FWarriorWidgetControllerParams& InWidgetControllerParams)
{
	PlayerController = InWidgetControllerParams.PC;
	PlayerState = InWidgetControllerParams.PS;
	AbilitySystemComponent = InWidgetControllerParams.ASC;
	AttributeSet = InWidgetControllerParams.AS;
}
