#ifndef TEST

#ifndef II887522_CALCULATOR_APP_H
#define II887522_CALCULATOR_APP_H

#include <SDL.h>

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class App final
	{
		// remove copy semantics
		App(const App&) = delete;
		App& operator=(const App&) = delete;

		// remove move semantics
		App(App&&) = delete;
		App& operator=(App&&) = delete;

		SDL_Window*const window;
		SDL_Surface*const ico;
		SDL_Renderer*const renderer;

		void render();

	public:
		explicit App();
		void show();
		~App();
	};
}

#endif
#endif