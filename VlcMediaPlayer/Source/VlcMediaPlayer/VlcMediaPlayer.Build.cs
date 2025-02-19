// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class VlcMediaPlayer : ModuleRules
{
	public VlcMediaPlayer(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Add the import library
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "Release", "libvlc.lib"));
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "Release", "libvlccore.lib"));

			// Delay-load the DLL, so we can load it from the right place first
			PublicDelayLoadDLLs.Add("libvlc.dll");
			PublicDelayLoadDLLs.Add("libvlccore.dll");
			
			// Ensure that the DLL is staged along with the executable
			RuntimeDependencies.Add("$(BinaryOutputDir)/libvlc.dll",
				"$(ModuleDir)/ThirdParty/Release/libvlc.dll");
			RuntimeDependencies.Add("$(BinaryOutputDir)/libvlccore.dll",
				"$(ModuleDir)/ThirdParty/Release/libvlccore.dll");
			
			// copy icons
			RuntimeDependencies.Add(Path.Combine("$(PluginDir)", "Resources", "icons", "..."),StagedFileType.NonUFS);
			
			// Move vlc plugins dll to binary output directory
			RuntimeDependencies.Add(
				Path.Combine("$(BinaryOutputDir)","plugins"), Path.Combine("$(ModuleDir)", "ThirdParty", "Release", "plugins", "...")
			);
		}
	
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory,"ThirdParty","include"));
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"UMG",
				"RHI",
				"RenderCore"
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
