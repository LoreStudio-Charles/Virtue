#include "CustomStyle.h"
#include "Styling/SlateStyle.h"
#include "Styling/SlateTypes.h"
#include "Slate/SlateGameResources.h"
#include "Styling/SlateStyleRegistry.h"

// Define the unique style set name
TSharedPtr<FSlateStyleSet> FCustomStyle::StyleInstance = nullptr;

void FCustomStyle::Initialize()
{
     if (!StyleInstance.IsValid())
     {
          StyleInstance = MakeShareable(new FSlateStyleSet("CustomStyle"));

          // Register a dark background brush
          StyleInstance->Set("MainMenu.Background", new FSlateColorBrush(FLinearColor::Black));

          // Register other styles (fonts, buttons, etc.)
          StyleInstance->Set("MainMenu.ButtonFont", FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), 24));
          StyleInstance->Set("MainMenu.ButtonColor", FLinearColor::Red);
          StyleInstance->Set("MainMenu.ButtonText", FTextBlockStyle()
               .SetFont(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), 24))
               .SetColorAndOpacity(FSlateColor(FLinearColor::White))
          );

          FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
     }
}

void FCustomStyle::Shutdown()
{
     if (StyleInstance.IsValid())
     {
          FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
          ensure(StyleInstance.IsUnique());
          StyleInstance.Reset();
     }
}

const ISlateStyle& FCustomStyle::Get()
{
     return *StyleInstance;
}
