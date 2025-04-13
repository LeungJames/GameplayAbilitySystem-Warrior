// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/WarriorUserWidget.h"

void UWarriorUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
