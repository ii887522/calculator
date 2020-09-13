#ifndef TEST

#include "ContextMenu.h"
#include "../Any/Activity.h"
#include "../Any/Enums.h"
#include <SDL.h>

namespace ii887522::Calculator
{
	ContextMenu::ContextMenu() : Activity{ SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 88, 68,
		SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALWAYS_ON_TOP | SDL_WINDOW_SKIP_TASKBAR | SDL_WINDOW_POPUP_MENU) }, scene{ getRenderer() } { }

	Action ContextMenu::react(const SDL_Event& event)
	{
		switch (event.type)
		{
		case SDL_MOUSEMOTION:
			if (SDL_GetWindowFlags(getWindow()) & SDL_WINDOW_INPUT_FOCUS) return scene.reactMouseMotionWithFocus(event.motion);
			break;
		case SDL_MOUSEBUTTONDOWN: if (event.button.windowID == SDL_GetWindowID(getWindow())) return reactMouseButtonDown(event.button);
			break;
		case SDL_MOUSEBUTTONUP: if (event.button.windowID == SDL_GetWindowID(getWindow())) return reactMouseButtonUp(event.button);
			break;
		case SDL_WINDOWEVENT: return reactWindowEvent(event.window);
		}
		return Action::NONE;
	}

	Action ContextMenu::step(const unsigned int dt)
	{
		return scene.step(dt);
	}

	void ContextMenu::renderBackground()
	{
		SDL_SetRenderDrawColor(getRenderer(), 224u, 224u, 224u, 224u);
		SDL_RenderClear(getRenderer());
	}

	void ContextMenu::render()
	{
		renderBackground();
		scene.render();
	}

	void ContextMenu::show()
	{
		render();
		SDL_RenderPresent(getRenderer());
	}
}

#endif