#ifndef II887522_CALCULATOR_RANGE_H
#define II887522_CALCULATOR_RANGE_H

namespace ii887522::Calculator
{
	template <typename T> struct Range final
	{
		// remove operator= copy semantics
		Range& operator=(const Range&) = delete;

		// remove move semantics
		Range(Range&&) = delete;
		Range& operator=(Range&&) = delete;

		const T min;
		const T max;

		explicit constexpr Range(const T& min, const T& max) : min{ min }, max{ max } { }
		constexpr Range(const Range&) = default;
	};
}

#endif