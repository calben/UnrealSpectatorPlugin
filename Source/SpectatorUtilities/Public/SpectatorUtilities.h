#pragma once

#include "Modules/ModuleManager.h"

class FSpectatorUtilitiesModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
