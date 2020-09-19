#ifdef TEST

#include "Point.test.h"
#include "../../main/Struct/Point.h"

namespace ii887522::Calculator
{
	constexpr static void testEqual()
	{
		static_assert(!Point{ 0, 0 }.operator==(Point{ 1, 1 }));
		static_assert(!Point{ 1, 0 }.operator==(Point{ 1, 1 }));
		static_assert(Point{ 1, 1 }.operator==(Point{ 1, 1 }));
		static_assert(!Point{ 2, 2 }.operator==(Point{ 1, 1 }));
		static_assert(!Point{ 2, 2 }.operator==(Point{ 2, 1 }));
		static_assert(Point{ 2, 2 }.operator==(Point{ 2, 2 }));
	}

	void testPoint()
	{
		testEqual();
	}
}

#endif