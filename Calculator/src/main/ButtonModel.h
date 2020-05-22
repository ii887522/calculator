#ifndef II887522_CALCULATOR_BUTTON_MODEL_H
#define II887522_CALCULATOR_BUTTON_MODEL_H

#include "Point.h"

namespace ii887522::Calculator
{
	// 
	class ButtonModel final
	{
		enum class State : unsigned int
		{
			INITIAL, HOVERED, PRESSED
		};

		// remove copy semantics
		ButtonModel(const ButtonModel&) = delete;
		ButtonModel& operator=(const ButtonModel&) = delete;

		// remove move semantics
		ButtonModel(ButtonModel&&) = delete;
		ButtonModel& operator=(ButtonModel&&) = delete;

		State state;

	public:
		float lightness;

		// 
		explicit constexpr ButtonModel() : state{ State::INITIAL }, lightness { 1.f } { }

		constexpr void reactMouseMotion(const Point& mousePosition)
		{

		}

		constexpr void reactLeftMouseButtonDown()
		{

		}

		constexpr void reactLeftMouseButtonUp()
		{

		}

		constexpr void reactMouseLeaveWindow()
		{

		}
	};
}

#endif