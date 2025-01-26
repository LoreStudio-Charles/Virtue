#include "SMainMenu.h"
#include "SlateOptMacros.h"
#include "Widgets/Text/STextBlock.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SMainMenu::Construct(const FArguments& InArgs)
{
     ChildSlot
          [
               SNew(STextBlock)
                    .Text(FText::FromString(TEXT("Main Menu")))
          ];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
