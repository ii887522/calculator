#ifndef II887522_CALCULATOR_BUTTON_MODEL_H
#define II887522_CALCULATOR_BUTTON_MODEL_H

#include "Point.h"
#include "Rect.h"
#include "math_ext.h"

namespace ii887522::Calculator
{
	// Not Thread Safe
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

		constexpr void reactMouseMotionWhenInitial(const Point& mousePosition)
		{
			if (!isOverlap(mousePosition, rect)) return;
			state = State::HOVERED;
			lightness = .9f;
		}
		
		constexpr void reactMouseMotionWhenHovered(const Point& mousePosition)
		{
			if (isOverlap(mousePosition, rect)) return;
			state = State::INITIAL;
			lightness = 1.f;
		}

		constexpr void reactMouseMotionWhenPressed(const Point& mousePosition)
		{
			if (isOverlap(mousePosition, rect)) return;
			state = State::INITIAL;
			lightness = 1.f;
		}

	public:
		const Rect rect;
		float lightness;

		explicit constexpr ButtonModel(const Rect& rect) : state{ State::INITIAL }, rect{ rect }, lightness{ 1.f } { }

		constexpr void reactMouseMotion(const Point& mousePosition)
		{
			switch (state)
			{
			case State::INITIAL: reactMouseMotionWhenInitial(mousePosition);
				break;
			case State::HOVERED: reactMouseMotionWhenHovered(mousePosition);
				break;
			case State::PRESSED: reactMouseMotionWhenPressed(mousePosition);
			}
		}

		constexpr void reactLeftMouseButtonDown()
		{
			if (state != State::HOVERED) return;
			state = State::PRESSED;
			lightness = .8f;
		}

		constexpr void reactLeftMouseButtonUp()
		{
			if (state != State::PRESSED) return;
			state = State::HOVERED;
			lightness = .9f;
		}

		constexpr void reactMouseLeaveWindow()
		{
			state = State::INITIAL;
			lightness = 1.f;
		}
	};
}

#endif