#include "UIManager.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void UUIManager::ShowMainMenu()
{
     if (!MainMenu)
     {
          MainMenu = CreateWidget<UMainMenuWidget>(GetWorld(), MainMenuWidgetClass);
     }

     if (MainMenu)
     {
          MainMenu->NativeConstruct();
     }
}
