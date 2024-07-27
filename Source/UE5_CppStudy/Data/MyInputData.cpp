#include "MyInputData.h"

const UInputAction* UMyInputData::FindInputActionByTag(const FGameplayTag& InputTag) const
{
	for (const FMyInputAction& Action : InputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}

	return nullptr;
}
