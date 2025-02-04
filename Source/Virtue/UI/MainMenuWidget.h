#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "MainMenuWidget.generated.h"

/**
 * UMainMenuWidget represents the main menu UI.
 * It contains buttons and text elements for various menu actions.
 */
UCLASS()
class VIRTUE_API UMainMenuWidget : public UUserWidget
{
     GENERATED_BODY()

public:
     // Override NativeConstruct to bind button events and update UI state.
     virtual void NativeConstruct() override;

     // Button click handler functions (must be marked with UFUNCTION() for dynamic binding).
     UFUNCTION()
     void OnConnectButtonClicked();

     UFUNCTION()
     void OnLogoutButtonClicked();

     UFUNCTION()
     void OnCharactersButtonClicked();

     UFUNCTION()
     void OnOptionsButtonClicked();

     UFUNCTION()
     void OnQuitButtonClicked();

     // Toggle login state and update the menu state.
     UFUNCTION(BlueprintCallable)
     void ToggleFakeLogin();

     // Update UI elements based on login state.
     UFUNCTION(BlueprintCallable)
     void UpdateMenuState();

     // Quit the game.
     UFUNCTION(BlueprintCallable)
     void QuitGame();

     // Functions to load additional menus.
     UFUNCTION(BlueprintCallable)
     void LoadCharacterMenu();

     UFUNCTION(BlueprintCallable)
     void LoadOptionsMenu();

protected:
     // UI elements for buttons.
     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UButton* ConnectButton;

     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UButton* QuitButton;

     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UButton* CharactersButton;

     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UButton* OptionsButton;

     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UButton* LogoutButton;

     // UI elements for button labels.
     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UTextBlock* ConnectButtonText;

     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UTextBlock* QuitButtonText;

     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UTextBlock* CharactersButtonText;

     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UTextBlock* OptionsButtonText;

     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UTextBlock* LogoutButtonText;

private:
     // Tracks login state.
     bool bIsFakeLoggedIn = false;
};
