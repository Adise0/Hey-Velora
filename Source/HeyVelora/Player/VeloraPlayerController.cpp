#include "Player/VeloraPlayerController.h"

#include "Engine/Engine.h"
#include "Engine/LocalPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

namespace {
// Placeholder feedback until the simulation exists.
void PrintInput(const FString &Message) {
  if (GEngine) {
    GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::Cyan, Message);
  }
}
} // namespace

void AVeloraPlayerController::BeginPlay() {
  Super::BeginPlay();

  UEnhancedInputLocalPlayerSubsystem *InputSubsystem =
      ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
  if (InputSubsystem && ensureMsgf(MappingContext, TEXT("No mapping context set in %s"), *GetName())) {
    InputSubsystem->AddMappingContext(MappingContext, 0);
  }

  SetShowMouseCursor(true);

  FInputModeGameAndUI InputMode;
  InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
  InputMode.SetHideCursorDuringCapture(false);
  SetInputMode(InputMode);
}

void AVeloraPlayerController::SetupInputComponent() {
  Super::SetupInputComponent();

  UEnhancedInputComponent *Input = CastChecked<UEnhancedInputComponent>(InputComponent);

  Input->BindAction(SelectAction, ETriggerEvent::Triggered, this, &ThisClass::OnSelect);
  Input->BindAction(PauseAction, ETriggerEvent::Triggered, this, &ThisClass::OnPause);
  Input->BindAction(RestartAction, ETriggerEvent::Triggered, this, &ThisClass::OnRestart);
  Input->BindAction(Speed1Action, ETriggerEvent::Triggered, this, &ThisClass::OnSpeed, 1);
  Input->BindAction(Speed2Action, ETriggerEvent::Triggered, this, &ThisClass::OnSpeed, 2);
  Input->BindAction(Speed3Action, ETriggerEvent::Triggered, this, &ThisClass::OnSpeed, 4);
  Input->BindAction(Speed4Action, ETriggerEvent::Triggered, this, &ThisClass::OnSpeed, 8);
}

void AVeloraPlayerController::OnSelect() { PrintInput(TEXT("Select")); }

void AVeloraPlayerController::OnPause() { PrintInput(TEXT("Pause")); }

void AVeloraPlayerController::OnRestart() { PrintInput(TEXT("Restart")); }

void AVeloraPlayerController::OnSpeed(int32 Speed) {
  PrintInput(FString::Printf(TEXT("Speed %dx"), Speed));
}
