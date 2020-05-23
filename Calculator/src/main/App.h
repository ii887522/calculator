#ifndef TEST

#ifndef II887522_CALCULATOR_APP_H
#define II887522_CALCULATOR_APP_H

#include <SDL.h>
#include "Scene.h"
#include "Enums.h"
#include "Size.h"

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
		Scene scene;

		void renderBackground();
		void render();

		constexpr Action reactMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent)
		{
			if (buttonEvent.button == SDL_BUTTON_LEFT) return scene.reactLeftMouseButtonDown(buttonEvent);
			return Action::NONE;
		}

		constexpr Action reactMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent)
		{
			if (buttonEvent.button == SDL_BUTTON_LEFT) return scene.reactLeftMouseButtonUp(buttonEvent);
			return Action::NONE;
		}

		constexpr Action reactWindowEvent(const SDL_WindowEvent& windowEvent)
		{
			if (windowEvent.event == SDL_WINDOWEVENT_LEAVE) return scene.reactMouseLeaveWindow(windowEvent);
			return Action::NONE;
		}

	public:
		explicit App(const Size& = Size{ 320, 480 });

		constexpr Action react(const SDL_Event& event)
		{
			switch (event.type)
			{
			case SDL_QUIT: return Action::QUIT;
			case SDL_MOUSEMOTION: return scene.reactMouseMotion(event.motion);
			case SDL_MOUSEBUTTONDOWN: return reactMouseButtonDown(event.button);
			case SDL_MOUSEBUTTONUP: return reactMouseButtonUp(event.button);
			case SDL_WINDOWEVENT: return reactWindowEvent(event.window);
			}
			return Action::NONE;
		}

		Action step(const unsigned int dt);
		void show();
		~App();
	};
}

#endif
#endif