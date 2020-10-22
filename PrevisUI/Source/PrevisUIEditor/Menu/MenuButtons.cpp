#include "MenuButtons.h"
#include "../PrevisUIEditor.h"
#include "MenuBar.h"

#define LOCTEXT_NAMESPACE "MenuButtons"

// Class to abstact commands
class MenuCommands : public TCommands<MenuCommands>
{
public:
    // Constructor to initialize the commands
    MenuCommands()
        : TCommands<MenuCommands>(
            TEXT("MenuTool"),                       // Context name for fast lookup
            FText::FromString("Example Menu tool"), // Context name for displaying
            NAME_None,                              // No parent context
            FEditorStyle::GetStyleSetName()) {}     // Icon Style Set

    // Called by Register (herited function from TCommands to register the new command)
    virtual void RegisterCommands() override
    {
        // Macro registering the command to the editor
        UI_COMMAND(MenuCommand1, "Menu Command 1", "Test Menu Command 1.", EUserInterfaceActionType::Button, FInputGesture());

    }

public:
    // Pointer to the commands MenuCommand1
    TSharedPtr<FUICommandInfo> MenuCommand1;
};

void MenuButtons::OnStartupModule()
{
    CommandList = MakeShareable(new FUICommandList);
    // Call RegisterCommands from the MenuCommands class declarated above to register the commands
    MenuCommands::Register();
    // Add commands to CommandList
    MapCommands();

    // Add the menu content to the menu bar we created in MenuBar.cpp
    FPrevisUIEditor::Get().menuBar->AddMenuExtension(
        FMenuExtensionDelegate::CreateRaw(this, &MenuButtons::MakeMenuEntry),   // Funcion that will actually create the UI element
        FName("Section_1"),                                                     // The place where we want to place our extension
        CommandList);                                                           // The command list to be called with this extension

	UE_LOG(LogTemp, Warning, TEXT("PrevisUI Module : Menu buttons loaded"));
}

void MenuButtons::OnShutdownModule()
{

}

void MenuButtons::MakeMenuEntry(FMenuBuilder& menuBuilder)
{
	// Add an entry for the menu
	menuBuilder.AddMenuEntry(MenuCommands::Get().MenuCommand1);
}

void MenuButtons::MapCommands()
{
    // Associate the command that we created with Register to the commandList : 
    CommandList->MapAction(
        MenuCommands::Get().MenuCommand1,                               // The variable to store the command in
        FExecuteAction::CreateRaw(this, &MenuButtons::MenuCommand1),    // The function to be called when this command is invoked
        FCanExecuteAction());                                           // Function testing of the command can be calls (like a boolean)
}

void MenuButtons::MenuCommand1()
{
    UE_LOG(LogTemp, Log, TEXT("clicked MenuCommand1"));
}


#undef LOCTEXT_NAMESPACE