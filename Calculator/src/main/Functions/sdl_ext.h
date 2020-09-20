#ifndef TEST

#ifndef II887522_CALCULATOR_SDL_EXT_H
#define II887522_CALCULATOR_SDL_EXT_H

#include <SDL.h>
#include "../Struct/Point.h"
#include "../Struct/Size.h"

namespace ii887522::Calculator
{
	// Param window: it must not be assigned to integer
	Point getWindowPosition(SDL_Window*const window);

	Point getMousePosition();

	// Param window: it must not be assigned to integer
	Size getWindowSize(SDL_Window*const window);
}

#endif
#endif