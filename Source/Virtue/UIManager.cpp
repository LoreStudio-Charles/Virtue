#include "UIManager.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"

void UUIManager::ShowMainMenu()
{
     // Create the widget instance if it hasn't been created yet.
     if (!MainMenu && MainMenuWidgetClass)
     {
          MainMenu = CreateWidget<UMainMenuWidget>(GetWorld(), MainMenuWidgetClass);
     }

     // Instead of calling NativeConstruct manually,
     // add the widget to the viewport so that its lifecycle functions are called automatically.
     if (MainMenu)
     {
          MainMenu->AddToViewport();
     }
     else
     {
          UE_LOG(LogTemp, Warning, TEXT("MainMenuWidgetClass is not set or MainMenu creation failed!"));
     }
}
