#include "SMainMenuWidget.h"
#include "Widgets/Text/STextBlock.h"

void SMainMenuWidget::Construct(const FArguments& InArgs)
{
     ChildSlot
          [
               SNew(STextBlock)
                    .Text(FText::FromString("Main Menu"))
                    .Font(FSlateFontInfo(FPaths::ProjectContentDir() / TEXT("Fonts/Grenze-Bold"), 32)) //this probably doesn't work
          ];
}
