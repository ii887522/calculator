#ifdef TEST

#include "math_ext.test.h"
#include "../main/math_ext.h"
#include "../main/Range.h"

namespace ii887522::Calculator
{
	constexpr static void testIsOverlapX()
	{
		static_assert(!isOverlapX(0, Range{ 1, 3 }));
		static_assert(isOverlapX(1, Range{ 1, 3 }));
		static_assert(isOverlapX(2, Range{ 1, 3 }));
		static_assert(!isOverlapX(3, Range{ 1, 3 }));
		static_assert(!isOverlapX(4, Range{ 1, 3 }));
		static_assert(!isOverlapX(0, Range{ 2, 5 }));
		static_assert(isOverlapX(2, Range{ 2, 5 }));
		static_assert(isOverlapX(4, Range{ 2, 5 }));
		static_assert(!isOverlapX(6, Range{ 2, 5 }));
		static_assert(!isOverlapX(8, Range{ 2, 5 }));
	}

	constexpr static void testIsOverlapY()
	{
		static_assert(!isOverlapY(0, Range{ 1, 3 }));
		static_assert(isOverlapY(1, Range{ 1, 3 }));
		static_assert(isOverlapY(2, Range{ 1, 3 }));
		static_assert(!isOverlapY(3, Range{ 1, 3 }));
		static_assert(!isOverlapY(4, Range{ 1, 3 }));
		static_assert(!isOverlapY(0, Range{ 2, 5 }));
		static_assert(isOverlapY(2, Range{ 2, 5 }));
		static_assert(isOverlapY(4, Range{ 2, 5 }));
		static_assert(!isOverlapY(6, Range{ 2, 5 }));
		static_assert(!isOverlapY(8, Range{ 2, 5 }));
	}

	constexpr static void testIsOverlap()
	{
		static_assert(!isOverlap(Point{ 0, 0 }, Rect{ Point{ 1, 1 }, Size{ 3, 3 } }));
		static_assert(!isOverlap(Point{ 2, 0 }, Rect{ Point{ 1, 1 }, Size{ 3, 3 } }));
		static_assert(isOverlap(Point{ 2, 2 }, Rect{ Point{ 1, 1 }, Size{ 3, 3 } }));
		static_assert(!isOverlap(Point{ 0, 0 }, Rect{ Point{ 2, 2 }, Size{ 5, 5 } }));
		static_assert(!isOverlap(Point{ 2, 0 }, Rect{ Point{ 2, 2 }, Size{ 5, 5 } }));
		static_assert(isOverlap(Point{ 2, 2 }, Rect{ Point{ 2, 2 }, Size{ 5, 5 } }));
	}

	constexpr static void testClamp()
	{

	}

	void testMathExt()
	{
		testIsOverlapX();
		testIsOverlapY();
		testIsOverlap();
		testClamp();
	}
}

#endif