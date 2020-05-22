#ifndef TEST

#include <SDL.h>
#include "Subsystems.h"
#include "App.h"

namespace ii887522::Calculator
{
	static int main(int, char**)
	{
		const Subsystems subsystems;
		App app;
		SDL_Event event;
		while (SDL_WaitEvent(&event))
		{
			if (app.react(event) == App::Action::QUIT) break;
			app.show();
		}
		return 0;
	}
}

int main(int argc, char** argv)
{
	return ii887522::Calculator::main(argc, argv);
}

#endif