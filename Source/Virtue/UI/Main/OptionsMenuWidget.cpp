// OptionsMenuWidget.cpp
#include "OptionsMenuWidget.h"

// Always include your widget's header first to satisfy Unreal's include order requirements.
#include "UIBindingHelpers.h"          // Contains BIND_BUTTON and helper functions.
#include "UIManager.h"
#include "MessagesFunctionLibrary.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/PlayerController.h"
#include "Logging/LogMacros.h"

// Define a dedicated log category (or use an existing one)
DEFINE_LOG_CATEGORY_STATIC(LogOptionsMenu, Log, All);

//////////////////////////////////////////////////////////////////////////
// NativeConstruct & NativeDestruct

void UOptionsMenuWidget::NativeConstruct()
{
     Super::NativeConstruct();
     UE_LOG(LogOptionsMenu, Warning, TEXT("UOptionsMenuWidget::NativeConstruct() called"));

     // Set the Options Menu title text to uppercase.
     if (OptionsMenuTitleText)
     {
          FText OptionsText = UMessagesFunctionLibrary::GetOptionsText();
          OptionsMenuTitleText->SetText(OptionsText.ToUpper());
     }

     // --- Bind button events and set localized texts using helper functions. ---
     BIND_BUTTON(UOptionsMenuWidget, ReturnToGameButton, OnReturnToGameButtonClicked);
     UIHelpers::SetLocalizedText(ReturnToGameButtonText, UMessagesFunctionLibrary::GetReturnToGameText());

     BIND_BUTTON(UOptionsMenuWidget, GraphicsButton, OnGraphicsButtonClicked);
     UIHelpers::SetLocalizedText(GraphicsButtonText, UMessagesFunctionLibrary::GetGraphicsText());

     BIND_BUTTON(UOptionsMenuWidget, AudioButton, OnAudioButtonClicked);
     UIHelpers::SetLocalizedText(AudioButtonText, UMessagesFunctionLibrary::GetAudioText());

     BIND_BUTTON(UOptionsMenuWidget, ControlsButton, OnControlsButtonClicked);
     UIHelpers::SetLocalizedText(ControlsButtonText, UMessagesFunctionLibrary::GetControlsText());

     BIND_BUTTON(UOptionsMenuWidget, GameplayButton, OnGameplayButtonClicked);
     UIHelpers::SetLocalizedText(GameplayButtonText, UMessagesFunctionLibrary::GetGameplayText());

     BIND_BUTTON(UOptionsMenuWidget, AccessibilityButton, OnAccessibilityButtonClicked);
     UIHelpers::SetLocalizedText(AccessibilityButtonText, UMessagesFunctionLibrary::GetAccessibilityText());

     BIND_BUTTON(UOptionsMenuWidget, QuitToMainMenuButton, OnQuitToMainMenuButtonClicked);
     UIHelpers::SetLocalizedText(QuitToMainMenuButtonText, UMessagesFunctionLibrary::GetQuitToMainMenuText());

     BIND_BUTTON(UOptionsMenuWidget, QuitToDesktopButton, OnQuitToDesktopButtonClicked);
     UIHelpers::SetLocalizedText(QuitToDesktopButtonText, UMessagesFunctionLibrary::GetQuitToDesktopText());
}

void UOptionsMenuWidget::NativeDestruct()
{
     // Unbind all button events to prevent duplicate bindings on re-creation.
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

     UE_LOG(LogOptionsMenu, Warning, TEXT("UOptionsMenuWidget::NativeDestruct() called - bindings cleared."));
     Super::NativeDestruct();
}

//////////////////////////////////////////////////////////////////////////
// Button Event Handlers

void UOptionsMenuWidget::OnReturnToGameButtonClicked()
{
     UE_LOG(LogOptionsMenu, Warning, TEXT("OptionsMenuWidget: 'Return to Game' button clicked."));

     if (UUIManager* UIManager = GetGameInstance()->GetSubsystem<UUIManager>())
     {
          UIManager->CloseAllMenus();
          UE_LOG(LogOptionsMenu, Warning, TEXT("OptionsMenuWidget: All menus closed."));
     }
     else
     {
          UE_LOG(LogOptionsMenu, Error, TEXT("OptionsMenuWidget: UIManager subsystem is null!"));
     }

     UWorld* World = GetWorld();
     if (World)
     {
          UGameplayStatics::OpenLevel(World, FName("OpenWorld"));
          UE_LOG(LogOptionsMenu, Warning, TEXT("OptionsMenuWidget: Game level 'OpenWorld' loaded."));
     }
     else
     {
          UE_LOG(LogOptionsMenu, Error, TEXT("OptionsMenuWidget: GetWorld() returned null."));
     }
}

void UOptionsMenuWidget::OnGraphicsButtonClicked()
{
     UE_LOG(LogOptionsMenu, Warning, TEXT("OptionsMenuWidget: 'Graphics' button clicked."));
     // TODO: Implement graphics settings functionality.
}

void UOptionsMenuWidget::OnAudioButtonClicked()
{
     UE_LOG(LogOptionsMenu, Warning, TEXT("OptionsMenuWidget: 'Audio' button clicked."));
     // TODO: Implement audio settings functionality.
}

void UOptionsMenuWidget::OnControlsButtonClicked()
{
     UE_LOG(LogOptionsMenu, Warning, TEXT("OptionsMenuWidget: 'Controls' button clicked."));
     // TODO: Implement controls settings functionality.
}

void UOptionsMenuWidget::OnGameplayButtonClicked()
{
     UE_LOG(LogOptionsMenu, Warning, TEXT("OptionsMenuWidget: 'Gameplay' button clicked."));
     // TODO: Implement gameplay settings functionality.
}

void UOptionsMenuWidget::OnAccessibilityButtonClicked()
{
     UE_LOG(LogOptionsMenu, Warning, TEXT("OptionsMenuWidget: 'Accessibility' button clicked."));
     // TODO: Implement accessibility settings functionality.
}

void UOptionsMenuWidget::OnQuitToMainMenuButtonClicked()
{
     UE_LOG(LogOptionsMenu, Warning, TEXT("OptionsMenuWidget: 'Quit to Main Menu' button clicked."));

     UUIManager* UIManager = GetGameInstance()->GetSubsystem<UUIManager>();
     if (!UIManager)
     {
          UE_LOG(LogOptionsMenu, Error, TEXT("OptionsMenuWidget: UIManager subsystem is null!"));
          return;
     }

     UIManager->CloseMenu(this);
     UE_LOG(LogOptionsMenu, Warning, TEXT("OptionsMenuWidget: Options Menu closed."));

     UIManager->ShowMainMenu();

     if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
     {
          FInputModeUIOnly InputMode;
          PC->SetInputMode(InputMode);
          PC->bShowMouseCursor = true;
          UE_LOG(LogOptionsMenu, Warning, TEXT("OptionsMenuWidget: Input mode set to UI only, mouse cursor enabled."));
     }
     else
     {
          UE_LOG(LogOptionsMenu, Error, TEXT("OptionsMenuWidget: Failed to get PlayerController."));
     }
}

void UOptionsMenuWidget::OnQuitToDesktopButtonClicked()
{
     UE_LOG(LogOptionsMenu, Warning, TEXT("OptionsMenuWidget: 'Quit to Desktop' button clicked."));

     UWorld* World = GetWorld();
     if (!World)
     {
          UE_LOG(LogOptionsMenu, Error, TEXT("OptionsMenuWidget: GetWorld() returned null."));
          return;
     }

     if (World->IsPlayInEditor())
     {
          UKismetSystemLibrary::QuitGame(World, nullptr, EQuitPreference::Quit, false);
          UE_LOG(LogOptionsMenu, Warning, TEXT("OptionsMenuWidget: Quit game in editor mode."));
     }
     else
     {
          FPlatformMisc::RequestExit(true);
          UE_LOG(LogOptionsMenu, Warning, TEXT("OptionsMenuWidget: Application exit requested."));
     }
}
