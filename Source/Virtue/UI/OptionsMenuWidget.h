#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseMenuWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "OptionsMenuWidget.generated.h"

/**
 * OptionsMenuWidget is derived from BaseMenu.
 This widget creates the "Options" menu.
 */
UCLASS()
class VIRTUE_API UOptionsMenuWidget : public UBaseMenuWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;


	// UI element for buttons
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ReturnToGameButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* GraphicsButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* AudioButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ControlsButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* GameplayButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* AccessibilityButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* QuitToMainMenuButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* QuitToDesktopButton;

	// UI element for the button text
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* OptionsMenuTitleText;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* ReturnToGameButtonText;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* GraphicsButtonText;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* AudioButtonText;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* ControlsButtonText;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* GameplayButtonText;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* AccessibilityButtonText;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* QuitToMainMenuButtonText;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* QuitToDesktopButtonText;



protected:
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
	bool isInGameSession = false;
};
