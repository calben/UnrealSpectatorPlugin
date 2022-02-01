#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"

#include "SpectatorComponentWidget.generated.h"

UCLASS()
class SPECTATORUTILITIES_API USpectatorComponentWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    class USpectatorComponent* Component;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Widget, meta = (AllowPrivateAccess = "true", BindWidget))
    class UPanelWidget* ItemsPanel;

    UFUNCTION(BlueprintCallable)
    void Setup(class USpectatorComponent* InComponent);

    UFUNCTION(BlueprintCallable)
    virtual void Reset();
};
