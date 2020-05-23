#ifndef TEST

#ifndef II887522_CALCULATOR_VIEW_H
#define II887522_CALCULATOR_VIEW_H

#include <SDL.h>
#include "Enums.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	struct View
	{
		// remove copy semantics
		View(const View&) = delete;
		View& operator=(const View&) = delete;

		// remove move semantics
		View(View&&) = delete;
		View& operator=(View&&) = delete;

		virtual Action reactMouseMotion(const SDL_MouseMotionEvent&);
		virtual Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent&);
		virtual Action reactLeftMouseButtonUp(const SDL_MouseButtonEvent&);
		virtual Action reactMouseLeaveWindow(const SDL_WindowEvent&);
		virtual Action step(const unsigned int dt);
		virtual void render() = 0;
		virtual ~View();

	protected:
		SDL_Renderer*const renderer;

		// Param renderer: it must not be assigned to integer
		explicit View(SDL_Renderer*const renderer);
	};
}

#endif
#endif