#include "Sample.h"
#include "SampleAnimInstance.h"

#include "Animation/AnimNode_StateMachine.h"
#include "Animation/AnimInstanceProxy.h"

#include "VisualLogger.h"

// declaration of the log category used for the transition rules logs
DEFINE_LOG_CATEGORY(LogAnimationTransitions);

bool USampleAnimInstance::LogAnimationTransition(const bool TransitionEvaluation, int32 MachineIndex, int32 TransitionIndex)
{
// only executed if the visual logger is available
#if ENABLE_VISUAL_LOG
	if (bLogAnimationTransitions && TransitionEvaluation)
	{
		FString StateMachineName;
		FString TransitionName;

		FAnimNode_StateMachine* MachineInstance = GetStateMachineInstance(MachineIndex);
		if (MachineInstance && MachineInstance->IsValidTransitionIndex(TransitionIndex))
		{
			if (bShowStateMachineName)
			{
				FAnimInstanceProxy& AnimInstanceProxy = GetProxyOnAnyThread<FAnimInstanceProxy>();
				IAnimClassInterface* AnimClassInterface = AnimInstanceProxy.GetAnimClassInterface();
				if (AnimClassInterface)
				{
					const FBakedAnimationStateMachine* MachineDescription = AnimInstanceProxy.GetMachineDescription(AnimClassInterface, MachineInstance);
					if (MachineDescription)
					{
						StateMachineName.Append("(");
						StateMachineName.Append(MachineDescription->MachineName.ToString());
						StateMachineName.Append(")");
					}
				}
			}

			//TransitionName = MachineInstance->GetTransitionInfo(TransitionIndex).StateName.ToString();

			FAnimationTransitionBetweenStates TransitionInfo = MachineInstance->GetTransitionInfo(TransitionIndex);
			TransitionName.Append(MachineInstance->GetStateInfo(TransitionInfo.PreviousState).StateName.ToString());
			TransitionName.Append(" to ");
			TransitionName.Append(MachineInstance->GetStateInfo(TransitionInfo.NextState).StateName.ToString());
		}

		// UE_VLOG_UELOG could also be used for normal console logging and visual logging
		UE_VLOG(this, LogAnimationTransitions, Log, TEXT("State machine %s: Transition (%s)")
			, *StateMachineName
			, *TransitionName
		);

		bLogIsDirty = true;
	}
#endif

	return TransitionEvaluation;
}




