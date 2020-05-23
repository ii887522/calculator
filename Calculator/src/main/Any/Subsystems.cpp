#ifndef TEST

#include "Subsystems.h"
#include <SDL.h>
#include <SDL_image.h>

namespace ii887522::Calculator
{
	Subsystems::Subsystems()
	{
		SDL_Init(SDL_INIT_VIDEO);
		IMG_Init(IMG_INIT_PNG);
	}

	Subsystems::~Subsystems()
	{
		IMG_Quit();
		SDL_Quit();
	}
}

#endif