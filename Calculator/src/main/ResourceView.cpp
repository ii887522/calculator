#ifndef TEST

#include "ResourceView.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>

using std::string;

namespace ii887522::Calculator
{
	ResourceView::ResourceView(SDL_Renderer*const renderer, const string& filePath) : renderer{ renderer },
		surface{ IMG_Load(filePath.c_str()) }, texture{ SDL_CreateTextureFromSurface(renderer, surface) } { }

	void ResourceView::render()
	{

	}

	ResourceView::~ResourceView()
	{
		SDL_DestroyTexture(texture);
		SDL_FreeSurface(surface);
	}
}

#endif