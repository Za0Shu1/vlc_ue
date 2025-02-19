// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Public/VlcPlayerWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVlcPlayerWidget() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UWidget();
	UPackage* Z_Construct_UPackage__Script_VlcMediaPlayer();
	VLCMEDIAPLAYER_API UClass* Z_Construct_UClass_UVlcPlayerWidget();
	VLCMEDIAPLAYER_API UClass* Z_Construct_UClass_UVlcPlayerWidget_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UVlcPlayerWidget::execStopVideo)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopVideo();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVlcPlayerWidget::execPlayVideo)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_VideoPath);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PlayVideo(Z_Param_VideoPath);
		P_NATIVE_END;
	}
	void UVlcPlayerWidget::StaticRegisterNativesUVlcPlayerWidget()
	{
		UClass* Class = UVlcPlayerWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "PlayVideo", &UVlcPlayerWidget::execPlayVideo },
			{ "StopVideo", &UVlcPlayerWidget::execStopVideo },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo_Statics
	{
		struct VlcPlayerWidget_eventPlayVideo_Parms
		{
			FString VideoPath;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VideoPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_VideoPath;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo_Statics::NewProp_VideoPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo_Statics::NewProp_VideoPath = { "VideoPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VlcPlayerWidget_eventPlayVideo_Parms, VideoPath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo_Statics::NewProp_VideoPath_MetaData), Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo_Statics::NewProp_VideoPath_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo_Statics::NewProp_VideoPath,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo_Statics::Function_MetaDataParams[] = {
		{ "Category", "VLC Media Player | Control" },
		{ "ModuleRelativePath", "Public/VlcPlayerWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVlcPlayerWidget, nullptr, "PlayVideo", nullptr, nullptr, Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo_Statics::VlcPlayerWidget_eventPlayVideo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo_Statics::VlcPlayerWidget_eventPlayVideo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVlcPlayerWidget_StopVideo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVlcPlayerWidget_StopVideo_Statics::Function_MetaDataParams[] = {
		{ "Category", "VLC Media Player | Control" },
		{ "ModuleRelativePath", "Public/VlcPlayerWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVlcPlayerWidget_StopVideo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVlcPlayerWidget, nullptr, "StopVideo", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVlcPlayerWidget_StopVideo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVlcPlayerWidget_StopVideo_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UVlcPlayerWidget_StopVideo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVlcPlayerWidget_StopVideo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVlcPlayerWidget);
	UClass* Z_Construct_UClass_UVlcPlayerWidget_NoRegister()
	{
		return UVlcPlayerWidget::StaticClass();
	}
	struct Z_Construct_UClass_UVlcPlayerWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImageSize_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ImageSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VideoResolution_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_VideoResolution;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAutoPlay_MetaData[];
#endif
		static void NewProp_bAutoPlay_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoPlay;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultVideoPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_DefaultVideoPath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bRepeat_MetaData[];
#endif
		static void NewProp_bRepeat_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bRepeat;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VideoTexture_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_VideoTexture;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVlcPlayerWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_VlcMediaPlayer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVlcPlayerWidget_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVlcPlayerWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVlcPlayerWidget_PlayVideo, "PlayVideo" }, // 2303003449
		{ &Z_Construct_UFunction_UVlcPlayerWidget_StopVideo, "StopVideo" }, // 1411986312
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVlcPlayerWidget_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVlcPlayerWidget_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "VlcPlayerWidget.h" },
		{ "ModuleRelativePath", "Public/VlcPlayerWidget.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_ImageSize_MetaData[] = {
		{ "Category", "VLC Media Player | Config" },
		{ "ModuleRelativePath", "Public/VlcPlayerWidget.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_ImageSize = { "ImageSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVlcPlayerWidget, ImageSize), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_ImageSize_MetaData), Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_ImageSize_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_VideoResolution_MetaData[] = {
		{ "Category", "VLC Media Player | Config" },
		{ "ModuleRelativePath", "Public/VlcPlayerWidget.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_VideoResolution = { "VideoResolution", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVlcPlayerWidget, VideoResolution), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_VideoResolution_MetaData), Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_VideoResolution_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_bAutoPlay_MetaData[] = {
		{ "Category", "VLC Media Player | Config" },
		{ "ModuleRelativePath", "Public/VlcPlayerWidget.h" },
	};
#endif
	void Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_bAutoPlay_SetBit(void* Obj)
	{
		((UVlcPlayerWidget*)Obj)->bAutoPlay = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_bAutoPlay = { "bAutoPlay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVlcPlayerWidget), &Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_bAutoPlay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_bAutoPlay_MetaData), Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_bAutoPlay_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_DefaultVideoPath_MetaData[] = {
		{ "Category", "VLC Media Player | Config" },
		{ "ModuleRelativePath", "Public/VlcPlayerWidget.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_DefaultVideoPath = { "DefaultVideoPath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVlcPlayerWidget, DefaultVideoPath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_DefaultVideoPath_MetaData), Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_DefaultVideoPath_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_bRepeat_MetaData[] = {
		{ "Category", "VLC Media Player | Config" },
		{ "ModuleRelativePath", "Public/VlcPlayerWidget.h" },
	};
#endif
	void Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_bRepeat_SetBit(void* Obj)
	{
		((UVlcPlayerWidget*)Obj)->bRepeat = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_bRepeat = { "bRepeat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVlcPlayerWidget), &Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_bRepeat_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_bRepeat_MetaData), Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_bRepeat_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_VideoTexture_MetaData[] = {
		{ "ModuleRelativePath", "Public/VlcPlayerWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_VideoTexture = { "VideoTexture", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVlcPlayerWidget, VideoTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_VideoTexture_MetaData), Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_VideoTexture_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVlcPlayerWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_ImageSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_VideoResolution,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_bAutoPlay,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_DefaultVideoPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_bRepeat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVlcPlayerWidget_Statics::NewProp_VideoTexture,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVlcPlayerWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVlcPlayerWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVlcPlayerWidget_Statics::ClassParams = {
		&UVlcPlayerWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UVlcPlayerWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVlcPlayerWidget_Statics::PropPointers),
		0,
		0x00B000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVlcPlayerWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UVlcPlayerWidget_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVlcPlayerWidget_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVlcPlayerWidget()
	{
		if (!Z_Registration_Info_UClass_UVlcPlayerWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVlcPlayerWidget.OuterSingleton, Z_Construct_UClass_UVlcPlayerWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVlcPlayerWidget.OuterSingleton;
	}
	template<> VLCMEDIAPLAYER_API UClass* StaticClass<UVlcPlayerWidget>()
	{
		return UVlcPlayerWidget::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVlcPlayerWidget);
	UVlcPlayerWidget::~UVlcPlayerWidget() {}
	struct Z_CompiledInDeferFile_FID_Projects_UnrealProjects_TestProjects_VlcTest_Plugins_VlcMediaPlayer_Source_VlcMediaPlayer_Public_VlcPlayerWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_UnrealProjects_TestProjects_VlcTest_Plugins_VlcMediaPlayer_Source_VlcMediaPlayer_Public_VlcPlayerWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVlcPlayerWidget, UVlcPlayerWidget::StaticClass, TEXT("UVlcPlayerWidget"), &Z_Registration_Info_UClass_UVlcPlayerWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVlcPlayerWidget), 2655932950U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_UnrealProjects_TestProjects_VlcTest_Plugins_VlcMediaPlayer_Source_VlcMediaPlayer_Public_VlcPlayerWidget_h_3221302819(TEXT("/Script/VlcMediaPlayer"),
		Z_CompiledInDeferFile_FID_Projects_UnrealProjects_TestProjects_VlcTest_Plugins_VlcMediaPlayer_Source_VlcMediaPlayer_Public_VlcPlayerWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_UnrealProjects_TestProjects_VlcTest_Plugins_VlcMediaPlayer_Source_VlcMediaPlayer_Public_VlcPlayerWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
