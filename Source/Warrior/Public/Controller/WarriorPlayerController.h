// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"
#include "WarriorPlayerController.generated.h"

class UInputMappingContext;
struct FInputActionValue;

UCLASS()
class WARRIOR_API AWarriorPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;

private:
	void Move(const FInputActionValue& InputValue);
	void Look(const FInputActionValue& InputValue);

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Input", meta=(AllowPrivateAccess=true))
	TObjectPtr<UInputMappingContext> DefaultInputMappingContext;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Input", meta=(AllowPrivateAccess=true))
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Input", meta=(AllowPrivateAccess=true))
	UInputAction* LookAction;
};
