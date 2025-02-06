#include "MainMenuWidget.h"
#include "UIManager.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "MessagesFunctionLibrary.h"
#include "OptionsMenuWidget.h"

void UMainMenuWidget::NativeConstruct()
{
     Super::NativeConstruct();
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::NativeConstruct() called"));

     // Bind each button directly using AddDynamic.
     if (ConnectButton)
     {
          UE_LOG(LogTemp, Warning, TEXT("ConnectButton is valid."));
          ConnectButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnConnectButtonClicked);
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("ConnectButton is NULL! Check Blueprint bindings."));
     }
     if (LogoutButton)
     {
          LogoutButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnLogoutButtonClicked);
     }
     if (CharactersButton)
     {
          CharactersButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnCharactersButtonClicked);
     }
     if (OptionsButton)
     {
          OptionsButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnOptionsButtonClicked);
     }
     if (QuitButton)
     {
          QuitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitButtonClicked);
     }

     // Set localized text for each button label via your function library.
     if (ConnectButtonText)
     {
          ConnectButtonText->SetText(UMessagesFunctionLibrary::GetConnectText());
     }
     if (LogoutButtonText)
     {
          LogoutButtonText->SetText(UMessagesFunctionLibrary::GetLogoutText());
     }
     if (CharactersButtonText)
     {
          CharactersButtonText->SetText(UMessagesFunctionLibrary::GetCharactersText());
     }
     if (OptionsButtonText)
     {
          OptionsButtonText->SetText(UMessagesFunctionLibrary::GetOptionsText());
     }
     if (QuitButtonText)
     {
          QuitButtonText->SetText(UMessagesFunctionLibrary::GetQuitText());
     }

     // Update UI state based on login status.
     UpdateMenuState();
}

void UMainMenuWidget::ToggleFakeLogin()
{
     bIsFakeLoggedIn = !bIsFakeLoggedIn;
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::ToggleFakeLogin() toggled: %s"),
          bIsFakeLoggedIn ? TEXT("Logged In") : TEXT("Logged Out"));
     UpdateMenuState();
}

void UMainMenuWidget::UpdateMenuState()
{
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::UpdateMenuState() called"));

     // Ensure required buttons exist.
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
     UWorld* World = GetWorld();
     if (!World) return;

     if (World->IsPlayInEditor())
     {
          // Quit gracefully in PIE.
          UKismetSystemLibrary::QuitGame(World, nullptr, EQuitPreference::Quit, false);
     }
     else
     {
          // Quit in packaged builds.
          FPlatformMisc::RequestExit(true);
     }
}

void UMainMenuWidget::LoadCharacterMenu()
{
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::OnCharactersButtonClicked() called; loading Character menu"));
     // Use UIManager to show the Characters Menu.
          if (UUIManager* UIManager = GetGameInstance()->GetSubsystem<UUIManager>())
          {
               UIManager->ShowCharactersMenu();
          }
          else
          {
               UE_LOG(LogTemp, Error, TEXT("UIManager is NULL!"));
          }
}

void UMainMenuWidget::LoadOptionsMenu()
{
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::LoadOptionsMenu() called; loading Options menu"));

     // Use UIManager to show the Options Menu.
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
     ToggleFakeLogin();
}

void UMainMenuWidget::OnLogoutButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::OnLogoutButtonClicked() called"));
     ToggleFakeLogin();
}

void UMainMenuWidget::OnCharactersButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::OnCharactersButtonClicked() called"));
     LoadCharacterMenu();
}

void UMainMenuWidget::OnOptionsButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::OnOptionsButtonClicked() called"));
     LoadOptionsMenu();
}

void UMainMenuWidget::OnQuitButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::OnQuitButtonClicked() called"));
     QuitGame();
}
