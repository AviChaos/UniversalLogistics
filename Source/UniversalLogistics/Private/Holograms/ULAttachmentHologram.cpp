#include "Holograms/ULAttachmentHologram.h"
#include "ULLog.h"

AULAttachmentHologram::AULAttachmentHologram()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AULAttachmentHologram::BeginPlay()
{
    UE_LOG(LogUniversalLogistics, Warning, TEXT("ULAttachmentHologram::BeginPlay"));

    Super::BeginPlay();
}

void AULAttachmentHologram::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    UE_LOG(LogUniversalLogistics, VeryVerbose, TEXT("Tick"));
}

bool AULAttachmentHologram::IsValidHitResult(const FHitResult& HitResult) const
{
    UE_LOG(LogUniversalLogistics, Warning, TEXT("IsValidHitResult"));

    return Super::IsValidHitResult(HitResult);
}

bool AULAttachmentHologram::TrySnapToActor(const FHitResult& HitResult)
{
    UE_LOG(LogUniversalLogistics, Warning,
        TEXT("TrySnapToActor - Reverse=%s"),
        mIsReverseMode ? TEXT("ON") : TEXT("OFF"));

    const bool bResult = Super::TrySnapToActor(HitResult);

    UE_LOG(LogUniversalLogistics, Warning,
        TEXT("TrySnapToActor Result=%s"),
        bResult ? TEXT("TRUE") : TEXT("FALSE"));

    UE_LOG(LogUniversalLogistics, Warning,
        TEXT("Hit Actor: %s"),
        HitResult.GetActor() ? *HitResult.GetActor()->GetName() : TEXT("None"));

    return bResult;
}

void AULAttachmentHologram::SetHologramLocationAndRotation(const FHitResult& HitResult)
{
    UE_LOG(LogUniversalLogistics, Warning,
        TEXT("SetHologramLocationAndRotation - Reverse=%s"),
        mIsReverseMode ? TEXT("ON") : TEXT("OFF"));

    Super::SetHologramLocationAndRotation(HitResult);
}

void AULAttachmentHologram::GetSupportedBuildModes_Implementation(
    TArray<TSubclassOf<UFGBuildGunModeDescriptor>>& out_buildModes) const
{
    // Keep every vanilla mode
    Super::GetSupportedBuildModes_Implementation(out_buildModes);

    // Add Reverse if assigned in Blueprint
    if (mBuildModeReverse)
    {
        out_buildModes.AddUnique(mBuildModeReverse);
    }
}

void AULAttachmentHologram::OnBuildModeChanged(
    TSubclassOf<UFGHologramBuildModeDescriptor> buildMode)
{
    Super::OnBuildModeChanged(buildMode);

    mIsReverseMode = (buildMode == mBuildModeReverse);

    UpdateConnectionDirections();

    UE_LOG(
        LogUniversalLogistics,
        Warning,
        TEXT("Reverse Mode: %s"),
        mIsReverseMode ? TEXT("ON") : TEXT("OFF")
    );
}

void AULAttachmentHologram::CheckValidPlacement()
{
    UE_LOG(LogUniversalLogistics, Warning,
        TEXT("UL Custom Placement Validation"));

    // Intentionally bypass Coffee Stain validation.
}

void AULAttachmentHologram::ConfigureComponents(AFGBuildable* inBuildable) const
{
    Super::ConfigureComponents(inBuildable);

    UE_LOG(LogUniversalLogistics,
        Warning,
        TEXT("ConfigureComponents called"));
}

void AULAttachmentHologram::UpdateConnectionDirections()
{
    UE_LOG(LogUniversalLogistics,
        Warning,
        TEXT("UpdateConnectionDirections()"));
}