#include "Sample.h"
#include "SampleLogCharacter.h"

#if ENABLE_VISUAL_LOG
#include "VisualLogger.h"
#include "SampleAnimInstance.h"
#endif

// Called when the game starts or when spawned
void ASampleLogCharacter::BeginPlay()
{
	Super::BeginPlay();

#if ENABLE_VISUAL_LOG
	// find an instance of the animation blueprint
	TArray<UActorComponent*> ActorComponents = GetComponentsByClass(USkeletalMeshComponent::StaticClass());
	for (UActorComponent* ActorComponent : ActorComponents)
	{
		USkeletalMeshComponent* SkeletalMeshComponent = Cast<USkeletalMeshComponent>(ActorComponent);
		if (SkeletalMeshComponent)
		{
			SampleAnimInstance = Cast<USampleAnimInstance>(SkeletalMeshComponent->GetAnimInstance());
			if (SampleAnimInstance)
			{
				break;
			}
		}
	}
#endif
}

// Called every frame
void ASampleLogCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

#if ENABLE_VISUAL_LOG
	UE_VLOG(this, LogActor, Log, TEXT("Actor Log"));

	// if we want to do additional work with the animation blueprint
	if (SampleAnimInstance && SampleAnimInstance->bLogIsDirty)
	{
		UE_VLOG(this, LogAnimationTransitions, Warning, TEXT("Animation Transition"));
		SampleAnimInstance->bLogIsDirty = false;
	}
#endif
}


#if ENABLE_VISUAL_LOG
void ASampleLogCharacter::GrabDebugSnapshot(FVisualLogEntry* Snapshot) const
{
	const int32 CatIndex = Snapshot->Status.AddZeroed();
	FVisualLogStatusCategory& PlaceableCategory = Snapshot->Status[CatIndex];
	PlaceableCategory.Category = TEXT("Sample Character");
	// these will appear on the left panel on the visual logger
	PlaceableCategory.Add(TEXT("Location: "), GetActorLocation().ToString());
	PlaceableCategory.Add(TEXT("Rotation: "), GetActorRotation().ToString());
}
#endif



