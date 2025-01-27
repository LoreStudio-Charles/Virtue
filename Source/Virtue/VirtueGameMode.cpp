#include "VirtueGameMode.h"
#include "Engine/World.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/SWeakWidget.h"
#include "SMainMenuWidget.h"

AVirtueGameMode::AVirtueGameMode()
{
     // Default constructor setup
}

void AVirtueGameMode::StartPlay()
{
     Super::StartPlay();

     // Is Slate running?
     if (FSlateApplication::IsInitialized())
     {
          UE_LOG(LogTemp, Warning, TEXT("Slate Application is Initialized"));
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("Slate Application is NOT Initialized"));
     }

     // Log to confirm Virtue Game Mode has started
     UE_LOG(LogTemp, Warning, TEXT("Virtue Game Mode Started"));

     if (GEngine && GEngine->GameViewport)
     {
          TSharedPtr<SMainMenuWidget> MainMenuWidget = SNew(SMainMenuWidget)
               .Visibility(EVisibility::Visible);
          GEngine->GameViewport->AddViewportWidgetContent(MainMenuWidget.ToSharedRef());

          // TROUBLESHOOTING: Looking for the viewport to be added
          UE_LOG(LogTemp, Warning, TEXT("Main Menu Widget Added to Viewport"));
     }
     else
     {
          // // TROUBLESHOOTING: Just a check
          UE_LOG(LogTemp, Error, TEXT("GEngine or GameViewport is null!"));
     }
}
