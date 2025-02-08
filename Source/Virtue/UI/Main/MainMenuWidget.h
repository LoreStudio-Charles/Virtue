#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

// Forward declarations to reduce compile-time dependencies.
class UButton;
class UTextBlock;
class UUIManager;

/**
 * UMainMenuWidget represents the main menu UI.
 * It includes buttons and text labels for various menu actions and updates its state based on login status.
 */
UCLASS()
class VIRTUE_API UMainMenuWidget : public UUserWidget
{
     GENERATED_BODY()

public:
     // Override NativeConstruct to bind button events and update UI state.
     virtual void NativeConstruct() override;

     // --- Button Click Handlers (must be UFUNCTION() for dynamic binding) ---
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

     // --- Blueprint-callable Functions ---
     UFUNCTION(BlueprintCallable, Category = "Menu")
     void ToggleFakeLogin();

     UFUNCTION(BlueprintCallable, Category = "Menu")
     void UpdateMenuState();

     UFUNCTION(BlueprintCallable, Category = "Menu")
     void QuitGame();

     UFUNCTION(BlueprintCallable, Category = "Menu")
     void LoadCharactersMenu();

     UFUNCTION(BlueprintCallable, Category = "Menu")
     void LoadOptionsMenu();

protected:
     // --- UI Elements for Buttons ---
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

     // --- UI Elements for Button Labels ---
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
     // Tracks the fake login state.
     bool bIsFakeLoggedIn = false;

     // Helper method for safely setting text on a UTextBlock.
     void SetButtonTextSafe(UTextBlock* TextBlock, const FText& NewText);

     // Helper method for setting button visibility.
     void SetButtonVisibility(UButton* Button, bool bVisible);

     // Returns the UI Manager subsystem.
     UUIManager* GetUIManager() const;
};
