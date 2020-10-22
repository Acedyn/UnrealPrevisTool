#include "PrevisUIEditor.h"
#include "Menu/MenuBar.h"
#include "Menu/MenuButtons.h"
#include "Window/WindowBase.h"

IMPLEMENT_GAME_MODULE(FPrevisUIEditor, PrevisUIEditor)

TSharedRef<FWorkspaceItem> FPrevisUIEditor::MenuRoot = FWorkspaceItem::NewGroup(FText::FromString("Menu Root"));

void FPrevisUIEditor::AddModule()
{
    menuBar = new MenuBar;
    menuButtons = new MenuButtons;
    windowBase = new WindowBase;
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