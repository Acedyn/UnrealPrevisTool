#pragma once
#include "../PrevisUIEditorInterface.h"

// For SDockTab Slate widget
#include "Widgets/Docking/SDockTab.h"

// Base class for windows
class WindowBase : public PrevisUIEditorModule
{
public:
    virtual ~WindowBase() {}

    virtual void OnStartupModule() override;
    virtual void OnShutdownModule() override;

    // Called by OnStartupModule
    virtual void Initialize() {};
    // Called by OnStartupModule to spawn the window
    virtual TSharedRef<SDockTab> SpawnWindow(const FSpawnTabArgs& TabSpawnArgs);

    virtual void CreateMenuEntry(FMenuBuilder& menuBuilder);

private:
    FName WindowName;
    FText WindowDisplayName;
    FText ToolTip;
};