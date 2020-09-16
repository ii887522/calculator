#ifndef TEST

#ifndef II887522_CALCULATOR_RESOURCE_VIEW_H
#define II887522_CALCULATOR_RESOURCE_VIEW_H

#include "../Any/View.h"
#include "../Any/ResourceViewModel.h"
#include <SDL.h>
#include <string>
#include "../Struct/Point.h"
#include "../Any/Enums.h"

using std::string;

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class ResourceView : public View
	{
		// remove copy semantics
		ResourceView(const ResourceView&) = delete;
		ResourceView& operator=(const ResourceView&) = delete;

		// remove move semantics
		ResourceView(ResourceView&&) = delete;
		ResourceView& operator=(ResourceView&&) = delete;

		ResourceViewModel viewModel;
		Point position;
		SDL_Surface* surface;
		SDL_Texture* texture;

	protected:
		constexpr Point& getPosition()
		{
			return position;
		}

		constexpr SDL_Surface* getSurface()
		{
			return surface;
		}

		constexpr SDL_Texture* getTexture()
		{
			return texture;
		}

		// Param surface: it must not be assigned to integer
		void set(SDL_Surface*const surface);

		void free();

	public:
		// Param renderer: it must not be assigned to integer
		// Param surface: it must not be assigned to integer
		explicit ResourceView(SDL_Renderer*const renderer, SDL_Surface*const surface, const Point& position = Point{ },
			const Ability = Ability::NONE);

		virtual void enable() override;
		virtual void tryDisable() override;
		virtual void render() override;
		~ResourceView();
	};
}

#endif
#endif