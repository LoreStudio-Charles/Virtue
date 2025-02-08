#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Virtue/Data/VirtueEnums.h" // Ensure this defines ECharacterMenuScreen with Landing, Create, Delete, Select.
#include "CharactersMenuWidget.generated.h"

// Forward declarations to reduce compile-time dependencies.
class UButton;
class UTextBlock;
class UCanvasPanel;
class UVerticalBox;

/**
 * UCharactersMenuWidget handles the transition-to-character, character deletion,
 * and character-creation screens.
 *
 * It binds button events, updates localized text, and manages switching between
 * canvas panels based on the ECharacterMenuScreen enum.
 */
UCLASS()
class VIRTUE_API UCharactersMenuWidget : public UUserWidget
{
     GENERATED_BODY()

public:
     /** Sets the active screen by showing only the canvas corresponding to the given screen type. */
     UFUNCTION(BlueprintCallable, Category = "Character Menu")
     void SetActiveScreen(ECharacterMenuScreen Screen);

     // UUserWidget override.
     virtual void NativeConstruct() override;

     // --- Event Handlers: Transition-to-Character Screen ---
     UFUNCTION()
     void OnCTScreenCreateButtonClicked();

     UFUNCTION()
     void OnCTScreenBackButtonClicked();

     UFUNCTION()
     void OnCTScreenSelectCharacterButtonClicked();

     UFUNCTION()
     void OnCTScreenDeleteCharacterButtonClicked();

     // --- Event Handlers: Character Creation Screen ---
     UFUNCTION()
     void OnPartsHeadButtonClicked();

     UFUNCTION()
     void OnPartsHairButtonClicked();

     UFUNCTION()
     void OnPartsTorsoButtonClicked();

     UFUNCTION()
     void OnPartsArmsButtonClicked();

     UFUNCTION()
     void OnPartsLegsButtonClicked();

     UFUNCTION()
     void OnPartsAccessoriesButtonClicked();

     UFUNCTION()
     void OnBackButtonClicked();

     UFUNCTION()
     void OnPartsButtonClicked();

     UFUNCTION()
     void OnCreateButtonClicked();

protected:
     // --- Canvas Panels for Screen Switching ---
     /** Canvas for the Landing screen. Bind this in UMG. */
     UPROPERTY(meta = (BindWidget))
     UCanvasPanel* LandingCanvas;

     /** Canvas for the Create screen. Bind this in UMG. */
     UPROPERTY(meta = (BindWidget))
     UCanvasPanel* CreateCanvas;

     /** Canvas for the Delete screen. Bind this in UMG. */
     UPROPERTY(meta = (BindWidget))
     UCanvasPanel* DeleteCanvas;

     /** Canvas for the Select screen. Bind this in UMG. */
     UPROPERTY(meta = (BindWidget))
     UCanvasPanel* SelectCanvas;

     // --- Transition-to-Character Screen UI Elements ---
     UPROPERTY(meta = (BindWidget))
     UButton* CTScreenCreateButton;

     UPROPERTY(meta = (BindWidget))
     UButton* CTScreenBackButton;

     UPROPERTY(meta = (BindWidget))
     UButton* CTScreenSelectCharacterButton;

     UPROPERTY(meta = (BindWidget))
     UButton* CTScreenDeleteCharacterButton;

     UPROPERTY(meta = (BindWidget))
     UTextBlock* CTScreenCreateButtonText;

     UPROPERTY(meta = (BindWidget))
     UTextBlock* CTScreenBackButtonText;

     UPROPERTY(meta = (BindWidget))
     UTextBlock* CTScreenSelectCharacterButtonText;

     UPROPERTY(meta = (BindWidget))
     UTextBlock* CTScreenDeleteCharacterButtonText;

     // --- Character Creation Screen UI Elements ---
     UPROPERTY(meta = (BindWidget))
     UButton* PartsHeadButton;

     UPROPERTY(meta = (BindWidget))
     UButton* PartsHairButton;

     UPROPERTY(meta = (BindWidget))
     UButton* PartsTorsoButton;

     UPROPERTY(meta = (BindWidget))
     UButton* PartsArmsButton;

     UPROPERTY(meta = (BindWidget))
     UButton* PartsLegsButton;

     UPROPERTY(meta = (BindWidget))
     UButton* PartsAccessoriesButton;

     UPROPERTY(meta = (BindWidget))
     UButton* BackButton;

     UPROPERTY(meta = (BindWidget))
     UButton* CreateButton;

     UPROPERTY(meta = (BindWidget))
     UTextBlock* PartsHeadButtonText;

     UPROPERTY(meta = (BindWidget))
     UTextBlock* PartsHairButtonText;

     UPROPERTY(meta = (BindWidget))
     UTextBlock* PartsTorsoButtonText;

     UPROPERTY(meta = (BindWidget))
     UTextBlock* PartsArmsButtonText;

     UPROPERTY(meta = (BindWidget))
     UTextBlock* PartsLegsButtonText;

     UPROPERTY(meta = (BindWidget))
     UTextBlock* PartsAccessoriesButtonText;

     UPROPERTY(meta = (BindWidget))
     UTextBlock* BackButtonText;

     UPROPERTY(meta = (BindWidget))
     UTextBlock* CreateButtonText;

     // --- Layout Container ---
     UPROPERTY(meta = (BindWidget))
     UVerticalBox* PartsVerticalBox;

     // --- Internal State ---
     bool bInPartsMenu = false;

     // --- Helper Methods ---
     /**
      * Retrieves the root widget cast as a UCanvasPanel.
      * @return The root widget as a UCanvasPanel, or nullptr if the cast fails.
      */
     UCanvasPanel* GetRootCanvasPanel() const;
};
