#include "UIManager.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "UObject/SoftObjectPath.h"
#include "Logging/LogMacros.h"
#include <Blueprint/WidgetBlueprintLibrary.h>

void UUIManager::Initialize(FSubsystemCollectionBase& Collection)
{
     Super::Initialize(Collection);

     // Instead of using ConstructorHelpers (which can't be used here), we use FSoftObjectPath.
     if (!OptionsMenuWidgetClass)
     {
          FSoftObjectPath OptionsMenuPath(TEXT("/Game/UI_Menu/WBP_OptionsMenuWidget.WBP_OptionsMenuWidget_C"));
          UObject* LoadedObject = OptionsMenuPath.TryLoad();
          if (LoadedObject)
          {
               OptionsMenuWidgetClass = Cast<UClass>(LoadedObject);
               if (OptionsMenuWidgetClass)
               {
                    UE_LOG(LogTemp, Warning, TEXT("UIManager::Initialize - OptionsMenuWidgetClass assigned via SoftObjectPath."));
               }
               else
               {
                    UE_LOG(LogTemp, Error, TEXT("UIManager::Initialize - Loaded object is not a UClass."));
               }
          }
          else
          {
               UE_LOG(LogTemp, Error, TEXT("UIManager::Initialize - Failed to load OptionsMenuWidget via SoftObjectPath."));
          }
     }
}

void UUIManager::CloseAllMenus()
{
     TArray<UUserWidget*> FoundWidgets;
     UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(), FoundWidgets, UUserWidget::StaticClass(), false);

     for (UUserWidget* Widget : FoundWidgets)
     {
          if (Widget)
          {
               Widget->SetVisibility(ESlateVisibility::Collapsed);
               Widget->RemoveFromParent();
          }
     }

     UE_LOG(LogTemp, Warning, TEXT("All UI widgets removed."));
}

void UUIManager::ShowMainMenu()
{
     UE_LOG(LogTemp, Warning, TEXT("!!!!!!!!!!!!!!!! MAIN MENU CALLED !!!!!!!!!!!!!!!!!!!!"));
     if (OptionsMenu)
     {
          UE_LOG(LogTemp, Warning, TEXT("Recalling MainMenu; making it visible."));
          MainMenu->SetVisibility(ESlateVisibility::Visible);
     }
     else
     {
          UE_LOG(LogTemp, Warning, TEXT("MainMenu does not exist."));
     }
     // Ensure we have a valid MainMenuWidgetClass.
     if (!MainMenuWidgetClass)
     {
          FSoftObjectPath MainMenuPath(TEXT("/Game/UI_Menu/WBP_MainMenuWidget.WBP_MainMenuWidget_C"));
          UObject* LoadedObject = MainMenuPath.TryLoad();
          if (LoadedObject)
          {
               MainMenuWidgetClass = Cast<UClass>(LoadedObject);
               if (MainMenuWidgetClass)
               {
                    UE_LOG(LogTemp, Warning, TEXT("UIManager::Initialize - MainMenuWidgetClass assigned via SoftObjectPath."));
               }
               else
               {
                    UE_LOG(LogTemp, Error, TEXT("UIManager::Initialize - Loaded object is not a UClass."));
               }
          }
          else
          {
               UE_LOG(LogTemp, Error, TEXT("UIManager::Initialize - Failed to load MainMenuWidget via SoftObjectPath."));
          }
     }

     // Create the widget if it doesn't exist yet.
     if (!MainMenu)
     {
          UWorld* World = GetGameInstance()->GetWorld();
          if (World)
          {
               MainMenu = CreateWidget<UMainMenuWidget>(World, MainMenuWidgetClass);
          }
     }

     if (MainMenu)
     {
          MainMenu->AddToViewport();
          UE_LOG(LogTemp, Warning, TEXT("UIManager: Main Menu displayed"));
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("UIManager::ShowMainMenu - Failed to create MainMenu widget"));
     }
}

void UUIManager::ShowOptionsMenu()
{
     UE_LOG(LogTemp, Warning, TEXT("In UIManager::ShowOptionsMenu()"));

     // If the main menu exists, hide it instead of removing it.
     if (MainMenu)
     {
          UE_LOG(LogTemp, Warning, TEXT("MainMenu exists; hiding it."));
          MainMenu->SetVisibility(ESlateVisibility::Collapsed);
     }
     else
     {
          UE_LOG(LogTemp, Warning, TEXT("MainMenu does not exist."));
     }

     // Ensure OptionsMenuWidgetClass is set.
     if (!OptionsMenuWidgetClass)
     {
          UE_LOG(LogTemp, Error, TEXT("UIManager::ShowOptionsMenu - OptionsMenuWidgetClass is NULL!"));
          return;
     }

     UWorld* World = GetGameInstance()->GetWorld();
     if (!World)
     {
          UE_LOG(LogTemp, Error, TEXT("UIManager::ShowOptionsMenu - GetWorld() returned NULL"));
          return;
     }

     // Create OptionsMenu widget if not already created.
     if (!OptionsMenu)
     {
          OptionsMenu = CreateWidget<UOptionsMenuWidget>(World, OptionsMenuWidgetClass);
          if (!OptionsMenu)
          {
               UE_LOG(LogTemp, Error, TEXT("UIManager::ShowOptionsMenu - Failed to create OptionsMenu widget"));
               return;
          }
     }

     OptionsMenu->AddToViewport();
     UE_LOG(LogTemp, Warning, TEXT("UIManager: Options Menu displayed successfully."));
}
