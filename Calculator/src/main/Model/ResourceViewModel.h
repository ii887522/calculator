#ifndef II887522_CALCULATOR_RESOURCE_VIEW_MODEL_H
#define II887522_CALCULATOR_RESOURCE_VIEW_MODEL_H

#include "../Any/Enums.h"

namespace ii887522::Calculator
{
	// Not Thread Safe
	class ResourceViewModel final
	{
		// remove copy semantics
		ResourceViewModel(const ResourceViewModel&) = delete;
		ResourceViewModel& operator=(const ResourceViewModel&) = delete;

		// remove move semantics
		ResourceViewModel(ResourceViewModel&&) = delete;
		ResourceViewModel& operator=(ResourceViewModel&&) = delete;

		const Ability ability;
		unsigned int a;

	public:
		explicit constexpr ResourceViewModel(const Ability ability = Ability::NONE) : ability{ ability }, a{ 255u } { }

		constexpr unsigned int getA() const
		{
			return a;
		}

		constexpr void enable()
		{
			a = 255u;
		}

		constexpr void tryDisable()
		{
			if (ability == Ability::CAN_DISABLE) a = 128u;
		}
	};
}

#endif