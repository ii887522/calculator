#ifndef II887522_CALCULATOR_BUTTON_MODEL_H
#define II887522_CALCULATOR_BUTTON_MODEL_H

#include "../Struct/Point.h"
#include "../Struct/Rect.h"
#include "../Functions/math_ext.h"
#include "Enums.h"
#include "../Struct/AnimatedFloat.h"
#include "../Struct/Range.h"
#include <SDL.h>
#include "../Struct/Message.h"

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
		const Message _message;
		const SDL_Keycode keyCode;

		constexpr void reactMouseMotionWhenInitial(const Point& mousePosition)
		{
			if (!isOverlap(mousePosition, rect)) return;
			state = State::HOVERED;
			elaspedTime = 0u;
			lightness.start = lightness.now;
			lightness.end = .9f;
			borderA.start = borderA.now;
			borderA.end = 255.f;
			isAnimating = true;
		}
		
		constexpr void reactMouseMotionWhenHovered(const Point& mousePosition)
		{
			if (isOverlap(mousePosition, rect)) return;
			state = State::INITIAL;
			elaspedTime = 0u;
			lightness.start = lightness.now;
			lightness.end = 1.f;
			borderA.start = borderA.now;
			borderA.end = 0.f;
			isAnimating = true;
		}

		constexpr void reactMouseMotionWhenPressed(const Point& mousePosition)
		{
			if (isOverlap(mousePosition, rect)) return;
			state = State::INITIAL;
			elaspedTime = 0u;
			lightness.start = lightness.now;
			lightness.end = 1.f;
			borderA.start = borderA.now;
			borderA.end = 0.f;
			isAnimating = true;
		}

	public:
		const Rect rect;
		AnimatedFloat lightness;
		AnimatedFloat borderA;
		bool isAnimating;
		Message message;

		explicit ButtonModel(const Rect& rect, const Message& message = Message{ }, const SDL_Keycode keyCode = SDLK_UNKNOWN);

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
			borderA.start = borderA.now;
			borderA.end = 255.f;
			isAnimating = true;
		}

		void reactLeftMouseButtonUp();

		constexpr void reactMouseLeaveWindow()
		{
			state = State::INITIAL;
			elaspedTime = 0u;
			lightness.start = lightness.now;
			lightness.end = 1.f;
			borderA.start = borderA.now;
			borderA.end = 0.f;
			isAnimating = true;
		}

		void reactKeyDown(const SDL_Keycode);

		constexpr void reactKeyUp(const SDL_Keycode p_keyCode)
		{
			if (keyCode != p_keyCode) return;
			state = State::INITIAL;
			elaspedTime = 0u;
			lightness.start = lightness.now;
			lightness.end = 1.f;
			borderA.start = borderA.now;
			borderA.end = 0.f;
			isAnimating = true;
		}

		constexpr void step(const unsigned int dt)
		{
			elaspedTime += dt;
			const auto duration{ 200u };
			clamp(elaspedTime, Range<const unsigned int>{ 0u, duration });
			lightness.now = lightness.start + (lightness.end - lightness.start) * (static_cast<float>(elaspedTime) / duration);
			borderA.now = borderA.start + (borderA.end - borderA.start) * (static_cast<float>(elaspedTime) / duration);
			if (elaspedTime == duration) isAnimating = false;
		}
	};
}

#endif