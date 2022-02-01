#include "Widget/ImageSpectatorComponentWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Image.h"
#include "Components/PanelWidget.h"
#include "Components/StatefulImageButton.h"
#include "GameFramework/SpectatableComponent.h"
#include "GameFramework/SpectatorComponent.h"

void UImageSpectatorComponentWidget::Reset()
{
    ItemsPanel->ClearChildren();
    if (ensureAlways(Component != nullptr) && ensureAlways(ItemWidgetClass != nullptr))
    {
        if (Component->DefaultViewTarget != nullptr)
        {
            auto Widget = WidgetTree->ConstructWidget<UStatefulImageButton>(ItemWidgetClass, FName("Default"));
            if (ensureAlways(Widget != nullptr))
            {
                Widget->ButtonImage->SetBrushFromTexture(Component->DefaultViewTargetIcon);
                ItemsPanel->AddChild(Widget);
                Widget->OnPressed.BindLambda([=]() { Component->SetViewTarget(Component->DefaultViewTarget); });
            }
        }
        for (const auto Spectatable : Component->SpectatableComponents)
        {
            auto Widget = WidgetTree->ConstructWidget<UStatefulImageButton>(ItemWidgetClass, FName(Spectatable->FriendlyName));
            if (ensureAlways(Widget != nullptr))
            {
                Widget->ButtonImage->SetBrushFromTexture(Spectatable->Icon);
                ItemsPanel->AddChild(Widget);
                Widget->OnPressed.BindLambda([=]() { Component->SetViewTarget(Spectatable->GetOwner()); });
            }
        }
    }
}
