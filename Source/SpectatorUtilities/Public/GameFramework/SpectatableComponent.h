#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

#include "SpectatableComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPECTATORUTILITIES_API USpectatableComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FriendlyName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    class UTexture2D* Icon;

    USpectatableComponent();

    virtual void OnComponentDestroyed(bool bDestroyingHierarchy);

    virtual void BeginPlay() override;
};
