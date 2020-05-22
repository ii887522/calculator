#ifndef TEST

#include "Button.h"
#include <SDL.h>

namespace ii887522::Calculator
{
	void Button::render(SDL_Renderer*const renderer)
	{
		SDL_SetRenderDrawColor(renderer, static_cast<Uint8>(192u * viewModel.lightness.now), static_cast<Uint8>(192u *
			viewModel.lightness.now), static_cast<Uint8>(192u * viewModel.lightness.now), 255u);
		const SDL_Rect rect{ viewModel.rect.position.x, viewModel.rect.position.y, viewModel.rect.size.w, viewModel.rect.size.h };
		SDL_RenderFillRect(renderer, &rect);
	}
}

#endif