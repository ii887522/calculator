#ifndef TEST

#ifndef II887522_CALCULATOR_SCENE_H
#define II887522_CALCULATOR_SCENE_H

#include <SDL.h>
#include "View.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class Scene final
	{
		// remove copy semantics
		Scene(const Scene&) = delete;
		Scene& operator=(const Scene&) = delete;

		// remove move semantics
		Scene(Scene&&) = delete;
		Scene& operator=(Scene&&) = delete;

		View*const views[2u];

	public:
		// Param renderer: it must not be assigned to integer
		explicit Scene(SDL_Renderer*const renderer);

		~Scene();
	};
}

#endif
#endif