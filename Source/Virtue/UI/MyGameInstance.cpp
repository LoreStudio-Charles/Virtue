#include "MyGameInstance.h"
#include "UIManager.h"
#include "OnlineSessionManager.h"
#include "Logging/LogMacros.h"

void UMyGameInstance::Init()
{
     Super::Init();

     UIManager = GetSubsystem<UUIManager>();
     if (UIManager)
     {
          UE_LOG(LogTemp, Warning, TEXT("UMyGameInstance::Init() - UIManager subsystem found"));

          if (MainMenuWidgetClass)
          {
               UIManager->SetMainMenuWidgetClass(MainMenuWidgetClass);
               UE_LOG(LogTemp, Warning, TEXT("MainMenuWidgetClass set successfully."));
          }
          else
          {
               UE_LOG(LogTemp, Error, TEXT("MainMenuWidgetClass is NULL! Make sure it is assigned in BP_MyGameInstance."));
          }

          if (OptionsMenuWidgetClass)
          {
               UIManager->SetOptionsMenuWidgetClass(OptionsMenuWidgetClass);
               UE_LOG(LogTemp, Warning, TEXT("OptionsMenuWidgetClass set successfully."));
          }
          else
          {
               UE_LOG(LogTemp, Error, TEXT("OptionsMenuWidgetClass is NULL! Make sure it is assigned in BP_MyGameInstance."));
          }

          UIManager->ShowMainMenu();
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("UMyGameInstance::Init() - UIManager subsystem not found!"));
     }
}
