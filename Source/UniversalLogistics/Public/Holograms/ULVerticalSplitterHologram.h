#pragma once

#include "CoreMinimal.h"
#include "FGRecipe.h"
#include "Holograms/ULAttachmentHologram.h"
#include "Hologram/FGHologramBuildModeDescriptor.h"
#include "ULVerticalSplitterHologram.generated.h"


class UFGBuildGunModeDescriptor;


UCLASS()
class UNIVERSALLOGISTICS_API AULVerticalSplitterHologram : public AULAttachmentHologram
{
	GENERATED_BODY()


public:

	AULVerticalSplitterHologram();


	virtual bool IsValidHitResult(const FHitResult& HitResult) const override;


	virtual void GetSupportedBuildModes_Implementation(
		TArray<TSubclassOf<UFGBuildGunModeDescriptor>>& OutBuildModes
	) const override;

	virtual void OnBuildModeChanged(
    TSubclassOf<UFGHologramBuildModeDescriptor> BuildMode
	) override;


	UPROPERTY(EditDefaultsOnly, Category="Universal Logistics")
	TSubclassOf<UFGRecipe> mNormalRecipe;

	UPROPERTY(EditDefaultsOnly, Category="Universal Logistics")
	TSubclassOf<UFGRecipe> mReverseRecipe;

	
protected:

	virtual bool TrySnapToActor(const FHitResult& HitResult) override;


	virtual void ConfigureComponents(AFGBuildable* InBuildable) const override;

};