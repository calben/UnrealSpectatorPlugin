#pragma once

#include "CoreMinimal.h"
#include "Widget/SpectatorComponentWidget.h"

#include "TextSpectatorComponentWidget.generated.h"

UCLASS()
class SPECTATORUTILITIES_API UTextSpectatorComponentWidget : public USpectatorComponentWidget
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<class UStatefulButton> ItemWidgetClass;

    virtual void Reset() override;
};
