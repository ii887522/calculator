#ifndef TEST

#ifndef II887522_CALCULATOR_MAIN_ACTIVITY_H
#define II887522_CALCULATOR_MAIN_ACTIVITY_H

#include "../Any/Activity.h"
#include <SDL.h>
#include "../Scene/MainScene.h"
#include "../Any/Enums.h"
#include "../Struct/Size.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class MainActivity final : public Activity
	{
		// remove copy semantics
		MainActivity(const MainActivity&) = delete;
		MainActivity& operator=(const MainActivity&) = delete;

		// remove move semantics
		MainActivity(MainActivity&&) = delete;
		MainActivity& operator=(MainActivity&&) = delete;

		SDL_Surface*const ico;
		MainScene scene;

		void renderBackground();
		void render();

		constexpr Action reactMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent)
		{
			switch (buttonEvent.button)
			{
			case SDL_BUTTON_LEFT: return scene.reactLeftMouseButtonDown(buttonEvent);
			case SDL_BUTTON_RIGHT: return scene.reactRightMouseButtonDown(buttonEvent);
			}
			return Action::NONE;
		}

		Pair<Action, Message> reactMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent);

		constexpr Action reactWindowEvent(const SDL_WindowEvent& windowEvent)
		{
			switch (windowEvent.event)
			{
			case SDL_WINDOWEVENT_CLOSE: if (windowEvent.windowID == SDL_GetWindowID(getWindow())) return Action::QUIT;
				break;
			case SDL_WINDOWEVENT_LEAVE: return scene.reactMouseLeaveWindow(windowEvent);
			}
			return Action::NONE;
		}

	public:
		explicit MainActivity(const Size& = Size{ 318, 437 });
		virtual Pair<Action, Message> react(const SDL_Event& event) override;
		virtual Action step(const unsigned int dt) override;
		virtual void show() override;
		~MainActivity();
	};
}

#endif
#endif