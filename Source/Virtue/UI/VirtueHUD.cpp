#include "VirtueHUD.h"
#include "Kismet/GameplayStatics.h"
#include "UIManager.h"
#include "Engine/World.h"

AVirtueHUD::AVirtueHUD()
{
     
}

void AVirtueHUD::BeginPlay()
{
     Super::BeginPlay();

     FString CurrentLevelName = GetWorld()->GetMapName();
     CurrentLevelName.RemoveFromStart(GetWorld()->StreamingLevelsPrefix); // Remove "UEDPIE_X_" if in PIE mode

     if (CurrentLevelName == "MainMenuLevel")
     {
          UUIManager* UIManager = GetGameInstance()->GetSubsystem<UUIManager>();
          if (UIManager)
          {
               UE_LOG(LogTemp, Warning, TEXT("VirtueHUD: Showing Main Menu in Main Menu Level"));
               UIManager->ShowMainMenu();
          }
          else
          {
               UE_LOG(LogTemp, Error, TEXT("VirtueHUD::BeginPlay - UIManager subsystem not found!"));
          }
     }
     else
     {
          UE_LOG(LogTemp, Warning, TEXT("VirtueHUD: Skipping Main Menu in Level %s"), *CurrentLevelName);
     }
}
