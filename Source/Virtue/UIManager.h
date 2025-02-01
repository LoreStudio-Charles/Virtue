#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MainMenuWidget.h"  // Include the header for UMainMenuWidget
#include "UIManager.generated.h"

UCLASS()
class VIRTUE_API UUIManager : public UGameInstanceSubsystem
{
     GENERATED_BODY()

public:
     // Function to show the main menu
     void ShowMainMenu();

private:
     // Editable property to assign the main menu widget blueprint in the editor
     UPROPERTY(EditDefaultsOnly, Category = "UI")
     TSubclassOf<UMainMenuWidget> MainMenuWidgetClass;

     // The instance of the main menu widget
     UPROPERTY()
     UMainMenuWidget* MainMenu;
};
