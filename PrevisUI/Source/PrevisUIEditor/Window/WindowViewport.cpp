#include "WindowViewport.h"
#include "../PrevisUIEditor.h"

#include "SlateBasics.h"
#include "SlateExtras.h"
#include "Slate/SceneViewport.h"

void SWindowViewport::Construct(const FArguments& InArgs)
{
	// Create Viewport Widget
	WindowViewport = SNew(SViewport)
		.IsEnabled(true)
		.EnableGammaCorrection(false)
		.ShowEffectWhenDisabled(false)
		.EnableBlending(true)
		.ToolTip(SNew(SToolTip).Text(FText::FromString("SWindowViewport")));


	// Create Viewport Client that will query all the data
	//WindowViewportClient = MakeShareable(new FWindowViewportClient());

	// Create Scene Viewport that will be linked to the Viewport Client
	//SceneViewport = MakeShareable(new FSceneViewport(WindowViewportClient.Get(), WindowViewport));

	// Assign SceneViewport to Viewport widget
	//WindowViewport->SetViewportInterface(SceneViewport.ToSharedRef());

	// add WindowViewport widget for our custom SWindowViewport widget
	this->ChildSlot
		[
			WindowViewport.ToSharedRef()
		];
}

void SWindowViewport::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	// Call FViewport each engine tick
	//SceneViewport->Draw();
	UE_LOG(LogTemp, Warning, TEXT("VIEWPORT TICKING OMG"));
}

//void FWindowViewportClient::Draw(FViewport* Viewport, FCanvas* Canvas)
//{
//	// Clear entire canvas
//	Canvas->Clear(FLinearColor::Black);
//
//	// Draw SceenCaptureComponent texture to entire canvas
//	auto TextRenderTarget2D = FPrevisUIEditor::Get().GetTextureRenderTarget2D();
//	if (TextRenderTarget2D.IsValid() && TextRenderTarget2D->Resource != nullptr)
//	{
//		FCanvasTileItem TileItem(
//			FVector2D(0, 0), 
//			TextRenderTarget2D->Resource,
//			FVector2D(Viewport->GetRenderTargetTexture()->GetSizeX(), 
//			Viewport->GetRenderTargetTexture()->GetSizeY()),
//			FLinearColor::White);
//
//		TileItem.BlendMode = ESimpleElementBlendMode::SE_BLEND_Opaque;
//		Canvas->DrawItem(TileItem);
//	}
//}