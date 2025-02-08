#include "UIManager.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "UObject/SoftObjectPath.h"
#include "Logging/LogMacros.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Virtue/Settings/AssetPaths.h"
#include "Virtue/UI/Main/MainMenuWidget.h"
#include "Virtue/UI/Main/OptionsMenuWidget.h"
#include "Virtue/UI/CharacterCustomization/CharactersMenuWidget.h"

namespace
{
     TSubclassOf<UUserWidget> LoadWidgetClass(const FString& AssetPath)
     {
          if (AssetPath.IsEmpty())
          {
               UE_LOG(LogTemp, Error, TEXT("LoadWidgetClass: AssetPath is empty!"));
               return nullptr;
          }

          FSoftObjectPath WidgetPath(*AssetPath);
          UObject* LoadedObject = WidgetPath.TryLoad();
          if (LoadedObject)
          {
               TSubclassOf<UUserWidget> WidgetClass = Cast<UClass>(LoadedObject);
               if (!WidgetClass)
               {
                    UE_LOG(LogTemp, Error, TEXT("LoadWidgetClass: Loaded object is not a UClass!"));
               }
               return WidgetClass;
          }

          UE_LOG(LogTemp, Error, TEXT("LoadWidgetClass: Failed to load widget from path: %s"), *AssetPath);
          return nullptr;
     }
}

void UUIManager::Initialize(FSubsystemCollectionBase& Collection)
{
     Super::Initialize(Collection);
     UE_LOG(LogTemp, Warning, TEXT("UUIManager::Initialize() called"));
     UE_LOG(LogTemp, Warning, TEXT("MainMenuWidget asset path: %s"), *AssetPaths::MainMenuWidget);


     if (!OptionsMenuWidgetClass)
     {
          OptionsMenuWidgetClass = LoadWidgetClass(AssetPaths::OptionsMenuWidget);
     }
     if (!CharactersMenuWidgetClass)
     {
          CharactersMenuWidgetClass = LoadWidgetClass(AssetPaths::CharactersMenuWidget);
     }
     if (!MainMenuWidgetClass)
     {
          MainMenuWidgetClass = LoadWidgetClass(AssetPaths::MainMenuWidget);
     }
}

void UUIManager::OpenMenu(TSubclassOf<UUserWidget> MenuClass)
{
     if (!IsValid(MenuClass))
     {
          UE_LOG(LogTemp, Error, TEXT("OpenMenu: MenuClass is invalid!"));
          return;
     }

     UWorld* World = GetWorld();
     if (!World)
     {
          UE_LOG(LogTemp, Error, TEXT("OpenMenu: GetWorld() returned null!"));
          return;
     }

     UUserWidget* NewMenu = CreateWidget<UUserWidget>(World, MenuClass);
     if (IsValid(NewMenu))
     {
          NewMenu->AddToViewport(100);
          UE_LOG(LogTemp, Warning, TEXT("OpenMenu: Widget added to viewport."));
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("OpenMenu: Failed to create widget."));
     }
}

void UUIManager::CloseMenu(UUserWidget* MenuInstance)
{
     if (IsValid(MenuInstance))
     {
          MenuInstance->RemoveFromParent();
          UE_LOG(LogTemp, Warning, TEXT("CloseMenu: Menu removed from viewport."));
     }
}

void UUIManager::CloseAllMenus()
{
     UWorld* World = GetWorld();
     if (!World)
     {
          UE_LOG(LogTemp, Error, TEXT("CloseAllMenus: GetWorld() returned null!"));
          return;
     }

     TArray<UUserWidget*> FoundWidgets;
     UWidgetBlueprintLibrary::GetAllWidgetsOfClass(World, FoundWidgets, UUserWidget::StaticClass(), false);
     for (UUserWidget* Widget : FoundWidgets)
     {
          if (IsValid(Widget))
          {
               Widget->RemoveFromParent();
          }
     }
     UE_LOG(LogTemp, Warning, TEXT("CloseAllMenus: All UI widgets removed."));
}

void UUIManager::ShowMainMenu()
{
     UE_LOG(LogTemp, Warning, TEXT("ShowMainMenu() called"));

     UWorld* World = GetWorld();
     if (!World)
     {
          UE_LOG(LogTemp, Error, TEXT("ShowMainMenu: GetWorld() returned null!"));
          return;
     }

     // Close the Options Menu if it exists.
     if (IsValid(OptionsMenu))
     {
          CloseMenu(OptionsMenu);
          OptionsMenu = nullptr;
          UE_LOG(LogTemp, Warning, TEXT("ShowMainMenu: Options Menu closed."));
     }

     // If the Main Menu doesn't exist, create it.
     if (!IsValid(MainMenu))
     {
          if (!MainMenuWidgetClass)
          {
               UE_LOG(LogTemp, Error, TEXT("ShowMainMenu: MainMenuWidgetClass is null!"));
               return;
          }
          MainMenu = CreateWidget<UMainMenuWidget>(World, MainMenuWidgetClass);
          if (MainMenu)
          {
               UE_LOG(LogTemp, Warning, TEXT("ShowMainMenu: Main Menu widget created at %p."), MainMenu);
          }
     }

     if (IsValid(MainMenu))
     {
          // Add to viewport with a high Z-order.
          MainMenu->AddToViewport(100);
          // **Set visibility to Visible to override any previous Collapsed state.**
          MainMenu->SetVisibility(ESlateVisibility::Visible);
          UE_LOG(LogTemp, Warning, TEXT("ShowMainMenu: Main Menu added to viewport and set to Visible."));
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("ShowMainMenu: Failed to create Main Menu widget."));
     }
}

void UUIManager::ShowOptionsMenu()
{
     UE_LOG(LogTemp, Warning, TEXT("ShowOptionsMenu() called"));

     UWorld* World = GetWorld();
     if (!World)
     {
          UE_LOG(LogTemp, Error, TEXT("ShowOptionsMenu: GetWorld() returned null!"));
          return;
     }

     if (IsValid(MainMenu))
     {
          MainMenu->SetVisibility(ESlateVisibility::Collapsed);
          UE_LOG(LogTemp, Warning, TEXT("ShowOptionsMenu: Main Menu collapsed."));
     }

     if (!IsValid(OptionsMenu))
     {
          if (!OptionsMenuWidgetClass)
          {
               UE_LOG(LogTemp, Error, TEXT("ShowOptionsMenu: OptionsMenuWidgetClass is null!"));
               return;
          }
          OptionsMenu = CreateWidget<UOptionsMenuWidget>(World, OptionsMenuWidgetClass);
     }

     if (IsValid(OptionsMenu))
     {
          OptionsMenu->AddToViewport(100);
          UE_LOG(LogTemp, Warning, TEXT("ShowOptionsMenu: Options Menu added to viewport."));
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("ShowOptionsMenu: Failed to create Options Menu widget."));
     }
}

void UUIManager::ShowCharactersMenu()
{
     UE_LOG(LogTemp, Warning, TEXT("ShowCharactersMenu() called"));

     UWorld* World = GetWorld();
     if (!World)
     {
          UE_LOG(LogTemp, Error, TEXT("ShowCharactersMenu: GetWorld() returned null!"));
          return;
     }

     if (IsValid(MainMenu))
     {
          MainMenu->SetVisibility(ESlateVisibility::Collapsed);
     }

     if (!IsValid(CharactersMenu))
     {
          if (!CharactersMenuWidgetClass)
          {
               UE_LOG(LogTemp, Error, TEXT("ShowCharactersMenu: CharactersMenuWidgetClass is null!"));
               return;
          }
          CharactersMenu = CreateWidget<UCharactersMenuWidget>(World, CharactersMenuWidgetClass);
     }

     if (IsValid(CharactersMenu))
     {
          CharactersMenu->AddToViewport(100);
          UE_LOG(LogTemp, Warning, TEXT("ShowCharactersMenu: Characters Menu added to viewport."));
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("ShowCharactersMenu: Failed to create Character Menu widget."));
     }
}
