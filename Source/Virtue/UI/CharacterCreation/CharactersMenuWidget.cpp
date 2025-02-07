#include "CharactersMenuWidget.h"
#include "Virtue/UI/OptionsMenuWidget.h"
#include "Components/Button.h"
#include "Logging/LogMacros.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Virtue/UI/UIManager.h"
#include <Virtue/UI/MessagesFunctionLibrary.h>

// NativeConstruct is called when the widget is constructed.
void UCharactersMenuWidget::NativeConstruct()
{
     Super::NativeConstruct();
     UE_LOG(LogTemp, Warning, TEXT("UCharactersMenuWidget::NativeConstruct() called"));

     // Bind the buttons.
     if (PartsHeadButton)
     {
          PartsHeadButton->OnClicked.RemoveDynamic(this, &UCharactersMenuWidget::OnPartsHeadButtonClicked);
          PartsHeadButton->OnClicked.AddDynamic(this, &UCharactersMenuWidget::OnPartsHeadButtonClicked);
     }

     if (PartsHairButton)
     {
          PartsHairButton->OnClicked.RemoveDynamic(this, &UCharactersMenuWidget::OnPartsHairButtonClicked);
          PartsHairButton->OnClicked.AddDynamic(this, &UCharactersMenuWidget::OnPartsHairButtonClicked);
     }

     if (PartsTorsoButton)
     {
          PartsTorsoButton->OnClicked.RemoveDynamic(this, &UCharactersMenuWidget::OnPartsTorsoButtonClicked);
          PartsTorsoButton->OnClicked.AddDynamic(this, &UCharactersMenuWidget::OnPartsTorsoButtonClicked);
     }

     if (PartsArmsButton)
     {
          PartsArmsButton->OnClicked.RemoveDynamic(this, &UCharactersMenuWidget::OnPartsArmsButtonClicked);
          PartsArmsButton->OnClicked.AddDynamic(this, &UCharactersMenuWidget::OnPartsArmsButtonClicked);
     }

     if (PartsLegsButton)
     {
          PartsLegsButton->OnClicked.RemoveDynamic(this, &UCharactersMenuWidget::OnPartsLegsButtonClicked);
          PartsLegsButton->OnClicked.AddDynamic(this, &UCharactersMenuWidget::OnPartsLegsButtonClicked);
     }

     if (PartsAccessoriesButton)
     {
          PartsAccessoriesButton->OnClicked.RemoveDynamic(this, &UCharactersMenuWidget::OnPartsAccessoriesButtonClicked);
          PartsAccessoriesButton->OnClicked.AddDynamic(this, &UCharactersMenuWidget::OnPartsAccessoriesButtonClicked);
     }

     if (BackButton)
     {
          BackButton->OnClicked.RemoveDynamic(this, &UCharactersMenuWidget::OnBackButtonClicked);
          BackButton->OnClicked.AddDynamic(this, &UCharactersMenuWidget::OnBackButtonClicked);
     }

     if (CreateButton)
     {
          CreateButton->OnClicked.RemoveDynamic(this, &UCharactersMenuWidget::OnCreateButtonClicked);
          CreateButton->OnClicked.AddDynamic(this, &UCharactersMenuWidget::OnCreateButtonClicked);
     }

     // Set localized text for UI elements if needed.
     if (PartsHeadButtonText)
     {
          FText PartsHead = UMessagesFunctionLibrary::GetPartsHeadButtonText();
          PartsHeadButtonText->SetText(PartsHead);
     }

     if (PartsHairButtonText)
     {
          FText PartsHair = UMessagesFunctionLibrary::GetPartsHairButtonText();
          PartsHairButtonText->SetText(PartsHair);
     }

     if (PartsTorsoButtonText)
     {
          FText PartsTorso = UMessagesFunctionLibrary::GetPartsTorsoButtonText();
          PartsTorsoButtonText->SetText(PartsTorso);
     }
     
     if (PartsArmsButtonText)
     {
          FText PartsArms = UMessagesFunctionLibrary::GetPartsArmsButtonText();
          PartsArmsButtonText->SetText(PartsArms);
     }

     if (PartsLegsButtonText)
     {
          FText PartsLegs = UMessagesFunctionLibrary::GetPartsLegsButtonText();
          PartsLegsButtonText->SetText(PartsLegs);
     }

     if (PartsAccessoriesButtonText)
     {
          FText PartsAccessories = UMessagesFunctionLibrary::GetPartsAccessoriesButtonText();
          PartsAccessoriesButtonText->SetText(PartsAccessories);
     }

     if (BackButtonText)
     {
          FText BackButtonT = UMessagesFunctionLibrary::GetBackButtonText();
          BackButtonText->SetText(BackButtonT);
     }

     if (CreateButtonText)
     {
          FText CreateButtonT = UMessagesFunctionLibrary::GetCreateButtonText();
          CreateButtonText->SetText(CreateButtonT);
     }
}

void UCharactersMenuWidget::OnPartsHeadButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("Head button clicked"));
     // Implement logic to update your character list here.
     OnPartsButtonClicked();
}

void UCharactersMenuWidget::OnPartsHairButtonClicked(){
     UE_LOG(LogTemp, Warning, TEXT("Hair button clicked"));
     // Implement logic to update your character list here.
     OnPartsButtonClicked();
}

void UCharactersMenuWidget::OnPartsTorsoButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("Torso button clicked"));
     // Implement logic to update your character list here.
     OnPartsButtonClicked();
}

void UCharactersMenuWidget::OnPartsArmsButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("Arms button clicked"));
     // Implement logic to update your character list here.
     OnPartsButtonClicked();
}

void UCharactersMenuWidget::OnPartsLegsButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("Legs button clicked"));
     // Implement logic to update your character list here.
     OnPartsButtonClicked();
}

void UCharactersMenuWidget::OnPartsAccessoriesButtonClicked(){
     UE_LOG(LogTemp, Warning, TEXT("Accessories button clicked"));
     // Implement logic to update your character list here.
     OnPartsButtonClicked();
}

void UCharactersMenuWidget::OnBackButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("Back button clicked"));
     // Implement logic to update your character list here.
     if (UUIManager* UIManager = GetGameInstance()->GetSubsystem<UUIManager>())
     {
          if (!bInPartsMenu)
          {
               // Close this Options Menu using UIManager's helper function.
               UIManager->CloseMenu(this);
               // Show the Main Menu.
               UIManager->ShowMainMenu();
               UE_LOG(LogTemp, Warning, TEXT("OptionsMenuWidget: Options Menu closed, Main Menu displayed."));
          }
          else
          {
               PartsVerticalBox->SetVisibility(ESlateVisibility::Visible);
               bInPartsMenu = false;
          }
     }
}

void UCharactersMenuWidget::OnPartsButtonClicked()
{
     PartsVerticalBox->SetVisibility(ESlateVisibility::Collapsed);
     bInPartsMenu = true;
}

void UCharactersMenuWidget::OnCreateButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("Simulate creating character"));
}