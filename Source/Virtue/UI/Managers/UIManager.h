#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Blueprint/UserWidget.h"
#include "UIManager.generated.h"

// Forward declarations of your widget classes.
class UMainMenuWidget;
class UOptionsMenuWidget;
class UCharactersMenuWidget;

/**
 * UUIManager is a GameInstanceSubsystem that manages UI menus.
 */
UCLASS(Blueprintable)
class VIRTUE_API UUIManager : public UGameInstanceSubsystem
{
     GENERATED_BODY()

public:
     // Override Initialize.
     virtual void Initialize(FSubsystemCollectionBase& Collection) override;

     // Menu management functions.
     UFUNCTION(BlueprintCallable, Category = "UI")
     void OpenMenu(TSubclassOf<UUserWidget> MenuClass);

     UFUNCTION(BlueprintCallable, Category = "UI")
     void CloseMenu(UUserWidget* MenuInstance);

     UFUNCTION(BlueprintCallable, Category = "UI")
     void CloseAllMenus();

     UFUNCTION(BlueprintCallable, Category = "UI")
     void ShowMainMenu();

     UFUNCTION(BlueprintCallable, Category = "UI")
     void ShowOptionsMenu();

     UFUNCTION(BlueprintCallable, Category = "UI")
     void ShowCharactersMenu();

     // Setter methods for widget classes.
     UFUNCTION(BlueprintCallable, Category = "UI")
     void SetMainMenuWidgetClass(TSubclassOf<UMainMenuWidget> WidgetClass) { MainMenuWidgetClass = WidgetClass; }

     UFUNCTION(BlueprintCallable, Category = "UI")
     void SetOptionsMenuWidgetClass(TSubclassOf<UOptionsMenuWidget> WidgetClass) { OptionsMenuWidgetClass = WidgetClass; }

     UFUNCTION(BlueprintCallable, Category = "UI")
     void SetCharactersMenuWidgetClass(TSubclassOf<UCharactersMenuWidget> WidgetClass) { CharactersMenuWidgetClass = WidgetClass; }

protected:
     // Widget class references, typically set via defaults or asset paths.
     UPROPERTY(EditDefaultsOnly, Category = "Config | UI")
     TSubclassOf<UMainMenuWidget> MainMenuWidgetClass;

     UPROPERTY(EditDefaultsOnly, Category = "Config | UI")
     TSubclassOf<UOptionsMenuWidget> OptionsMenuWidgetClass;

     UPROPERTY(EditDefaultsOnly, Category = "Config | UI")
     TSubclassOf<UCharactersMenuWidget> CharactersMenuWidgetClass;

     // Instance pointers for created menus.
     UPROPERTY()
     UMainMenuWidget* MainMenu = nullptr;

     UPROPERTY()
     UOptionsMenuWidget* OptionsMenu = nullptr;

     UPROPERTY()
     UCharactersMenuWidget* CharactersMenu = nullptr;
};
