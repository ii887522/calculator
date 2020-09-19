#ifdef TEST

#include "comparison.test.h"
#include <cassert>
#include "../main/Functions/comparison.h"
#include <vector>

using std::vector;

namespace ii887522::Calculator
{
	static void testEqual()
	{
		assert(equal(vector<int>{ }, vector<int>{ }));
		assert(!equal(vector<int>{ 0 }, vector<int>{ }));
		assert(!equal(vector<int>{ 0 }, vector<int>{ 1 }));
		assert(equal(vector<int>{ 1 }, vector<int>{ 1 }));
		assert(equal(vector<int>{ 1, 0 }, vector<int>{ 1, 0 }));
		assert(!equal(vector<int>{ 1, 1 }, vector<int>{ 1, 0 }));
		assert(!equal(vector<int>{ 1, 1 }, vector<int>{ 0, 1 }));
		assert(equal(vector<int>{ 1, 1 }, vector<int>{ 1, 1 }));
		assert(equal(vector<unsigned int>{ 1u, 1u }, vector<unsigned int>{ 1u, 1u }));
	}

	void testComparison()
	{
		testEqual();
	}
}

#endif