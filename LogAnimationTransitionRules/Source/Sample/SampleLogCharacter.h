#pragma once

#if ENABLE_VISUAL_LOG
#include "VisualLogger/VisualLoggerDebugSnapshotInterface.h"
#endif	

#include "SampleCharacter.h"
#include "SampleLogCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLE_API ASampleLogCharacter : public ASampleCharacter, public IVisualLoggerDebugSnapshotInterface
{
	GENERATED_BODY()

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

#if ENABLE_VISUAL_LOG
	/** Appends information about this actor to the visual logger */
	virtual void GrabDebugSnapshot(FVisualLogEntry* Snapshot) const override;

private:
	class USampleAnimInstance* SampleAnimInstance = nullptr;
#endif
	
};
