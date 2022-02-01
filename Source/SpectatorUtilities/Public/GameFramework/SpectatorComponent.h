#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

#include "SpectatorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnViewTargetsUpdated);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPECTATORUTILITIES_API USpectatorComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bSetupDefaultViewTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float BlendTime = 0.3f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    class AActor* DefaultViewTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    class UTexture2D* DefaultViewTargetIcon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    class UTexture2D* DefaultPawnTargetIcon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<class USpectatableComponent*> SpectatableComponents;

    FOnViewTargetsUpdated OnViewTargetsUpdated;

    USpectatorComponent();

    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
    void SetupViewTargets();

    UFUNCTION(BlueprintCallable)
    void GetSpectatableComponents();

    UFUNCTION(BlueprintCallable)
    void SetViewTarget(AActor* Target);
};
