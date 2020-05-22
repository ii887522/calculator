#ifndef TEST

#ifndef II887522_CALCULATOR_BUTTON_H
#define II887522_CALCULATOR_BUTTON_H

#include <SDL.h>
#include "ButtonModel.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class Button final
	{
		// remove copy semantics
		Button(const Button&) = delete;
		Button& operator=(const Button&) = delete;

		// remove move semantics
		Button(Button&&) = delete;
		Button& operator=(Button&&) = delete;

		ButtonModel viewModel;

	public:
		// 
		explicit constexpr Button() { }

		constexpr void reactMouseMotion(const SDL_MouseMotionEvent& motionEvent)
		{
			motionEvent;
		}

		constexpr void reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent)
		{
			buttonEvent;
		}

		constexpr void reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent)
		{
			buttonEvent;
		}

		constexpr void reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent)
		{
			windowEvent;
		}

		// Param renderer: it must not be assigned to integer
		void render(SDL_Renderer*const renderer);
	};
}

#endif
#endif