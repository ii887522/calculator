#ifndef TEST

#ifndef II887522_CALCULATOR_BUTTON_H
#define II887522_CALCULATOR_BUTTON_H

#include <SDL.h>
#include "ButtonModel.h"
#include "Rect.h"
#include "Point.h"
#include "Enums.h"

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

		SDL_Renderer*const renderer;
		ButtonModel viewModel;

	public:
		// Param renderer: it must not be assigned to integer
		explicit constexpr Button(SDL_Renderer*const renderer, const Rect& rect) : renderer{ renderer }, viewModel{ rect } { }

		constexpr Action reactMouseMotion(const SDL_MouseMotionEvent& motionEvent)
		{
			viewModel.reactMouseMotion(Point{ motionEvent.x, motionEvent.y });
			if (viewModel.isAnimating) return Action::START_ANIMATION;
			return Action::NONE;
		}

		constexpr Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent&)
		{
			viewModel.reactLeftMouseButtonDown();
			if (viewModel.isAnimating) return Action::START_ANIMATION;
			return Action::NONE;
		}

		constexpr Action reactLeftMouseButtonUp(const SDL_MouseButtonEvent&)
		{
			viewModel.reactLeftMouseButtonUp();
			if (viewModel.isAnimating) return Action::START_ANIMATION;
			return Action::NONE;
		}

		constexpr Action reactMouseLeaveWindow(const SDL_WindowEvent&)
		{
			viewModel.reactMouseLeaveWindow();
			if (viewModel.isAnimating) return Action::START_ANIMATION;
			return Action::NONE;
		}

		constexpr Action step(const unsigned int dt)
		{
			viewModel.step(dt);
			if (viewModel.isAnimating) return Action::NONE;
			return Action::STOP_ANIMATION;
		}

		void render();
	};
}

#endif
#endif