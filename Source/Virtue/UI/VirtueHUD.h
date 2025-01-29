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

     /** Displays the main menu */
     void ShowMainMenu();

protected:
     /** Main menu UMG widget class */
     UPROPERTY(EditDefaultsOnly, Category = "UI")
     TSubclassOf<UUserWidget> MainMenuClass;

private:
     /** Pointer to the current menu widget */
     UPROPERTY()
     UUserWidget* MainMenuWidget;
};
