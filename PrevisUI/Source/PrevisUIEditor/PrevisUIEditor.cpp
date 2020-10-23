#include "PrevisUIEditor.h"
#include "Menu/MenuBar.h"
#include "Menu/MenuButtons.h"
#include "Window/WindowBase.h"

IMPLEMENT_GAME_MODULE(FPrevisUIEditor, PrevisUIEditor)


void FPrevisUIEditor::AddModule()
{
    // Initialize all the modules
    menuBar = new MenuBar;
    menuButtons = new MenuButtons;
    windowBase = new WindowBase;
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

TWeakObjectPtr<UTextureRenderTarget2D> FPrevisUIEditor::GetTextureRenderTarget2D()
{
    return TextureRenderTarget2D;
}

void FPrevisUIEditor::SetTextureRenderTarget2D(UTextureRenderTarget2D* TexRenderTarget2D)
{
    TextureRenderTarget2D = TexRenderTarget2D;
}