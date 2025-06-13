// This is a practice project, Free to use!


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

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

void AAuraPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);

}

void AAuraPlayerController::Move(const struct FInputActionValue& InputActionValue)
{
    const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>(); // Get the input axis vector from the action value
    const FRotator Rotation = GetControlRotation();
    const FRotator YawRotation(0.f, Rotation.Yaw, 0.f); // Create a rotation based on the control rotation's yaw

    const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X); // Get the forward direction based on the yaw rotation
    const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y); // Get the right direction based on the yaw rotation

    if (APawn* ControlledPawn = GetPawn<APawn>())
    {
        ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y); // Add movement input in the forward direction based on the Y axis of the input vector
        ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
    }
}