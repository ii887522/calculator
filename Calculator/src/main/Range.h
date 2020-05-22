#ifndef II887522_CALCULATOR_RANGE_H
#define II887522_CALCULATOR_RANGE_H

namespace ii887522::Calculator
{
	struct Range final
	{
		// remove copy semantics
		Range(const Range&) = delete;
		Range& operator=(const Range&) = delete;

		// remove move semantics
		Range(Range&&) = delete;
		Range& operator=(Range&&) = delete;

		const int min;
		const int max;

		explicit constexpr Range(const int min = 0, const int max = 0) : min{ min }, max{ max } { }
	};
}

#endif