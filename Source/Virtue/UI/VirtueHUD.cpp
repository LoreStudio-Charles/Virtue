#include "VirtueHUD.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "D:\Virtue\Source\Virtue\MenuSystem\MenuDataStructs.h" // Fix this Greg
#include "Engine/DataTable.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h" // and this?
#include <stdio.h>

// Declare pointers for the data tables
UDataTable* MenuDataTable;
UDataTable* MenuItemDataTable;


AVirtueHUD::AVirtueHUD()
{
     // Loading the MenuDataTable
     static ConstructorHelpers::FObjectFinder<UDataTable> MenuTableFinder(TEXT("/Game/Data/DT_Menus.DT_Menus"));
     if (MenuTableFinder.Succeeded())
     {
          MenuDataTable = MenuTableFinder.Object;
     }

     // Loadinkg the MenuItemDataTable
     static ConstructorHelpers::FObjectFinder<UDataTable> MenuItemTableFinder(TEXT("/Game/Data/DT_MenuItems.DT_MenuItems"));
     if (MenuItemTableFinder.Succeeded())
     {
          MenuItemDataTable = MenuItemTableFinder.Object;
     }

     // Loading BP_BaseMenu and BP_MenuItemWidget to class variable MenuBP
     static ConstructorHelpers::FClassFinder<UUserWidget> MenuBP(TEXT("/Game/UI_Menu/BP_BaseMenu.BP_BaseMenu_C"));
     static ConstructorHelpers::FClassFinder<UUserWidget> MenuItemBP(TEXT("/Game/UI_Menu/WBP_MainMenuItemWidget.WBP_MainMenuItemWidget_C"));

     // Assigning classes to variables BaseMenuClass & MenuItemClass
     if (MenuBP.Succeeded() && MenuItemBP.Succeeded())
     {
          BaseMenuClass = MenuBP.Class;
          MenuItemClass = MenuItemBP.Class;
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
     if (MenuDataTable)
     {
          //FMenuData* MenuData - declares a pointer to a FMenuData struct.  FindRow<T> returns a pointer to the row data if found, or nullptr if the row DNE.
          FMenuData* MenuData = MenuDataTable->FindRow<FMenuData>(FName("Main"), TEXT("BeginPlay"));
          UE_LOG(LogTemp, Warning, TEXT("Menu Name: %s"), *MenuData->MenuName.ToString());
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("Row with MenuID 'Main' not found"));
     }
     // Check if the MenuItemDataTable is loaded
     if (MenuItemDataTable)
     {
          // Example: Access a row for a specific button  ******* YOU LEFT OFF RIGHT HERE LAST NIGHT *******
          FMenuItemData* MenuItemData = MenuItemDataTable->FindRow<FMenuItemData>(FName("MainMenu_StartGame"), TEXT("BeginPlay"));
          if (MenuItemData)
          {
               // Access data from the found row
               UE_LOG(LogTemp, Warning, TEXT("Button Name: %s"), *MenuItemData->ButtonName.ToString());
               UE_LOG(LogTemp, Warning, TEXT("Action Type: %s"), *MenuItemData->ActionType.ToString());
          }
          else
          {
               UE_LOG(LogTemp, Error, TEXT("Row with ButtonName 'StartButton' not found"));
          }
     }

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
