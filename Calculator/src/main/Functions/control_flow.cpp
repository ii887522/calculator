#include "control_flow.h"
#include <functional>

using std::function;

namespace ii887522::Calculator
{
	void loop(const unsigned int times, const function<void(const unsigned int)>& run)
	{
		for (auto i{ 0u }; i != times; ++i) run(i);
	}
}