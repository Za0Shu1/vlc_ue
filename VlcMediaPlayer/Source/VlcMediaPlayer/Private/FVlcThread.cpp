#include "FVlcThread.h"

#include "IImageWrapper.h"
#include "IImageWrapperModule.h"

FVlcThread::FVlcThread(const FString& InVideoPath)
	: VideoPath(InVideoPath), Thread(nullptr), bIsRunning(false),
	  VlcInstance(nullptr), VlcMedia(nullptr), VlcMediaPlayer(nullptr),
	  VideoWidth(1920), VideoHeight(1080)
{
}

FVlcThread::~FVlcThread()
{
	StopThread();
}

void FVlcThread::StartThread()
{
	check(!Thread);
	bIsRunning = true;
	UE_LOG(LogTemp, Warning, TEXT("Thread Start"));
	Count = 0;
	Thread = FRunnableThread::Create(this,TEXT("VlcMediaThread"));
}

bool FVlcThread::Init()
{
	// init libvlc
	const char* VlcArgs[] = {"--no-xlib"};
	VlcInstance = libvlc_new(1, VlcArgs);
	UE_LOG(LogTemp, Warning, TEXT("Thread Init"));

	return (VlcInstance != nullptr);
}

uint32 FVlcThread::Run()
{
	// open media
	VlcMedia = libvlc_media_new_location(VlcInstance,TCHAR_TO_ANSI(*VideoPath));
	VlcMediaPlayer = libvlc_media_player_new_from_media(VlcMedia);
	libvlc_media_release(VlcMedia);

	// set callbacks
	libvlc_video_set_format(VlcMediaPlayer, "RGBA", VideoWidth, VideoHeight, VideoWidth * 4);
	libvlc_video_set_callbacks(VlcMediaPlayer, &FVlcThread::VlcLock, &FVlcThread::VlcUnlock, nullptr, this);

	libvlc_media_player_play(VlcMediaPlayer);
	while (bIsRunning)
	{
		if (libvlc_media_player_is_playing(VlcMediaPlayer))
		{
			UE_LOG(LogTemp, Warning, TEXT("Video is playing and decoding frames."));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Video is not playing yet, waiting for frames..."));
		}
		FPlatformProcess::Sleep(0.2f);
	}

	return 0;
}

void FVlcThread::Stop()
{
	UE_LOG(LogTemp, Warning, TEXT("Thread Stop"));
}

void FVlcThread::Exit()
{
	UE_LOG(LogTemp, Warning, TEXT("Thread Exit"));
}

void* FVlcThread::VlcLock(void* Opaque, void** Pixels)
{
	FVlcThread* VlcThread = static_cast<FVlcThread*>(Opaque);
	if (VlcThread)
	{
		const int FrameSize = VlcThread->VideoWidth * VlcThread->VideoHeight * 4;
		VlcThread->LockedBuffer.SetNumUninitialized(FrameSize);
		*Pixels = VlcThread->LockedBuffer.GetData();
		UE_LOG(LogTemp, Warning, TEXT("lock"));
	}
	return nullptr;
}

void FVlcThread::VlcUnlock(void* Opaque, void* Picture, void* const* Planes)
{
	FVlcThread* VlcThread = static_cast<FVlcThread*>(Opaque);
	if (VlcThread && VlcThread->LockedBuffer.Num() > 0)
	{
		TArray<uint8> FrameData;
		FrameData.Append((uint8*)(*Planes), VlcThread->VideoWidth * VlcThread->VideoHeight * 4);
		VlcThread->FrameDataQueue.Enqueue(MoveTemp(FrameData));

		UE_LOG(LogTemp, Warning, TEXT("unlock"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("VlcUnlock: No locked buffer or invalid data"));
	}
}

void FVlcThread::StopThread()
{
	bIsRunning = false;
	UE_LOG(LogTemp, Warning, TEXT("Stop Thread"));

	if (VlcMediaPlayer)
	{
		libvlc_media_player_stop(VlcMediaPlayer);
		libvlc_media_player_release(VlcMediaPlayer);
		VlcMediaPlayer = nullptr;
	}

	// Empty LockedBuffer
	LockedBuffer.Empty();

	UE_LOG(LogTemp, Warning, TEXT("Empty FrameDataQueue"));
	TArray<uint8> DummyFrame;
	while (FrameDataQueue.Dequeue(DummyFrame))
	{
	}

	if (Thread)
	{
		Thread->WaitForCompletion();
		UE_LOG(LogTemp, Warning, TEXT("WaitForCompletion"));

		//Thread->Kill();
		delete Thread;
		Thread = nullptr;
	}

	UE_LOG(LogTemp, Warning, TEXT("Release VlcInstance"));

	if (VlcInstance)
	{
		libvlc_release(VlcInstance);
		VlcInstance = nullptr;
	}
}
