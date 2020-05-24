#ifndef TEST

#include "CalcScreen.h"
#include "../Any/View.h"
#include <SDL.h>
#include "../Struct/Rect.h"

namespace ii887522::Calculator
{
	CalcScreen::CalcScreen(SDL_Renderer*const renderer, const Rect& rect) : View{ renderer }, rect{ rect } { }

	void CalcScreen::render()
	{
		SDL_SetRenderDrawColor(renderer, 192u, 192u, 192u, 255u);
		const SDL_Rect sdl_rect{ rect.position.x, rect.position.y, rect.size.w, rect.size.h };
		SDL_RenderFillRect(renderer, &sdl_rect);
	}
}

#endif