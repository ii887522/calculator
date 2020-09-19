#ifdef TEST

#include "ResourceViewModel.test.h"
#include <cassert>
#include "../../main/Model/ResourceViewModel.h"
#include "../../main/Any/Enums.h"

namespace ii887522::Calculator
{
	static void testEnable()
	{
		{
			ResourceViewModel resourceViewModel;
			resourceViewModel.enable();
			assert(resourceViewModel.getA() == 255u);
		}
		{
			ResourceViewModel resourceViewModel{ Ability::CAN_DISABLE };
			resourceViewModel.enable();
			assert(resourceViewModel.getA() == 255u);
		}
	}

	static void testTryDisable()
	{
		{
			ResourceViewModel resourceViewModel;
			resourceViewModel.tryDisable();
			assert(resourceViewModel.getA() == 255u);
		}
		{
			ResourceViewModel resourceViewModel{ Ability::CAN_DISABLE };
			resourceViewModel.tryDisable();
			assert(resourceViewModel.getA() == 128u);
		}
	}

	void testResourceViewModel()
	{
		testEnable();
		testTryDisable();
	}
}

#endif