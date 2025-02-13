#include "MenuItemWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/Border.h"
#include "MessagesFunctionLibrary.h"

void UMenuItemWidget::NativeConstruct()
{
     Super::NativeConstruct();

     // Set up button click and hover events
     if (MainButton)
     {
          MainButton->OnHovered.AddDynamic(this, &UMenuItemWidget::OnHovered);
          MainButton->OnUnhovered.AddDynamic(this, &UMenuItemWidget::OnUnhovered);
          MainButton->OnClicked.AddDynamic(this, &UMenuItemWidget::OnClicked);
     }
}

void UMenuItemWidget::SetMenuItemKey(const FName& NewKey)
{
     MenuItemKey = NewKey;
     UpdateTextFromUIStrings();
}

void UMenuItemWidget::SetMenuText(const FText& NewText)
{
     if (ItemText)
     {
          ItemText->SetText(NewText);
     }
}

void UMenuItemWidget::UpdateTextFromUIStrings()
{
     if (ItemText && !MenuItemKey.IsNone())
     {
          //FText LocalizedText = UMessagesFunctionLibrary::GetUIString(MenuItemKey);
          //ItemText->SetText(LocalizedText);
     }
}

void UMenuItemWidget::OnHovered()
{

}

void UMenuItemWidget::OnUnhovered()
{

}

void UMenuItemWidget::OnClicked()
{
     if (ItemText)
     {
          ItemText->SetRenderScale(FVector2D(0.9f, 0.9f)); // Shrink effect on click
     }
}
