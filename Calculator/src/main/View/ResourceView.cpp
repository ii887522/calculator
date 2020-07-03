#ifndef TEST

#include "ResourceView.h"
#include "../Any/View.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "../Struct/Point.h"

using std::string;

namespace ii887522::Calculator
{
	ResourceView::ResourceView(SDL_Renderer* const renderer, SDL_Surface* const surface, const Point& position) : View{ renderer },
		position{ position }, surface{ surface }, texture{ SDL_CreateTextureFromSurface(renderer, surface) } { }

	void ResourceView::set(SDL_Surface* const newSurface)
	{
		free();
		surface = newSurface;
		texture = SDL_CreateTextureFromSurface(renderer, newSurface);
	}

	void ResourceView::render()
	{
		const SDL_Rect rect{ position.x, position.y, surface->w, surface->h };
		SDL_RenderCopy(renderer, texture, nullptr, &rect);
	}

	void ResourceView::free()
	{
		SDL_DestroyTexture(texture);
		SDL_FreeSurface(surface);
	}

	ResourceView::~ResourceView()
	{
		free();
	}
}

#endif