#include "OptionsMenuWidget.h"
#include "Components/Button.h"
#include "Logging/LogMacros.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "UIManager.h"
#include "MessagesFunctionLibrary.h"

// NativeConstruct is called when the widget is constructed.
void UOptionsMenuWidget::NativeConstruct()
{
     Super::NativeConstruct();
     UE_LOG(LogTemp, Warning, TEXT("UOptionsMenuWidget::NativeConstruct() called"));

     // Set the title of the menu
     if (OptionsMenuTitleText)
     {
          // Retrieve the localized "Options" text from the string table via the helper function.
          FText OptionsText = UMessagesFunctionLibrary::GetOptionsText();
          OptionsText = OptionsText.ToUpper();
          OptionsMenuTitleText->SetText(OptionsText);
     }

     // Bind the Return to Game button and set the button text.
     if (ReturnToGameButton)
     {
          ReturnToGameButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnReturnToGameButtonClicked);
          ReturnToGameButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnReturnToGameButtonClicked);
     }
     if (ReturnToGameButtonText)
     {
          FText ReturnToGame = UMessagesFunctionLibrary::GetReturnToGameText();
          ReturnToGameButtonText->SetText(ReturnToGame);
     }

     // Bind the Graphics button and set the button text.
     if (GraphicsButton)
     {
          GraphicsButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnGraphicsButtonClicked);
          GraphicsButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnGraphicsButtonClicked);
     }
     if (GraphicsButtonText)
     {
          FText Graphics = UMessagesFunctionLibrary::GetGraphicsText();
          GraphicsButtonText->SetText(Graphics);
     }

     // Bind the Audio button and set the button text.
     if (AudioButton)
     {
          AudioButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnAudioButtonClicked);
          AudioButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnAudioButtonClicked);
     }
     if (AudioButtonText)
     {
          FText Audio = UMessagesFunctionLibrary::GetAudioText();
          AudioButtonText->SetText(Audio);
     }

     // Bind the Controls button and set the button text.
     if (ControlsButton)
     {
          ControlsButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnControlsButtonClicked);
          ControlsButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnControlsButtonClicked);
     }
     if (ControlsButtonText)
     {
          FText Controls = UMessagesFunctionLibrary::GetControlsText();
          ControlsButtonText->SetText(Controls);
     }

     // Bind the Gameplay button and set the button text.
     if (GameplayButton)
     {
          GameplayButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnGameplayButtonClicked);
          GameplayButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnGameplayButtonClicked);
     }
     if (GameplayButtonText)
     {
          FText Gameplay = UMessagesFunctionLibrary::GetGameplayText();
          GameplayButtonText->SetText(Gameplay);
     }

     // Bind the Accessibility button and set the button text.
     if (AccessibilityButton)
     {
          AccessibilityButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnAccessibilityButtonClicked);
          AccessibilityButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnAccessibilityButtonClicked);
     }
     if (AccessibilityButtonText)
     {
          FText Accessibility = UMessagesFunctionLibrary::GetAccessibilityText();
          AccessibilityButtonText->SetText(Accessibility);
     }

     // Bind the Quit to Main Menu button and set the button text.
     if (QuitToMainMenuButton)
     {
          QuitToMainMenuButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnQuitToMainMenuButtonClicked);
          QuitToMainMenuButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnQuitToMainMenuButtonClicked);
     }
     if (QuitToMainMenuButtonText)
     {
          FText QuitToMainMenu = UMessagesFunctionLibrary::GetQuitToMainMenuText();
          QuitToMainMenuButtonText->SetText(QuitToMainMenu);
     }

     // Bind the Quit to Desktop button and set the button text.
     if (QuitToDesktopButton)
     {
          QuitToDesktopButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnQuitToDesktopButtonClicked);
          QuitToDesktopButton->OnClicked.AddDynamic(this, &UOptionsMenuWidget::OnQuitToDesktopButtonClicked);
     }
     if (QuitToDesktopButtonText)
     {
          FText QuitToDesktop = UMessagesFunctionLibrary::GetQuitToDesktopText();
          QuitToDesktopButtonText->SetText(QuitToDesktop);
     }
}

// NativeDestruct is called when the widget is being removed or destroyed.
// This override ensures that any event bindings are cleared.
void UOptionsMenuWidget::NativeDestruct()
{
     // Unbind all button events to prevent duplicate binding on re-creation.
     if (ReturnToGameButton)
          ReturnToGameButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnReturnToGameButtonClicked);
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
     if (QuitToMainMenuButton)
          QuitToMainMenuButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnQuitToMainMenuButtonClicked);
     if (QuitToDesktopButton)
          QuitToDesktopButton->OnClicked.RemoveDynamic(this, &UOptionsMenuWidget::OnQuitToDesktopButtonClicked);
     

     UE_LOG(LogTemp, Warning, TEXT("UOptionsMenuWidget::NativeDestruct() called - bindings cleared."));

     Super::NativeDestruct();
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

// Called when the Quit to Main Menu button is clicked.
// This function closes the Options Menu and asks the UIManager to show the Main Menu.
void UOptionsMenuWidget::OnQuitToMainMenuButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("OptionsMenuWidget: Quit to Main Menu button clicked - Returning to Main Menu"));

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

// Called when the Quit to Desktop button is clicked.
// This function quits to the desktop.
void UOptionsMenuWidget::OnQuitToDesktopButtonClicked()
{
     // If we're in the editor (PIE), use UKismetSystemLibrary::QuitGame to gracefully exit the game session
     if (GEngine->GetWorld() && GEngine->GetWorld()->IsPlayInEditor())
     {
          // Quit from PIE mode (editor)
          UKismetSystemLibrary::QuitGame(GEngine->GetWorld(), nullptr, EQuitPreference::Quit, false);
     }
     else
     {
          // Quit from a packaged game
          FPlatformMisc::RequestExit(true);
     }
}
