#ifndef TEST

#include "ContextMenu.h"
#include "../Any/Activity.h"
#include "../Any/Enums.h"
#include <SDL.h>
#include "../Struct/Pair.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	ContextMenu::ContextMenu() : Activity{ SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 88, 68,
		SDL_WINDOW_HIDDEN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALWAYS_ON_TOP | SDL_WINDOW_SKIP_TASKBAR | SDL_WINDOW_POPUP_MENU) },
		scene{ getRenderer() } { }

	Action ContextMenu::reactMessage(const Message& message)
	{
		if (message.head == Message::Head::SHOW_CONTEXT_MENU) SDL_ShowWindow(getWindow());
		return scene.reactMessage(message);
	}

	Pair<Action, Message> ContextMenu::react(const SDL_Event& event)
	{
		switch (event.type)
		{
		case SDL_MOUSEMOTION:
			if (SDL_GetWindowFlags(getWindow()) & SDL_WINDOW_INPUT_FOCUS)
				return Pair{ scene.reactMouseMotionWithFocus(event.motion), Message{ } };
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.windowID == SDL_GetWindowID(getWindow())) return Pair{ reactMouseButtonDown(event.button), Message{ } };
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.windowID == SDL_GetWindowID(getWindow())) return Pair{ reactMouseButtonUp(event.button), Message{ } };
			break;
		case SDL_WINDOWEVENT: return Pair{ reactWindowEvent(event.window), Message{ } };
		}
		return Pair{ Action::NONE, Message{ } };
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