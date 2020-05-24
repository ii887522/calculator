#ifndef TEST

#include "View.h"
#include <SDL.h>
#include "Enums.h"

namespace ii887522::Calculator
{
	View::View(SDL_Renderer*const renderer) : renderer{ renderer } { }
	
	Action View::reactMouseMotion(const SDL_MouseMotionEvent&)
	{
		return Action::NONE;
	}
	
	Action View::reactLeftMouseButtonDown(const SDL_MouseButtonEvent&)
	{
		return Action::NONE;
	}

	Action View::reactLeftMouseButtonUp(const SDL_MouseButtonEvent&)
	{
		return Action::NONE;
	}

	Action View::reactMouseLeaveWindow(const SDL_WindowEvent&)
	{
		return Action::NONE;
	}

	Action View::reactKeyDown(const SDL_KeyboardEvent&)
	{
		return Action::NONE;
	}

	Action View::reactKeyUp(const SDL_KeyboardEvent&)
	{
		return Action::NONE;
	}

	Action View::step(const unsigned int)
	{
		return Action::NONE;
	}

	View::~View() { }
}

#endif