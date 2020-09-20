#ifndef TEST

#ifndef II887522_CALCULATOR_APP_H
#define II887522_CALCULATOR_APP_H

#include "Activity.h"
#include <SDL.h>
#include "../Any/Enums.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	// See also "../Functions/calculator.cpp" if you are looking for main entry point
	class App final
	{
		// remove copy semantics
		App(const App&) = delete;
		App& operator=(const App&) = delete;

		// remove move semantics
		App(App&&) = delete;
		App& operator=(App&&) = delete;

		Activity*const activities[2u];
		bool isAnimating;
		unsigned int activityAnimationsCount;

	public:
		// Param window: it must not be assigned to integer
		explicit App(SDL_Window*const = SDL_CreateWindow("Calcuator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 318, 437, 0u));

		Action reactMessage(const Message&);
		Action react(const SDL_Event& event);
		Action step(const unsigned int dt);
		void show();
		~App();
	};
}

#endif
#endif