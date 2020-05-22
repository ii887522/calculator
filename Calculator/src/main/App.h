#ifndef TEST

#ifndef II887522_CALCULATOR_APP_H
#define II887522_CALCULATOR_APP_H

#include <SDL.h>
#include "Button.h"

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

		void render();

		constexpr void reactMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent)
		{
			if (buttonEvent.button == SDL_BUTTON_LEFT) button.reactLeftMouseButtonDown(buttonEvent);
		}

		constexpr void reactMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent)
		{
			if (buttonEvent.button == SDL_BUTTON_LEFT) button.reactLeftMouseButtonUp(buttonEvent);
		}

		constexpr void reactWindowEvent(const SDL_WindowEvent& windowEvent)
		{
			if (windowEvent.event == SDL_WINDOWEVENT_LEAVE) button.reactMouseLeaveWindow(windowEvent);
		}

	public:
		enum class Action : unsigned int
		{
			NONE, QUIT
		};

		explicit App();

		constexpr Action react(const SDL_Event& event)
		{
			switch (event.type)
			{
			case SDL_QUIT: return Action::QUIT;
			case SDL_MOUSEMOTION: button.reactMouseMotion(event.motion);
				break;
			case SDL_MOUSEBUTTONDOWN: reactMouseButtonDown(event.button);
				break;
			case SDL_MOUSEBUTTONUP: reactMouseButtonUp(event.button);
				break;
			case SDL_WINDOWEVENT: reactWindowEvent(event.window);
			}
			return Action::NONE;
		}

		void show();
		~App();
	};
}

#endif
#endif