#ifndef TEST

#include "ContextMenu.h"
#include "../Any/Activity.h"
#include "../Any/Enums.h"
#include <SDL.h>

namespace ii887522::Calculator
{
	ContextMenu::ContextMenu() : Activity{ SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 64, 128,
		SDL_WINDOW_ALWAYS_ON_TOP | SDL_WINDOW_SKIP_TASKBAR | SDL_WINDOW_POPUP_MENU) } { }

	Action ContextMenu::react(const SDL_Event& event)
	{
		event;
		return Action::NONE;
	}

	Action ContextMenu::step(const unsigned int dt)
	{
		dt;
		return Action::NONE;
	}

	void ContextMenu::show()
	{

	}
}

#endif