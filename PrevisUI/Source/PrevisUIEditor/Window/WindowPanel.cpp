#include "WindowPanel.h"

#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Text/STextBlock.h"

void WindowPanel::Construct(const FArguments& InArgs)
{
    // Store the value passed in the Tool argument in the tool variable
    tool = InArgs._Tool;
    // If the argument passed is valid
    if (tool.IsValid())
    {
        // do anything you need from tool object
    }

    // The acturl content of the widget
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