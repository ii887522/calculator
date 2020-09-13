#ifndef TEST

#include "ContextMenuScene.h"
#include "../View/ResourceView.h"
#include "../ResourceView/Text.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "../Any/Enums.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "../Functions/control_flow.h"

namespace ii887522::Calculator
{
	ContextMenuScene::ContextMenuScene(SDL_Renderer*const renderer) : ContextMenuScene(renderer, TTF_OpenFont("res/main/arial.ttf", 16),
		Size{ 31, 31 }, 4) { }

	ContextMenuScene::ContextMenuScene(SDL_Renderer*const renderer, TTF_Font*const font, const Size& iconSize, const int paddingTop)
		: views{
			new ResourceView{ renderer, IMG_Load("res/main/copy.png"), Point{ 0, paddingTop } },
			new Text{ renderer, font, Point{ iconSize.w, 10 }, "Copy" },
			new ResourceView{ renderer, IMG_Load("res/main/paste.png"), Point{ 0, iconSize.h + paddingTop } },
			new Text{ renderer, font, Point{ iconSize.w, iconSize.h + 10 }, "Paste" }
		}
		{
			TTF_CloseFont(font);
		}

	Action ContextMenuScene::reactMessage(const Message& p_message)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			const auto [action, message]{ views[i]->reactMessage(p_message) };
			if (message.head != Message::Head::EMPTY) result = reactMessage(message);
			if (action != Action::START_ANIMATION) return;
			incrementViewAnimationsCount();
			if (getIsAnimating()) return;
			result = action;
			setIsAnimating(true);
		});
		return result;
	}

	Action ContextMenuScene::reactMouseMotionWithFocus(const SDL_MouseMotionEvent& motionEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			const auto action{ views[i]->reactMouseMotion(motionEvent) };
			if (action != Action::START_ANIMATION) return;
			incrementViewAnimationsCount();
			if (getIsAnimating()) return;
			result = action;
			setIsAnimating(true);
		});
		return result;
	}

	Action ContextMenuScene::reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			const auto action{ views[i]->reactLeftMouseButtonDown(buttonEvent) };
			if (action != Action::START_ANIMATION) return;
			incrementViewAnimationsCount();
			if (getIsAnimating()) return;
			result = action;
			setIsAnimating(true);
		});
		return result;
	}

	Action ContextMenuScene::reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			const auto [action, message]{ views[i]->reactLeftMouseButtonUp(buttonEvent) };
			if (message.head != Message::Head::EMPTY) result = reactMessage(message);
			if (action != Action::START_ANIMATION) return;
			incrementViewAnimationsCount();
			if (getIsAnimating()) return;
			result = action;
			setIsAnimating(true);
		});
		return result;
	}

	Action ContextMenuScene::reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			const auto action{ views[i]->reactMouseLeaveWindow(windowEvent) };
			if (action != Action::START_ANIMATION) return;
			incrementViewAnimationsCount();
			if (getIsAnimating()) return;
			result = action;
			setIsAnimating(true);
		});
		return result;
	}

	Action ContextMenuScene::step(const unsigned int dt)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			const auto action{ views[i]->step(dt) };
			if (action != Action::STOP_ANIMATION) return;
			decrementViewAnimationsCount();
			if (getViewAnimationsCount() != 0u) return;
			result = action;
			setIsAnimating(false);
		});
		return result;
	}

	void ContextMenuScene::render()
	{
		loop(sizeof views / sizeof(View*), [=](const auto i) {
			views[i]->render();
		});
	}
}

#endif