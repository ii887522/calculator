#ifndef TEST

#include "Text.h"
#include "../View/ResourceView.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "../Struct/Point.h"

using std::string;

namespace ii887522::Calculator
{
	Text::Text(SDL_Renderer*const renderer, TTF_Font*const font, const string& value, const Point& position) :
		ResourceView{ renderer, TTF_RenderText_Blended(font, value.c_str(), SDL_Color{ 0u, 0u, 0u, 255u }), position } { }
}

#endif