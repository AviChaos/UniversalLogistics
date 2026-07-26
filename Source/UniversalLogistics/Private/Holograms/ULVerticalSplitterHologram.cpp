#include "Holograms/ULVerticalSplitterHologram.h"


#include "FGBlueprintFunctionLibrary.h"
#include "Buildables/FGBuildable.h"
#include "Hologram/FGHologramBuildModeDescriptor.h"
#include "ULLog.h"



AULVerticalSplitterHologram::AULVerticalSplitterHologram()
{
}



bool AULVerticalSplitterHologram::IsValidHitResult(const FHitResult& HitResult) const
{
	UE_LOG(LogUniversalLogistics, Warning,
		TEXT("ULVerticalSplitterHologram::IsValidHitResult"));

	return Super::IsValidHitResult(HitResult);
}



bool AULVerticalSplitterHologram::TrySnapToActor(const FHitResult& HitResult)
{
	UE_LOG(LogUniversalLogistics, Warning,
		TEXT("ULVerticalSplitterHologram::TrySnapToActor"));

	return Super::TrySnapToActor(HitResult);
}



void AULVerticalSplitterHologram::ConfigureComponents(AFGBuildable* InBuildable) const
{
	UE_LOG(LogUniversalLogistics, Warning,
		TEXT("ULVerticalSplitterHologram::ConfigureComponents"));

	Super::ConfigureComponents(InBuildable);
}



void AULVerticalSplitterHologram::GetSupportedBuildModes_Implementation(
	TArray<TSubclassOf<UFGBuildGunModeDescriptor>>& OutBuildModes
) const
{
	Super::GetSupportedBuildModes_Implementation(OutBuildModes);


	UE_LOG(LogUniversalLogistics, Warning,
		TEXT("ULVerticalSplitterHologram::GetSupportedBuildModes"));
}

    

void AULVerticalSplitterHologram::OnBuildModeChanged(
    TSubclassOf<UFGHologramBuildModeDescriptor> BuildMode)
{

    UE_LOG(LogUniversalLogistics, Warning,
    TEXT("========== BUILD MODE CALLBACK FIRED =========="));
    
    Super::OnBuildModeChanged(BuildMode);

    UE_LOG(
        LogUniversalLogistics,
        Warning,
        TEXT("Incoming BuildMode = %s"),
        *GetNameSafe(BuildMode.Get())
    );

    UE_LOG(
        LogUniversalLogistics,
        Warning,
        TEXT("Reverse Descriptor = %s"),
        *GetNameSafe(mBuildModeReverse.Get())
    );

    mIsReverseMode = (BuildMode == mBuildModeReverse);

    UE_LOG(
        LogUniversalLogistics,
        Warning,
        TEXT("Reverse Mode = %s"),
        mIsReverseMode ? TEXT("TRUE") : TEXT("FALSE")
    );
}