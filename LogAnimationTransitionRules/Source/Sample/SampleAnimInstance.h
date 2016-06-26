#pragma once

#include "Animation/AnimInstance.h"
#include "SampleAnimInstance.generated.h"

// declaration of the log category used for the transition rules logs
SAMPLE_API DECLARE_LOG_CATEGORY_EXTERN(LogAnimationTransitions, Log, All);

/**
 * 
 */
UCLASS()
class SAMPLE_API USampleAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:

	UPROPERTY(Category = "Transitions", EditAnywhere, meta = (Tooltip = "Should the transition rules be logged? Will only show successful transitions."))
	bool bLogAnimationTransitions = true;

	UPROPERTY(Category = "Transitions", EditAnywhere, meta = (Tooltip = "Should it should the current state machine name on the transition logs?"))
	bool bShowStateMachineName = true;

	UPROPERTY(Category = "Transitions", BlueprintReadWrite)
	bool bLogIsDirty = false;

	// BlueprintPure so it can be used on the transition rules(no execution flow pins), BlueprintInternalUseOnly so it won't be used in regular blueprints, AnimGetter will autofill the machine and transition index
	UFUNCTION(Category = "Transitions", BlueprintPure, meta = (Tooltip = "Log transition rule. Will only show successful transitions.", BlueprintInternalUseOnly = "true", AnimGetter = "true"))
	bool LogAnimationTransition(const bool TransitionEvaluation, int32 MachineIndex, int32 TransitionIndex);
	
	
	
};
