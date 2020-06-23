#ifndef TEST

#include "CalcResult.h"
#include "../ResourceView/Text.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	CalcResult::CalcResult(SDL_Renderer* const renderer, const Rect& calcScreenRect, TTF_Font* const font) :
		Text{ renderer, font, Point{ calcScreenRect.position.x + calcScreenRect.size.w - /* margin right */ 10,
		calcScreenRect.position.y + calcScreenRect.size.h - /* margin bottom */ 8 }, "0" }, font{ font } { }

	void CalcResult::set(const string& value)
	{
		ResourceView::set(TTF_RenderText_Blended(font, value.c_str(), SDL_Color{ 0u, 0u, 0u, 255u }));
	}

	Message CalcResult::reactMessage(const Message& message)
	{
		viewModel.reactMessage(message);
		set(viewModel.value);
		return viewModel.message;
	}

	void CalcResult::render()
	{
		const SDL_Rect rect{ position.x - surface->w, position.y - surface->h, surface->w, surface->h };
		SDL_RenderCopy(renderer, texture, nullptr, &rect);
	}

	CalcResult::~CalcResult()
	{
		TTF_CloseFont(font);
	}
}

#endif