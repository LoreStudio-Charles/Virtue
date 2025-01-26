#include "SMainMenuWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"

#define LOCTEXT_NAMESPACE "MainMenu"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SMainMenuWidget::Construct(const FArguments& InArgs)
{
     // Setting up the UI layout with a vertical box
     ChildSlot
          [
               SNew(SVerticalBox)
                    + SVerticalBox::Slot()
                    .HAlign(HAlign_Center)
                    .VAlign(VAlign_Center)
                    [
                         SNew(SButton)
                              .Text(LOCTEXT("StartGame", "Start Game"))
                              .OnClicked(this, &SMainMenuWidget::OnStartGameClicked)
                    ]
                    + SVerticalBox::Slot()
                    .HAlign(HAlign_Center)
                    .VAlign(VAlign_Center)
                    [
                         SNew(SButton)
                              .Text(LOCTEXT("Quit", "Quit"))
                              .OnClicked(this, &SMainMenuWidget::OnQuitClicked)
                    ]
          ];
}

// Function to handle Start Game button click
FReply SMainMenuWidget::OnStartGameClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("Start Game Clicked"));
     return FReply::Handled();
}

// Function to handle Quit button click
FReply SMainMenuWidget::OnQuitClicked()
{
     UE_LOG(LogTemp, Warning, TEXT("Quit Clicked"));
     return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef LOCTEXT_NAMESPACE
