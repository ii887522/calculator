#include "ButtonModel.h"
#include "../Struct/Rect.h"
#include "../Struct/Message.h"
#include <SDL.h>

namespace ii887522::Calculator
{
	ButtonModel::ButtonModel(const Rect& rect, const Message& message, const Ability ability,const SDL_Keycode keyCode) :
		state{ State::INITIAL }, elaspedTime{ 0u }, _message{ message }, keyCode{ keyCode }, ability{ ability }, rect{ rect },
		lightness{ 1.f }, borderA{ 0.f }, isAnimating{ false } { }

	void ButtonModel::reactMessage(const Message& p_message)
	{
		message = Message{ };
		if (p_message.head != Message::Head::ERROR || ability != Ability::CAN_DISABLE) return;
		state = State::DISABLED;
		elaspedTime = 0u;
		lightness.start = lightness.now;
		lightness.end = 1.f;
		borderA.start = borderA.now;
		borderA.end = 0.f;
		isAnimating = true;
	}

	void ButtonModel::reactLeftMouseButtonUp()
	{
		message = Message{ };
		if (state != State::PRESSED || state == State::DISABLED) return;
		state = State::HOVERED;
		elaspedTime = 0u;
		lightness.start = lightness.now;
		lightness.end = .9f;
		borderA.start = borderA.now;
		borderA.end = 255.f;
		isAnimating = true;
		message = _message;
	}

	void ButtonModel::reactKeyDown(const SDL_Keycode p_keyCode)
	{
		message = Message{ };
		if (keyCode != p_keyCode || state == State::DISABLED) return;
		state = State::PRESSED;
		elaspedTime = 0u;
		lightness.start = lightness.now;
		lightness.end = .8f;
		borderA.start = borderA.now;
		borderA.end = 255.f;
		isAnimating = true;
		message = _message;
	}
}