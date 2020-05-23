#ifndef TEST

#include "App.h"
#include <SDL.h>
#include <SDL_image.h>
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "Enums.h"

namespace ii887522::Calculator
{
	App::App(const Size& size) : window{ SDL_CreateWindow("Calcuator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.w, size.h,
		0u) }, ico{ IMG_Load("res/main/calculator.png") }, renderer{ SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE) },
		scene{ renderer, size }
	{
		SDL_SetWindowIcon(window, ico);
		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	}

	Action App::step(const unsigned int dt)
	{
		return scene.step(dt);
	}

	void App::renderBackground()
	{
		SDL_SetRenderDrawColor(renderer, 192u, 192u, 192u, 255u);
		SDL_RenderClear(renderer);
	}

	void App::render()
	{
		renderBackground();
		scene.render();
	}

	void App::show()
	{
		render();
		SDL_RenderPresent(renderer);
	}

	App::~App()
	{
		SDL_DestroyRenderer(renderer);
		SDL_FreeSurface(ico);
		SDL_DestroyWindow(window);
	}
}

#endif