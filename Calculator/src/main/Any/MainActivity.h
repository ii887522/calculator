#ifndef TEST

#ifndef II887522_CALCULATOR_MAIN_ACTIVITY_H
#define II887522_CALCULATOR_MAIN_ACTIVITY_H

#include <SDL.h>
#include "MainScene.h"
#include "Enums.h"
#include "../Struct/Size.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	// See also "../Functions/calculator.cpp" if you are looking for main entry point
	class MainActivity final
	{
		// remove copy semantics
		MainActivity(const MainActivity&) = delete;
		MainActivity& operator=(const MainActivity&) = delete;

		// remove move semantics
		MainActivity(MainActivity&&) = delete;
		MainActivity& operator=(MainActivity&&) = delete;

		SDL_Window*const window;
		SDL_Surface*const ico;
		SDL_Renderer*const renderer;
		MainScene scene;

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
		explicit MainActivity(const Size& = Size{ 318, 437 });

		constexpr Action react(const SDL_Event& event)
		{
			switch (event.type)
			{
			case SDL_QUIT: return Action::QUIT;
			case SDL_MOUSEMOTION: return scene.reactMouseMotion(event.motion);
			case SDL_MOUSEBUTTONDOWN: return reactMouseButtonDown(event.button);
			case SDL_MOUSEBUTTONUP: return reactMouseButtonUp(event.button);
			case SDL_WINDOWEVENT: return reactWindowEvent(event.window);
			case SDL_KEYDOWN: return scene.reactKeyDown(event.key);
			case SDL_KEYUP: return scene.reactKeyUp(event.key);
			}
			return Action::NONE;
		}

		Action step(const unsigned int dt);
		void show();
		~MainActivity();
	};
}

#endif
#endif