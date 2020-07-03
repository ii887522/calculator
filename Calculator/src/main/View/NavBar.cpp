#ifndef TEST

#include "NavBar.h"
#include "../Any/View.h"
#include <SDL.h>
#include "../Struct/Size.h"

namespace ii887522::Calculator
{
	NavBar::NavBar(SDL_Renderer*const renderer, const Size& size) : View{ renderer }, size{ size } { }

	void NavBar::render()
	{
		SDL_SetRenderDrawColor(renderer, 192u, 192u, 192u, 255u);
		const SDL_Rect rect{ 0, 0, size.w, size.h };
		SDL_RenderFillRect(renderer, &rect);
	}
}

#endif