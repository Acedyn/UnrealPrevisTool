#include "WindowBase.h"
#include "windowPanel.h"
#include "../PrevisUIEditor.h"
#include "../Menu/MenuBar.h"

#include "Templates/SharedPointer.h"

void WindowBase::OnStartupModule()
{
    Initialize();
    FGlobalTabmanager::Get()->RegisterNomadTabSpawner(WindowName, FOnSpawnTab::CreateRaw(this, &WindowBase::SpawnWindow))
        .SetGroup(FPrevisUIEditor::Get().GetMenuRoot())
        .SetDisplayName(WindowDisplayName)
        .SetTooltipText(ToolTip);

    FPrevisUIEditor::Get().menuBar->AddMenuExtension(
        FMenuExtensionDelegate::CreateRaw(this, &WindowBase::CreateMenuEntry),
        FName("Section_2"));

    UE_LOG(LogTemp, Warning, TEXT("PrevisUI Module : Window base loaded"));
}

void WindowBase::OnShutdownModule()
{

}

void WindowBase::CreateMenuEntry(FMenuBuilder& menuBuilder)
{
    FGlobalTabmanager::Get()->PopulateTabSpawnerMenu(menuBuilder, WindowName);
};

TSharedRef<SDockTab> WindowBase::SpawnWindow(const FSpawnTabArgs& TabSpawnArgs)
{
    TSharedRef<SDockTab> SpawnedWindow = SNew(SDockTab)
        .TabRole(ETabRole::NomadTab)
        [
            SNew(WindowPanel)
            //.Tool(SharedThis(this))
        ];

    return SpawnedWindow;
}