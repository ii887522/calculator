#ifndef II887522_CALCULATOR_CALC_SCREEN_MODEL_H
#define II887522_CALCULATOR_CALC_SCREEN_MODEL_H

#include "../Struct/Point.h"
#include "../Struct/Message.h"
#include "../Struct/Rect.h"
#include "../Functions/math_ext.h"

namespace ii887522::Calculator
{
	// Not Thread Safe
	class CalcScreenModel final
	{
		enum class State : unsigned int
		{
			INITIAL, HOVERED, PRESSED
		};

		// remove copy semantics
		CalcScreenModel(const CalcScreenModel&) = delete;
		CalcScreenModel& operator=(const CalcScreenModel&) = delete;

		// remove move semantics
		CalcScreenModel(CalcScreenModel&&) = delete;
		CalcScreenModel& operator=(CalcScreenModel&&) = delete;

		const Rect calcResultRect;
		State state;
		Message message;

		void reactMouseMotionWhenInitial(const Point& mousePosition)
		{
			if (isOverlap(mousePosition, calcResultRect)) state = State::HOVERED;
		}

		constexpr void reactMouseMotionWhenHovered(const Point& mousePosition)
		{
			if (!isOverlap(mousePosition, calcResultRect)) state = State::INITIAL;
		}

		constexpr void reactMouseMotionWhenPressed(const Point& mousePosition)
		{
			if (!isOverlap(mousePosition, calcResultRect)) state = State::INITIAL;
		}

	public:
		explicit CalcScreenModel(const Rect& calcResultRect);

		constexpr const Message& getMessage() const
		{
			return message;
		}

		void reactMouseMotion(const Point& mousePosition)
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

		constexpr void reactRightMouseButtonDown()
		{
			if (state == State::HOVERED) state = State::PRESSED;
		}

		void reactRightMouseButtonUp()
		{
			message = Message{ };
			if (state != State::PRESSED) return;
			state = State::HOVERED;
			message = Message{ Message::Head::SHOW_CONTEXT_MENU };
		}

		constexpr void reactMouseLeaveWindow()
		{
			state = State::INITIAL;
		}
	};
}

#endif