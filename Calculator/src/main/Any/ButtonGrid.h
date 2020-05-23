#ifndef II887522_CALCULATOR_BUTTON_GRID_H
#define II887522_CALCULATOR_BUTTON_GRID_H

#include "../Struct/Point.h"
#include "../Struct/Size.h"

namespace ii887522::Calculator
{
	class ButtonGrid final
	{
		// remove copy semantics
		ButtonGrid(const ButtonGrid&) = delete;
		ButtonGrid& operator=(const ButtonGrid&) = delete;

		// remove move semantics
		ButtonGrid(ButtonGrid&&) = delete;
		ButtonGrid& operator=(ButtonGrid&&) = delete;

		const Point position;
		const int buttonMargin;
		const int cols;

	public:
		const Size buttonSize;

		explicit constexpr ButtonGrid(const Point& position = Point{ }) : position{ position }, buttonMargin{ 2 }, cols{ 4 },
			buttonSize{ 72, 48 } { }

		constexpr int getButtonX(const int i) const
		{
			return position.x + (buttonSize.w + buttonMargin) * (i % cols);
		}

		constexpr int getButtonY(const int i) const
		{
			return position.y + (buttonSize.h + buttonMargin) * (i / cols);
		}
	};
}

#endif