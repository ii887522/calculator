#ifndef TEST

#include "MainActivity.h"
#include "../Any/Activity.h"
#include <SDL.h>
#include <SDL_image.h>
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"
#include "../Any/Enums.h"
#include "../Functions/sdl_ext.h"

namespace ii887522::Calculator
{
	MainActivity::MainActivity(SDL_Window*const window) : Activity{ window }, ico{ IMG_Load("res/main/calculator.png") },
		scene{ getRenderer(), getWindowSize(window) }
	{
		SDL_SetWindowIcon(getWindow(), ico);
		SDL_SetRenderDrawBlendMode(getRenderer(), SDL_BLENDMODE_BLEND);
	}

	Pair<Action, Message> MainActivity::reactMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent)
	{
		switch (buttonEvent.button)
		{
		case SDL_BUTTON_LEFT: return Pair{ scene.reactLeftMouseButtonUp(buttonEvent), Message{ } };
		case SDL_BUTTON_RIGHT: return scene.reactRightMouseButtonUp(buttonEvent);
		}
		return Pair{ Action::NONE, Message{ } };
	}

	Pair<Action, Message> MainActivity::react(const SDL_Event& event)
	{
		switch (event.type)
		{
		case SDL_MOUSEMOTION:
			return Pair{ SDL_GetWindowFlags(getWindow()) & SDL_WINDOW_INPUT_FOCUS ?
				scene.reactMouseMotionWithFocus(event.motion) : scene.reactMouseMotionWithoutFocus(event.motion), Message{ } };
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.windowID == SDL_GetWindowID(getWindow())) return Pair{ reactMouseButtonDown(event.button), Message{ } };
			break;
		case SDL_MOUSEBUTTONUP: if (event.button.windowID == SDL_GetWindowID(getWindow())) return reactMouseButtonUp(event.button);
			break;
		case SDL_WINDOWEVENT: return Pair{ reactWindowEvent(event.window), Message{ } };
		case SDL_KEYDOWN: if (event.key.windowID == SDL_GetWindowID(getWindow())) return Pair{ scene.reactKeyDown(event.key), Message{ } };
			break;
		case SDL_KEYUP: if (event.key.windowID == SDL_GetWindowID(getWindow())) return Pair{ scene.reactKeyUp(event.key), Message{ } };
		}
		return Pair{ Action::NONE, Message{ } };
	}

	Action MainActivity::step(const unsigned int dt)
	{
		return scene.step(dt);
	}

	void MainActivity::renderBackground()
	{
		SDL_SetRenderDrawColor(getRenderer(), 192u, 192u, 192u, 255u);
		SDL_RenderClear(getRenderer());
	}

	void MainActivity::render()
	{
		renderBackground();
		scene.render();
	}

	void MainActivity::show()
	{
		render();
		SDL_RenderPresent(getRenderer());
	}

	MainActivity::~MainActivity()
	{
		SDL_FreeSurface(ico);
	}
}

#endif