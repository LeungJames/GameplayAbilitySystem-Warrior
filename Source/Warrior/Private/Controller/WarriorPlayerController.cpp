// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/WarriorPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Engine/LocalPlayer.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AWarriorPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&ThisClass::Move);
	EnhancedInputComponent->BindAction(LookAction,ETriggerEvent::Triggered,this,&ThisClass::Look);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(DefaultInputMappingContext,0);
	}
	
}

void AWarriorPlayerController::Move(const FInputActionValue& InputValue)
{
	const FVector2D InputVector = InputValue.Get<FVector2D>();
	const FRotator ControlYawRotation = FRotator(0,GetControlRotation().Yaw,0);
	const FVector Forward = FRotationMatrix(ControlYawRotation).GetUnitAxis(EAxis::X);
	const FVector Right = FRotationMatrix(ControlYawRotation).GetUnitAxis(EAxis::Y);
	GetPawn()->AddMovementInput(Forward,InputVector.Y);
	GetPawn()->AddMovementInput(Right,InputVector.X);
}

void AWarriorPlayerController::Look(const FInputActionValue& InputValue)
{
	FVector2D LookInputVector = InputValue.Get<FVector2D>();
	GetPawn()->AddControllerYawInput(LookInputVector.X);
	GetPawn()->AddControllerPitchInput(LookInputVector.Y);
}
