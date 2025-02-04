#include "MainMenuWidget.h"
#include "UIManager.h"
#include "Components/Button.h"
#include "Logging/LogMacros.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "MessagesFunctionLibrary.h"
#include "OptionsMenuWidget.h"

void UMainMenuWidget::NativeConstruct()
{
     Super::NativeConstruct();
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::NativeConstruct() called"));

     // Bind the ConnectButton.
     if (ConnectButton)
     {
          UE_LOG(LogTemp, Warning, TEXT("ConnectButton is valid."));
          ConnectButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnConnectButtonClicked);
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("ConnectButton is NULL! Check Blueprint bindings."));
     }
     if (ConnectButtonText)
     {
          // Retrieve the localized "Logout" text from the string table via the helper function.
          FText ConnectText = UMessagesFunctionLibrary::GetConnectText();
          ConnectButtonText->SetText(ConnectText);
     }

     // Bind the LogoutButton.
     if (LogoutButton)
     {
          LogoutButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnLogoutButtonClicked);
     }
     if (LogoutButtonText)
     {
          // Retrieve the localized "Logout" text from the string table via the helper function.
          FText LogoutText = UMessagesFunctionLibrary::GetLogoutText();
          LogoutButtonText->SetText(LogoutText);
     }

     // Bind the CharactersButton.
     if (CharactersButton)
     {
          CharactersButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnCharactersButtonClicked);
     }
     if (CharactersButtonText)
     {
          // Retrieve the localized "Characters" text from the string table via the helper function.
          FText CharacterText = UMessagesFunctionLibrary::GetCharactersText();
          CharactersButtonText->SetText(CharacterText);
     }

     // Bind the OptionsButton.
     if (OptionsButton)
     {
          OptionsButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnOptionsButtonClicked);
     }
     if (OptionsButtonText)
     {
          // Retrieve the localized "Options" text from the string table via the helper function.
          FText OptionsText = UMessagesFunctionLibrary::GetOptionsText();
          OptionsButtonText->SetText(OptionsText);
     }

     // Bind the QuitButton, Set the QuitButtonText from string table ST_UIStrings.
     if (QuitButton)
     {
          QuitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitButtonClicked);
     }
     if (QuitButtonText)
     {
          // Retrieve the localized "Quit" text from the string table via the helper function.
          FText QuitText = UMessagesFunctionLibrary::GetQuitText();
          QuitButtonText->SetText(QuitText);
     }

     // Call UpdateMenuState so the UI reflects the login state.
     UpdateMenuState();
}

void UMainMenuWidget::ToggleFakeLogin()
{
     bIsFakeLoggedIn = !bIsFakeLoggedIn;
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::ToggleFakeLogin() toggled: %s"),
          bIsFakeLoggedIn ? TEXT("Logged In") : TEXT("Logged Out"));
     // Call UpdateMenuState to update button visibility and states.
     UpdateMenuState();
}

void UMainMenuWidget::UpdateMenuState()
{
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::UpdateMenuState() called"));

     if (!ConnectButton || !LogoutButton || !CharactersButton || !QuitButton)
     {
          UE_LOG(LogTemp, Error, TEXT("One or more buttons are NULL in UpdateMenuState!"));
          return;
     }

     if (bIsFakeLoggedIn)
     {
          ConnectButton->SetVisibility(ESlateVisibility::Collapsed);
          LogoutButton->SetVisibility(ESlateVisibility::Visible);
          CharactersButton->SetIsEnabled(true);
     }
     else
     {
          ConnectButton->SetVisibility(ESlateVisibility::Visible);
          LogoutButton->SetVisibility(ESlateVisibility::Collapsed);
          CharactersButton->SetIsEnabled(false);
     }
}

void UMainMenuWidget::QuitGame()
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

void UMainMenuWidget::LoadCharacterMenu()
{
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::OnCharacterButtonClicked() called; loading Character menu"));
}

void UMainMenuWidget::LoadOptionsMenu()
{
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::LoadOptionsMenu() called; loading Options menu"));

     // Use UIManager to show the Options Menu
     if (UUIManager* UIManager = GetGameInstance()->GetSubsystem<UUIManager>())
     {
          UIManager->ShowOptionsMenu();
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("UIManager is NULL!"));
     }
}

void UMainMenuWidget::OnConnectButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::OnConnectButtonClicked() called"));
     // Toggle login state when ConnectButton is clicked
     ToggleFakeLogin();
}

void UMainMenuWidget::OnLogoutButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::OnLogoutButtonClicked() called"));
     // Toggle login state when LogoutButton is clicked
     ToggleFakeLogin();
}

void UMainMenuWidget::OnCharactersButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::OnCharactersButtonClicked() called"));
     // Load the Characters Menu
     LoadCharacterMenu();
}

void UMainMenuWidget::OnOptionsButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("Options Button Clicked"));

     // Use UIManager to show the Options Menu
     if (UUIManager* UIManager = GetGameInstance()->GetSubsystem<UUIManager>())
     {
          UIManager->ShowOptionsMenu();
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("UIManager is NULL!"));
     }
}

void UMainMenuWidget::OnQuitButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::OnQuitButtonClicked() called"));
     // Call QuitGame() when QuitButton is clicked
     QuitGame();
}
