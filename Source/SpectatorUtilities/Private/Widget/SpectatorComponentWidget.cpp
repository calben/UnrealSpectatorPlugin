#include "Widget/SpectatorComponentWidget.h"

#include "GameFramework/SpectatorComponent.h"

void USpectatorComponentWidget::Setup(USpectatorComponent* InComponent)
{
    Component = InComponent;
    if (ensureAlways(Component != nullptr))
    {
        Component->OnViewTargetsUpdated.AddDynamic(this, &USpectatorComponentWidget::Reset);
        Reset();
    }
}

void USpectatorComponentWidget::Reset()
{
}
