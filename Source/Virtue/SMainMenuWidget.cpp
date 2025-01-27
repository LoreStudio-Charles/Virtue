#include "SMainMenuWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "Styling/SlateTypes.h"
#include "Styling/SlateStyle.h"
#include "CustomStyle.h"

#define LOCTEXT_NAMESPACE "MainMenu"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SMainMenuWidget::Construct(const FArguments& InArgs)
{
     UE_LOG(LogTemp, Warning, TEXT("SMainMenuWidget Construct"));
     // Retrieve custom style
     const FSlateFontInfo& ButtonFont = FCustomStyle::Get().GetFontStyle("MainMenu.ButtonFont");
     const FSlateBrush* BackgroundBrush = FCustomStyle::Get().GetBrush("MainMenu.Background");
     const FLinearColor& ButtonTextColor = FCustomStyle::Get().GetColor("MainMenu.ButtonTextColor");
     const FLinearColor& ButtonColor = FCustomStyle::Get().GetColor("MainMenu.ButtonColor");

     ChildSlot
          [
               SNew(SBorder)
                    .BorderImage(BackgroundBrush)  // Set the dark background here
                    .Padding(FMargin(10))  // Outer padding for the entire menu
                    [
                         SNew(SVerticalBox)

                              // Main Menu Text
                              + SVerticalBox::Slot()
                              .HAlign(HAlign_Center)
                              .VAlign(VAlign_Top)  // Align the text to the top
                              .Padding(FMargin(0, 5))  // Space below the title
                              [
                                   SNew(STextBlock)
                                        .Text(LOCTEXT("MainMenuText", "Virtue"))
                                        .Font(ButtonFont)
                                        .ColorAndOpacity(ButtonTextColor)
                              ]

                              // Spacer between the title and the buttons
                              + SVerticalBox::Slot()
                              .AutoHeight()
                              .VAlign(VAlign_Top)
                              .Padding(FMargin(0, 40))  // Add some space between the title and buttons

                              // Start Game Button
                              + SVerticalBox::Slot()
                              .HAlign(HAlign_Left)  // Align the button to the left
                              .VAlign(VAlign_Top)   // Align to the top
                              .AutoHeight()
                              .Padding(FMargin(50, 10))  // Padding to the left
                              [
                                   SNew(SBox)
                                        .WidthOverride(250)   // Set uniform width
                                        .HeightOverride(50)   // Set uniform height
                                        [
                                             SNew(SButton)
                                                  .Text(LOCTEXT("StartGame", "Start Game"))
                                                  .OnClicked(this, &SMainMenuWidget::OnStartGameClicked)
                                                  .ButtonColorAndOpacity(FCustomStyle::Get().GetColor("MainMenu.ButtonColor"))
                                                  .ContentPadding(FMargin(10, 5))  // Padding inside the button
                                                  .TextStyle(FCustomStyle::Get(), "MainMenu.ButtonText")
                                        ]
                              ]

                              // Quit Button
                              + SVerticalBox::Slot()
                              .HAlign(HAlign_Left)
                              .VAlign(VAlign_Top)
                              .AutoHeight()
                              .Padding(FMargin(50, 10))  // Add space between the buttons
                              [
                                   SNew(SBox)
                                        .WidthOverride(250)   // Set uniform width
                                        .HeightOverride(50)   // Set uniform height
                                        [
                                             SNew(SButton)
                                                  .Text(LOCTEXT("Quit", "Quit"))
                                                  .OnClicked(this, &SMainMenuWidget::OnQuitClicked)
                                                  .ButtonColorAndOpacity(FCustomStyle::Get().GetColor("MainMenu.ButtonColor"))
                                                  .ContentPadding(FMargin(10, 5))  // Padding inside the button
                                                  .TextStyle(FCustomStyle::Get(), "MainMenu.ButtonText")
                                        ]
                              ]

                              // Stretch the space after the buttons to push them up
                              + SVerticalBox::Slot()
                              .FillHeight(1.0f)  // Take the remaining space to push the buttons up
                              [
                                   SNew(SVerticalBox)
                              ]
                    ]
          ];
}


FReply SMainMenuWidget::OnStartGameClicked()
{
     if (OnStartGameClickedDelegate.IsBound())
     {
          OnStartGameClickedDelegate.Execute();
     }

     return FReply::Handled();
}

FReply SMainMenuWidget::OnQuitClicked()
{
     // Safely quit the application
     FPlatformMisc::RequestExit(true);  // Use true to ensure the editor quits

     return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef LOCTEXT_NAMESPACE
