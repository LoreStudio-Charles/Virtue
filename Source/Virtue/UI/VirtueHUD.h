#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "Virtue/MainMenuWidget.h"  // Include the custom UMainMenuWidget header
#include "VirtueHUD.generated.h"  // This must be at the bottom

UCLASS()
class VIRTUE_API AVirtueHUD : public AHUD
{
     GENERATED_BODY()

public:
     // Constructor
     AVirtueHUD();

     // Called when the game starts or when spawned
     virtual void BeginPlay() override;

     // Show Main Menu
     void ShowMainMenu();

     // Widget Class Reference (Editable in Editor)
     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
     TSubclassOf<UMainMenuWidget> MainMenuWidgetClass;  // Changed to UMainMenuWidget if available

     // The actual Main Menu Widget instance
     UPROPERTY()
     UMainMenuWidget* MainMenuWidget;  // Changed type accordingly
};
