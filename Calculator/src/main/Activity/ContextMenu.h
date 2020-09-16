#ifndef TEST

#ifndef II887522_CALCULATOR_CONTEXT_MENU_H
#define II887522_CALCULATOR_CONTEXT_MENU_H

#include "../Any/Activity.h"
#include <SDL.h>
#include "../Any/Enums.h"
#include "../Scene/ContextMenuScene.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"
#include "../Struct/Size.h"
#include "../Functions/sdl_ext.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class ContextMenu final : public Activity
	{
		// remove copy semantics
		ContextMenu(const ContextMenu&) = delete;
		ContextMenu& operator=(const ContextMenu&) = delete;

		// remove move semantics
		ContextMenu(ContextMenu&&) = delete;
		ContextMenu& operator=(ContextMenu&&) = delete;

		SDL_Window*const parentWindow;
		ContextMenuScene scene;

		void reactShowMessage();

		constexpr Action reactMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent)
		{
			if (buttonEvent.button == SDL_BUTTON_LEFT) return scene.reactLeftMouseButtonDown(buttonEvent);
			return Action::NONE;
		}

		Pair<Action, Message> reactMouseButtonUp(const SDL_MouseButtonEvent&);

		constexpr Action reactWindowEvent(const SDL_WindowEvent& windowEvent)
		{
			switch (windowEvent.event)
			{
			case SDL_WINDOWEVENT_LEAVE: return scene.reactMouseLeaveWindow(windowEvent);
			case SDL_WINDOWEVENT_FOCUS_LOST: if (windowEvent.windowID == SDL_GetWindowID(getWindow())) SDL_HideWindow(getWindow());
			}
			return Action::NONE;
		}

		void renderBorder();
		void render();

	public:
		// Param parentWindow: it must not be assigned to integer
		explicit ContextMenu(SDL_Window*const parentWindow, const Size& = Size{ 88, 62 });

		virtual Action reactMessage(const Message&) override;
		virtual Pair<Action, Message> react(const SDL_Event&) override;
		virtual Action step(const unsigned int dt) override;
		virtual void show() override;
	};
}

#endif
#endif