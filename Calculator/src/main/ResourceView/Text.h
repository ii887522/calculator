#ifndef TEST

#ifndef II887522_CALCULATOR_TEXT_H
#define II887522_CALCULATOR_TEXT_H

#include "../View/ResourceView.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "../Struct/Point.h"

using std::string;

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	struct Text final : public ResourceView
	{
		// remove copy semantics
		Text(const Text&) = delete;
		Text& operator=(const Text&) = delete;

		// remove move semantics
		Text(Text&&) = delete;
		Text& operator=(Text&&) = delete;

		// Param renderer: it must not be assigned to integer
		// Param font: it must not be assigned to integer
		explicit Text(SDL_Renderer*const renderer, TTF_Font*const font, const string& value, const Point& position = Point{ });
	};
}

#endif
#endif