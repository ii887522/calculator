#ifndef TEST

#include "MainScene.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "../ResourceView/RadialGradient.h"
#include "../View/NavBar.h"
#include "../View/Button.h"
#include "../View/ResourceView.h"
#include "../ResourceView/Text.h"
#include "../View/CalcScreen.h"
#include "../Text/CalcExpr.h"
#include "../Text/CalcResult.h"
#include "../View/ButtonGroup.h"
#include "../View/TextGroup.h"
#include "../View/CalcExprPaster.h"
#include "../Functions/control_flow.h"
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "../Struct/Color.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"
#include "../Any/Enums.h"
#include "../Any/ButtonGrid.h"

namespace ii887522::Calculator
{
	MainScene::MainScene(SDL_Renderer*const renderer, const Size& size, const int buttonSize) :
		MainScene{ renderer, size, 9u, Rect{ Point{ 0, buttonSize }, Size{ size.w, 89 } }, TTF_OpenFont("res/main/arial.ttf", 20),
			buttonSize, ButtonGrid{ Point{ 4, 134 } } } { }

	MainScene::MainScene(SDL_Renderer*const renderer, const Size& size, const unsigned int maxSizeIgnoreDash, const Rect& calcScreenRect,
		TTF_Font*const font, const int buttonSize, const ButtonGrid& buttonGrid) : Scene{ }, views{
			new RadialGradient{ renderer, size },
			new NavBar{ renderer, Size{ size.w, buttonSize } },
			new Button{ renderer, Rect{ Point{ 0, 0 }, Size{ buttonSize, buttonSize } }, Color{ 192u, 192u, 192u } },
			new ResourceView{ renderer, IMG_Load("res/main/drawer.png") },
			new Text{ renderer, font, Point{ 53, 10 }, "Standard" },
			new Button{ renderer, Rect{ Point{ size.w - buttonSize, 0 }, Size{ buttonSize, buttonSize } }, Color{ 192u, 192u, 192u } },
			new ResourceView{ renderer, IMG_Load("res/main/history.png"), Point{ size.w - buttonSize, 0 } },
			new CalcScreen{ renderer, calcScreenRect },
			new CalcExpr{ renderer, calcScreenRect, maxSizeIgnoreDash },
			new CalcResult{ renderer, calcScreenRect, maxSizeIgnoreDash },
			new ButtonGroup{ renderer, buttonGrid },
			new TextGroup{ renderer, font, buttonGrid },
			new CalcExprPaster{ }
		}, viewAbilities{
			Ability::ALWAYS_REACT, Ability::NONE, Ability::NONE, Ability::NONE, Ability::NONE, Ability::NONE, Ability::NONE, Ability::NONE,
			Ability::NONE, Ability::NONE, Ability::NONE, Ability::NONE, Ability::NONE
		}
		{
			TTF_CloseFont(font);
		}

	Action MainScene::reactMessage(const Message& p_message)
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

	Action MainScene::reactMouseMotionWithFocus(const SDL_MouseMotionEvent& motionEvent)
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

	Action MainScene::reactMouseMotionWithoutFocus(const SDL_MouseMotionEvent& motionEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			if (viewAbilities[i] != Ability::ALWAYS_REACT) return;
			const auto action{ views[i]->reactMouseMotion(motionEvent) };
			if (action != Action::START_ANIMATION) return;
			incrementViewAnimationsCount();
			if (getIsAnimating()) return;
			result = action;
			setIsAnimating(true);
		});
		return result;
	}

	Action MainScene::reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent)
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

	Pair<Action, Message> MainScene::reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent)
	{
		auto resultAction{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &resultAction](const auto i) {
			const auto [action, message]{ views[i]->reactLeftMouseButtonUp(buttonEvent) };
			if (message.head != Message::Head::EMPTY) resultAction = reactMessage(message);
			if (action != Action::START_ANIMATION) return;
			incrementViewAnimationsCount();
			if (getIsAnimating()) return;
			resultAction = action;
			setIsAnimating(true);
		});
		return Pair{ resultAction, Message{ } };
	}

	Action MainScene::reactRightMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			const auto action{ views[i]->reactRightMouseButtonDown(buttonEvent) };
			if (action != Action::START_ANIMATION) return;
			incrementViewAnimationsCount();
			if (getIsAnimating()) return;
			result = action;
			setIsAnimating(true);
		});
		return result;
	}

	Pair<Action, Message> MainScene::reactRightMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent)
	{
		auto resultAction{ Action::NONE };
		auto resultMessage{ Message{ } };
		loop(sizeof views / sizeof(View*), [=, &resultAction, &resultMessage](const auto i) {
			const auto [action, message]{ views[i]->reactRightMouseButtonUp(buttonEvent) };
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

	Action MainScene::reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent)
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

	Action MainScene::reactKeyDown(const SDL_KeyboardEvent& keyEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			const auto [action, message]{ views[i]->reactKeyDown(keyEvent) };
			if (message.head != Message::Head::EMPTY) result = reactMessage(message);
			if (action != Action::START_ANIMATION) return;
			incrementViewAnimationsCount();
			if (getIsAnimating()) return;
			result = action;
			setIsAnimating(true);
		});
		return result;
	}

	Action MainScene::reactKeyUp(const SDL_KeyboardEvent& keyEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			const auto action{ views[i]->reactKeyUp(keyEvent) };
			if (action != Action::START_ANIMATION) return;
			incrementViewAnimationsCount();
			if (getIsAnimating()) return;
			result = action;
			setIsAnimating(true);
		});
		return result;
	}

	Action MainScene::step(const unsigned int dt)
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

	void MainScene::render()
	{
		loop(sizeof views / sizeof(View*), [=](const auto i) {
			views[i]->render();
		});
	}

	MainScene::~MainScene()
	{
		loop(sizeof views / sizeof(View*), [=](const auto i) {
			delete views[i];
		});
	}
}

#endif