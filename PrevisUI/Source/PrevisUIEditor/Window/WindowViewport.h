#pragma once

#include "Widgets/SCompoundWidget.h"
#include "Engine/TextureRenderTarget2D.h"

class SWindowViewport : public SCompoundWidget
{
public:
	// Create agument for our custom slate widget (argument are called with SNew(<widgetname>).<argumentname>)
	// Here there is no arguments
	SLATE_BEGIN_ARGS(SWindowViewport) { }
	SLATE_END_ARGS()

	// Create the content of the custom widget
	void Construct(const FArguments& InArgs);

private:
	// The viewport container that will be in our tab
	TSharedPtr<SViewport> WindowViewport;
	// The viewport that will be populated by one of the editor's viewport client and projected in the  WindowViewport widget
	TSharedPtr<FSceneViewport> SceneViewport;

public:
	// Tick function that will update the content of WindowViewport
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
};


/////////////////////////////////////////    OPTIONAL CUSTOM VIEWPORT CLIENT FOR CUSTOM RENDER TARGET    /////////////////////////////////////////

class FWindowViewportClient : public FViewportClient
{
public:
	/** FViewportClient interface */
	/**
	* Execute Draw each tick
	* This is the place for issue draw cumments and start rendering
	*/
	virtual void Draw(FViewport* Viewport, FCanvas* Canvas) override;
	virtual bool InputKey(FViewport* Viewport, int32 ControllerId, FKey Key, EInputEvent Event, float AmountDepressed = 1.0f, bool bGamepad = false) override;
	virtual bool InputAxis(FViewport* Viewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime, int32 NumSamples = 1, bool bGamepad = false) override;
	virtual bool InputGesture(FViewport* Viewport, EGestureEvent GestureType, const FVector2D& GestureDelta, bool bIsDirectionInvertedFromDevice) override;
	virtual UWorld* GetWorld() const override { return nullptr; }
	virtual void RedrawRequested(FViewport* Viewport) override { Viewport->Draw(); }

private:
	TSharedPtr<UTextureRenderTarget2D> TextureRenderTarget2D;
};