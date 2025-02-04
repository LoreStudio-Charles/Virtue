#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "MainMenuWidget.generated.h"

/**
 * UMainMenuWidget represents the main menu UI.
 * It may contain buttons and text elements, such as a Quit button label.
 */

UCLASS()
class VIRTUE_API UMainMenuWidget : public UUserWidget
{
     GENERATED_BODY()

public:
     virtual void NativeConstruct() override;

     // UI element for buttons
     UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
     UButton* ConnectButton;

     UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
     UButton* QuitButton;

     UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
     UButton* CharactersButton;

     UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
     UButton* OptionsButton;

     UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
     UButton* LogoutButton;

     // UI element for the button text.
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

     // Toggle login state
     UFUNCTION(BlueprintCallable)
     void ToggleFakeLogin();

protected:
     // Handle button clicks
     UFUNCTION()
     void OnConnectButtonClicked();

     UFUNCTION()
     void OnLogoutButtonClicked();

     UFUNCTION()
     void OnQuitButtonClicked();

     UFUNCTION()
     void OnCharactersButtonClicked();

     UFUNCTION()
     void OnOptionsButtonClicked();

     // Update menu state based on login status
     UFUNCTION(BlueprintCallable)
     void UpdateMenuState();

     UFUNCTION(BlueprintCallable)
     void QuitGame();

     UFUNCTION(BlueprintCallable)
     void LoadCharacterMenu();

     UFUNCTION(BlueprintCallable)
     void LoadOptionsMenu();

private:
     bool bIsFakeLoggedIn = false;  // Tracks login state
};
