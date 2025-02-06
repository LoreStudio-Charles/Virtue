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

     // Bind the `Head` parts button.
     if (PartsHeadButton)
     {
          PartsHeadButton->OnClicked.RemoveDynamic(this, &UCharactersMenuWidget::OnPartsHeadButtonClicked);
          PartsHeadButton->OnClicked.AddDynamic(this, &UCharactersMenuWidget::OnPartsHeadButtonClicked);
     }

     // Bind the `Torso` parts button.
     if (PartsTorsoButton)
     {
          PartsTorsoButton->OnClicked.RemoveDynamic(this, &UCharactersMenuWidget::OnPartsTorsoButtonClicked);
          PartsTorsoButton->OnClicked.AddDynamic(this, &UCharactersMenuWidget::OnPartsTorsoButtonClicked);
     }

     // Bind the `Back` button.
     if (BackButton)
     {
          BackButton->OnClicked.RemoveDynamic(this, &UCharactersMenuWidget::OnBackButtonClicked);
          BackButton->OnClicked.AddDynamic(this, &UCharactersMenuWidget::OnBackButtonClicked);
     }

     // Bind the `Create` button.
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

     if (PartsTorsoButtonText)
     {
          FText PartsTorso = UMessagesFunctionLibrary::GetPartsTorsoButtonText();
          PartsTorsoButtonText->SetText(PartsTorso);
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

void UCharactersMenuWidget::OnPartsTorsoButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("Torso button clicked"));
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