#ifndef TEST

#ifndef II887522_CALCULATOR_RESOURCE_VIEW_H
#define II887522_CALCULATOR_RESOURCE_VIEW_H

#include "View.h"
#include <SDL.h>
#include <string>
#include "Point.h"

using std::string;

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class ResourceView final : public View
	{
		// remove copy semantics
		ResourceView(const ResourceView&) = delete;
		ResourceView& operator=(const ResourceView&) = delete;

		// remove move semantics
		ResourceView(ResourceView&&) = delete;
		ResourceView& operator=(ResourceView&&) = delete;

		const Point position;
		SDL_Surface*const surface;
		SDL_Texture*const texture;

	public:
		// Param renderer: it must not be assigned to integer
		explicit ResourceView(SDL_Renderer*const renderer, const string& filePath, const Point& position = Point{ });

		virtual void render() override;
		~ResourceView();
	};
}

#endif
#endif