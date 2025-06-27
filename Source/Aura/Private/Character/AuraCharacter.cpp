// This is a practice project, Free to use!


#include "Character/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerController.h"
#include "Player/AuraPlayerState.h"
#include "UI/HUD/AuraHUD.h"

AAuraCharacter::AAuraCharacter()
{
    // Set this character to call Tick() every frame.
    // PrimaryActorTick.bCanEverTick = true;

    GetCharacterMovement()->bOrientRotationToMovement = true; // Character will rotate to movement direction
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f); // Set rotation rate for character
    GetCharacterMovement()->bConstrainToPlane = true; // Constrain movement to the plane
    GetCharacterMovement()->bSnapToPlaneAtStart = true; // Snap to the plane at the start

    bUseControllerRotationPitch = false; // Disable controller rotation pitch
    bUseControllerRotationRoll = false; // Disable controller rotation roll
    bUseControllerRotationYaw = false; // Enable controller rotation yaw
    
}

void AAuraCharacter::PossessedBy(AController* NewController) 
{
    Super::PossessedBy(NewController);
    InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
    Super::OnRep_PlayerState();

    // iNIT Ability Actor Info for the Client
    InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo()
{
    // Int ability actor info for the Server
    AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
    check(AuraPlayerState);
    AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this); // Initialize the Ability System Component with this actor

    AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
    AttributeSet = AuraPlayerState->GetAttributeSet();


	if (AAuraPlayerController* AuraPlayerController = Cast<AAuraPlayerController>(GetController()))
	{
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(AuraPlayerController->GetHUD()))
		{
			AuraHUD->InitOverlay(AuraPlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}

}
