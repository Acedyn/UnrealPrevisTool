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

    // Called at StartupModule() to load all the modules
    virtual void AddModule() override;

    // Singleton like acces to this module
    static inline FPrevisUIEditor& Get()
    {
        return FModuleManager::LoadModuleChecked< FPrevisUIEditor >("PrevisUIEditor");
    }

    // Check if the module was loaded correctly
    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("PrevisUIEditor");
    }


public:
    // Pointers to modules to be loaded
    MenuBar* menuBar = nullptr;
    MenuButtons* menuButtons = nullptr;
    WindowBase* windowBase = nullptr;
};