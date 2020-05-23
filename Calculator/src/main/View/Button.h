#ifndef TEST

#ifndef II887522_CALCULATOR_BUTTON_H
#define II887522_CALCULATOR_BUTTON_H

#include "../Any/View.h"
#include <SDL.h>
#include "../Any/ButtonModel.h"
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Any/Enums.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class Button final : public View
	{
		// remove copy semantics
		Button(const Button&) = delete;
		Button& operator=(const Button&) = delete;

		// remove move semantics
		Button(Button&&) = delete;
		Button& operator=(Button&&) = delete;

		ButtonModel viewModel;
		bool isAnimating;

	public:
		// Param renderer: it must not be assigned to integer
		explicit Button(SDL_Renderer*const renderer, const Rect& rect);

		virtual Action reactMouseMotion(const SDL_MouseMotionEvent&) override;
		virtual Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent&) override;
		virtual Action reactLeftMouseButtonUp(const SDL_MouseButtonEvent&) override;
		virtual Action reactMouseLeaveWindow(const SDL_WindowEvent&) override;
		virtual Action step(const unsigned int dt) override;
		virtual void render() override;
	};
}

#endif
#endif