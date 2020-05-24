#ifndef II887522_CALCULATOR_POINT_H
#define II887522_CALCULATOR_POINT_H

namespace ii887522::Calculator
{
	struct Point final
	{
		// remove operator= copy semantics
		Point& operator=(const Point&) = delete;

		// remove move semantics
		Point(Point&&) = delete;
		Point& operator=(Point&&) = delete;

		int x;
		int y;

		explicit constexpr Point(const int x = 0, const int y = 0) : x{ x }, y{ y } { }
		constexpr Point(const Point&) = default;
	};
}

#endif