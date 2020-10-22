#pragma once
#include "WindowBase.h"

#include "Widgets/SCompoundWidget.h"

class WindowPanel : public SCompoundWidget
{
    // Create agument for our custom slate widget (argument are called with SNew(<widgetname>).<argumentname>)
    SLATE_BEGIN_ARGS(WindowPanel) {}
    SLATE_ARGUMENT(TWeakPtr<class WindowBase>, Tool)
    SLATE_END_ARGS()

    // Create the content of the custom widget
    void Construct(const FArguments& InArgs);

protected:
    // Stores the Tool argument passed value
    TWeakPtr<WindowBase> tool;
};