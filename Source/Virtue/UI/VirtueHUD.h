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
     // Constructor
     AVirtueHUD();

     // Called when the game starts or when spawned
     virtual void BeginPlay() override;

     // Show Main Menu
     void ShowMainMenu();

     // Widget Class Reference (Editable in Editor)
     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
     TSubclassOf<UUserWidget> MainMenuWidgetClass;

     // The actual Main Menu Widget instance
     UPROPERTY()
     UUserWidget* MainMenuWidget;
};
