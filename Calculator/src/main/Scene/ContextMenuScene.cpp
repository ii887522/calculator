#ifndef TEST

#include "ContextMenuScene.h"
#include "../View/ResourceView.h"
#include "../ResourceView/Text.h"
#include "../View/Button.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "../Struct/Rect.h"
#include "../Struct/Color.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"
#include "../Any/Enums.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "../Functions/control_flow.h"

namespace ii887522::Calculator
{
	ContextMenuScene::ContextMenuScene(SDL_Renderer*const renderer, const Size& size) :
		ContextMenuScene(renderer, size, TTF_OpenFont("res/main/arial.ttf", 16), Size{ 31, 31 }) { }

	ContextMenuScene::ContextMenuScene(SDL_Renderer*const renderer, const Size& size, TTF_Font*const font, const Size& iconSize) : views{
			new Button{
				renderer, Rect{ Point{ 0, 0 }, Size{ size.w, (size.h >> 1u) } }, Color{ 224u, 224u, 224u },
				Message{ Message::Head::COPY_FROM_CALC_RESULT }
			},
			new ResourceView{ renderer, IMG_Load("res/main/copy.png") },
			new Text{ renderer, font, Point{ iconSize.w, 6 }, "Copy" },
			new Button{
				renderer, Rect{ Point{ 0, size.h >> 1u }, Size{ size.w, (size.h >> 1u) } }, Color{ 224u, 224u, 224u },
				Message{ Message::Head::PASTE_TO_CALC_RESULT }, Ability::CAN_DISABLE
			},
			new ResourceView{ renderer, IMG_Load("res/main/paste.png"), Point{ 0, iconSize.h }, Ability::CAN_DISABLE },
			new Text{ renderer, font, Point{ iconSize.w, iconSize.h + 6 }, "Paste", Ability::CAN_DISABLE }
		}
		{
			TTF_CloseFont(font);
		}

	void ContextMenuScene::enable()
	{
		loop(sizeof views / sizeof(View*), [=](const auto i) {
			views[i]->enable();
		});
	}

	void ContextMenuScene::tryDisable()
	{
		loop(sizeof views / sizeof(View*), [=](const auto i) {
			views[i]->tryDisable();
		});
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

	Pair<Action, Message> ContextMenuScene::reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent)
	{
		auto resultAction{ Action::NONE };
		auto resultMessage{ Message{ } };
		loop(sizeof views / sizeof(View*), [=, &resultAction, &resultMessage](const auto i) {
			const auto [action, message]{ views[i]->reactLeftMouseButtonUp(buttonEvent) };
			if (message.head != Message::Head::EMPTY)
			{
				resultMessage = message;
				resultAction = reactMessage(message);
			}
			if (action != Action::START_ANIMATION) return;
			incrementViewAnimationsCount();
			if (getIsAnimating()) return;
			resultAction = action;
			setIsAnimating(true);
		});
		return Pair{ resultAction, resultMessage };
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