#ifndef TEST

#include "ContextMenu.h"
#include "../Any/Activity.h"
#include "../Any/Enums.h"
#include <SDL.h>
#include "../Struct/Pair.h"
#include "../Struct/Message.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"

namespace ii887522::Calculator
{
	ContextMenu::ContextMenu(SDL_Window*const parentWindow, const Size& size) : Activity{ SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, size.w, size.h, SDL_WINDOW_HIDDEN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALWAYS_ON_TOP |
		SDL_WINDOW_SKIP_TASKBAR | SDL_WINDOW_POPUP_MENU) }, parentWindow{ parentWindow }, scene{ getRenderer(), size }
	{
		SDL_SetRenderDrawBlendMode(getRenderer(), SDL_BLENDMODE_BLEND);
	}

	void ContextMenu::reactShowMessage()
	{
		const auto parentPosition{ getWindowPosition(parentWindow) };
		const auto mousePosition{ getMousePosition() };
		SDL_SetWindowPosition(getWindow(), parentPosition.x + mousePosition.x, parentPosition.y + mousePosition.y);
		if (SDL_HasClipboardText()) scene.enable();
		else scene.tryDisable();
		SDL_ShowWindow(getWindow());
	}

	Pair<Action, Message> ContextMenu::reactMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent)
	{
		if (buttonEvent.button != SDL_BUTTON_LEFT) return Pair{ Action::NONE, Message{ } };
		const auto [action, message]{ scene.reactLeftMouseButtonUp(buttonEvent) };
		if (message.head != Message::Head::EMPTY) SDL_HideWindow(getWindow());
		return Pair{ action, message };
	}

	Action ContextMenu::reactMessage(const Message& message)
	{
		if (message.head != Message::Head::SHOW_CONTEXT_MENU) return scene.reactMessage(message);
		reactShowMessage();
		return Action::NONE;
	}

	Pair<Action, Message> ContextMenu::react(const SDL_Event& event)
	{
		switch (event.type)
		{
		case SDL_MOUSEMOTION:
			if (SDL_GetWindowFlags(getWindow()) & SDL_WINDOW_MOUSE_FOCUS)
				return Pair{ scene.reactMouseMotionWithFocus(event.motion), Message{ } };
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.windowID == SDL_GetWindowID(getWindow())) return Pair{ reactMouseButtonDown(event.button), Message{ } };
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.windowID == SDL_GetWindowID(getWindow())) return reactMouseButtonUp(event.button);
			break;
		case SDL_WINDOWEVENT:
			if (event.window.windowID == SDL_GetWindowID(getWindow())) return Pair{ reactWindowEvent(event.window), Message{ } };
		}
		return Pair{ Action::NONE, Message{ } };
	}

	Action ContextMenu::step(const unsigned int dt)
	{
		return scene.step(dt);
	}

	void ContextMenu::renderBorder()
	{
		SDL_SetRenderDrawColor(getRenderer(), 128u, 128u, 128u, 255u);
		const auto size{ getWindowSize(getWindow()) };
		const SDL_Rect rect{ 0, 0, size.w, size.h };
		SDL_RenderDrawRect(getRenderer(), &rect);
	}

	void ContextMenu::render()
	{
		scene.render();
		renderBorder();
	}

	void ContextMenu::show()
	{
		render();
		SDL_RenderPresent(getRenderer());
	}
}

#endif