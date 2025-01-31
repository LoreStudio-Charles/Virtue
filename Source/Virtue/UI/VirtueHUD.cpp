#include "VirtueHUD.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

AVirtueHUD::AVirtueHUD()
{
     static ConstructorHelpers::FClassFinder<UUserWidget> MenuBP(TEXT("/Game/UI_Menu/BP_BaseMenu.BP_BaseMenu_C"));

 
     if (MenuBP.Succeeded())
     {
          BaseMenuClass = MenuBP.Class;
     }
}

void AVirtueHUD::BeginPlay()
{
     Super::BeginPlay();
     UE_LOG(LogTemp, Warning, TEXT("AVirtueHUD::BeginPlay() called"));

     FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(this, false);
     CurrentLevelName.RemoveFromStart(TEXT("UEDPIE_0_"));  // This is funny, could not figure out why 'MainMenuLevel' would not work.  Turns out when you play in editor mode, it throws UEDPIE_O prefix to indicate that
     UE_LOG(LogTemp, Warning, TEXT("Level Name %s"), *CurrentLevelName); // you are running the U(nreal) E(ngine) D(eveloper) P(lay) I(n) E(ditor) on instance 0, hence, UEDPIE_0_  about two hours down the drain.

     bool isConnected = false;
     if (CurrentLevelName == "MainMenuLevel")
     {
          ShowBaseMenu();
     }
     
}

void AVirtueHUD::ShowBaseMenu()
{
     if (!BaseMenuClass)
     {
          UE_LOG(LogTemp, Error, TEXT("BaseMenuClass is NULL! Check asset path."));
          return;
     }

     if (!BaseMenuWidget)
     {
          UE_LOG(LogTemp, Warning, TEXT("Creating BaseMenuWidget"));
          BaseMenuWidget = CreateWidget<UUserWidget>(GetWorld(), BaseMenuClass);

          if (BaseMenuWidget)
          {
               BaseMenuWidget->AddToViewport();
          }
          else
          {
               UE_LOG(LogTemp, Error, TEXT("Failed to create BaseMenuWidget"));
          }
     }
}
