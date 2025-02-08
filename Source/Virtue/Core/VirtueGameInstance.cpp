#include "VirtueGameInstance.h"
#include "UIManager.h"
#include "Virtue/Online/OnlineSessionManager.h"
#include "Logging/LogMacros.h"

void UVirtueGameInstance::Init()
{
     Super::Init();

     UIManager = GetSubsystem<UUIManager>();
     if (UIManager)
     {
          UE_LOG(LogTemp, Warning, TEXT("UVirtueGameInstance::Init() - UIManager subsystem found"));

          if (MainMenuWidgetClass)
          {
               UIManager->SetMainMenuWidgetClass(MainMenuWidgetClass);
               UE_LOG(LogTemp, Warning, TEXT("MainMenuWidgetClass set successfully."));
          }
          else
          {
               UE_LOG(LogTemp, Error, TEXT("MainMenuWidgetClass is NULL! Make sure it is assigned in BP_VirtueGameInstance."));
          }

          if (OptionsMenuWidgetClass)
          {
               UIManager->SetOptionsMenuWidgetClass(OptionsMenuWidgetClass);
               UE_LOG(LogTemp, Warning, TEXT("OptionsMenuWidgetClass set successfully."));
          }
          else
          {
               UE_LOG(LogTemp, Error, TEXT("OptionsMenuWidgetClass is NULL! Make sure it is assigned in BP_VirtueGameInstance."));
          }

          if (CharactersMenuWidgetClass)
          {
               UIManager->SetCharactersMenuWidgetClass(CharactersMenuWidgetClass);
               UE_LOG(LogTemp, Warning, TEXT("CharactersMenuWidgetClass set successfully."));
          }
          else
          {
               UE_LOG(LogTemp, Error, TEXT("CharactersMenuWidgetClass is NULL! Make sure it is assigned in BP_VirtueGameInstance."));
          }

          UIManager->ShowMainMenu();
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("UVirtueGameInstance::Init() - UIManager subsystem not found!"));
     }
}


