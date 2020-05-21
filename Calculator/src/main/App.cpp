#ifndef TEST

#include "App.h"
#include <SDL.h>

namespace ii887522::Calculator
{
	App::App() : window{ SDL_CreateWindow("Calcuator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 320, 480, 0u) } { }

	App::~App()
	{
		SDL_DestroyWindow(window);
	}
}

#endif