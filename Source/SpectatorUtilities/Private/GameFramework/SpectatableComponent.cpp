#include "GameFramework/SpectatableComponent.h"

#include "EngineUtils.h"
#include "GameFramework/SpectatorComponent.h"

USpectatableComponent::USpectatableComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void USpectatableComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
    Super::OnComponentDestroyed(bDestroyingHierarchy);
    const auto World = GetWorld();
    if (World != nullptr)
    {
        for (TActorIterator<AActor> ActorItr(World); ActorItr; ++ActorItr)
        {
            auto SpectatorComponent = (*ActorItr)->FindComponentByClass<USpectatorComponent>();
            if (SpectatorComponent != nullptr)
            {
                SpectatorComponent->SetupViewTargets();
            }
        }
    }
}

void USpectatableComponent::BeginPlay()
{
    Super::BeginPlay();
    for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
    {
        auto SpectatorComponent = (*ActorItr)->FindComponentByClass<USpectatorComponent>();
        if (SpectatorComponent != nullptr)
        {
            SpectatorComponent->SetupViewTargets();
        }
    }
}
