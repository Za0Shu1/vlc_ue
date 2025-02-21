#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"
#include "vlc/vlc.h"

class FVlcThread : public FRunnable
{
public:
	FVlcThread(const FString& InVideoPath);
	virtual ~FVlcThread();

	void StartThread();
	void StopThread();

	// Frame Data (ThreadSafe)
	TQueue<TArray<uint8>> FrameDataQueue;

protected:
	// RRunnable Interface
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
	virtual void Exit() override;

private:
	FString VideoPath;

	// Thread controller
	FRunnableThread* Thread;
	FThreadSafeBool bIsRunning;

	// Libvlc instance
	libvlc_instance_t* VlcInstance;
	libvlc_media_t* VlcMedia;
	libvlc_media_player_t* VlcMediaPlayer;

	// Video param
	int32 VideoWidth;
	int32 VideoHeight;

	// Video buffer
	TArray<uint8> LockedBuffer;
	static void* VlcLock(void* Opaque,void** Pixels);
	static void VlcUnlock(void* Opaque, void* Picture, void* const* Planes);

	// test
	int32 Count;
};
