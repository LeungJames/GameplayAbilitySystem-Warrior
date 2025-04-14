// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/WarriorWidgetController.h"
#include "OverlayWidgetController.generated.h"

/**
 * 
 */

class UWarriorUserWidget;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedDelegate, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedDelegate, float, NewMaxHealth);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedDelegate, float, NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedDelegate, float, NewMaxMana);

USTRUCT(BlueprintType)
struct FUIWidgetRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag MessageTag = FGameplayTag();
 
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Message = FText();
 
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UWarriorUserWidget> MessageWidget;
 
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Image = nullptr;
	
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMessageWidgetRowSignature, FUIWidgetRow, Row);

UCLASS(BlueprintType,Blueprintable)
class WARRIOR_API UOverlayWidgetController : public UWarriorWidgetController
{
	GENERATED_BODY()

public:
	virtual void BindCallbacks() override;
	virtual void BroadcastInitValues() const override;
	
	
	UPROPERTY(BlueprintAssignable)
	FOnHealthChangedDelegate OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMaxHealthChangedDelegate OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnManaChangedDelegate OnManaChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMaxManaChangedDelegate OnMaxManaChanged;

	UPROPERTY(BlueprintAssignable)
	FMessageWidgetRowSignature MessageWidgetRowDelegate;

protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Widget Table")
	TObjectPtr<UDataTable> MessageWidgetDataTable;

	template<typename T>
	T* FindUIWidgetRow(UDataTable* DataTable,const FGameplayTag& Tag);
	
private:
	void HealthChanged(const FOnAttributeChangeData& Data) const;
	void MaxHealthChanged(const FOnAttributeChangeData& Data) const;

	void ManaChanged(const FOnAttributeChangeData& Data) const;
	void MaxManaChanged(const FOnAttributeChangeData& Data) const;
};

template <typename T>
T* UOverlayWidgetController::FindUIWidgetRow(UDataTable* DataTable,const FGameplayTag& Tag)
{
	return DataTable->FindRow<T>(Tag.GetTagName(),TEXT(""));
}
