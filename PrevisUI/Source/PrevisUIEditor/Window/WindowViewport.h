#pragma once

#include "Widgets/SCompoundWidget.h"

class WindowViewport : public SCompoundWidget
{
public:
	// Create agument for our custom slate widget (argument are called with SNew(<widgetname>).<argumentname>)
	// Here there is no arguments
	SLATE_BEGIN_ARGS(WindowViewport) { }
	SLATE_END_ARGS()

	// Create the content of the custom widget
	void Construct(const FArguments& InArgs);

private:
	TSharedPtr<SViewport> Viewport;
	/*TSharedPtr<FSceneViewport> SceneViewport;
	TSharedPtr<FWindowViewportClient> WindowViewportClient;*/

public:
	// SWidget overrides
	/**
	* Tick each engine tick, this is where we call FViewport::Draw() --> FPlaySceneViewportClient::Draw(...)
	*/
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;

};


class FWindowViewportClient : public FViewportClient
{
public:
	/** FViewportClient interface */
	/**
	* Execute Draw each tick
	* This is the place for issue draw cumments and start rendering
	*/
	/*virtual void Draw(FViewport* Viewport, FCanvas* Canvas) override;
	virtual bool InputKey(FViewport* Viewport, int32 ControllerId, FKey Key, EInputEvent Event, float AmountDepressed = 1.0f, bool bGamepad = false) override;
	virtual bool InputAxis(FViewport* Viewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime, int32 NumSamples = 1, bool bGamepad = false) override;
	virtual bool InputGesture(FViewport* Viewport, EGestureEvent GestureType, const FVector2D& GestureDelta, bool bIsDirectionInvertedFromDevice) override;
	virtual UWorld* GetWorld() const override { return nullptr; }
	virtual void RedrawRequested(FViewport* Viewport) override { Viewport->Draw(); }*/
};