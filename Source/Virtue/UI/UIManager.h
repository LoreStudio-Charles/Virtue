#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MainMenuWidget.h"
#include "OptionsMenuWidget.h"
#include "UIManager.generated.h"

UCLASS(Blueprintable)
class VIRTUE_API UUIManager : public UGameInstanceSubsystem
{
     GENERATED_BODY()

public:
     void CloseAllMenus();

     // Shows the Main Menu widget.
     UFUNCTION(BlueprintCallable, Category = "UI")
     void ShowMainMenu();

     // Shows the Options Menu widget.
     UFUNCTION(BlueprintCallable, Category = "UI")
     void ShowOptionsMenu();

     // Setter functions to assign widget classes.
     UFUNCTION(BlueprintCallable, Category = "UI")
     void SetMainMenuWidgetClass(TSubclassOf<UMainMenuWidget> WidgetClass)
     {
          MainMenuWidgetClass = WidgetClass;
     }

     UFUNCTION(BlueprintCallable, Category = "UI")
     void SetOptionsMenuWidgetClass(TSubclassOf<UOptionsMenuWidget> WidgetClass)
     {
          OptionsMenuWidgetClass = WidgetClass;
     }

     // Optional getters.
     UFUNCTION(BlueprintCallable, Category = "UI")
     TSubclassOf<UMainMenuWidget> GetMainMenuWidgetClass() const { return MainMenuWidgetClass; }

     UFUNCTION(BlueprintCallable, Category = "UI")
     TSubclassOf<UOptionsMenuWidget> GetOptionsMenuWidgetClass() const { return OptionsMenuWidgetClass; }

     // Override Initialize() for subsystem initialization.
     virtual void Initialize(FSubsystemCollectionBase& Collection) override;

private:
     // Editable properties so you can assign these in BP_UIManager or via code.
     UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", meta = (AllowPrivateAccess = "true"))
     TSubclassOf<UMainMenuWidget> MainMenuWidgetClass;

     UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", meta = (AllowPrivateAccess = "true"))
     TSubclassOf<UOptionsMenuWidget> OptionsMenuWidgetClass;

     // Instance pointers.
     UPROPERTY()
     UMainMenuWidget* MainMenu;

     UPROPERTY()
     UOptionsMenuWidget* OptionsMenu;
};
