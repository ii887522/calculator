#ifndef TEST

#ifndef II887522_CALCULATOR_APP_H
#define II887522_CALCULATOR_APP_H

#include <SDL.h>
#include "Button.h"
#include "Enums.h"

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
		Button button;

		void renderBackground();
		void render();

		constexpr Action reactMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent)
		{
			if (buttonEvent.button == SDL_BUTTON_LEFT) return button.reactLeftMouseButtonDown(buttonEvent);
			return Action::NONE;
		}

		constexpr Action reactMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent)
		{
			if (buttonEvent.button == SDL_BUTTON_LEFT) return button.reactLeftMouseButtonUp(buttonEvent);
			return Action::NONE;
		}

		constexpr Action reactWindowEvent(const SDL_WindowEvent& windowEvent)
		{
			if (windowEvent.event == SDL_WINDOWEVENT_LEAVE) return button.reactMouseLeaveWindow(windowEvent);
			return Action::NONE;
		}

	public:
		explicit App();

		constexpr Action react(const SDL_Event& event)
		{
			switch (event.type)
			{
			case SDL_QUIT: return Action::QUIT;
			case SDL_MOUSEMOTION: return button.reactMouseMotion(event.motion);
			case SDL_MOUSEBUTTONDOWN: return reactMouseButtonDown(event.button);
			case SDL_MOUSEBUTTONUP: return reactMouseButtonUp(event.button);
			case SDL_WINDOWEVENT: return reactWindowEvent(event.window);
			}
			return Action::NONE;
		}

		constexpr Action step(const unsigned int dt)
		{
			return button.step(dt);
		}

		void show();
		~App();
	};
}

#endif
#endif