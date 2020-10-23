#include "WindowPanel.h"

#include "SlateBasics.h"
#include "SlateExtras.h"
#include "..\..\..\..\..\..\..\..\Programes\Unreal 4.25\UE_4.25\Engine\Source\Runtime\Slate\Private\Widgets\Views\SListPanel.h"

void WindowPanel::Construct(const FArguments& InArgs)
{
    // Store the value passed in the Tool argument in the tool variable
    tool = InArgs._Tool;
    // If the argument passed is valid
    if (tool.IsValid())
    {
        // do anything you need from tool object
    }

    // The actual content of the widget
    ChildSlot
    [
        SNew(SScrollBox)
        + SScrollBox::Slot()
        .VAlign(VAlign_Top)
        .Padding(5)
        [
            SNew(SBorder)
            .BorderBackgroundColor(FColor(192, 192, 192, 255))
            .Padding(15.0f)
            [
                SNew(STextBlock)
                .Text(FText::FromString(TEXT("This is a tab example.")))
            ]
        ]
    ];
}