#include "UIManager.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "UObject/SoftObjectPath.h"
#include "Logging/LogMacros.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Virtue/Settings/AssetPaths.h"

// Called when the subsystem is created.
void UUIManager::Initialize(FSubsystemCollectionBase& Collection)
{
     Super::Initialize(Collection);
     UE_LOG(LogTemp, Warning, TEXT("UUIManager::Initialize() called"));

     // If OptionsMenuWidgetClass is not set, attempt to load it via a soft object path.
     if (!OptionsMenuWidgetClass)
     {
          // Adjust the path as necessary. Ensure the asset exists at this location.
          FSoftObjectPath OptionsMenuPath(*AssetPaths::OptionsMenuWidget);
          UObject* LoadedObject = OptionsMenuPath.TryLoad();
          if (LoadedObject)
          {
               OptionsMenuWidgetClass = Cast<UClass>(LoadedObject);
               if (OptionsMenuWidgetClass)
               {
                    UE_LOG(LogTemp, Warning, TEXT("UUIManager::Initialize - OptionsMenuWidgetClass assigned via SoftObjectPath."));
               }
               else
               {
                    UE_LOG(LogTemp, Error, TEXT("UUIManager::Initialize - Loaded object is not a UClass."));
               }
          }
          else
          {
               UE_LOG(LogTemp, Error, TEXT("UUIManager::Initialize - Failed to load OptionsMenuWidget via SoftObjectPath."));
          }
     }
     if (!CharactersMenuWidgetClass)
     {
          FSoftObjectPath CharactersMenuPath(*AssetPaths::CharactersMenuWidget);
          UObject* LoadedObject = CharactersMenuPath.TryLoad();
          if (LoadedObject)
          {
               CharactersMenuWidgetClass = Cast<UClass>(LoadedObject);
               if (CharactersMenuWidgetClass)
               {
                    UE_LOG(LogTemp, Warning, TEXT("UUIManager::Initialize - CharactersMenuWidgetClass assigned via SoftObjectPath."));
               }
               else
               {
                    UE_LOG(LogTemp, Error, TEXT("UUIManager::Initialize - Loaded object is not a UClass."));
               }
          }
          else
          {
               UE_LOG(LogTemp, Error, TEXT("UUIManager::Initialize - Failed to load CharactersMenuWidget via SoftObjectPath."));
          }
     }

}

// Helper function: Opens a menu given its widget class.
void UUIManager::OpenMenu(TSubclassOf<UUserWidget> MenuClass)
{
     if (!MenuClass)
     {
          UE_LOG(LogTemp, Error, TEXT("OpenMenu: MenuClass is null!"));
          return;
     }

     UWorld* World = GetWorld();
     if (!World)
     {
          UE_LOG(LogTemp, Error, TEXT("OpenMenu: GetWorld() returned null!"));
          return;
     }

     UUserWidget* NewMenu = CreateWidget<UUserWidget>(World, MenuClass);
     if (NewMenu)
     {
          NewMenu->AddToViewport();
          UE_LOG(LogTemp, Warning, TEXT("OpenMenu: Widget added to viewport."));
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("OpenMenu: Failed to create widget."));
     }
}

// Closes a specific menu widget by removing it from the viewport.
void UUIManager::CloseMenu(UUserWidget* MenuInstance)
{
     if (MenuInstance && MenuInstance->IsInViewport())
     {
          MenuInstance->RemoveFromParent();
          UE_LOG(LogTemp, Warning, TEXT("CloseMenu: Menu removed from viewport."));
     }
}

// Closes all UI widgets currently on screen.
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

     UE_LOG(LogTemp, Warning, TEXT("CloseAllMenus: All UI widgets removed."));
}

// Shows the Main Menu. If the Options Menu is open, it is closed first.
void UUIManager::ShowMainMenu()
{
     UE_LOG(LogTemp, Warning, TEXT("UUIManager::ShowMainMenu() called"));

     // If the Options Menu is open, close it.
     if (OptionsMenu)
     {
          OptionsMenu->RemoveFromParent();
          OptionsMenu = nullptr;
          UE_LOG(LogTemp, Warning, TEXT("ShowMainMenu: Options Menu removed."));
     }

     // If the Main Menu is not already created, create it.
     if (!MainMenu)
     {
          if (!MainMenuWidgetClass)
          {
               // Attempt to load MainMenuWidgetClass via a soft object path if not set.
               FSoftObjectPath MainMenuPath(*AssetPaths::MainMenuWidget);
               UObject* LoadedObject = MainMenuPath.TryLoad();
               if (LoadedObject)
               {
                    MainMenuWidgetClass = Cast<UClass>(LoadedObject);
                    if (MainMenuWidgetClass)
                    {
                         UE_LOG(LogTemp, Warning, TEXT("ShowMainMenu: MainMenuWidgetClass assigned via SoftObjectPath."));
                    }
                    else
                    {
                         UE_LOG(LogTemp, Error, TEXT("ShowMainMenu: Loaded object is not a UClass."));
                    }
               }
               else
               {
                    UE_LOG(LogTemp, Error, TEXT("ShowMainMenu: Failed to load MainMenuWidget via SoftObjectPath."));
                    return;
               }
          }

          UWorld* World = GetWorld();
          if (World)
          {
               MainMenu = CreateWidget<UMainMenuWidget>(World, MainMenuWidgetClass);
          }
     }

     if (MainMenu)
     {
          // Make sure the Main Menu is visible and add it to the viewport.
          MainMenu->SetVisibility(ESlateVisibility::Visible);
          MainMenu->AddToViewport();
          UE_LOG(LogTemp, Warning, TEXT("ShowMainMenu: Main Menu displayed."));
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("ShowMainMenu: Failed to create Main Menu widget."));
     }
}

// Shows the Options Menu. If the Main Menu is open, it is hidden (visibility set to Collapsed).
void UUIManager::ShowOptionsMenu()
{
     UE_LOG(LogTemp, Warning, TEXT("UUIManager::ShowOptionsMenu() called"));

     // If the Main Menu exists, hide it.
     if (MainMenu)
     {
          MainMenu->SetVisibility(ESlateVisibility::Collapsed);
          UE_LOG(LogTemp, Warning, TEXT("ShowOptionsMenu: Main Menu hidden."));
     }
     else
     {
          UE_LOG(LogTemp, Warning, TEXT("ShowOptionsMenu: Main Menu does not exist."));
     }

     // Ensure the Options Menu widget class is set.
     if (!OptionsMenuWidgetClass)
     {
          UE_LOG(LogTemp, Error, TEXT("ShowOptionsMenu: OptionsMenuWidgetClass is NULL!"));
          return;
     }

     UWorld* World = GetWorld();
     if (!World)
     {
          UE_LOG(LogTemp, Error, TEXT("ShowOptionsMenu: GetWorld() returned NULL."));
          return;
     }

     // If the Options Menu is not already created, create it.
     if (!OptionsMenu)
     {
          OptionsMenu = CreateWidget<UOptionsMenuWidget>(World, OptionsMenuWidgetClass);
          if (!OptionsMenu)
          {
               UE_LOG(LogTemp, Error, TEXT("ShowOptionsMenu: Failed to create Options Menu widget."));
               return;
          }
     }

     // Make sure the Options Menu is visible and add it to the viewport.
     OptionsMenu->SetVisibility(ESlateVisibility::Visible);
     OptionsMenu->AddToViewport();
     UE_LOG(LogTemp, Warning, TEXT("ShowOptionsMenu: Options Menu displayed successfully."));
}

void UUIManager::ShowCharactersMenu()
{
     UE_LOG(LogTemp, Warning, TEXT("UUIManager::ShowCharactersMenu() called"));

     // If the Main Menu exists, hide it.
     if (MainMenu)
     {
          MainMenu->SetVisibility(ESlateVisibility::Collapsed);
          UE_LOG(LogTemp, Warning, TEXT("ShowCharactersMenu: Main Menu hidden."));
     }
     else
     {
          UE_LOG(LogTemp, Warning, TEXT("ShowCharactersMenu: Main Menu does not exist."));
     }

     // Ensure the Characters Menu widget class is set.
     if (!CharactersMenuWidgetClass)
     {
          UE_LOG(LogTemp, Error, TEXT("ShowCharactersMenu: CharactersMenuWidgetClass is NULL!"));
          return;
     }

     UWorld* World = GetWorld();
     if (!World)
     {
          UE_LOG(LogTemp, Error, TEXT("ShowCharactersMenu: GetWorld() returned NULL."));
          return;
     }

     // If the Characters Menu is not already created, create it.
     if (!IsValid(CharactersMenu))
     {
          CharactersMenu = CreateWidget<UCharactersMenuWidget>(World, CharactersMenuWidgetClass);
          if (!CharactersMenu)
          {
               UE_LOG(LogTemp, Error, TEXT("ShowCharactersMenu: Failed to create Characters Menu widget."));
               return;
          }
     }

     // Make sure the Characters Menu is visible and add it to the viewport.
     if (!CharactersMenu->IsInViewport())
     {
          CharactersMenu->AddToViewport();
          UE_LOG(LogTemp, Warning, TEXT("ShowCharactersMenu: Characters Menu displayed successfully."));
     }
     else
     {
          UE_LOG(LogTemp, Warning, TEXT("ShowCharactersMenu: Characters Menu was already visible."));
     }
}
