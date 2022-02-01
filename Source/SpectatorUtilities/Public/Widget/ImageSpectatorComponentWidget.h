#pragma once

#include "CoreMinimal.h"
#include "Widget/SpectatorComponentWidget.h"

#include "ImageSpectatorComponentWidget.generated.h"

UCLASS()
class SPECTATORUTILITIES_API UImageSpectatorComponentWidget : public USpectatorComponentWidget
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<class UStatefulImageButton> ItemWidgetClass;

    virtual void Reset() override;
};
