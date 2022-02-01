#include "GameFramework/SpectatorComponent.h"

#include "EngineUtils.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpectatableComponent.h"
#include "GameFramework/SpectatorCamera.h"
#include "Kismet/GameplayStatics.h"

USpectatorComponent::USpectatorComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void USpectatorComponent::BeginPlay()
{
    Super::BeginPlay();
    SetupViewTargets();
}

void USpectatorComponent::SetupViewTargets()
{
    GetSpectatableComponents();
    if (bSetupDefaultViewTarget)
    {
        DefaultViewTarget = GetWorld()->GetFirstPlayerController()->GetPawn();
    }
}

void USpectatorComponent::GetSpectatableComponents()
{
    SpectatableComponents.Empty();
    for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
    {
        auto SpectatableComponent = (*ActorItr)->FindComponentByClass<USpectatableComponent>();
        if (SpectatableComponent != nullptr && SpectatableComponent->GetOwner() != this->GetOwner())
        {
            SpectatableComponents.Add(SpectatableComponent);
        }
    }
    OnViewTargetsUpdated.Broadcast();
}

void USpectatorComponent::SetViewTarget(AActor* Target)
{
    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
    if (PlayerController != nullptr)
    {
        PlayerController->SetViewTargetWithBlend(Target, BlendTime, EViewTargetBlendFunction::VTBlend_EaseInOut, 2.0f, false);
    }
}
