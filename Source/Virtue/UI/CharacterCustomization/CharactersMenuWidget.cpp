#include "CharactersMenuWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/CanvasPanel.h"
#include "Components/VerticalBox.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Virtue/UI/Managers/UIManager.h"
#include "Virtue/UI/Base/MessagesFunctionLibrary.h"
#include "Virtue/UI/Base/UIBindingHelpers.h"
#include "Logging/LogMacros.h"
#include "Virtue/Data/VirtueEnums.h"

//////////////////////////////////////////////////////////////////////////
// Helper Methods

UCanvasPanel* UCharactersMenuWidget::GetRootCanvasPanel() const
{
     return Cast<UCanvasPanel>(GetRootWidget());
}

//////////////////////////////////////////////////////////////////////////
// NativeConstruct

void UCharactersMenuWidget::NativeConstruct()
{
     Super::NativeConstruct();
     UE_LOG(LogTemp, Warning, TEXT("UCharactersMenuWidget::NativeConstruct() called"));

     // Set a default active screen.
     SetActiveScreen(ECharacterMenuScreen::Landing);
     UE_LOG(LogTemp, Warning, TEXT("UCharactersMenuWidget::NativeConstruct() - Default screen set to Select"));

     // Bind buttons for the Transition-to-Character Screen.
     BIND_BUTTON(UCharactersMenuWidget, CTScreenCreateButton, OnCTScreenCreateButtonClicked);
     BIND_BUTTON(UCharactersMenuWidget, CTScreenBackButton, OnCTScreenBackButtonClicked);
     BIND_BUTTON(UCharactersMenuWidget, CTScreenSelectCharacterButton, OnCTScreenSelectCharacterButtonClicked);
     BIND_BUTTON(UCharactersMenuWidget, CTScreenDeleteCharacterButton, OnCTScreenDeleteCharacterButtonClicked);

     // Bind buttons for the Character Creation Screen.
     BIND_BUTTON(UCharactersMenuWidget, PartsHeadButton, OnPartsHeadButtonClicked);
     BIND_BUTTON(UCharactersMenuWidget, PartsHairButton, OnPartsHairButtonClicked);
     BIND_BUTTON(UCharactersMenuWidget, PartsTorsoButton, OnPartsTorsoButtonClicked);
     BIND_BUTTON(UCharactersMenuWidget, PartsArmsButton, OnPartsArmsButtonClicked);
     BIND_BUTTON(UCharactersMenuWidget, PartsLegsButton, OnPartsLegsButtonClicked);
     BIND_BUTTON(UCharactersMenuWidget, PartsAccessoriesButton, OnPartsAccessoriesButtonClicked);
     BIND_BUTTON(UCharactersMenuWidget, BackButton, OnBackButtonClicked);
     BIND_BUTTON(UCharactersMenuWidget, CreateButton, OnCreateButtonClicked);

     // Set localized text for Transition-to-Character Screen UI elements.
     UIHelpers::SetLocalizedText(CTScreenCreateButtonText, UMessagesFunctionLibrary::GetCTScreenCreateButtonText());
     UIHelpers::SetLocalizedText(CTScreenBackButtonText, UMessagesFunctionLibrary::GetCTScreenBackButtonText());
     UIHelpers::SetLocalizedText(CTScreenSelectCharacterButtonText, UMessagesFunctionLibrary::GetCTScreenSelectCharacterButtonText());
     UIHelpers::SetLocalizedText(CTScreenDeleteCharacterButtonText, UMessagesFunctionLibrary::GetCTScreenDeleteCharacterButtonText());

     // Set localized text for Character Creation Screen UI elements.
     UIHelpers::SetLocalizedText(PartsHeadButtonText, UMessagesFunctionLibrary::GetPartsHeadButtonText());
     UIHelpers::SetLocalizedText(PartsHairButtonText, UMessagesFunctionLibrary::GetPartsHairButtonText());
     UIHelpers::SetLocalizedText(PartsTorsoButtonText, UMessagesFunctionLibrary::GetPartsTorsoButtonText());
     UIHelpers::SetLocalizedText(PartsArmsButtonText, UMessagesFunctionLibrary::GetPartsArmsButtonText());
     UIHelpers::SetLocalizedText(PartsLegsButtonText, UMessagesFunctionLibrary::GetPartsLegsButtonText());
     UIHelpers::SetLocalizedText(PartsAccessoriesButtonText, UMessagesFunctionLibrary::GetPartsAccessoriesButtonText());
     UIHelpers::SetLocalizedText(BackButtonText, UMessagesFunctionLibrary::GetBackButtonText());
     UIHelpers::SetLocalizedText(CreateButtonText, UMessagesFunctionLibrary::GetCreateButtonText());
}

//////////////////////////////////////////////////////////////////////////
// Event Handlers - Transition-to-Character Screen

void UCharactersMenuWidget::OnCTScreenCreateButtonClicked()
{
     if (GetRootCanvasPanel())
     {
          SetActiveScreen(ECharacterMenuScreen::Create);
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("OnCTScreenCreateButtonClicked: Root widget is not a CanvasPanel!"));
     }
}

void UCharactersMenuWidget::OnCTScreenDeleteCharacterButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("OnCTScreenDeleteCharacterButtonClicked: Delete Character button pressed"));
}

void UCharactersMenuWidget::OnCTScreenSelectCharacterButtonClicked()
{
     if (GetRootCanvasPanel())
     {
          SetActiveScreen(ECharacterMenuScreen::Select);
     }
     else
     {
          UE_LOG(LogTemp, Error, TEXT("OnCTScreenSelectCharacterButtonClicked: Root widget is not a CanvasPanel!"));
     }
}

void UCharactersMenuWidget::OnCTScreenBackButtonClicked()
{
     if (UUIManager* UIManager = GetGameInstance()->GetSubsystem<UUIManager>())
     {
          UIManager->CloseMenu(this);
          UIManager->ShowMainMenu();
          UE_LOG(LogTemp, Warning, TEXT("OnCTScreenBackButtonClicked: Characters Menu closed, Main Menu displayed."));
     }
}

//////////////////////////////////////////////////////////////////////////
// Event Handlers - Character Creation Screen

void UCharactersMenuWidget::OnPartsHeadButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("OnPartsHeadButtonClicked: Head button clicked"));
     OnPartsButtonClicked();
}

void UCharactersMenuWidget::OnPartsHairButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("OnPartsHairButtonClicked: Hair button clicked"));
     OnPartsButtonClicked();
}

void UCharactersMenuWidget::OnPartsTorsoButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("OnPartsTorsoButtonClicked: Torso button clicked"));
     OnPartsButtonClicked();
}

void UCharactersMenuWidget::OnPartsArmsButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("OnPartsArmsButtonClicked: Arms button clicked"));
     OnPartsButtonClicked();
}

void UCharactersMenuWidget::OnPartsLegsButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("OnPartsLegsButtonClicked: Legs button clicked"));
     OnPartsButtonClicked();
}

void UCharactersMenuWidget::OnPartsAccessoriesButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("OnPartsAccessoriesButtonClicked: Accessories button clicked"));
     OnPartsButtonClicked();
}

void UCharactersMenuWidget::OnBackButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("OnBackButtonClicked: Back button clicked"));
     if (UUIManager* UIManager = GetGameInstance()->GetSubsystem<UUIManager>())
     {
          if (!bInPartsMenu)
          {
               UIManager->CloseMenu(this);
               UIManager->ShowMainMenu();
               UE_LOG(LogTemp, Warning, TEXT("OnBackButtonClicked: Options Menu closed, Main Menu displayed."));
          }
          else
          {
               if (PartsVerticalBox)
               {
                    PartsVerticalBox->SetVisibility(ESlateVisibility::Visible);
               }
               bInPartsMenu = false;
          }
     }
}

void UCharactersMenuWidget::OnPartsButtonClicked()
{
     if (PartsVerticalBox)
     {
          PartsVerticalBox->SetVisibility(ESlateVisibility::Collapsed);
     }
     bInPartsMenu = true;
}

void UCharactersMenuWidget::OnCreateButtonClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("OnCreateButtonClicked: Simulate creating character"));
}

//////////////////////////////////////////////////////////////////////////
// SetActiveScreen

void UCharactersMenuWidget::SetActiveScreen(ECharacterMenuScreen Screen)
{
     // Update visibility for the Landing screen.
     if (LandingCanvas)
     {
         LandingCanvas->SetVisibility(Screen == ECharacterMenuScreen::Landing ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
     }

     // Update visibility for the Create screen.
     if (CreateCanvas)
     {
          CreateCanvas->SetVisibility(Screen == ECharacterMenuScreen::Create ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
     }
     else
     {
          UE_LOG(LogTemp, Warning, TEXT("SetActiveScreen: CreateCanvas is not bound."));
     }

     // Update visibility for the Delete screen.
     if (DeleteCanvas)
     {
          DeleteCanvas->SetVisibility(Screen == ECharacterMenuScreen::Delete ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
     }
     else
     {
          UE_LOG(LogTemp, Warning, TEXT("SetActiveScreen: DeleteCanvas is not bound."));
     }

     // Update visibility for the Select screen.
     if (SelectCanvas)
     {
          SelectCanvas->SetVisibility(Screen == ECharacterMenuScreen::Select ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
     }
     else
     {
          UE_LOG(LogTemp, Warning, TEXT("SetActiveScreen: SelectCanvas is not bound."));
     }

     UE_LOG(LogTemp, Warning, TEXT("SetActiveScreen: Active screen set to %d"), static_cast<uint8>(Screen));
}
