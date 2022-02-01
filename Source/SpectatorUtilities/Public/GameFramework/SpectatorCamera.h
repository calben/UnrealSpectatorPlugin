#pragma once

#include "Camera/CameraActor.h"
#include "CoreMinimal.h"

#include "SpectatorCamera.generated.h"

UCLASS()
class SPECTATORUTILITIES_API ASpectatorCamera : public ACameraActor
{
    GENERATED_BODY()

public:
    ASpectatorCamera(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    class USpectatableComponent* Spectatable;
};
