#ifndef TEST

#include "CalcExpr.h"
#include "../ResourceView/Text.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Message.h"
#include <algorithm>

using std::min;
using std::max;

namespace ii887522::Calculator
{
	CalcExpr::CalcExpr(SDL_Renderer*const renderer, const Rect& calcScreenRect, const unsigned int maxSizeIgnoreDash,
		const int horizontalMargin, TTF_Font*const font) : Text{ renderer, font, Point{ calcScreenRect.position.x + calcScreenRect.size.w
			- horizontalMargin, calcScreenRect.position.y + /* margin top */ 2 } }, speed{ 6 },
			boundingRect{
				Point{ calcScreenRect.position.x + horizontalMargin, calcScreenRect.position.y },
				Size{ calcScreenRect.size.w - (horizontalMargin << 1), calcScreenRect.size.h }
			}, font{ font }, viewModel{ maxSizeIgnoreDash } { }

	void CalcExpr::set(const string& value)
	{
		ResourceView::set(TTF_RenderText_Blended(font, value.c_str(), SDL_Color{ 0u, 0u, 0u, 255u }));
	}

	Message CalcExpr::reactMessage(const Message& message)
	{
		switch (message.head)
		{
		case Message::Head::INPUT_LEFT:
			moveRight();
			break;
		case Message::Head::INPUT_RIGHT:
			moveLeft();
			break;
		case Message::Head::INPUT_C:
		case Message::Head::INPUT_CE:
		case Message::Head::INPUT_DIVIDE:
		case Message::Head::INPUT_EQUAL:
		case Message::Head::INPUT_MINUS:
		case Message::Head::INPUT_MULTIPLY:
		case Message::Head::INPUT_PLUS:
		case Message::Head::INPUT_SQR:
		case Message::Head::INPUT_SQRT:
			position.x = boundingRect.position.x + boundingRect.size.w;
		}
		viewModel.reactMessage(message);
		set(viewModel.value);
		return viewModel.message;
	}

	void CalcExpr::render()
	{
		const SDL_Rect srcRect{
			max(0, boundingRect.position.x - position.x + surface->w), 0, min(surface->w, boundingRect.size.w), surface->h
		};
		const SDL_Rect dstRect{
			max(position.x - surface->w, boundingRect.position.x), position.y, min(surface->w, boundingRect.size.w), surface->h
		};
		SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
	}

	CalcExpr::~CalcExpr()
	{
		TTF_CloseFont(font);
	}
}

#endif