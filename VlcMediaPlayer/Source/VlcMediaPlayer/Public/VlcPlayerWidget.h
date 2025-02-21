// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FVlcThread.h"
#include "Blueprint/UserWidget.h"
#include "VlcPlayerWidget.generated.h"

/**
 * 
 */
UCLASS()
class VLCMEDIAPLAYER_API UVlcPlayerWidget : public UWidget
{
	GENERATED_BODY()
public:
	UVlcPlayerWidget();

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category = "VLC Media Player | Config")
	FIntPoint ImageSize = FIntPoint(1920,1080);

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category = "VLC Media Player | Config")
	FIntPoint VideoResolution = FIntPoint(1920,1080);

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category = "VLC Media Player | Config")
	bool bAutoPlay = true;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category = "VLC Media Player | Config")
	FString DefaultVideoPath;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category = "VLC Media Player | Config")
	bool bRepeat = true;
	
	UFUNCTION(BlueprintCallable,Category = "VLC Media Player | Control")
	void PlayVideo(const FString& VideoPath);

	UFUNCTION(BlueprintCallable,Category = "VLC Media Player | Control")
	void StopVideo();
	
	//~ Begin UWidget Interface
	virtual void SynchronizeProperties() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	virtual TSharedRef<SWidget> RebuildWidget() override;
#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif
	//~ End UWidget Interface

private:
	UPROPERTY()
	UTexture2D* VideoTexture;

	TSharedPtr<FSlateBrush> VideoBrush;

	// vlc thread instance
	TUniquePtr<FVlcThread> VlcThread;

	void UpdateTexture(TArray<uint8>& FrameData) const;
	FTSTicker::FDelegateHandle FrameTickerHandle;
};
