#pragma once
#include "WindowBase.h"

#include "Widgets/SCompoundWidget.h"

class SWindowPanel : public SCompoundWidget
{
    // Create agument for our custom slate widget (argument are called with SNew(<widgetname>).<argumentname>)
    SLATE_BEGIN_ARGS(SWindowPanel) {}
    SLATE_ARGUMENT(TWeakPtr<class WindowBase>, Tool)
    SLATE_END_ARGS()

    // Create the content of the custom widget
    void Construct(const FArguments& InArgs);

protected:
    // Stores the Tool argument passed value
    TWeakPtr<WindowBase> tool;
};