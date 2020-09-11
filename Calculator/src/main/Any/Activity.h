#ifndef TEST

#ifndef II887522_CALCULATOR_ACTIVITY_H
#define II887522_CALCULATOR_ACTIVITY_H

#include <SDL.h>
#include "../Any/Enums.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class Activity
	{
		// remove copy semantics
		Activity(const Activity&) = delete;
		Activity& operator=(const Activity&) = delete;

		// remove move semantics
		Activity(Activity&&) = delete;
		Activity& operator=(Activity&&) = delete;

		SDL_Window*const window;
		SDL_Renderer*const renderer;

	protected:
		// Param window: it must not be assigned to integer
		explicit Activity(SDL_Window*const window);

		constexpr SDL_Window* getWindow() const
		{
			return window;
		}

		constexpr SDL_Renderer* getRenderer() const
		{
			return renderer;
		}

	public:
		virtual Action react(const SDL_Event&) = 0;
		virtual Action step(const unsigned int dt) = 0;
		virtual void show() = 0;
		virtual ~Activity();
	};
}

#endif
#endif