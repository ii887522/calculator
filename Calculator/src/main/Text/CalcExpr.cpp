#ifndef TEST

#include "CalcExpr.h"
#include "../ResourceView/Text.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "../Struct/Rect.h"
#include "../Struct/Point.h"

namespace ii887522::Calculator
{
	CalcExpr::CalcExpr(SDL_Renderer*const renderer, const Rect& calcScreenRect, TTF_Font*const font) :
		Text{ renderer, font, Point{ calcScreenRect.position.x + calcScreenRect.size.w - /* margin right */ 18,
		calcScreenRect.position.y + /* margin top */ 2 } }, font{ font } { }

	void CalcExpr::render()
	{
		const SDL_Rect rect{ position.x - surface->w, position.y, surface->w, surface->h };
		SDL_RenderCopy(renderer, texture, nullptr, &rect);
	}

	CalcExpr::~CalcExpr()
	{
		TTF_CloseFont(font);
	}
}

#endif