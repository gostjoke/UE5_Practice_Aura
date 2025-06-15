// This is a practice project, Free to use!


#include "Character/AuraCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter()
{
    // Set this character to call Tick() every frame.
    // PrimaryActorTick.bCanEverTick = true;

    GetCharacterMovement()->bOrientRotationToMovement = true; // Character will rotate to movement direction
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // Set rotation rate for character
    GetCharacterMovement()->bConstrainToPlane = true; // Constrain movement to the plane
    GetCharacterMovement()->bSnapToPlaneAtStart = true; // Snap to the plane at the start

    bUseControllerRotationPitch = false; // Disable controller rotation pitch
    bUseControllerRotationRoll = false; // Disable controller rotation roll
    bUseControllerRotationYaw = false; // Enable controller rotation yaw
    

}