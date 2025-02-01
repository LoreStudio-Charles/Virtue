#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "Logging/LogMacros.h"

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

     // Call UpdateMenuState so the UI reflects the login state.
     UpdateMenuState();
}

void UMainMenuWidget::ToggleFakeLogin_Implementation()
{
     bIsFakeLoggedIn = !bIsFakeLoggedIn;
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::ToggleFakeLogin_Implementation() toggled: %s"),
          bIsFakeLoggedIn ? TEXT("Logged In") : TEXT("Logged Out"));
     // Call our UpdateMenuState, which will call UMainMenuWidget's override.
     UpdateMenuState();
}

void UMainMenuWidget::UpdateMenuState_Implementation()
{
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::UpdateMenuState_Implementation() called"));

     if (!ConnectButton || !LogoutButton || !CharactersButton)
     {
          UE_LOG(LogTemp, Error, TEXT("One or more buttons are NULL in UpdateMenuState_Implementation!"));
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

void UMainMenuWidget::OnConnectButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::OnConnectButtonClicked() called"));
     // Call ToggleFakeLogin() on this instance; this will invoke our override.
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
     // Future functionality: Navigate to character selection.
}
