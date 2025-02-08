#pragma once

#include "CoreMinimal.h"
#include "BaseMenuWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "OptionsMenuWidget.generated.h"

/**
 * UOptionsMenuWidget creates the "Options" menu.
 * It binds various button events for actions like returning to the game,
 * changing settings, or quitting to the main menu or desktop.
 */
UCLASS()
class VIRTUE_API UOptionsMenuWidget : public UBaseMenuWidget
{
	GENERATED_BODY()

public:
	// Override NativeConstruct and NativeDestruct for widget setup and teardown.
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	// --- UI Elements for Buttons ---
	UPROPERTY(BlueprintReadWrite, Category = "Options Menu|Buttons", meta = (BindWidget))
	UButton* ReturnToGameButton;

	UPROPERTY(BlueprintReadWrite, Category = "Options Menu|Buttons", meta = (BindWidget))
	UButton* GraphicsButton;

	UPROPERTY(BlueprintReadWrite, Category = "Options Menu|Buttons", meta = (BindWidget))
	UButton* AudioButton;

	UPROPERTY(BlueprintReadWrite, Category = "Options Menu|Buttons", meta = (BindWidget))
	UButton* ControlsButton;

	UPROPERTY(BlueprintReadWrite, Category = "Options Menu|Buttons", meta = (BindWidget))
	UButton* GameplayButton;

	UPROPERTY(BlueprintReadWrite, Category = "Options Menu|Buttons", meta = (BindWidget))
	UButton* AccessibilityButton;

	UPROPERTY(BlueprintReadWrite, Category = "Options Menu|Buttons", meta = (BindWidget))
	UButton* QuitToMainMenuButton;

	UPROPERTY(BlueprintReadWrite, Category = "Options Menu|Buttons", meta = (BindWidget))
	UButton* QuitToDesktopButton;

	// --- UI Elements for Text Blocks ---
	UPROPERTY(BlueprintReadOnly, Category = "Options Menu|Text", meta = (BindWidget))
	UTextBlock* OptionsMenuTitleText;

	UPROPERTY(BlueprintReadOnly, Category = "Options Menu|Text", meta = (BindWidget))
	UTextBlock* ReturnToGameButtonText;

	UPROPERTY(BlueprintReadOnly, Category = "Options Menu|Text", meta = (BindWidget))
	UTextBlock* GraphicsButtonText;

	UPROPERTY(BlueprintReadOnly, Category = "Options Menu|Text", meta = (BindWidget))
	UTextBlock* AudioButtonText;

	UPROPERTY(BlueprintReadOnly, Category = "Options Menu|Text", meta = (BindWidget))
	UTextBlock* ControlsButtonText;

	UPROPERTY(BlueprintReadOnly, Category = "Options Menu|Text", meta = (BindWidget))
	UTextBlock* GameplayButtonText;

	UPROPERTY(BlueprintReadOnly, Category = "Options Menu|Text", meta = (BindWidget))
	UTextBlock* AccessibilityButtonText;

	UPROPERTY(BlueprintReadOnly, Category = "Options Menu|Text", meta = (BindWidget))
	UTextBlock* QuitToMainMenuButtonText;

	UPROPERTY(BlueprintReadOnly, Category = "Options Menu|Text", meta = (BindWidget))
	UTextBlock* QuitToDesktopButtonText;

protected:
	// --- Button Event Handlers ---
	UFUNCTION()
	void OnReturnToGameButtonClicked();

	UFUNCTION()
	void OnGraphicsButtonClicked();

	UFUNCTION()
	void OnAudioButtonClicked();

	UFUNCTION()
	void OnControlsButtonClicked();

	UFUNCTION()
	void OnGameplayButtonClicked();

	UFUNCTION()
	void OnAccessibilityButtonClicked();

	UFUNCTION()
	void OnQuitToMainMenuButtonClicked();

	UFUNCTION()
	void OnQuitToDesktopButtonClicked();

private:
	// Tracks whether the widget is used during an active game session.
	bool bIsInGameSession = false;
};
