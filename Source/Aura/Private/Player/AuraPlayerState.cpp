// This is a practice project, Free to use!


#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"


AAuraPlayerState::AAuraPlayerState()
{
    AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
    AbilitySystemComponent->SetIsReplicated(true); // Ensure the Ability System Component is replicated

    AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");

    NetUpdateFrequency = 100.f; // Set a custom network update frequency
}


UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const 
{
	return AbilitySystemComponent;
}
