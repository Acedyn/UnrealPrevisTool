#include "WindowBase.h"
#include "windowPanel.h"
#include "../PrevisUIEditor.h"
#include "../Menu/MenuBar.h"

#include "Templates/SharedPointer.h"

void WindowBase::OnStartupModule()
{
    // Register out window to the FGlobalTabmanager
    FGlobalTabmanager::Get()->RegisterNomadTabSpawner(WindowName, FOnSpawnTab::CreateRaw(this, &WindowBase::SpawnWindow))
        .SetDisplayName(WindowDisplayName)  // Set the displayed name of the window
        .SetTooltipText(ToolTip);           // Set the tooltip of the window

    // Add the menu button to the menu bar we created in MenuBar.cpp to spawn the window
    FPrevisUIEditor::Get().menuBar->AddMenuExtension(
        FMenuExtensionDelegate::CreateRaw(this, &WindowBase::CreateMenuEntry),  // Funcion that will actually create the UI element
        FName("Section_2"));                                                    // The place where we want to place our extension

    UE_LOG(LogTemp, Warning, TEXT("PrevisUI Module : Window base loaded"));
}

void WindowBase::OnShutdownModule()
{

}

void WindowBase::CreateMenuEntry(FMenuBuilder& menuBuilder)
{
    // Add a button that will spawn the given window
    FGlobalTabmanager::Get()->PopulateTabSpawnerMenu(menuBuilder, WindowName);
};

TSharedRef<SDockTab> WindowBase::SpawnWindow(const FSpawnTabArgs& TabSpawnArgs)
{
    // Create the window of type : SDockTab
    TSharedRef<SDockTab> SpawnedWindow = SNew(SDockTab)
        .TabRole(ETabRole::PanelTab)
        [
            // Create a child widget of custom type defined in WindowPanel.h
            SNew(WindowPanel)
        ];

    return SpawnedWindow;
}