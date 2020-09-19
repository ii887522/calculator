#ifndef TEST

#include "ButtonGroup.h"
#include "../Any/View.h"
#include <SDL.h>
#include "Button.h"
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "../Struct/Color.h"
#include "../Any/Enums.h"
#include "../Any/ButtonGrid.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	ButtonGroup::ButtonGroup(SDL_Renderer* const renderer, const ButtonGrid& buttonGrid) : View{ renderer }, buttons{
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(0), buttonGrid.getButtonY(0) }, buttonGrid.getButtonSize() },
			Color{ 224u, 224u, 224u }, Message{ Message::Head::INPUT_LEFT }, Ability::CAN_DISABLE, SDLK_LEFT },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(1), buttonGrid.getButtonY(1) }, buttonGrid.getButtonSize() },
			Color{ 224u, 224u, 224u }, Message{ Message::Head::INPUT_SQR }, Ability::CAN_DISABLE },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(2), buttonGrid.getButtonY(2) }, buttonGrid.getButtonSize() },
			Color{ 224u, 224u, 224u }, Message{ Message::Head::INPUT_SQRT }, Ability::CAN_DISABLE },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(3), buttonGrid.getButtonY(3) }, buttonGrid.getButtonSize() },
			Color{ 224u, 224u, 224u }, Message{ Message::Head::INPUT_RIGHT }, Ability::CAN_DISABLE, SDLK_RIGHT },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(4), buttonGrid.getButtonY(4) }, buttonGrid.getButtonSize() },
			Color{ 224u, 224u, 224u }, Message{ Message::Head::INPUT_CE } },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(5), buttonGrid.getButtonY(5) }, buttonGrid.getButtonSize() },
			Color{ 224u, 224u, 224u }, Message{ Message::Head::INPUT_C }, Ability::NONE, SDLK_c },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(6), buttonGrid.getButtonY(6) }, buttonGrid.getButtonSize() },
			Color{ 224u, 224u, 224u }, Message{ Message::Head::INPUT_BACKSPACE }, Ability::CAN_DISABLE, SDLK_BACKSPACE },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(7), buttonGrid.getButtonY(7) }, buttonGrid.getButtonSize() },
			Color{ 224u, 224u, 224u }, Message{ Message::Head::INPUT_DIVIDE }, Ability::CAN_DISABLE, SDLK_KP_DIVIDE },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(8), buttonGrid.getButtonY(8) }, buttonGrid.getButtonSize() },
			Color{ 255u, 255u, 255u }, Message{ Message::Head::INPUT_7 }, Ability::NONE, SDLK_KP_7 },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(9), buttonGrid.getButtonY(9) }, buttonGrid.getButtonSize() },
			Color{ 255u, 255u, 255u }, Message{ Message::Head::INPUT_8 }, Ability::NONE, SDLK_KP_8 },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(10), buttonGrid.getButtonY(10) }, buttonGrid.getButtonSize() },
			Color{ 255u, 255u, 255u }, Message{ Message::Head::INPUT_9 }, Ability::NONE, SDLK_KP_9 },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(11), buttonGrid.getButtonY(11) }, buttonGrid.getButtonSize() },
			Color{ 224u, 224u, 224u }, Message{ Message::Head::INPUT_MULTIPLY }, Ability::CAN_DISABLE, SDLK_KP_MULTIPLY },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(12), buttonGrid.getButtonY(12) }, buttonGrid.getButtonSize() },
			Color{ 255u, 255u, 255u }, Message{ Message::Head::INPUT_4 }, Ability::NONE, SDLK_KP_4 },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(13), buttonGrid.getButtonY(13) }, buttonGrid.getButtonSize() },
			Color{ 255u, 255u, 255u }, Message{ Message::Head::INPUT_5 }, Ability::NONE, SDLK_KP_5 },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(14), buttonGrid.getButtonY(14) }, buttonGrid.getButtonSize() },
			Color{ 255u, 255u, 255u }, Message{ Message::Head::INPUT_6 }, Ability::NONE, SDLK_KP_6 },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(15), buttonGrid.getButtonY(15) }, buttonGrid.getButtonSize() },
			Color{ 224u, 224u, 224u }, Message{ Message::Head::INPUT_MINUS }, Ability::CAN_DISABLE, SDLK_KP_MINUS },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(16), buttonGrid.getButtonY(16) }, buttonGrid.getButtonSize() },
			Color{ 255u, 255u, 255u }, Message{ Message::Head::INPUT_1 }, Ability::NONE, SDLK_KP_1 },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(17), buttonGrid.getButtonY(17) }, buttonGrid.getButtonSize() },
			Color{ 255u, 255u, 255u }, Message{ Message::Head::INPUT_2 }, Ability::NONE, SDLK_KP_2 },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(18), buttonGrid.getButtonY(18) }, buttonGrid.getButtonSize() },
			Color{ 255u, 255u, 255u }, Message{ Message::Head::INPUT_3 }, Ability::NONE, SDLK_KP_3 },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(19), buttonGrid.getButtonY(19) }, buttonGrid.getButtonSize() },
			Color{ 224u, 224u, 224u }, Message{ Message::Head::INPUT_PLUS }, Ability::CAN_DISABLE, SDLK_KP_PLUS },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(20), buttonGrid.getButtonY(20) }, buttonGrid.getButtonSize() },
			Color{ 255u, 255u, 255u }, Message{ Message::Head::INPUT_SIGN }, Ability::CAN_DISABLE },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(21), buttonGrid.getButtonY(21) }, buttonGrid.getButtonSize() },
			Color{ 255u, 255u, 255u }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(22), buttonGrid.getButtonY(22) }, buttonGrid.getButtonSize() },
			Color{ 255u, 255u, 255u }, Message{ Message::Head::INPUT_DOT }, Ability::CAN_DISABLE, SDLK_KP_PERIOD },
		Button{ renderer, Rect{ Point{ buttonGrid.getButtonX(23), buttonGrid.getButtonY(23) }, buttonGrid.getButtonSize() },
			Color{ 86u, 173u, 255u }, Message{ Message::Head::INPUT_EQUAL }, Ability::CAN_DISABLE, SDLK_KP_ENTER }
	}, isAnimating{ false }, buttonAnimationsCount{ 0u } { }

	Pair<Action, Message> ButtonGroup::reactMessage(const Message& p_message)
	{
		auto resultAction{ Action::NONE };
		auto resultMessage{ Message{ } };
		for (auto i{ 0u }; i != sizeof buttons / sizeof Button; ++i)
		{
			const auto [action, message]{ buttons[i].reactMessage(p_message) };
			if (message.head != Message::Head::EMPTY) resultMessage = message;
			if (action != Action::START_ANIMATION) continue;
			++buttonAnimationsCount;
			if (isAnimating) continue;
			resultAction = action;
			isAnimating = true;
		}
		return Pair{ resultAction, resultMessage };
	}

	Action ButtonGroup::reactMouseMotion(const SDL_MouseMotionEvent& motionEvent)
	{
		auto result{ Action::NONE };
		for (auto i{ 0u }; i != sizeof buttons / sizeof Button; ++i)
		{
			const auto action{ buttons[i].reactMouseMotion(motionEvent) };
			if (action != Action::START_ANIMATION) continue;
			++buttonAnimationsCount;
			if (isAnimating) continue;
			result = action;
			isAnimating = true;
		}
		return result;
	}

	Action ButtonGroup::reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent)
	{
		auto result{ Action::NONE };
		for (auto i{ 0u }; i != sizeof buttons / sizeof Button; ++i)
		{
			const auto action{ buttons[i].reactLeftMouseButtonDown(buttonEvent) };
			if (action != Action::START_ANIMATION) continue;
			++buttonAnimationsCount;
			if (isAnimating) continue;
			result = action;
			isAnimating = true;
		}
		return result;
	}

	Pair<Action, Message> ButtonGroup::reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent)
	{
		auto resultAction{ Action::NONE };
		auto resultMessage{ Message{ } };
		for (auto i{ 0u }; i != sizeof buttons / sizeof Button; ++i)
		{
			const auto [action, message]{ buttons[i].reactLeftMouseButtonUp(buttonEvent) };
			if (message.head != Message::Head::EMPTY) resultMessage = message;
			if (action != Action::START_ANIMATION) continue;
			++buttonAnimationsCount;
			if (isAnimating) continue;
			resultAction = action;
			isAnimating = true;
		}
		return Pair{ resultAction, resultMessage };
	}

	Action ButtonGroup::reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent)
	{
		auto result{ Action::NONE };
		for (auto i{ 0u }; i != sizeof buttons / sizeof Button; ++i)
		{
			const auto action{ buttons[i].reactMouseLeaveWindow(windowEvent) };
			if (action != Action::START_ANIMATION) continue;
			++buttonAnimationsCount;
			if (isAnimating) continue;
			result = action;
			isAnimating = true;
		}
		return result;
	}

	Pair<Action, Message> ButtonGroup::reactKeyDown(const SDL_KeyboardEvent& keyEvent)
	{
		auto resultAction{ Action::NONE };
		auto resultMessage{ Message{ } };
		for (auto i{ 0u }; i != sizeof buttons / sizeof Button; ++i)
		{
			const auto [action, message]{ buttons[i].reactKeyDown(keyEvent) };
			if (message.head != Message::Head::EMPTY) resultMessage = message;
			if (action != Action::START_ANIMATION) continue;
			++buttonAnimationsCount;
			if (isAnimating) continue;
			resultAction = action;
			isAnimating = true;
		}
		return Pair{ resultAction, resultMessage };
	}

	Action ButtonGroup::reactKeyUp(const SDL_KeyboardEvent& keyEvent)
	{
		auto result{ Action::NONE };
		for (auto i{ 0u }; i != sizeof buttons / sizeof Button; ++i)
		{
			const auto action{ buttons[i].reactKeyUp(keyEvent) };
			if (action != Action::START_ANIMATION) continue;
			++buttonAnimationsCount;
			if (isAnimating) continue;
			result = action;
			isAnimating = true;
		}
		return result;
	}

	Action ButtonGroup::step(const unsigned int dt)
	{
		auto result{ Action::NONE };
		for (auto i{ 0u }; i != sizeof buttons / sizeof Button; ++i)
		{
			const auto action{ buttons[i].step(dt) };
			if (action != Action::STOP_ANIMATION) continue;
			--buttonAnimationsCount;
			if (buttonAnimationsCount != 0u) continue;
			result = action;
			isAnimating = false;
		}
		return result;
	}

	void ButtonGroup::render()
	{
		for (auto i{ 0u }; i != sizeof buttons / sizeof Button; ++i) buttons[i].render();
	}
}

#endif