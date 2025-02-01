#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MainMenuWidget.h"
#include "Subsystems/GameInstanceSubsystem.h" 
#include "UIManager.generated.h"

UCLASS()
class VIRTUE_API UUIManager : public UGameInstanceSubsystem
{
     GENERATED_BODY()

public:
     void ShowMainMenu();

private:
     UPROPERTY(EditDefaultsOnly, Category = "UI")
     TSubclassOf<UMainMenuWidget> MainMenuWidgetClass;

     UPROPERTY()
     UMainMenuWidget* MainMenu;
};
