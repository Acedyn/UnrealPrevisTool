#pragma once

#include "Widgets/SCompoundWidget.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/SceneCapture2D.h"

/////////////////////////////////////////    OPTIONAL CUSTOM VIEWPORT CLIENT FOR CUSTOM RENDER TARGET    /////////////////////////////////////////

class FCustomViewportClient : public FViewportClient
{
public:

	// Called by the FViewport that will be connected to this FWindowViewportClient's Draw function 
	virtual void Draw(FViewport* Viewport, FCanvas* Canvas) override;

	// Set the TextureRenderTarget2D that will be the source of our custom viewport client
	void SetTextureRenderTarget(UTextureRenderTarget2D* TextureRenderTarget2DParm);

	// !!!!! Check FViewportClient's depracated functions before define those functions !!!!!
	/*virtual bool InputKey(FViewport* Viewport, int32 ControllerId, FKey Key, EInputEvent Event, float AmountDepressed = 1.0f, bool bGamepad = false) override;
	virtual bool InputAxis(FViewport* Viewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime, int32 NumSamples = 1, bool bGamepad = false) override;
	virtual bool InputGesture(FViewport* Viewport, EGestureEvent GestureType, const FVector2D& GestureDelta, bool bIsDirectionInvertedFromDevice) override;*/
	virtual UWorld* GetWorld() const override { return nullptr; }
	virtual void RedrawRequested(FViewport* Viewport) override { Viewport->Draw(); }

private:
	TSharedPtr<UTextureRenderTarget2D> TextureRenderTarget2D;
};


class SWindowViewport : public SCompoundWidget
{
public:
	~SWindowViewport();

	// Create agument for our custom slate widget (argument are called with SNew(<widgetname>).<argumentname>)
	// Here there is no arguments
	SLATE_BEGIN_ARGS(SWindowViewport) { }
	SLATE_END_ARGS()

	// Create the content of the custom widget
	void Construct(const FArguments& InArgs);

private:
	// The viewport container that will be in our tab
	TSharedPtr<SViewport> WindowViewport;
	// The viewport that will be populated by one of the editor's viewport client (or the custom one) and projected in the  WindowViewport widget
	TSharedPtr<FSceneViewport> SceneViewport;
	// Custom viewport client that will feed the scene viewport with a UTextureRenderTarget2D that can be created from anything (cam, texture, ...)
	FCustomViewportClient* CustomViewportClient = new FCustomViewportClient;

	USceneCaptureComponent2D* SceneCaptureComponent;
	UTextureRenderTarget2D* RenderTarget2D;

	ACameraActor* CameraActor;
	ASceneCapture2D* SceneCaptureActor;

public:
	// Tick function that will update the content of WindowViewport
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
};


