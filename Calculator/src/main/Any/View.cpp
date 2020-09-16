#ifndef TEST

#include "View.h"
#include <SDL.h>
#include "Enums.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	View::View(SDL_Renderer*const renderer) : renderer{ renderer } { }

	void View::enable() { }
	void View::tryDisable() { }

	Action View::reactMouseMotion(const SDL_MouseMotionEvent&)
	{
		return Action::NONE;
	}

	Action View::reactLeftMouseButtonDown(const SDL_MouseButtonEvent&)
	{
		return Action::NONE;
	}

	Pair<Action, Message> View::reactLeftMouseButtonUp(const SDL_MouseButtonEvent&)
	{
		return Pair{ Action::NONE, Message{ } };
	}

	Action View::reactRightMouseButtonDown(const SDL_MouseButtonEvent&)
	{
		return Action::NONE;
	}

	Pair<Action, Message> View::reactRightMouseButtonUp(const SDL_MouseButtonEvent&)
	{
		return Pair{ Action::NONE, Message{ } };
	}

	Action View::reactMouseLeaveWindow(const SDL_WindowEvent&)
	{
		return Action::NONE;
	}

	Pair<Action, Message> View::reactKeyDown(const SDL_KeyboardEvent&)
	{
		return Pair{ Action::NONE, Message{ } };
	}

	Action View::reactKeyUp(const SDL_KeyboardEvent&)
	{
		return Action::NONE;
	}

	Pair<Action, Message> View::reactMessage(const Message&)
	{
		return Pair{ Action::NONE, Message{ } };
	}

	Action View::step(const unsigned int)
	{
		return Action::NONE;
	}

	View::~View() { }
}

#endif