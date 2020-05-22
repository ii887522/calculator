#ifndef II887522_CALCULATOR_BUTTON_MODEL_H
#define II887522_CALCULATOR_BUTTON_MODEL_H

#include "Point.h"
#include "Rect.h"
#include "math_ext.h"
#include "Enums.h"
#include "AnimatedFloat.h"
#include "Range.h"

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
		unsigned int elaspedTime;

		constexpr void reactMouseMotionWhenInitial(const Point& mousePosition)
		{
			if (!isOverlap(mousePosition, rect)) return;
			state = State::HOVERED;
			elaspedTime = 0u;
			lightness.start = lightness.now;
			lightness.end = .9f;
			isAnimating = true;
		}
		
		constexpr void reactMouseMotionWhenHovered(const Point& mousePosition)
		{
			if (isOverlap(mousePosition, rect)) return;
			state = State::INITIAL;
			elaspedTime = 0u;
			lightness.start = lightness.now;
			lightness.end = 1.f;
			isAnimating = true;
		}

		constexpr void reactMouseMotionWhenPressed(const Point& mousePosition)
		{
			if (isOverlap(mousePosition, rect)) return;
			state = State::INITIAL;
			elaspedTime = 0u;
			lightness.start = lightness.now;
			lightness.end = 1.f;
			isAnimating = true;
		}

	public:
		const Rect rect;
		AnimatedFloat lightness;
		bool isAnimating;

		explicit constexpr ButtonModel(const Rect& rect) : state{ State::INITIAL }, elaspedTime{ 0u }, rect{ rect }, lightness{ 1.f },
			isAnimating{ false } { }

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
			elaspedTime = 0u;
			lightness.start = lightness.now;
			lightness.end = .8f;
			isAnimating = true;
		}

		constexpr void reactLeftMouseButtonUp()
		{
			if (state != State::PRESSED) return;
			state = State::HOVERED;
			elaspedTime = 0u;
			lightness.start = lightness.now;
			lightness.end = .9f;
			isAnimating = true;
		}

		constexpr void reactMouseLeaveWindow()
		{
			state = State::INITIAL;
			elaspedTime = 0u;
			lightness.start = lightness.now;
			lightness.end = 1.f;
			isAnimating = true;
		}

		constexpr void step(const unsigned int dt)
		{
			elaspedTime += dt;
			const auto duration{ 200u };
			clamp(elaspedTime, Range<const unsigned int>{ 0u, duration });
			lightness.now = lightness.start + (lightness.end - lightness.start) * (static_cast<float>(elaspedTime) / duration);
			if (elaspedTime == duration) isAnimating = false;
		}
	};
}

#endif