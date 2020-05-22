#ifndef II887522_CALCULATOR_MATH_EXT_H
#define II887522_CALCULATOR_MATH_EXT_H

#include "Range.h"
#include "Point.h"
#include "Rect.h"

namespace ii887522::Calculator
{
	constexpr bool isOverlapX(const int x, const Range& xRange)
	{
		return x >= xRange.min && x < xRange.max;
	}

	constexpr bool isOverlapY(const int y, const Range& yRange)
	{
		return y >= yRange.min && y < yRange.max;
	}

	constexpr bool isOverlap(const Point& point, const Rect& rect)
	{
		return isOverlapX(point.x, Range{ rect.position.x, rect.position.x + rect.size.w }) &&
			isOverlapY(point.y, Range{ rect.position.y, rect.position.y + rect.size.h });
	}
}

#endif