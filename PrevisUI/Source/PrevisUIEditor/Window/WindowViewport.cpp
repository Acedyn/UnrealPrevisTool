#include "WindowViewport.h"
#include "../PrevisUIEditor.h"

#include "SlateBasics.h"
#include "SlateExtras.h"
#include "Slate/SceneViewport.h"


SWindowViewport::~SWindowViewport()
{
	//!!!!!!!!!!!!!!!!!!!!!! MEMORY LEAK HERE - FIX IMPORTANT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// TODO : fix errors and then use smartpointers

	//delete CustomViewportClient;
	//delete SceneCaptureComponent;
	//delete RenderTarget2D;
}

void SWindowViewport::Construct(const FArguments& InArgs)
{
	// Fetch all editor's viewport
	const TArray<FEditorViewportClient*> EditorViewportClients = GEditor->GetAllViewportClients();
	UE_LOG(LogTemp, Warning, TEXT("%d Editor viewport clients found"), EditorViewportClients.Num());

	// Create Viewport Widget
	WindowViewport = SNew(SViewport)
		.IsEnabled(true)
		.EnableGammaCorrection(false)
		.ShowEffectWhenDisabled(false)
		.EnableBlending(true)
		.ToolTip(SNew(SToolTip).Text(FText::FromString("SWindowViewport")));

	// Set the edito's viewport to perpective
	EditorViewportClients[0]->SetViewportType(LVT_Perspective);

	// Get a reference to the world
	UWorld* World = GEditor->GetEditorWorldContext().World();
	if (World)
	{
		// If the world does not contain any camera of scene capture -> Create one
		TActorIterator<ACameraActor> CameraItr(World);
		TActorIterator<ASceneCapture2D> SceneCaptureItr(World);
		if (CameraItr)
		{
			CameraActor = *CameraItr;
		}
		else
		{
			CameraActor = (ACameraActor*)World->SpawnActor<ACameraActor>(ACameraActor::StaticClass());
		}

		if (SceneCaptureItr)
		{
			SceneCaptureActor = *SceneCaptureItr;
		}
		else
		{
			SceneCaptureActor = (ASceneCapture2D*)World->SpawnActor<ASceneCapture2D>(ASceneCapture2D::StaticClass());
		}
	}

	// Get the capture component of the scene capture
	SceneCaptureComponent = SceneCaptureActor->GetCaptureComponent2D();
	// Set capture component's parameters
	SceneCaptureComponent->ProjectionType = ECameraProjectionMode::Type::Perspective;
	SceneCaptureComponent->FOVAngle = 90.0f;
	SceneCaptureComponent->CaptureSource = ESceneCaptureSource::SCS_SceneColorHDR;
	SceneCaptureComponent->CompositeMode = ESceneCaptureCompositeMode::SCCM_Overwrite;
	SceneCaptureComponent->bCaptureOnMovement = false;
	SceneCaptureComponent->bCaptureEveryFrame = false;
	SceneCaptureComponent->MaxViewDistanceOverride = -1.0f;
	SceneCaptureComponent->bAutoActivate = true;
	SceneCaptureComponent->DetailMode = EDetailMode::DM_High;

	// Create render target to store the result of the capture component
	RenderTarget2D = NewObject<UTextureRenderTarget2D>();
	// Set the clear color to blue (so if the viewport is blue its a problem from the source)
	RenderTarget2D->ClearColor = FLinearColor::Blue;
	// Set the resolution of the render target (TODO : adapt the resolution to the viewport size)
	RenderTarget2D->InitAutoFormat(512, 512);

	// Link the scene capture component with the render target
	SceneCaptureComponent->TextureTarget = RenderTarget2D;

	// Link the render target to the viewport client
	CustomViewportClient->SetTextureRenderTarget(RenderTarget2D);


	// Create Scene Viewport that will be linked to the editor's viewport client
	SceneViewport = MakeShareable(new FSceneViewport(CustomViewportClient, WindowViewport));

	// Assign SceneViewport to viewport widget
	WindowViewport->SetViewportInterface(SceneViewport.ToSharedRef());

	// add WindowViewport widget for our custom SWindowViewport widget
	this->ChildSlot
		[
			WindowViewport.ToSharedRef()
		];
}

void SWindowViewport::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	// Update the render target
	SceneCaptureComponent->CaptureScene();
	// Update the viewport (also calls the Draw function of the viewport client connected to this viewport)
	SceneViewport->Draw();
}


/////////////////////////////////////////    OPTIONAL CUSTOM VIEWPORT CLIENT FOR CUSTOM RENDER TARGET    /////////////////////////////////////////

void FCustomViewportClient::Draw(FViewport* Viewport, FCanvas* Canvas)
{
	// Clear entire canvas
	Canvas->Clear(FLinearColor::Blue);

	// Draw SceenCaptureComponent texture to entire canvas
	if (TextureRenderTarget2D.IsValid() && TextureRenderTarget2D->Resource != nullptr)
	{
		FCanvasTileItem TileItem(
			FVector2D(0, 0), 
			TextureRenderTarget2D->Resource,
			FVector2D(Viewport->GetRenderTargetTexture()->GetSizeX(),
				Viewport->GetRenderTargetTexture()->GetSizeY()),
				FLinearColor::White);

		TileItem.BlendMode = ESimpleElementBlendMode::SE_BLEND_Opaque;
		Canvas->DrawItem(TileItem);
	}
}

void FCustomViewportClient::SetTextureRenderTarget(UTextureRenderTarget2D* TextureRenderTarget2DParm)
{
	TextureRenderTarget2D = TSharedPtr<UTextureRenderTarget2D>(TextureRenderTarget2DParm);
}