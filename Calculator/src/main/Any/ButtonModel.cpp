#include "ButtonModel.h"
#include "../Struct/Rect.h"
#include "../Struct/Message.h"
#include <SDL.h>

namespace ii887522::Calculator
{
	ButtonModel::ButtonModel(const Rect& rect, const Message& message, const SDL_Keycode keyCode) : state{ State::INITIAL },
		elaspedTime{ 0u }, _message{ message }, keyCode{ keyCode }, rect{ rect }, lightness{ 1.f }, borderA{ 0.f }, isAnimating{ false } { }

	void ButtonModel::reactLeftMouseButtonUp()
	{
		message = Message{ };
		if (state != State::PRESSED) return;
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
		if (keyCode != p_keyCode) return;
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