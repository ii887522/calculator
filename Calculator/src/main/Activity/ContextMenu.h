#ifndef TEST

#ifndef II887522_CALCULATOR_CONTEXT_MENU_H
#define II887522_CALCULATOR_CONTEXT_MENU_H

#include "../Any/Activity.h"
#include <SDL.h>
#include "../Any/Enums.h"
#include "../Scene/ContextMenuScene.h"

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

		ContextMenuScene scene;

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

		void renderBackground();
		void render();

	public:
		explicit ContextMenu();
		virtual Action react(const SDL_Event&) override;
		virtual Action step(const unsigned int dt) override;
		virtual void show() override;
	};
}

#endif
#endif