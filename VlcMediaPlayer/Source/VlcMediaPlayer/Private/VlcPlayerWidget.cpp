// Fill out your copyright notice in the Description page of Project Settings.
#include "VlcPlayerWidget.h"
#include "Widgets/Layout/SScaleBox.h"
#define LOCTEXT_NAMESPACE "VlcMediaPlayer"


UVlcPlayerWidget::UVlcPlayerWidget()
{
}

void UVlcPlayerWidget::PlayVideo(const FString& VideoPath)
{
	VlcThread = MakeUnique<FVlcThread>(VideoPath);
	VlcThread->StartThread();

	VideoTexture = UTexture2D::CreateTransient(VideoResolution.X, VideoResolution.Y, PF_R8G8B8A8); //RGBA
	VideoTexture->UpdateResource(); // 将临时纹理与GPU资源关联，否则无法在渲染线程中使用（GetResource）


	VideoBrush = MakeShareable(new FSlateBrush());
	VideoBrush->SetResourceObject(VideoTexture);

	// @TODO: Set Delay/Interval for ticker
	FrameTickerHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateLambda([this](float DeltaTime)
	{
		TArray<uint8> FrameData;
		while (VlcThread && VlcThread->FrameDataQueue.Dequeue(FrameData))
		{
			// UE_LOG(LogTemp, Warning, TEXT("update texture"));
			UpdateTexture(FrameData);
		}
		return true;
	}), 0.f);
}

void UVlcPlayerWidget::StopVideo()
{
	if (VlcThread)
	{
		VlcThread->StopThread();
		VlcThread.Reset();
	}

	if (FrameTickerHandle.IsValid())
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
							if (VideoBrush && VideoTexture)
							{
								return VideoBrush.Get();
							}
							else
							{
								FSlateBrush* SlateBrush = new FSlateBrush();

								// 设置颜色为黑色
								SlateBrush->TintColor = FSlateColor(FLinearColor::Black);

								// 可选：设置图像的资源，这里可以设置为 nullptr，表示没有图像资源
								SlateBrush->SetResourceObject(nullptr);

								return SlateBrush;
							}
						})
					]

					+ SOverlay::Slot()
					  .VAlign(VAlign_Center)
					  .HAlign(HAlign_Center)
					[
						SNew(STextBlock)
					.Text(FText::FromString("VlcPlayerWidget"))
					.ColorAndOpacity(FLinearColor::White)
					.Font(FSlateFontInfo(FCoreStyle::GetDefaultFont(), 24))
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

void UVlcPlayerWidget::UpdateTexture(TArray<uint8>& FrameData) const
{
	if (!VideoTexture)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid VideoTexture"));
		return;
	}

	ENQUEUE_RENDER_COMMAND(UpdateVlcTexture)(
		[this, FrameData](FRHICommandListImmediate& RHICmdList)
		{
			if (!VideoTexture)
			{
				UE_LOG(LogTemp, Error, TEXT("Invalid VideoTexture"));
				return;
			}

			if (!VideoTexture->GetResource())
			{
				UE_LOG(LogTemp, Error, TEXT("Invalid VideoTexture Resource."));
				return;
			}

			// 确保我们获取到纹理的 RHI 资源
			FRHITexture2D* RHITexture2D = VideoTexture->GetResource()->GetTexture2DRHI();
			if (RHITexture2D)
			{
				// 设置需要更新的区域，这里假设更新整个纹理
				const uint32 Width = VideoResolution.X;
				const uint32 Height = VideoResolution.Y;
				const uint32 Stride = Width * 4; // 假设帧数据是 BGRA 格式

				// 将原始帧数据写入纹理
				RHICmdList.UpdateTexture2D(
					RHITexture2D,
					0, // MIP 层级，这里假设是 0
					FUpdateTextureRegion2D(0, 0, 0, 0, Width, Height),
					Stride,
					FrameData.GetData() // 获取帧数据的指针
				);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to get RHI texture"));
			}
		}
	);
}


#undef LOCTEXT_NAMESPACE
