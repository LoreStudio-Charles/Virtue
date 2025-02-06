#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.h"
#include "OptionsMenuWidget.h"
#include "D:\Virtue\Source\Virtue\UI\CharacterCreation\CharactersMenuWidget.h"
#include "UIManager.generated.h"

/**
 * UUIManager is a GameInstanceSubsystem that manages UI menus.
 * It creates, shows, and closes the Main Menu and Options Menu.
 */
UCLASS(Blueprintable)
class VIRTUE_API UUIManager : public UGameInstanceSubsystem
{
     GENERATED_BODY()

public:
     // Override the Initialize method (called when the subsystem is created).
     virtual void Initialize(FSubsystemCollectionBase& Collection) override;

     /** Opens a menu given its widget class and adds it to the viewport. */
     UFUNCTION(BlueprintCallable, Category = "UI")
     void OpenMenu(TSubclassOf<UUserWidget> MenuClass);

     /** Closes a specific menu widget (removes it from the viewport). */
     UFUNCTION(BlueprintCallable, Category = "UI")
     void CloseMenu(UUserWidget* MenuInstance);

     /** Closes all menus currently on screen. */
     UFUNCTION(BlueprintCallable, Category = "UI")
     void CloseAllMenus();

     /** Shows the Main Menu.
      *  If the Options Menu is open, it is closed.
      */
     UFUNCTION(BlueprintCallable, Category = "UI")
     void ShowMainMenu();

     /** Shows the Options Menu.
      *  If the Main Menu is open, it is hidden.
      * TODO: Determine performance gain/loss on hiding Main Menu or removing it and reloading it
      */
     UFUNCTION(BlueprintCallable, Category = "UI")
     void ShowOptionsMenu();

     UFUNCTION(BlueprintCallable, Category = "UI")
     void ShowCharactersMenu();

     /** Setter for the Main Menu widget class. */
     UFUNCTION(BlueprintCallable, Category = "UI")
     void SetMainMenuWidgetClass(TSubclassOf<UMainMenuWidget> WidgetClass)
     {
          MainMenuWidgetClass = WidgetClass;
     }

     /** Setter for the Options Menu widget class. */
     UFUNCTION(BlueprintCallable, Category = "UI")
     void SetOptionsMenuWidgetClass(TSubclassOf<UOptionsMenuWidget> WidgetClass)
     {
          OptionsMenuWidgetClass = WidgetClass;
     }

     /** Setter for the Characters Menu widget class. */
     UFUNCTION(BlueprintCallable, Category = "UI")
     void SetCharactersMenuWidgetClass(TSubclassOf<UCharactersMenuWidget> WidgetClass)
     {
          CharactersMenuWidgetClass = WidgetClass;
     }

     /** Getter for the Main Menu widget class. */
     UFUNCTION(BlueprintCallable, Category = "UI")
     TSubclassOf<UMainMenuWidget> GetMainMenuWidgetClass() const { return MainMenuWidgetClass; }

     /** Getter for the Options Menu widget class. */
     UFUNCTION(BlueprintCallable, Category = "UI")
     TSubclassOf<UOptionsMenuWidget> GetOptionsMenuWidgetClass() const { return OptionsMenuWidgetClass; }

     /** Getter for the Characters Menu widget class. */
     UFUNCTION(BlueprintCallable, Category = "UI")
     TSubclassOf<UCharactersMenuWidget> GetCharactersMenuWidgetClass() const { return CharactersMenuWidgetClass; }

private:
     // Editable properties for the widget classes.
     // These can be set in a Blueprint subclass of UUIManager or via defaults in code.
     UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Config | UI", meta = (AllowPrivateAccess = "true"))
     TSubclassOf<UMainMenuWidget> MainMenuWidgetClass;

     UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Config | UI", meta = (AllowPrivateAccess = "true"))
     TSubclassOf<UOptionsMenuWidget> OptionsMenuWidgetClass;

     UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Config | UI", meta = (AllowPrivateAccess = "true"))
     TSubclassOf<UCharactersMenuWidget> CharactersMenuWidgetClass;

     // Instance pointers for the created menus.
     UPROPERTY()
     UMainMenuWidget* MainMenu = nullptr;

     UPROPERTY()
     UOptionsMenuWidget* OptionsMenu = nullptr;

     UPROPERTY()
     UCharactersMenuWidget* CharactersMenu = nullptr;
};
