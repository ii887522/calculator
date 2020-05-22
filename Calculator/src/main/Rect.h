#ifndef II887522_CALCULATOR_RECT_H
#define II887522_CALCULATOR_RECT_H

#include "Point.h"
#include "Size.h"

namespace ii887522::Calculator
{
	struct Rect final
	{
		// remove operator= copy semantics
		Rect& operator=(const Rect&) = delete;

		// remove move semantics
		Rect(Rect&&) = delete;
		Rect& operator=(Rect&&) = delete;

		const Point position;
		const Size size;

		explicit constexpr Rect(const Point& position = Point{ }, const Size& size = Size{ }) : position{ position }, size{ size } { }
		constexpr Rect(const Rect&) = default;
	};
}

#endif