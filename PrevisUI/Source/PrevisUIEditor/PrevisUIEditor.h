#pragma once
#include "PrevisUIEditorInterface.h"

// For basic classes
#include "UnrealEd.h"
// For classes related to the level editor (FLevelEditorModule, FExtensibilityManager, ...)
#include "LevelEditor.h"

// Forward declaration
class MenuBar;
class MenuButtons;
class WindowBase;

class FPrevisUIEditor : public IPrevisUIEditorInterface
{
public:
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    virtual void AddModule() override;

    static inline FPrevisUIEditor& Get()
    {
        return FModuleManager::LoadModuleChecked< FPrevisUIEditor >("PrevisUIEditor");
    }

    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("PrevisUIEditor");
    }

public:
    MenuBar* menuBar = nullptr;
    MenuButtons* menuButtons = nullptr;
    WindowBase* windowBase = nullptr;
};