#ifndef TEST

#ifndef II887522_CALCULATOR_VIEW_H
#define II887522_CALCULATOR_VIEW_H

#include <SDL.h>
#include "Enums.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class View
	{
		// remove copy semantics
		View(const View&) = delete;
		View& operator=(const View&) = delete;

		// remove move semantics
		View(View&&) = delete;
		View& operator=(View&&) = delete;

		SDL_Renderer*const renderer;

	protected:
		constexpr SDL_Renderer* getRenderer()
		{
			return renderer;
		}

		// Param renderer: it must not be assigned to integer
		explicit View(SDL_Renderer*const renderer);

	public:
		virtual Action reactMouseMotion(const SDL_MouseMotionEvent&);
		virtual Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent&);
		virtual Pair<Action, Message> reactLeftMouseButtonUp(const SDL_MouseButtonEvent&);
		virtual Action reactMouseLeaveWindow(const SDL_WindowEvent&);
		virtual Pair<Action, Message> reactKeyDown(const SDL_KeyboardEvent&);
		virtual Action reactKeyUp(const SDL_KeyboardEvent&);
		virtual Pair<Action, Message> reactMessage(const Message&);
		virtual Action step(const unsigned int dt);
		virtual void render() = 0;
		virtual ~View();
	};
}

#endif
#endif