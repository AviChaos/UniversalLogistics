#pragma once

#include "Hologram/FGConveyorAttachmentHologram.h"
#include "Hologram/FGHologramBuildModeDescriptor.h"
#include "ULAttachmentHologram.generated.h"
/**
 * Base hologram class for all Universal Logistics attachment buildables.
 *
 * This class serves as the common foundation for all future UL holograms
 * (Vertical Splitters, Vertical Mergers, Smart Logistics, etc.).
 *
 * For Sprint 4 Phase 1, all overridden functions simply defer to the
 * vanilla implementation. Custom placement logic will be introduced
 * incrementally in later phases.
 */
UCLASS(Abstract)
class UNIVERSALLOGISTICS_API AULAttachmentHologram : public AFGConveyorAttachmentHologram
{
    GENERATED_BODY()

public:

    AULAttachmentHologram();

protected:

    virtual void BeginPlay() override;

    virtual void Tick(float DeltaSeconds) override;

    /** Reverse build mode (same concept as Conveyor Lift). */
    UPROPERTY(EditDefaultsOnly, Category="Build Modes")
    TSubclassOf<UFGHologramBuildModeDescriptor> mBuildModeReverse;
    /** True when the hologram is in Reverse build mode. */
    UPROPERTY()
    bool mIsReverseMode = false;

public:

    virtual bool IsValidHitResult(const FHitResult& HitResult) const override;

    virtual bool TrySnapToActor(const FHitResult& HitResult) override;

    virtual void SetHologramLocationAndRotation(const FHitResult& HitResult) override;

    virtual void GetSupportedBuildModes_Implementation(
        TArray<TSubclassOf<UFGBuildGunModeDescriptor>>& out_buildModes
    ) const override;

    virtual void OnBuildModeChanged(
        TSubclassOf<UFGHologramBuildModeDescriptor> buildMode
    ) override;

protected:

    virtual void CheckValidPlacement() override;
    
protected:

    virtual void ConfigureComponents(AFGBuildable* inBuildable) const override;
    
    /** Updates the hologram connection directions when build mode changes. */
    virtual void UpdateConnectionDirections();
};