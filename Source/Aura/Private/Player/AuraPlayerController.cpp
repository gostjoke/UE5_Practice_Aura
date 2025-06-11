// This is a practice project, Free to use!


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"

AAuraPlayerController::AAuraPlayerController()
{
    bReplicates = true; // Enable replication for this controller, for multiple players
}

void AAuraPlayerController::BeginPlay()
{
    Super::BeginPlay();
    check(AuraContext);
    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    check(Subsystem);
    Subsystem->AddMappingContext(AuraContext, 0); // Add the input mapping context to the local player subsystem

    bShowMouseCursor = true; // Show the mouse cursor for this player controller
    DefaultMouseCursor = EMouseCursor::Default; // Set the default mouse cursor

    FInputModeGameAndUI InputModeData; // Create an input mode that allows both game and UI interaction
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock); // Do not lock the mouse to the viewport
    InputModeData.SetHideCursorDuringCapture(false); // Do not hide the cursor during capture
    SetInputMode(InputModeData); // Apply the input mode to this player controller
}