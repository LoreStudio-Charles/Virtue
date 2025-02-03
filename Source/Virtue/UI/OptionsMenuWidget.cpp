#include "OptionsMenuWidget.h"
#include "Components/Button.h"
#include "Logging/LogMacros.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "UIManager.h"

// NativeConstruct is called when the widget is constructed.
void UOptionsMenuWidget::NativeConstruct()
{
     Super::NativeConstruct();
     UE_LOG(LogTemp, Warning, TEXT("UOptionsMenuWidget::NativeConstruct() called"));

     // Bind the Graphics button.
     if (GraphicsButton)
     {
          GraphicsButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnGraphicsButtonClicked);
          GraphicsButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnGraphicsButtonClicked);
     }

     // Bind the Audio button.
     if (AudioButton)
     {
          AudioButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnAudioButtonClicked);
          AudioButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnAudioButtonClicked);
     }

     // Bind the Controls button.
     if (ControlsButton)
     {
          ControlsButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnControlsButtonClicked);
          ControlsButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnControlsButtonClicked);
     }

     // Bind the Gameplay button.
     if (GameplayButton)
     {
          GameplayButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnGameplayButtonClicked);
          GameplayButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnGameplayButtonClicked);
     }

     // Bind the Accessibility button.
     if (AccessibilityButton)
     {
          AccessibilityButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnAccessibilityButtonClicked);
          AccessibilityButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnAccessibilityButtonClicked);
     }

     // Bind the Save & Quit button.
     if (SaveAndQuitButton)
     {
          SaveAndQuitButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnSaveAndQuitButtonClicked);
          SaveAndQuitButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnSaveAndQuitButtonClicked);
     }

     // Bind the Return to Game button.
     if (ReturnToGameButton)
     {
          ReturnToGameButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnReturnToGameButtonClicked);
          ReturnToGameButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnReturnToGameButtonClicked);
     }
}

// NativeDestruct is called when the widget is being removed or destroyed.
// This override ensures that any event bindings are cleared.
void UOptionsMenuWidget::NativeDestruct()
{
     // Unbind all button events to prevent duplicate binding on re-creation.
     if (GraphicsButton)
          GraphicsButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnGraphicsButtonClicked);
     if (AudioButton)
          AudioButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnAudioButtonClicked);
     if (ControlsButton)
          ControlsButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnControlsButtonClicked);
     if (GameplayButton)
          GameplayButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnGameplayButtonClicked);
     if (AccessibilityButton)
          AccessibilityButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnAccessibilityButtonClicked);
     if (SaveAndQuitButton)
          SaveAndQuitButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnSaveAndQuitButtonClicked);
     if (ReturnToGameButton)
          ReturnToGameButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnReturnToGameButtonClicked);

     UE_LOG(LogTemp, Warning, TEXT("UOptionsMenuWidget::NativeDestruct() called - bindings cleared."));

     Super::NativeDestruct();
}

// Called when the Graphics button is clicked.
void UOptionsMenuWidget::OnGraphicsButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("OptionsMenuWidget: Graphics button clicked"));
}

// Called when the Audio button is clicked.
void UOptionsMenuWidget::OnAudioButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("OptionsMenuWidget: Audio button clicked"));
}

// Called when the Controls button is clicked.
void UOptionsMenuWidget::OnControlsButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("OptionsMenuWidget: Controls button clicked"));
}

// Called when the Gameplay button is clicked.
void UOptionsMenuWidget::OnGameplayButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("OptionsMenuWidget: Gameplay button clicked"));
}

// Called when the Accessibility button is clicked.
void UOptionsMenuWidget::OnAccessibilityButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("OptionsMenuWidget: Accessibility button clicked"));
}

// Called when the Save & Quit button is clicked.
// This function closes the Options Menu and asks the UIManager to show the Main Menu.
void UOptionsMenuWidget::OnSaveAndQuitButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("OptionsMenuWidget: Save & Quit button clicked - Returning to Main Menu"));

     // Get the UIManager subsystem instance.
     if (UUIManager* UIManager = GetGameInstance()->GetSubsystem<UUIManager>())
     {
          // Close this Options Menu using UIManager's helper function.
          UIManager->CloseMenu(this);
          // Show the Main Menu.
          UIManager->ShowMainMenu();
          UE_LOG(LogTemp, Warning, TEXT("OptionsMenuWidget: Options Menu closed, Main Menu displayed."));
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("OptionsMenuWidget: UIManager subsystem is null!"));
     }
}

// Called when the Return to Game button is clicked.
// This function closes all menus and loads the game level.
void UOptionsMenuWidget::OnReturnToGameButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("OptionsMenuWidget: Return to Game button clicked"));

     // Get the UIManager subsystem instance.
     if (UUIManager* UIManager = GetGameInstance()->GetSubsystem<UUIManager>())
     {
          UIManager->CloseAllMenus();
     }

     // Load the specified game level (replace \"OpenWorld\" with your actual level name).
     UGameplayStatics::OpenLevel(GetWorld(), FName("OpenWorld"));
     UE_LOG(LogTemp, Warning, TEXT("OptionsMenuWidget: Game level loaded."));
}
