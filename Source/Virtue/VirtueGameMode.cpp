#include "VirtueGameMode.h"
#include "Engine/World.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/SWeakWidget.h"
#include "SMainMenu.h"
#include "SMainMenuWidget.h"

AVirtueGameMode::AVirtueGameMode()
{
     // Default constructor setup
}

void AVirtueGameMode::StartPlay()
{
     Super::StartPlay();

     // Log to confirm the game mode has started
     UE_LOG(LogTemp, Warning, TEXT("Virtue Game Mode Started"));

     if (GEngine && GEngine->GameViewport)
     {
          TSharedPtr<SMainMenuWidget> MainMenuWidget = SNew(SMainMenuWidget);
          GEngine->GameViewport->AddViewportWidgetContent(
               SNew(SWeakWidget).PossiblyNullContent(MainMenuWidget.ToSharedRef())
          );
     }
}
