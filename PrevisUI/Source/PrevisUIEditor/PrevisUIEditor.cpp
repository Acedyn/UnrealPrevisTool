#include "PrevisUIEditor.h"
#include "Menu/MenuBar.h"
#include "Menu/MenuButtons.h"

IMPLEMENT_GAME_MODULE(FPrevisUIEditor, PrevisUIEditor)

void FPrevisUIEditor::AddModule()
{
    menuBar = new MenuBar;
    menuButtons = new MenuButtons;
    Modules.Add(MakeShareable(menuBar));
    Modules.Add(MakeShareable(menuButtons));
}

void FPrevisUIEditor::StartupModule()
{
    IPrevisUIEditorInterface::StartupModule();

    UE_LOG(LogTemp, Warning, TEXT("PrevisUI Module : Modules loading successfull"));
}

void FPrevisUIEditor::ShutdownModule()
{
    IPrevisUIEditorInterface::ShutdownModule();
}