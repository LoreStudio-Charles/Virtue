#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "VirtueHUD.generated.h"

UCLASS()
class VIRTUE_API AVirtueHUD : public AHUD
{
     GENERATED_BODY()

public:
     AVirtueHUD();

     virtual void BeginPlay() override;

     /** Displays the menus */
     void ShowBaseMenu();
     void ShowOptionsMenu();

protected:
     /** Menu UMG widget class */
     UPROPERTY(EditDefaultsOnly, Category = "UI")
     TSubclassOf<UUserWidget> BaseMenuClass;

private:
     /** Pointer to the current menu widget */
     UPROPERTY()
     UUserWidget* BaseMenuWidget;
};
