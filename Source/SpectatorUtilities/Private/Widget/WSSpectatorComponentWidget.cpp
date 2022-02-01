#include "Widget/WSSpectatorComponentWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/OverlaySlot.h"
#include "GameFramework/SpectatableComponent.h"
#include "GameFramework/SpectatorComponent.h"

void UWSSpectatorComponentWidget::Setup(USpectatorComponent* InComponent)
{
    Component = InComponent;
    Component->OnViewTargetsUpdated.AddDynamic(this, &UWSSpectatorComponentWidget::CreateOptions);
    CreateOptions();
}

void UWSSpectatorComponentWidget::CreateOptions()
{
    if (ensureAlways(Component != nullptr))
    {
        TabBar->SetOptions({});
        if (Component->DefaultViewTarget != nullptr)
        {
            FButtonOptions Option;
            Option.ContentStyle = DefaultButtonContentStyle;
            Option.CustomIcon   = Component->DefaultViewTargetIcon;
            Option.Text         = FText::FromString("Default");
            TabBar->AddOption(Option);
        }
        for (const auto Spectatable : Component->SpectatableComponents)
        {
            FButtonOptions Option;
            Option.ContentStyle = DefaultButtonContentStyle;
            Option.CustomIcon   = Spectatable->Icon;
            Option.Text         = FText::FromString(Spectatable->FriendlyName);
            TabBar->AddOption(Option);
        }
    }
}

void UWSSpectatorComponentWidget::OnOptionSelected(int32 Index, FButtonOptions Option)
{
    AActor* Target = nullptr;
    if (Index == 0)
    {
        Target = Component->DefaultViewTarget;
    }
    else
    {
        const auto Spectatable = Component->SpectatableComponents[Index - 1];
        if (ensureAlways(Spectatable != nullptr))
        {
            Target = Spectatable->GetOwner();
        }
    }
    if (ensureAlways(Target != nullptr))
    {
        Component->SetViewTarget(Target);
    }
}

void UWSSpectatorComponentWidget::NativeOnInitialized()
{
    TabBar->OnCurrentIndexChanged.AddDynamic(this, &UWSSpectatorComponentWidget::OnOptionSelected);
}
