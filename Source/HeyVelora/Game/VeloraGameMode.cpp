#include "Game/VeloraGameMode.h"
#include "Player/VeloraPlayerController.h"

AVeloraGameMode::AVeloraGameMode() {
  // Velora has no body.
  DefaultPawnClass = nullptr;
  PlayerControllerClass = AVeloraPlayerController::StaticClass();
}
