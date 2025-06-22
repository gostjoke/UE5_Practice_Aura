// This is a practice project, Free to use!

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AuraAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes")
	FGameplayAttributeData MaxMana;


	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
		
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
		
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
};



