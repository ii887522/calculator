#ifndef TEST

#include "sdl_ext.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "SDL.h"

namespace ii887522::Calculator
{
	Point getWindowPosition(SDL_Window*const window)
	{
		int x;
		int y;
		SDL_GetWindowPosition(window, &x, &y);
		return Point{ x, y };
	}

	Point getMousePosition()
	{
		int x;
		int y;
		SDL_GetMouseState(&x, &y);
		return Point{ x, y };
	}

	Size getWindowSize(SDL_Window*const window)
	{
		int w;
		int h;
		SDL_GetWindowSize(window, &w, &h);
		return Size{ w, h };
	}
}

#endif