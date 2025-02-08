#include "MainMenuWidget.h"
#include "UIManager.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "MessagesFunctionLibrary.h"
#include "UIBindingHelpers.h"

// Define a dedicated log category for easier debugging.
DEFINE_LOG_CATEGORY_STATIC(LogMainMenu, Log, All);

void UMainMenuWidget::NativeConstruct()
{
     Super::NativeConstruct();
     UE_LOG(LogMainMenu, Warning, TEXT("UMainMenuWidget::NativeConstruct() called"));

     // Bind buttons using the helper macro defined in UIBindingHelpers.h.
     BIND_BUTTON(UMainMenuWidget, ConnectButton, OnConnectButtonClicked);
     BIND_BUTTON(UMainMenuWidget, LogoutButton, OnLogoutButtonClicked);
     BIND_BUTTON(UMainMenuWidget, CharactersButton, OnCharactersButtonClicked);
     BIND_BUTTON(UMainMenuWidget, OptionsButton, OnOptionsButtonClicked);
     BIND_BUTTON(UMainMenuWidget, QuitButton, OnQuitButtonClicked);

     // Set localized text on the button labels.
     UIHelpers::SetLocalizedText(ConnectButtonText, UMessagesFunctionLibrary::GetConnectText());
     UIHelpers::SetLocalizedText(LogoutButtonText, UMessagesFunctionLibrary::GetLogoutText());
     UIHelpers::SetLocalizedText(CharactersButtonText, UMessagesFunctionLibrary::GetCharactersText());
     UIHelpers::SetLocalizedText(OptionsButtonText, UMessagesFunctionLibrary::GetOptionsText());
     UIHelpers::SetLocalizedText(QuitButtonText, UMessagesFunctionLibrary::GetQuitText());

     UpdateMenuState();
}

UUIManager* UMainMenuWidget::GetUIManager() const
{
     // Check that the GameInstance exists before retrieving the subsystem.
     return (GetGameInstance()) ? GetGameInstance()->GetSubsystem<UUIManager>() : nullptr;
}

void UMainMenuWidget::UpdateMenuState()
{
     if (!ensure(ConnectButton && LogoutButton && CharactersButton && QuitButton))
     {
          UE_LOG(LogMainMenu, Error, TEXT("One or more buttons are NULL in UpdateMenuState!"));
          return;
     }

     // Update button visibility and state based on the fake login flag.
     const bool bLoggedIn = bIsFakeLoggedIn;
     UIHelpers::SetButtonVisibility(ConnectButton, !bLoggedIn);
     UIHelpers::SetButtonVisibility(LogoutButton, bLoggedIn);
     CharactersButton->SetIsEnabled(bLoggedIn);
}

void UMainMenuWidget::QuitGame()
{
     if (UWorld* World = GetWorld())
     {
          if (World->IsPlayInEditor())
          {
               UKismetSystemLibrary::QuitGame(World, nullptr, EQuitPreference::Quit, false);
          }
          else
          {
               FPlatformMisc::RequestExit(true);
          }
     }
     else
     {
          UE_LOG(LogMainMenu, Error, TEXT("QuitGame: GetWorld() returned NULL."));
     }
}

void UMainMenuWidget::ToggleFakeLogin()
{
     bIsFakeLoggedIn = !bIsFakeLoggedIn;
     UpdateMenuState();
}

void UMainMenuWidget::LoadCharactersMenu()
{
     if (UUIManager* UIManager = GetUIManager())
     {
          UIManager->ShowCharactersMenu();
     }
     else
     {
          UE_LOG(LogMainMenu, Error, TEXT("LoadCharactersMenu: UIManager is NULL!"));
     }
}

void UMainMenuWidget::LoadOptionsMenu()
{
     if (UUIManager* UIManager = GetUIManager())
     {
          UIManager->ShowOptionsMenu();
     }
     else
     {
          UE_LOG(LogMainMenu, Error, TEXT("LoadOptionsMenu: UIManager is NULL!"));
     }
}

void UMainMenuWidget::OnConnectButtonClicked()
{
     UE_LOG(LogMainMenu, Warning, TEXT("UMainMenuWidget::OnConnectButtonClicked() called"));
     bIsFakeLoggedIn = true;
     UpdateMenuState();
}

void UMainMenuWidget::OnLogoutButtonClicked()
{
     UE_LOG(LogMainMenu, Warning, TEXT("UMainMenuWidget::OnLogoutButtonClicked() called"));
     bIsFakeLoggedIn = false;
     UpdateMenuState();
}

void UMainMenuWidget::OnCharactersButtonClicked()
{
     UE_LOG(LogMainMenu, Warning, TEXT("UMainMenuWidget::OnCharactersButtonClicked() called"));
     LoadCharactersMenu();
}

void UMainMenuWidget::OnOptionsButtonClicked()
{
     UE_LOG(LogMainMenu, Warning, TEXT("UMainMenuWidget::OnOptionsButtonClicked() called"));
     LoadOptionsMenu();
}

void UMainMenuWidget::OnQuitButtonClicked()
{
     UE_LOG(LogMainMenu, Warning, TEXT("UMainMenuWidget::OnQuitButtonClicked() called"));
     QuitGame();
}

// Private helper: Safely set the text on a UTextBlock.
void UMainMenuWidget::SetButtonTextSafe(UTextBlock* TextBlock, const FText& NewText)
{
     if (TextBlock)
     {
          TextBlock->SetText(NewText);
     }
     else
     {
          UE_LOG(LogMainMenu, Error, TEXT("SetButtonTextSafe: TextBlock is NULL!"));
     }
}

// Private helper: Set the button's visibility.
void UMainMenuWidget::SetButtonVisibility(UButton* Button, bool bVisible)
{
     if (Button)
     {
          Button->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
     }
     else
     {
          UE_LOG(LogMainMenu, Error, TEXT("SetButtonVisibility: Button is NULL!"));
     }
}
