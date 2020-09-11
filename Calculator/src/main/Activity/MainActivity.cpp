#ifndef TEST

#include "MainActivity.h"
#include "../Any/Activity.h"
#include <SDL.h>
#include <SDL_image.h>
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "../Any/Enums.h"

namespace ii887522::Calculator
{
	MainActivity::MainActivity(const Size& size) : Activity{ SDL_CreateWindow("Calcuator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		size.w, size.h, 0u) }, ico{ IMG_Load("res/main/calculator.png") }, scene{ getRenderer(), size }
	{
		SDL_SetWindowIcon(getWindow(), ico);
		SDL_SetRenderDrawBlendMode(getRenderer(), SDL_BLENDMODE_BLEND);
	}

	Action MainActivity::react(const SDL_Event& event)
	{
		switch (event.type)
		{
		case SDL_MOUSEMOTION:
			return SDL_GetWindowFlags(getWindow()) & SDL_WINDOW_INPUT_FOCUS ?
				scene.reactMouseMotionWithFocus(event.motion) : scene.reactMouseMotionWithoutFocus(event.motion);
		case SDL_MOUSEBUTTONDOWN: if (event.button.windowID == SDL_GetWindowID(getWindow())) return reactMouseButtonDown(event.button);
			break;
		case SDL_MOUSEBUTTONUP: if (event.button.windowID == SDL_GetWindowID(getWindow())) return reactMouseButtonUp(event.button);
			break;
		case SDL_WINDOWEVENT: return reactWindowEvent(event.window);
		case SDL_KEYDOWN: if (event.key.windowID == SDL_GetWindowID(getWindow())) return scene.reactKeyDown(event.key);
			break;
		case SDL_KEYUP: if (event.key.windowID == SDL_GetWindowID(getWindow())) return scene.reactKeyUp(event.key);
		}
		return Action::NONE;
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