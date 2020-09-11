#ifndef TEST

#include <SDL.h>
#include "../Any/Subsystems.h"
#include "../Any/MainActivity.h"
#include "../Any/Enums.h"

namespace ii887522::Calculator
{
	static int main(int, char**)
	{
		const Subsystems subsystems;
		MainActivity mainActivity;
		SDL_Event event;
		mainActivity.show();
		while (true)
		{
			auto isAnimating{ false };
			auto lastTime{ SDL_GetTicks() };
			while (SDL_WaitEvent(&event))
			{
				switch (mainActivity.react(event))
				{
				case Action::QUIT: return EXIT_SUCCESS;
				case Action::START_ANIMATION: isAnimating = true;
				}
				if (isAnimating) break;
				const auto now{ SDL_GetTicks() };
				if (now - lastTime < 3u) continue;
				lastTime = now;
				mainActivity.show();
			}
			lastTime = SDL_GetTicks();
			while (true)
			{
				while (SDL_PollEvent(&event)) if (mainActivity.react(event) == Action::QUIT) return EXIT_SUCCESS;
				const auto now{ SDL_GetTicks() };
				const auto dt{ now - lastTime };
				lastTime = now;
				if (mainActivity.step(dt) == Action::STOP_ANIMATION) isAnimating = false;
				mainActivity.show();
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