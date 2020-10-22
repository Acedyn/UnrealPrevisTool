#pragma once
#include "WindowBase.h"

#include "Widgets/SCompoundWidget.h"

class WindowPanel : public SCompoundWidget
{
    SLATE_BEGIN_ARGS(WindowPanel) {}
    SLATE_ARGUMENT(TWeakPtr<class WindowBase>, Tool)
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs);

protected:
    TWeakPtr<WindowBase> tool;
};