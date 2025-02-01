#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "Logging/LogMacros.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"

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

     // Bind the LogoutButton.
     if (LogoutButton)
     {
          LogoutButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnLogoutButtonClicked);
     }

     // Bind the CharactersButton.
     if (CharactersButton)
     {
          CharactersButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnCharactersButtonClicked);
     }

     // Bind the OptionsButton.
     if (OptionsButton)
     {
          OptionsButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnOptionsButtonClicked);
     }

     // Bind the QuitButton.
     if (QuitButton)
     {
          QuitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitButtonClicked);
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
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::OnOptionsButtonClicked() called; loading Options menu"));
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
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::OnOptionsButtonClicked() called"));
     // Call QuitGame() when QuitButton is clicked
     LoadOptionsMenu();
}

void UMainMenuWidget::OnQuitButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::OnQuitButtonClicked() called"));
     // Call QuitGame() when QuitButton is clicked
     QuitGame();
}
