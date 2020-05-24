#ifndef TEST

#ifndef II887522_CALCULATOR_RESOURCE_VIEW_H
#define II887522_CALCULATOR_RESOURCE_VIEW_H

#include "../Any/View.h"
#include <SDL.h>
#include <string>
#include "../Struct/Point.h"

using std::string;

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	struct ResourceView : public View
	{
		// remove copy semantics
		ResourceView(const ResourceView&) = delete;
		ResourceView& operator=(const ResourceView&) = delete;

		// remove move semantics
		ResourceView(ResourceView&&) = delete;
		ResourceView& operator=(ResourceView&&) = delete;

		// Param renderer: it must not be assigned to integer
		// Param surface: it must not be assigned to integer
		explicit ResourceView(SDL_Renderer*const renderer, SDL_Surface*const surface, const Point& position = Point{ });

		virtual void render() override;
		~ResourceView();

	protected:
		Point position;
		SDL_Surface*const surface;
		SDL_Texture*const texture;
	};
}

#endif
#endif