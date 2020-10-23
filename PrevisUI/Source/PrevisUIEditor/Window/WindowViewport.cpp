#include "WindowViewport.h"
#include "../PrevisUIEditor.h"

#include "SlateBasics.h"
#include "SlateExtras.h"
#include "Slate/SceneViewport.h"

void WindowViewport::Construct(const FArguments& InArgs)
{
	// Create Viewport Widget
	Viewport = SNew(SViewport)
		.IsEnabled(true)
		.EnableGammaCorrection(false)
		.ShowEffectWhenDisabled(false)
		.EnableBlending(true)
		.ToolTip(SNew(SToolTip).Text(FText::FromString("SPlaySceneViewport")));


	//// Create Viewport Client
	//WindowViewportClient = MakeShareable(new FWindowViewportClient());

	//// Create Scene Viewport
	//SceneViewport = MakeShareable(new FSceneViewport(WindowViewportClient.Get(), Viewport));

	//// Assign SceneViewport to Viewport widget. It needed for rendering
	//Viewport->SetViewportInterface(SceneViewport.ToSharedRef());

	// Assing Viewport widget for our custom PlayScene Viewport
	this->ChildSlot
		[
			Viewport.ToSharedRef()
		];
}

void WindowViewport::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	// Call FViewport each engine tick
	//SceneViewport->Draw();
	UE_LOG(LogTemp, Warning, TEXT("VIEWPORT TICKING OMG"));
}

