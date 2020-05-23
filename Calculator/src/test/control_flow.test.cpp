#ifdef TEST

#include "control_flow.test.h"
#include <cassert>
#include "../main/control_flow.h"

namespace ii887522::Calculator
{
	static void testLoop()
	{
		{
			auto n{ 0 };
			loop(0u, [&]() {
				++n;
			});
			assert(n == 0);
		}
		{
			auto n{ 0 };
			loop(1u, [&]() {
				++n;
			});
			assert(n == 1);
		}
		{
			auto n{ 0 };
			loop(2u, [&]() {
				++n;
			});
			assert(n == 2);
		}
		{
			auto n{ 0 };
			loop(2u, [&]() {
				--n;
			});
			assert(n == -2);
		}
		{
			auto n{ 0 };
			loop(2u, [&]() {
				n -= 2;
			});
			assert(n == -4);
		}
	}

	void testControlFlow()
	{
		testLoop();
	}
}

#endif