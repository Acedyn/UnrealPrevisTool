#pragma once
#include "../PrevisUIEditorInterface.h"

class WindowBase : public PrevisUIEditorModule
{
public:
    virtual ~WindowBase() {}

    virtual void OnStartupModule() override;
    virtual void OnShutdownModule() override;

private:
};