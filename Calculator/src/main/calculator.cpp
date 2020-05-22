#ifndef TEST

#include <SDL.h>
#include "Subsystems.h"
#include "App.h"
#include "Enums.h"

namespace ii887522::Calculator
{
	static int main(int, char**)
	{
		const Subsystems subsystems;
		App app;
		SDL_Event event;
		while (true)
		{
			auto isAnimating{ false };
			while (SDL_WaitEvent(&event))
			{
				switch (app.react(event))
				{
				case Action::QUIT: return 0;
				case Action::START_ANIMATION: isAnimating = true;
				}
				if (isAnimating) break;
				app.show();
			}
			auto lastTime{ SDL_GetTicks() };
			while (true)
			{
				while (SDL_PollEvent(&event)) if (app.react(event) == Action::QUIT) return 0;
				const auto now{ SDL_GetTicks() };
				const auto dt{ now - lastTime };
				lastTime = now;
				if (app.step(dt) == Action::STOP_ANIMATION) isAnimating = false;
				app.show();
				if (!isAnimating) break;
				SDL_Delay(1u);
			}
		}
		return 0;
	}
}

int main(int argc, char** argv)
{
	return ii887522::Calculator::main(argc, argv);
}

#endif