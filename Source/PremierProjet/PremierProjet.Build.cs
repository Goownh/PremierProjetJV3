// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PremierProjet : ModuleRules
{
	public PremierProjet(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"PremierProjet",
			"PremierProjet/Variant_Platforming",
			"PremierProjet/Variant_Platforming/Animation",
			"PremierProjet/Variant_Combat",
			"PremierProjet/Variant_Combat/AI",
			"PremierProjet/Variant_Combat/Animation",
			"PremierProjet/Variant_Combat/Gameplay",
			"PremierProjet/Variant_Combat/Interfaces",
			"PremierProjet/Variant_Combat/UI",
			"PremierProjet/Variant_SideScrolling",
			"PremierProjet/Variant_SideScrolling/AI",
			"PremierProjet/Variant_SideScrolling/Gameplay",
			"PremierProjet/Variant_SideScrolling/Interfaces",
			"PremierProjet/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
