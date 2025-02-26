#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Animation/WidgetAnimation.h"
#include "Components/Button.h"
#include "MenuItemWidget.generated.h"

/**
 * A base class for menu items in the UI system.
 */
UCLASS(BlueprintType, Blueprintable)
class VIRTUE_API UMenuItemWidget : public UUserWidget
{
     GENERATED_BODY()

protected:
     virtual void NativeConstruct() override;

     UPROPERTY(BluePrintReadWrite, meta = (BindWidget))
     UButton* MainButton;

public:
     /** Sets the key used to look up the localized text from ST_UIStrings */
     UFUNCTION(BlueprintCallable, Category = "Menu Item")
     void SetMenuItemKey(const FName& NewKey);

     /** Updates the text manually */
     UFUNCTION(BlueprintCallable, Category = "Menu Item")
     void SetMenuText(const FText& NewText);

private:
     /** The text block displaying the menu item label */
     UPROPERTY(meta = (BindWidget))
     class UTextBlock* ItemText;

     /** The key to retrieve text from ST_UIStrings */
     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menu Item", meta = (AllowPrivateAccess = "true"))
     FName MenuItemKey;

     /** Updates the displayed text from ST_UIStrings */
     void UpdateTextFromUIStrings();

     /** Hover and Click Effects */
     UFUNCTION()
     void OnHovered();

     UFUNCTION()
     void OnUnhovered();

     UFUNCTION()
     void OnClicked();
};
