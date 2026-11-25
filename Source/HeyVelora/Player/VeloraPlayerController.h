#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VeloraPlayerController.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class HEYVELORA_API AVeloraPlayerController : public APlayerController {
  GENERATED_BODY()

protected:
  virtual void BeginPlay() override;
  virtual void SetupInputComponent() override;

private:
  UPROPERTY(EditDefaultsOnly, Category = "Input")
  TObjectPtr<UInputMappingContext> MappingContext;

  UPROPERTY(EditDefaultsOnly, Category = "Input")
  TObjectPtr<UInputAction> SelectAction;

  UPROPERTY(EditDefaultsOnly, Category = "Input")
  TObjectPtr<UInputAction> PauseAction;

  UPROPERTY(EditDefaultsOnly, Category = "Input")
  TObjectPtr<UInputAction> RestartAction;

  UPROPERTY(EditDefaultsOnly, Category = "Input")
  TObjectPtr<UInputAction> Speed1Action;

  UPROPERTY(EditDefaultsOnly, Category = "Input")
  TObjectPtr<UInputAction> Speed2Action;

  UPROPERTY(EditDefaultsOnly, Category = "Input")
  TObjectPtr<UInputAction> Speed3Action;

  UPROPERTY(EditDefaultsOnly, Category = "Input")
  TObjectPtr<UInputAction> Speed4Action;

  void OnSelect();
  void OnPause();
  void OnRestart();
  void OnSpeed(int32 Speed);
};
