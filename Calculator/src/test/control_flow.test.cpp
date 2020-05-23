#ifdef TEST

#include "control_flow.test.h"
#include <cassert>
#include "../main/Functions/control_flow.h"

namespace ii887522::Calculator
{
	static void testLoop()
	{
		{
			auto n{ 0 };
			loop(0u, [&](const auto) {
				++n;
			});
			assert(n == 0);
		}
		{
			auto n{ 0 };
			loop(1u, [&](const auto) {
				++n;
			});
			assert(n == 1);
		}
		{
			auto n{ 0 };
			loop(2u, [&](const auto) {
				++n;
			});
			assert(n == 2);
		}
		{
			auto n{ 0 };
			loop(2u, [&](const auto) {
				--n;
			});
			assert(n == -2);
		}
		{
			auto n{ 0 };
			loop(2u, [&](const auto i) {
				n -= i;
			});
			assert(n == -1);
		}
	}

	void testControlFlow()
	{
		testLoop();
	}
}

#endif