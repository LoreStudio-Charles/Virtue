#include "VirtueGameMode.h"
#include "Engine/World.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/SWeakWidget.h"
#include "SMainMenuWidget.h"
#include "CustomStyle.h"
#include <Kismet/GameplayStatics.h>

AVirtueGameMode::AVirtueGameMode()
{
     // Default constructor setup
}

bool bHasStarted = false;

void AVirtueGameMode::StartPlay()
{
     if (bHasStarted)
     {
          return;
     }

     Super::StartPlay();

     bHasStarted = true; // Ensure it's only executed once

     // Create and initialize your Slate widget here (only once)
     if (!MyWidget.IsValid()) // Check if MyWidget has already been created
     {
          MyWidget = SNew(SMainMenuWidget);

          // Bind the delegate to the method that handles the level loading
          MyWidget->SetStartGameDelegate(FStartGameDelegate::CreateUObject(this, &AVirtueGameMode::OnStartGame));

          // Get the mouse cursor to show
          APlayerController* PC = GetWorld()->GetFirstPlayerController();
          if (PC)
          {
               PC->bShowMouseCursor = true;
               PC->SetInputMode(FInputModeUIOnly());  // UI input mode
          }

          // Initialize custom style
          FCustomStyle::Initialize();

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
               // Use the already created MyWidget here
               GEngine->GameViewport->AddViewportWidgetContent(MyWidget.ToSharedRef());

               // TROUBLESHOOTING: Looking for the viewport to be added
               UE_LOG(LogTemp, Warning, TEXT("Main Menu Widget Added to Viewport"));
          }
          else
          {
               // TROUBLESHOOTING: Just a check
               UE_LOG(LogTemp, Error, TEXT("GEngine or GameViewport is null!"));
          }
     }
     else
     {
          UE_LOG(LogTemp, Warning, TEXT("Widget already created, skipping creation"));
     }
}

void AVirtueGameMode::OnStartGame()
{
     // Safely remove the widget from the viewport before transitioning to the new level
     if (GEngine && GEngine->GameViewport && MyWidget.IsValid())
     {
          GEngine->GameViewport->RemoveViewportWidgetContent(MyWidget.ToSharedRef());
          MyWidget.Reset(); // Reset the widget to ensure it is fully cleaned up
          UE_LOG(LogTemp, Warning, TEXT("Widget removed from viewport"));
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("Failed to remove widget on level load"));
     }

     // Now load the new level
     UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("GameStartLevel")));
}
