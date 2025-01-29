/*#include "UMenuItemWidget.h"

TSharedRef<SWidget> UMenuItemWidget::RebuildWidget()
{
     SlateWidget = SNew(SMenuItemWidget).MenuText(MenuText);
     return SlateWidget.ToSharedRef();
}

void UMenuItemWidget::SetText(const FText& NewText)
{
     MenuText = NewText;
     if (SlateWidget.IsValid())
     {
          SlateWidget->SetText(NewText);
     }
}
*/

#include "UMenuItemWidget.h"
#include "Components/Button.h"
#include "Materials/MaterialInstanceDynamic.h"

void UMenuItemWidget::NativeConstruct()
{
     Super::NativeConstruct();

     // Ensure the button is valid before binding
     if (DynamicButton)
     {
          DynamicButton->OnHovered.AddDynamic(this, &UMenuItemWidget::OnHovered);
          DynamicButton->OnUnhovered.AddDynamic(this, &UMenuItemWidget::OnUnhovered);
     }

     // Create a dynamic material instance (assuming your material is set on the widget)
     UMaterialInterface* Material = LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/Materials/MI_GlowEffect"));
     if (Material)
     {
          DynamicMaterial = UMaterialInstanceDynamic::Create(Material, this);
     }
}

void UMenuItemWidget::OnHovered()
{
     SetMaterialOpacity(1.0f);
     SetMaterialGlow(50.0f);
     UE_LOG(LogTemp, Log, TEXT("Button Hovered!"));
}

void UMenuItemWidget::OnUnhovered()
{
     SetMaterialOpacity(0.0f);
     SetMaterialGlow(0.0f);
     UE_LOG(LogTemp, Log, TEXT("Button Unhovered!"));
}

void UMenuItemWidget::SetMaterialOpacity(float Opacity)
{
     if (DynamicMaterial)
     {
          DynamicMaterial->SetScalarParameterValue(TEXT("Opacity"), Opacity);
     }
}

void UMenuItemWidget::SetMaterialGlow(float Glow)
{
     if (DynamicMaterial)
     {
          DynamicMaterial->SetScalarParameterValue(TEXT("GlowIntensity"), Glow);
     }
}
