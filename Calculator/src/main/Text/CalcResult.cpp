#ifndef TEST

#include "CalcResult.h"
#include "../ResourceView/Text.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Message.h"
#include "../Struct/Pair.h"
#include "../Any/Enums.h"

namespace ii887522::Calculator
{
	CalcResult::CalcResult(SDL_Renderer*const renderer, const Rect& calcScreenRect, const unsigned int maxSizeIgnoreDash,
		TTF_Font*const font) : Text{ renderer, font, Point{ calcScreenRect.position.x + calcScreenRect.size.w - /* margin right */ 10,
		calcScreenRect.position.y + calcScreenRect.size.h - /* margin bottom */ 8 }, "0" }, font{ font }, viewModel{ maxSizeIgnoreDash }
		{ }

	void CalcResult::set(const string& value)
	{
		ResourceView::set(TTF_RenderText_Blended(font, value.c_str(), SDL_Color{ 0u, 0u, 0u, 255u }));
	}

	Pair<Action, Message> CalcResult::reactMessage(const Message& message)
	{
		if (message.head == Message::Head::COPY_FROM_CALC_RESULT)
		{
			SDL_SetClipboardText(viewModel.getValue().c_str());
			return Pair{ Action::NONE, Message{ } };
		}
		viewModel.reactMessage(message);
		set(viewModel.getValue());
		return Pair{ Action::NONE, viewModel.getMessage() };
	}

	void CalcResult::render()
	{
		const SDL_Rect rect{ getPosition().x - getSurface()->w, getPosition().y - getSurface()->h, getSurface()->w, getSurface()->h };
		SDL_RenderCopy(getRenderer(), getTexture(), nullptr, &rect);
	}

	CalcResult::~CalcResult()
	{
		TTF_CloseFont(font);
	}
}

#endif