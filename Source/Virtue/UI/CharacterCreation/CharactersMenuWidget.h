#pragma once

#include "CoreMinimal.h"
#include "Virtue/UI/BaseMenuWidget.h"
#include "Components/Button.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "CharactersMenuWidget.generated.h"

/**
 * UCharactersMenuWidget represents the characters menu UI,
 * where players can view and select their available characters.
 */
UCLASS()
class VIRTUE_API UCharactersMenuWidget : public UBaseMenuWidget
{
     GENERATED_BODY()

public:
     virtual void NativeConstruct() override;

     // UI element for buttons
     UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
     UButton* PartsHeadButton;

     UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
     UButton* PartsHairButton;

     UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
     UButton* PartsTorsoButton;

     UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
     UButton* PartsArmsButton;

     UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
     UButton* PartsLegsButton;

     UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
     UButton* PartsAccessoriesButton;

     UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
     UButton* BackButton;

     UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
     UButton* CreateButton;

     // UI element for the button text
     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UTextBlock* PartsHeadButtonText;

     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UTextBlock* PartsHairButtonText;

     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UTextBlock* PartsTorsoButtonText;

     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UTextBlock* PartsArmsButtonText;

     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UTextBlock* PartsLegsButtonText;

     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UTextBlock* PartsAccessoriesButtonText;

     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UTextBlock* BackButtonText;

     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UTextBlock* CreateButtonText;

     // UI Element for the vertical box
     UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
     UVerticalBox* PartsVerticalBox;

protected:
     UFUNCTION()

     void OnPartsButtonClicked();
     
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
     void OnCreateButtonClicked();

private:
     bool bInPartsMenu = false;
};

