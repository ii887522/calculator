#ifndef II887522_CALCULATOR_MATH_EXT_H
#define II887522_CALCULATOR_MATH_EXT_H

#include "../Struct/Range.h"
#include "../Struct/Point.h"
#include "../Struct/Rect.h"
#include "../Struct/Flow.h"

namespace ii887522::Calculator
{
	constexpr bool isOverlapX(const int x, const Range<const int>& xRange)
	{
		return x >= xRange.min && x < xRange.max;
	}

	constexpr bool isOverlapY(const int y, const Range<const int>& yRange)
	{
		return y >= yRange.min && y < yRange.max;
	}

	constexpr bool isOverlap(const Point& point, const Rect& rect)
	{
		return isOverlapX(point.x, Range<const int>{ rect.position.x, rect.position.x + rect.size.w }) &&
			isOverlapY(point.y, Range<const int>{ rect.position.y, rect.position.y + rect.size.h });
	}

	constexpr void clamp(unsigned int& target, const Range<const unsigned int>& range)
	{
		if (target < range.min) target = range.min;
		else if (target > range.max) target = range.max;
	}

	constexpr float normalize(const float src, const Range<const float>& srcRange)
	{
		return (src - srcRange.min) / (srcRange.max - srcRange.min);
	}
}

#endif