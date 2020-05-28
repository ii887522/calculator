#ifndef TEST

#include "Button.h"
#include "../Any/View.h"
#include <SDL.h>
#include "../Struct/Pair.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	Button::Button(SDL_Renderer*const renderer, const Rect& rect, const Color& color, const Message& message, const SDL_Keycode keyCode)
		: View{ renderer }, viewModel{ rect, keyCode }, color{ color }, isAnimating{ false }, message{ message } { }

	Action Button::reactMouseMotion(const SDL_MouseMotionEvent& motionEvent)
	{
		viewModel.reactMouseMotion(Point{ motionEvent.x, motionEvent.y });
		if (isAnimating || !viewModel.isAnimating) return Action::NONE;
		isAnimating = true;
		return Action::START_ANIMATION;
	}

	Action Button::reactLeftMouseButtonDown(const SDL_MouseButtonEvent&)
	{
		viewModel.reactLeftMouseButtonDown();
		if (isAnimating || !viewModel.isAnimating) return Action::NONE;
		isAnimating = true;
		return Action::START_ANIMATION;
	}

	Pair<Action, Message> Button::reactLeftMouseButtonUp(const SDL_MouseButtonEvent&)
	{
		viewModel.reactLeftMouseButtonUp();
		if (!viewModel.isAnimating) return Pair{ Action::NONE, Message{ } };
		if (isAnimating) return Pair{ Action::NONE, message };
		isAnimating = true;
		return Pair{ Action::START_ANIMATION, message };
	}

	Action Button::reactMouseLeaveWindow(const SDL_WindowEvent&)
	{
		viewModel.reactMouseLeaveWindow();
		if (isAnimating || !viewModel.isAnimating) return Action::NONE;
		isAnimating = true;
		return Action::START_ANIMATION;
	}

	Pair<Action, Message> Button::reactKeyDown(const SDL_KeyboardEvent& keyEvent)
	{
		viewModel.reactKeyDown(keyEvent.keysym.sym);
		if (!viewModel.isAnimating) return Pair{ Action::NONE, Message{ } };
		if (isAnimating) return Pair{ Action::NONE, message };
		isAnimating = true;
		return Pair{ Action::START_ANIMATION, message };
	}

	Action Button::reactKeyUp(const SDL_KeyboardEvent& keyEvent)
	{
		viewModel.reactKeyUp(keyEvent.keysym.sym);
		if (isAnimating || !viewModel.isAnimating) return Action::NONE;
		isAnimating = true;
		return Action::START_ANIMATION;
	}

	Action Button::step(const unsigned int dt)
	{
		if (!isAnimating) return Action::NONE;
		viewModel.step(dt);
		if (viewModel.isAnimating) return Action::NONE;
		isAnimating = false;
		return Action::STOP_ANIMATION;
	}

	void Button::renderBackground()
	{
		SDL_SetRenderDrawColor(renderer, static_cast<Uint8>(color.r * viewModel.lightness.now), static_cast<Uint8>(color.g *
			viewModel.lightness.now), static_cast<Uint8>(color.b * viewModel.lightness.now), 255u);
		const SDL_Rect rect{ viewModel.rect.position.x, viewModel.rect.position.y, viewModel.rect.size.w, viewModel.rect.size.h };
		SDL_RenderFillRect(renderer, &rect);
	}

	void Button::renderBorder()
	{
		SDL_SetRenderDrawColor(renderer, 128u, 128u, 128u, static_cast<Uint8>(viewModel.borderA.now));
		const SDL_Rect rect{ viewModel.rect.position.x, viewModel.rect.position.y, viewModel.rect.size.w, viewModel.rect.size.h };
		SDL_RenderDrawRect(renderer, &rect);
	}

	void Button::render()
	{
		renderBackground();
		renderBorder();
	}
}

#endif