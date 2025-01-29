#include "VirtueHUD.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

AVirtueHUD::AVirtueHUD()
{
     static ConstructorHelpers::FClassFinder<UUserWidget> MenuBP(TEXT("/Game/UI_Menu/WBP_MainMenu.WBP_MainMenu_C"));
     if (MenuBP.Succeeded())
     {
          MainMenuClass = MenuBP.Class;
     }
}

void AVirtueHUD::BeginPlay()
{
     Super::BeginPlay();
     ShowMainMenu();
}

void AVirtueHUD::ShowMainMenu()
{
     if (MainMenuClass && !MainMenuWidget)
     {
          MainMenuWidget = CreateWidget<UUserWidget>(GetWorld(), MainMenuClass);
          if (MainMenuWidget)
          {
               MainMenuWidget->AddToViewport();

               APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
               if (PC)
               {
                    FInputModeUIOnly InputMode;
                    InputMode.SetWidgetToFocus(MainMenuWidget->TakeWidget());
                    PC->SetInputMode(InputMode);
                    PC->bShowMouseCursor = true;
               }
          }
     }
}
