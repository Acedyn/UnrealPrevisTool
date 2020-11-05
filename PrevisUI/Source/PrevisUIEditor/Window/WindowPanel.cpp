#include "WindowPanel.h"
#include "WindowViewport.h"

#include "SlateBasics.h"
#include "SlateExtras.h"

void SWindowPanel::Construct(const FArguments& InArgs)
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
        .Padding(2)
        [
            SNew(SBorder)
            .BorderBackgroundColor(FColor(192, 192, 192, 255))
            .Padding(15.0f)
            [
                SNew(STextBlock)
                .Text(FText::FromString(TEXT("This is a tab example.")))
            ]
        ]
        + SScrollBox::Slot()
        .HAlign(HAlign_Left)
        .Padding(2)
        [

            SNew(SVerticalBox)
            + SVerticalBox::Slot()
            .VAlign(VAlign_Top)
            .Padding(2)
            [
                SNew(SHorizontalBox)
                + SHorizontalBox::Slot()
                .HAlign(HAlign_Left)
                .Padding(2)
                [
                    SNew(SWindowViewport)
                    .Name(MakeShareable(new FString("InputCapture")))
                ]
                + SHorizontalBox::Slot()
                .HAlign(HAlign_Right)
                .Padding(2)
                [
                    SNew(SWindowViewport)
                    .Name(MakeShareable(new FString("MatteCapture")))
                ]
            ]
            + SVerticalBox::Slot()
            .VAlign(VAlign_Top)
            .Padding(2)
            [
                SNew(SHorizontalBox)
                + SHorizontalBox::Slot()
                .HAlign(HAlign_Left)
                .Padding(2)
                [
                    SNew(SWindowViewport)
                    .Name(MakeShareable(new FString("AOCapture")))
                ]
                + SHorizontalBox::Slot()
                .HAlign(HAlign_Right)
                .Padding(2)
                [
                    SNew(SWindowViewport)
                    .Name(MakeShareable(new FString("OutputCapture")))
                ]
            ]
        ]
    ];
}