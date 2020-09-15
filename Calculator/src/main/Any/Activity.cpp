#ifndef TEST

#include "Activity.h"
#include <SDL.h>
#include "../Struct/Message.h"
#include "../Any/Enums.h"

namespace ii887522::Calculator
{
	Activity::Activity(SDL_Window*const window) : window{ window }, renderer{ SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE) } { }

	Activity::~Activity()
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
	}
}

#endif