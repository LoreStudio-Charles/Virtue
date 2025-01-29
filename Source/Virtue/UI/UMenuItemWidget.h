/*

#pragma once

#include "Blueprint/UserWidget.h"
#include "SMenuItemWidget.h"
#include "UMenuItemWidget.generated.h"

UCLASS()
class VIRTUE_API UMenuItemWidget : public UUserWidget
{
     GENERATED_BODY()

public:
     /** Text displayed on the menu item 
     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menu", meta = (ExposeOnSpawn = "true"))
     FText MenuText;

     virtual TSharedRef<SWidget> RebuildWidget() override;

     /** Updates the text dynamically 
     UFUNCTION(BlueprintCallable, Category = "Menu")
     void SetText(const FText& NewText);

private:
     TSharedPtr<SMenuItemWidget> SlateWidget;
};
*/

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "UMenuItemWidget.generated.h"

UCLASS()
class VIRTUE_API UMenuItemWidget : public UUserWidget
{
     GENERATED_BODY()

protected:
     virtual void NativeConstruct() override;

     UFUNCTION()
     void OnHovered();

     UFUNCTION()
     void OnUnhovered();

     void SetMaterialOpacity(float Opacity);
     void SetMaterialGlow(float Glow);

private:
     UPROPERTY(meta = (BindWidget))
     UButton* DynamicButton;

     UPROPERTY()
     UMaterialInstanceDynamic* DynamicMaterial;
};
