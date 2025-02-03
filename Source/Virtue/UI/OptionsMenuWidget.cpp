#include "OptionsMenuWidget.h"
#include "Components/Button.h"
#include "Logging/LogMacros.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "UIManager.h"

void UOptionsMenuWidget::NativeConstruct()
{
     Super::NativeConstruct();
     UE_LOG(LogTemp, Warning, TEXT("UOptionsMenuWidget::NativeConstruct() called"));

     // Bind buttons
     if (GraphicsButton)
     {
          GraphicsButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnGraphicsButtonClicked);
     }
     if (AudioButton)
     {
          AudioButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnAudioButtonClicked);
     }
     if (ControlsButton)
     {
          ControlsButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnControlsButtonClicked);
     }
     if (GameplayButton)
     {
          GameplayButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnGameplayButtonClicked);
     }
     if (AccessibilityButton)
     {
          AccessibilityButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnAccessibilityButtonClicked);
     }
     if (SaveAndQuitButton)
     {
          // Unbind any existing bindings to prevent duplication
          SaveAndQuitButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnSaveAndQuitButtonClicked);
          SaveAndQuitButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnSaveAndQuitButtonClicked);
     }
     if (ReturnToGameButton)
     {
          ReturnToGameButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnReturnToGameButtonClicked);
     }
}

void UOptionsMenuWidget::OnGraphicsButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("Graphics button clicked"));
}

void UOptionsMenuWidget::OnAudioButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("Audio button clicked"));
}

void UOptionsMenuWidget::OnControlsButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("Controls button clicked"));
}

void UOptionsMenuWidget::OnGameplayButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("Gameplay button clicked"));
}

void UOptionsMenuWidget::OnAccessibilityButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("Accessibility button clicked"));
}

void UOptionsMenuWidget::OnSaveAndQuitButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("Returning to Main Menu"));

     if (UUIManager* UIManager = GetGameInstance()->GetSubsystem<UUIManager>())
     {
          RemoveFromParent(); // Removes the Options Menu from the screen before switching

          UIManager->ShowMainMenu();
          UE_LOG(LogTemp, Warning, TEXT("Options Menu removed, Main Menu displayed."));
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("UUIManager instance is null!"));
     }
}

void UOptionsMenuWidget::OnReturnToGameButtonClicked()
{
    UE_LOG(LogTemp, Warning, TEXT("CALLING RETURN TO GAME BUTTON CLICKED"));
    UE_LOG(LogTemp, Warning, TEXT("Returning to Game"));

    if (UUIManager* UIManager = GetGameInstance()->GetSubsystem<UUIManager>())
    {
        UIManager->CloseAllMenus(); // Ensure all UI is removed before opening the level
    }

    // Load the game level
    UGameplayStatics::OpenLevel(GetWorld(), FName("OpenWorld"));
}

