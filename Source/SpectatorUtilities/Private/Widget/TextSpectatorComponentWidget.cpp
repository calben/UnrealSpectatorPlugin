#include "Widget/TextSpectatorComponentWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/PanelWidget.h"
#include "Components/StatefulButton.h"
#include "Components/TextBlock.h"
#include "GameFramework/SpectatableComponent.h"
#include "GameFramework/SpectatorComponent.h"

void UTextSpectatorComponentWidget::Reset()
{
    ItemsPanel->ClearChildren();
    if (ensureAlways(Component != nullptr) && ensureAlways(ItemWidgetClass != nullptr))
    {
        if (Component->DefaultViewTarget != nullptr)
        {
            auto Widget = WidgetTree->ConstructWidget<UStatefulButton>(ItemWidgetClass, FName("Default"));
            if (ensureAlways(Widget != nullptr))
            {
                Widget->ButtonTextBlock->SetText(FText::FromString("Default"));
                ItemsPanel->AddChild(Widget);
                Widget->OnPressed.BindLambda([=]() { Component->SetViewTarget(Component->DefaultViewTarget); });
            }
        }
        for (const auto Spectatable : Component->SpectatableComponents)
        {
            auto Widget = WidgetTree->ConstructWidget<UStatefulButton>(ItemWidgetClass, FName(Spectatable->FriendlyName));
            if (ensureAlways(Widget != nullptr))
            {
                Widget->ButtonTextBlock->SetText(FText::FromString(Spectatable->FriendlyName));
                ItemsPanel->AddChild(Widget);
                Widget->OnPressed.BindLambda([=]() { Component->SetViewTarget(Spectatable->GetOwner()); });
            }
        }
    }
}
