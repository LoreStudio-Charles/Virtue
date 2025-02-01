#include "VirtueHUD.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"

AVirtueHUD::AVirtueHUD()
{
     // Assign MainMenuWidgetClass if not set in the Editor
     static ConstructorHelpers::FClassFinder<UUserWidget> MenuBP(TEXT("/Game/UI_Menu/WBP_MainMenuWidget"));
     if (MenuBP.Succeeded())
     {
          MainMenuWidgetClass = MenuBP.Class;
     }
}

void AVirtueHUD::BeginPlay()
{
     Super::BeginPlay();

     // Check if we're on the Main Menu Level
     FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(this, false);
     CurrentLevelName.RemoveFromStart(TEXT("UEDPIE_0_")); // Clean up the editor-level prefix

     if (CurrentLevelName == "MainMenuLevel")
     {
          ShowMainMenu();
     }
}

void AVirtueHUD::ShowMainMenu()
{
     if (MainMenuWidgetClass)
     {
          // Create the widget and add it to the viewport
          MainMenuWidget = CreateWidget<UMainMenuWidget>(GetWorld(), MainMenuWidgetClass);
          if (MainMenuWidget)
          {
               MainMenuWidget->AddToViewport();
          }
     }
     else
     {
          UE_LOG(LogTemp, Warning, TEXT("MainMenuWidgetClass is not set!"));
     }
}
