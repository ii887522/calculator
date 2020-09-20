#ifndef TEST

#include "Text.h"
#include "../View/ResourceView.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "../Struct/Point.h"
#include "../Any/Enums.h"
#include "../Struct/Message.h"
#include "../Struct/Pair.h"

using std::string;

namespace ii887522::Calculator
{
	Text::Text(SDL_Renderer*const renderer, TTF_Font*const font, const Point& position, const string& value, const Ability ability) :
		ResourceView{ renderer, TTF_RenderText_Blended(font, value.c_str(), SDL_Color{ 0u, 0u, 0u, 255u }), position },
		viewModel{ ability }, isAnimating{ false } { }

	void Text::enable()
	{
		viewModel.enable();
	}

	void Text::tryDisable()
	{
		viewModel.tryDisable();
	}

	Pair<Action, Message> Text::reactMessage(const Message& message)
	{
		viewModel.reactMessage(message);
		if (isAnimating || !viewModel.getIsAnimating()) return Pair{ Action::NONE, viewModel.getMessage() };
		isAnimating = true;
		return Pair{ Action::START_ANIMATION, viewModel.getMessage() };
	}

	Action Text::step(const unsigned int dt)
	{
		if (!isAnimating) return Action::NONE;
		viewModel.step(dt);
		if (viewModel.getIsAnimating()) return Action::NONE;
		isAnimating = false;
		return Action::STOP_ANIMATION;
	}

	void Text::render()
	{
		SDL_SetTextureAlphaMod(getTexture(), static_cast<Uint8>(viewModel.getA().now));
		const SDL_Rect rect{ getPosition().x, getPosition().y, getSurface()->w, getSurface()->h };
		SDL_RenderCopy(getRenderer(), getTexture(), nullptr, &rect);
	}
}

#endif