#ifdef TEST

#include "string_ext.test.h"
#include <cassert>
#include "../main/Functions/string_ext.h"

namespace ii887522::Calculator
{
	static void testNegate()
	{
		assert(-string{ "0" } == "0");
		assert(-string{ "1" } == "-1");
		assert(-string{ "2" } == "-2");
		assert(-string{ "-2" } == "2");
		assert(-string{ "-20" } == "20");
		assert(-string{ "-21" } == "21");
		assert(-string{ "-31" } == "31");
		assert(-string{ "-310" } == "310");
		assert(-string{ "310" } == "-310");
	}

	void testStringExt()
	{
		testNegate();
	}
}

#endif