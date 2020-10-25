#include "WindowViewport.h"
#include "../PrevisUIEditor.h"

#include "SlateBasics.h"
#include "SlateExtras.h"
#include "Slate/SceneViewport.h"


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

	// Create Scene Viewport that will be linked to the editor's viewport client
	SceneViewport = MakeShareable(new FSceneViewport(EditorViewportClients[0], WindowViewport));

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
	// Call FViewport each engine tick
	SceneViewport->Draw();
}


/////////////////////////////////////////    OPTIONAL CUSTOM VIEWPORT CLIENT FOR CUSTOM RENDER TARGET    /////////////////////////////////////////

void FWindowViewportClient::Draw(FViewport* Viewport, FCanvas* Canvas)
{
	// Clear entire canvas
	Canvas->Clear(FLinearColor::Black);

	// Draw SceenCaptureComponent texture to entire canvas
	if (TextureRenderTarget2D.IsValid() && TextureRenderTarget2D->Resource != nullptr)
	{
		FCanvasTileItem TileItem(
			FVector2D(0, 0), 
			TextureRenderTarget2D->Resource,
			FVector2D(Viewport->GetRenderTargetTexture()->GetSizeX(), Viewport->GetRenderTargetTexture()->GetSizeY()),
			FLinearColor::White);

		TileItem.BlendMode = ESimpleElementBlendMode::SE_BLEND_Opaque;
		Canvas->DrawItem(TileItem);
	}
}