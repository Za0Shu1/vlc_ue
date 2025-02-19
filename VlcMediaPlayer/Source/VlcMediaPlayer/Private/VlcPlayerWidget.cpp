// Fill out your copyright notice in the Description page of Project Settings.
#include "VlcPlayerWidget.h"

#include "Widgets/Layout/SScaleBox.h"
#define LOCTEXT_NAMESPACE "VlcMediaPlayer"


UVlcPlayerWidget::UVlcPlayerWidget()
{
	VideoTexture = UTexture2D::CreateTransient(VideoResolution.X, VideoResolution.Y, PF_B8G8R8A8);
}

void UVlcPlayerWidget::PlayVideo(const FString& VideoPath)
{
	VlcThread = MakeUnique<FVlcThread>(VideoPath);
	VlcThread->StartThread();

	FrameTickerHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateLambda([this](float DeltaTime)
	{
		TArray<uint8> FrameData;
		while (VlcThread && VlcThread->FrameDataQueue.Dequeue(FrameData))
		{
			UE_LOG(LogTemp, Warning, TEXT("update texture"));
			UpdateTexture(FrameData);
		}
		return true;
	}));
}

void UVlcPlayerWidget::StopVideo()
{
	if(VlcThread)
	{
		VlcThread->StopThread();
		VlcThread.Reset();
	}

	if(FrameTickerHandle.IsValid())
	{
		FTSTicker::GetCoreTicker().RemoveTicker(FrameTickerHandle);
		FrameTickerHandle.Reset();
	}
}

void UVlcPlayerWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
}

void UVlcPlayerWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	StopVideo();
}

TSharedRef<SWidget> UVlcPlayerWidget::RebuildWidget()
{
	const TSharedPtr<SOverlay> Overlay = SNew(SOverlay)

		+ SOverlay::Slot()
		  .VAlign(VAlign_Fill)
		  .HAlign(HAlign_Fill)
		[
			SNew(SScaleBox)
			.Stretch(EStretch::ScaleToFit)
			[
				SNew(SBox)
			.WidthOverride(ImageSize.X)
			.HeightOverride(ImageSize.Y)
				[
					SNew(SOverlay)
					+ SOverlay::Slot()
					  .VAlign(VAlign_Fill)
					  .HAlign(HAlign_Fill)
					[
						SNew(SImage)
						.Image_Lambda([this]()
						{
							FSlateBrush* Brush = new FSlateBrush();
							Brush->SetResourceObject(VideoTexture);
							return Brush;
						})
					]

					+ SOverlay::Slot()
					  .VAlign(VAlign_Center)
					  .HAlign(HAlign_Center)
					[
						SNew(STextBlock)
					.Text(FText::FromString("VlcPlayerWidget"))
					.ColorAndOpacity(FLinearColor::Black)
					.Font(FSlateFontInfo(FCoreStyle::GetDefaultFont(), 32))
					.Visibility_Lambda([this]()
						                {
							                return IsDesignTime()
								                       ? EVisibility::SelfHitTestInvisible
								                       : EVisibility::Collapsed;
						                })
					]
				]
			]
		];

	if (!IsDesignTime())
	{
		if (bAutoPlay)
		{
			PlayVideo(DefaultVideoPath);
		}
	}

	return Overlay.ToSharedRef();
}

#if WITH_EDITOR
const FText UVlcPlayerWidget::GetPaletteCategory()
{
	return LOCTEXT("PaletteCategory", "VlcMediaPlayer");
}
#endif

void UVlcPlayerWidget::UpdateTexture(const TArray<uint8>& FrameData) const
{
	ENQUEUE_RENDER_COMMAND(UpdateVlcTexture)(
		[this,FrameData](FRHICommandListImmediate& RHICmdList)
		{
			if (VideoTexture && VideoTexture->GetResource())
			{
				FRHITexture2D* RHITexture2D = VideoTexture->GetResource()->GetTexture2DRHI();
				RHICmdList.UpdateTexture2D(
					RHITexture2D,
					0,
					FUpdateTextureRegion2D(0, 0, 0, 0, VideoResolution.X, VideoResolution.Y),
					VideoResolution.X * 4,
					FrameData.GetData()
				);
			}
		}
	);
}


#undef LOCTEXT_NAMESPACE
