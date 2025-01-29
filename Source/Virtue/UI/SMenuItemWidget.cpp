/*
#include "SMenuItemWidget.h"
#include "Widgets/Text/STextBlock.h"

void SMenuItemWidget::Construct(const FArguments& InArgs)
{
     MenuText = InArgs._MenuText;

     ChildSlot
          [
               SAssignNew(TextBlock, STextBlock)
                    .Text(MenuText)
                    .Font(FSlateFontInfo(FPaths::ProjectContentDir() / TEXT("UI/Fonts/MyFont.ttf"), 24))
                    .Justification(ETextJustify::Center)
          ];
}

void SMenuItemWidget::SetText(const FText& NewText)
{
     MenuText.Set(NewText);
     if (TextBlock.IsValid())
     {
          TextBlock->SetText(NewText);
     }
}
*/