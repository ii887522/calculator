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
	ResourceView::ResourceView(SDL_Renderer*const renderer, const string& filePath, const Point& position) : View{ renderer },
		position{ position }, surface{ IMG_Load(filePath.c_str()) }, texture{ SDL_CreateTextureFromSurface(renderer, surface) } { }

	void ResourceView::render()
	{
		const SDL_Rect rect{ position.x, position.y, surface->w, surface->h };
		SDL_RenderCopy(renderer, texture, nullptr, &rect);
	}

	ResourceView::~ResourceView()
	{
		SDL_DestroyTexture(texture);
		SDL_FreeSurface(surface);
	}
}

#endif