#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "WidgetStudioRuntime/Public/Widgets/WSBase.h"
#include "WidgetStudioRuntime/Public/Widgets/WSContainer.h"
#include "WidgetStudioRuntime/Public/Widgets/WSModernTabBar.h"

#include "WSSpectatorComponentWidget.generated.h"

UCLASS()
class SPECTATORUTILITIES_API UWSSpectatorComponentWidget : public UWidgetStudioBase
{
    GENERATED_BODY()
public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Widget, meta = (AllowPrivateAccess = "true", BindWidget))
    UWidgetStudioModernTabBar* TabBar;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    class USpectatorComponent* Component;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Appearance)
    EButtonContentStyle DefaultButtonContentStyle = EButtonContentStyle::Icon;

    UFUNCTION(BlueprintCallable)
    void Setup(class USpectatorComponent* InComponent);

    UFUNCTION(BlueprintCallable)
    void CreateOptions();

    UFUNCTION(BlueprintCallable)
    void OnOptionSelected(int32 Index, FButtonOptions Option);

    void NativeOnInitialized();
};
