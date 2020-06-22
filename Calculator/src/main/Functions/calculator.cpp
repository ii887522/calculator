#ifndef TEST

#include <SDL.h>
#include "../Any/Subsystems.h"
#include "../Any/App.h"
#include "../Any/Enums.h"

namespace ii887522::Calculator
{
	static int main(int, char**)
	{
		const Subsystems subsystems;
		App app;
		SDL_Event event;
		app.show();
		while (true)
		{
			auto isAnimating{ false };
			auto lastTime{ SDL_GetTicks() };
			while (SDL_WaitEvent(&event))
			{
				switch (app.react(event))
				{
				case Action::QUIT: return EXIT_SUCCESS;
				case Action::START_ANIMATION: isAnimating = true;
				}
				if (isAnimating) break;
				const auto now{ SDL_GetTicks() };
				if (now - lastTime < 3u) continue;
				lastTime = now;
				app.show();
			}
			lastTime = SDL_GetTicks();
			while (true)
			{
				while (SDL_PollEvent(&event)) if (app.react(event) == Action::QUIT) return EXIT_SUCCESS;
				const auto now{ SDL_GetTicks() };
				const auto dt{ now - lastTime };
				lastTime = now;
				if (app.step(dt) == Action::STOP_ANIMATION) isAnimating = false;
				app.show();
				if (!isAnimating) break;
				SDL_Delay(1u);
			}
		}
		return EXIT_SUCCESS;
	}
}

int main(int argc, char** argv)
{
	return ii887522::Calculator::main(argc, argv);
}

#endif