#ifndef TEST

#ifndef II887522_CALCULATOR_BUTTON_H
#define II887522_CALCULATOR_BUTTON_H

#include <SDL.h>
#include "ButtonModel.h"
#include "Rect.h"
#include "Point.h"

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
		explicit constexpr Button(const Rect& rect) : viewModel{ rect } { }

		constexpr void reactMouseMotion(const SDL_MouseMotionEvent& motionEvent)
		{
			viewModel.reactMouseMotion(Point{ motionEvent.x, motionEvent.y });
		}

		constexpr void reactLeftMouseButtonDown(const SDL_MouseButtonEvent&)
		{
			viewModel.reactLeftMouseButtonDown();
		}

		constexpr void reactLeftMouseButtonUp(const SDL_MouseButtonEvent&)
		{
			viewModel.reactLeftMouseButtonUp();
		}

		constexpr void reactMouseLeaveWindow(const SDL_WindowEvent&)
		{
			viewModel.reactMouseLeaveWindow();
		}

		// Param renderer: it must not be assigned to integer
		void render(SDL_Renderer*const renderer);
	};
}

#endif
#endif