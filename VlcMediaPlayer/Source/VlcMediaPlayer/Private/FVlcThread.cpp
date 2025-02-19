#include "FVlcThread.h"

FVlcThread::FVlcThread(const FString& InVideoPath)
	: VideoPath(InVideoPath), Thread(nullptr), bIsRunning(false),
	  VlcInstance(nullptr), VlcMedia(nullptr), VlcMediaPlayer(nullptr),
	  VideoWidth(0), VideoHeight(0)
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
	libvlc_video_set_format(VlcMediaPlayer, "RV32", VideoWidth, VideoHeight, VideoWidth * 4);

#pragma region callbacks
	// libvlc_video_set_callbacks(
	// 	VlcMediaPlayer,
	// 	[](void* Opaque, void** Plane)-> void* {
	// 		UE_LOG(LogTemp, Warning, TEXT("lock"));
	// 		return Opaque;
	// 	}, //lock
	// 	[](void* Opaque, void* Picture, void* const* Planes)
	// 	{
	// 		FVlcThread* VlcThread = static_cast<FVlcThread*>(Opaque);
	// 		if (VlcThread && VlcThread->bIsRunning)
	// 		{
	// 			TArray<uint8> FrameData;
	// 			FrameData.Append((uint8*)Picture, VlcThread->VideoWidth * VlcThread->VideoHeight * 4);
	// 			VlcThread->FrameDataQueue.Enqueue(MoveTemp(FrameData));
	//
	// 			UE_LOG(LogTemp, Warning, TEXT("unlock"));
	// 		}
	// 	}, //unlock
	// 	nullptr, //display
	// 	this //context
	// );
#pragma endregion
	
  	libvlc_media_player_play(VlcMediaPlayer);
	while (bIsRunning)
	{
		UE_LOG(LogTemp,Warning,TEXT("Vlcthread running..."));
		FPlatformProcess::Sleep(0.2f);
	}

	// while (bIsRunning)
	// {
	// 	Count++;
	// 	UE_LOG(LogTemp, Warning, TEXT("Count: %d"), Count);
	// 	FPlatformProcess::Sleep(1.0f); // 执行间隔，防止堵塞
	// }

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

	UE_LOG(LogTemp, Warning, TEXT("Empty FrameDataQueue"));
	TArray<uint8> DummyFrame;
	while (FrameDataQueue.Dequeue(DummyFrame)) {}

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
