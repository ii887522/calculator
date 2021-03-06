#ifdef TEST

#include "math_ext.test.h"
#include <cassert>
#include "../../main/Functions/math_ext.h"
#include "../../main/Struct/Range.h"
#include "../../main/Struct/Flow.h"

namespace ii887522::Calculator
{
	constexpr static void testIsOverlapX()
	{
		static_assert(!isOverlapX(0, Range<const int>{ 1, 3 }));
		static_assert(isOverlapX(1, Range<const int>{ 1, 3 }));
		static_assert(isOverlapX(2, Range<const int>{ 1, 3 }));
		static_assert(!isOverlapX(3, Range<const int>{ 1, 3 }));
		static_assert(!isOverlapX(4, Range<const int>{ 1, 3 }));
		static_assert(!isOverlapX(0, Range<const int>{ 2, 5 }));
		static_assert(isOverlapX(2, Range<const int>{ 2, 5 }));
		static_assert(isOverlapX(4, Range<const int>{ 2, 5 }));
		static_assert(!isOverlapX(6, Range<const int>{ 2, 5 }));
		static_assert(!isOverlapX(8, Range<const int>{ 2, 5 }));
	}

	constexpr static void testIsOverlapY()
	{
		static_assert(!isOverlapY(0, Range<const int>{ 1, 3 }));
		static_assert(isOverlapY(1, Range<const int>{ 1, 3 }));
		static_assert(isOverlapY(2, Range<const int>{ 1, 3 }));
		static_assert(!isOverlapY(3, Range<const int>{ 1, 3 }));
		static_assert(!isOverlapY(4, Range<const int>{ 1, 3 }));
		static_assert(!isOverlapY(0, Range<const int>{ 2, 5 }));
		static_assert(isOverlapY(2, Range<const int>{ 2, 5 }));
		static_assert(isOverlapY(4, Range<const int>{ 2, 5 }));
		static_assert(!isOverlapY(6, Range<const int>{ 2, 5 }));
		static_assert(!isOverlapY(8, Range<const int>{ 2, 5 }));
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

	static void testClamp()
	{
		{
			unsigned int n{ 0u };
			clamp(n, Range<const unsigned int>{ 1u, 3u });
			assert(n == 1u);
		}
		{
			unsigned int n{ 1u };
			clamp(n, Range<const unsigned int>{ 1u, 3u });
			assert(n == 1u);
		}
		{
			unsigned int n{ 2u };
			clamp(n, Range<const unsigned int>{ 1u, 3u });
			assert(n == 2u);
		}
		{
			unsigned int n{ 3u };
			clamp(n, Range<const unsigned int>{ 1u, 3u });
			assert(n == 3u);
		}
		{
			unsigned int n{ 4u };
			clamp(n, Range<const unsigned int>{ 1u, 3u });
			assert(n == 3u);
		}
		{
			unsigned int n{ 0u };
			clamp(n, Range<const unsigned int>{ 2u, 6u });
			assert(n == 2u);
		}
		{
			unsigned int n{ 2u };
			clamp(n, Range<const unsigned int>{ 2u, 6u });
			assert(n == 2u);
		}
		{
			unsigned int n{ 4u };
			clamp(n, Range<const unsigned int>{ 2u, 6u });
			assert(n == 4u);
		}
		{
			unsigned int n{ 6u };
			clamp(n, Range<const unsigned int>{ 2u, 6u });
			assert(n == 6u);
		}
		{
			unsigned int n{ 8u };
			clamp(n, Range<const unsigned int>{ 2u, 6u });
			assert(n == 6u);
		}
	}

	constexpr static void testNormalize()
	{
		static_assert(normalize(1.f, Range<const float>{ 0.f, 4.f }) == .25f);
		static_assert(normalize(2.f, Range<const float>{ 0.f, 4.f }) == .5f);
		static_assert(normalize(3.f, Range<const float>{ 0.f, 4.f }) == .75f);
		static_assert(normalize(3.f, Range<const float>{ 1.f, 4.f }) == .66666667f);
		static_assert(normalize(3.f, Range<const float>{ 2.f, 4.f }) == .5f);
		static_assert(normalize(3.f, Range<const float>{ 2.f, 5.f }) == .33333333f);
		static_assert(normalize(3.f, Range<const float>{ 2.f, 6.f }) == .25f);
	}

	constexpr static void testMap()
	{
		static_assert(map(1.f, Flow<const Range<const float>>{ Range<const float>{ 0.f, 4.f }, Range<const float>{ 0.f, 2.f } }) ==
			.5f);
		static_assert(map(2.f, Flow<const Range<const float>>{ Range<const float>{ 0.f, 4.f }, Range<const float>{ 0.f, 2.f } }) ==
			1.f);
		static_assert(map(3.f, Flow<const Range<const float>>{ Range<const float>{ 0.f, 4.f }, Range<const float>{ 0.f, 2.f } }) ==
			1.5f);
		static_assert(map(3.f, Flow<const Range<const float>>{ Range<const float>{ 1.f, 4.f }, Range<const float>{ 0.f, 2.f } }) ==
			1.33333333f);
		static_assert(map(3.f, Flow<const Range<const float>>{ Range<const float>{ 2.f, 4.f }, Range<const float>{ 0.f, 2.f } }) ==
			1.f);
		static_assert(map(3.f, Flow<const Range<const float>>{ Range<const float>{ 2.f, 5.f }, Range<const float>{ 0.f, 2.f } }) ==
			.66666667f);
		static_assert(map(3.f, Flow<const Range<const float>>{ Range<const float>{ 2.f, 6.f }, Range<const float>{ 0.f, 2.f } }) ==
			.5f);
		static_assert(map(3.f, Flow<const Range<const float>>{ Range<const float>{ 2.f, 6.f }, Range<const float>{ 1.f, 2.f } }) ==
			1.25f);
		static_assert(map(3.f, Flow<const Range<const float>>{ Range<const float>{ 2.f, 6.f }, Range<const float>{ 2.f, 2.f } }) ==
			2.f);
		static_assert(map(3.f, Flow<const Range<const float>>{ Range<const float>{ 2.f, 6.f }, Range<const float>{ 2.f, 3.f } }) ==
			2.25f);
		static_assert(map(3.f, Flow<const Range<const float>>{ Range<const float>{ 2.f, 6.f }, Range<const float>{ 2.f, 4.f } }) ==
			2.5f);
	}

	void testMathExt()
	{
		testIsOverlapX();
		testIsOverlapY();
		testIsOverlap();
		testClamp();
		testNormalize();
		testMap();
	}
}

#endif