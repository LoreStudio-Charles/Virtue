#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateStyle.h"

class FCustomStyle
{
public:
     static void Initialize();
     static void Shutdown();
     static const ISlateStyle& Get();

private:
     static TSharedPtr<FSlateStyleSet> StyleInstance;
};
