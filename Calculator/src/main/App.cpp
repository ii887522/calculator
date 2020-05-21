#ifndef TEST

#include "App.h"
#include <SDL.h>
#include <SDL_image.h>

namespace ii887522::Calculator
{
	App::App() : window{ SDL_CreateWindow("Calcuator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 320, 480, 0u) },
		ico{ IMG_Load("res/main/calculator.png") }
	{
		SDL_SetWindowIcon(window, ico);
	}

	App::~App()
	{
		SDL_FreeSurface(ico);
		SDL_DestroyWindow(window);
	}
}

#endif