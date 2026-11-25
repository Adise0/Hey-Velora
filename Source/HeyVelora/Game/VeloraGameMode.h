#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "VeloraGameMode.generated.h" // always the last include

/** Chooses the game's classes. */
UCLASS()
class HEYVELORA_API AVeloraGameMode : public AGameModeBase {
  GENERATED_BODY()

public:
  AVeloraGameMode();
};
