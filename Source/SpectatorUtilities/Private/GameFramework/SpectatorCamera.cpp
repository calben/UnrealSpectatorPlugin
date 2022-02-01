#include "GameFramework/SpectatorCamera.h"

#include "GameFramework/SpectatableComponent.h"

ASpectatorCamera::ASpectatorCamera(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    Spectatable = CreateDefaultSubobject<USpectatableComponent>("Spectatable");
}
