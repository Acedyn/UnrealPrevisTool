#include "PrevisUIEditor.h"
#include "Menu/MenuBar.h"
#include "Menu/MenuButtons.h"
#include "Window/WindowBase.h"

IMPLEMENT_GAME_MODULE(FPrevisUIEditor, PrevisUIEditor)


void FPrevisUIEditor::AddModule()
{
    // Initialize all the modules
    menuBar = new FMenuBar;
    menuButtons = new FMenuButtons;
    windowBase = new FWindowBase;
    // Load all the modules
    Modules.Add(MakeShareable(menuBar));
    Modules.Add(MakeShareable(menuButtons));
    Modules.Add(MakeShareable(windowBase));
}

void FPrevisUIEditor::StartupModule()
{
    IPrevisUIEditorInterface::StartupModule();

    UE_LOG(LogTemp, Warning, TEXT("PrevisUI Module : Modules loaded successfull"));
}

void FPrevisUIEditor::ShutdownModule()
{
    IPrevisUIEditorInterface::ShutdownModule();
}