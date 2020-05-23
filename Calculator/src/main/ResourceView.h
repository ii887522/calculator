#ifndef TEST

#ifndef II887522_CALCULATOR_RESOURCE_VIEW_H
#define II887522_CALCULATOR_RESOURCE_VIEW_H

#include <SDL.h>
#include <string>

using std::string;

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class ResourceView final
	{
		// remove copy semantics
		ResourceView(const ResourceView&) = delete;
		ResourceView& operator=(const ResourceView&) = delete;

		// remove move semantics
		ResourceView(ResourceView&&) = delete;
		ResourceView& operator=(ResourceView&&) = delete;

		SDL_Renderer*const renderer;
		SDL_Surface*const surface;
		SDL_Texture*const texture;

	public:
		// Param renderer: it must not be assigned to integer
		explicit ResourceView(SDL_Renderer*const renderer, const string& filePath);

		void render();
		~ResourceView();
	};
}

#endif
#endif