#pragma once

// For modules related classes
#include "Modules/ModuleInterface.h"

class FPrevisUIEditorModule
{
public:
    virtual void OnStartupModule() {};
    virtual void OnShutdownModule() {};
};

class IPrevisUIEditorInterface : public IModuleInterface
{
public:
    void StartupModule() override
    {
        if (!IsRunningCommandlet())
        {
            AddModule();
            for (int32 i = 0; i < Modules.Num(); ++i)
            {
                Modules[i]->OnStartupModule();
            }
        }
    }

    void ShutdownModule() override
    {
        for (int32 i = 0; i < Modules.Num(); ++i)
        {
            Modules[i]->OnShutdownModule();
        }
    }

    virtual void AddModule() {};

protected:
    TArray<TSharedRef<FPrevisUIEditorModule>> Modules;
};