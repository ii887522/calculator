#ifndef TEST

#include "Button.h"
#include "../Any/View.h"
#include <SDL.h>
#include "../Struct/Pair.h"
#include "../Struct/Message.h"
#include "../Any/Enums.h"

namespace ii887522::Calculator
{
	Button::Button(SDL_Renderer*const renderer, const Rect& rect, const Color& color, const Message& message, const Ability ability,
		const SDL_Keycode keyCode) : View{ renderer }, viewModel{ rect, message, ability, keyCode }, color{ color }, isAnimating{ false }
	{ }

	void Button::enable()
	{
		viewModel.enable();
	}

	void Button::tryDisable()
	{
		viewModel.tryDisable();
	}

	Pair<Action, Message> Button::reactMessage(const Message& message)
	{
		viewModel.reactMessage(message);
		if (isAnimating || !viewModel.getIsAnimating()) return Pair{ Action::NONE, viewModel.getMessage() };
		isAnimating = true;
		return Pair{ Action::START_ANIMATION, viewModel.getMessage() };
	}

	Action Button::reactMouseMotion(const SDL_MouseMotionEvent& motionEvent)
	{
		viewModel.reactMouseMotion(Point{ motionEvent.x, motionEvent.y });
		if (isAnimating || !viewModel.getIsAnimating()) return Action::NONE;
		isAnimating = true;
		return Action::START_ANIMATION;
	}

	Action Button::reactLeftMouseButtonDown(const SDL_MouseButtonEvent&)
	{
		viewModel.reactLeftMouseButtonDown();
		if (isAnimating || !viewModel.getIsAnimating()) return Action::NONE;
		isAnimating = true;
		return Action::START_ANIMATION;
	}

	Pair<Action, Message> Button::reactLeftMouseButtonUp(const SDL_MouseButtonEvent&)
	{
		viewModel.reactLeftMouseButtonUp();
		if (!viewModel.getIsAnimating() || isAnimating) return Pair{ Action::NONE, viewModel.getMessage() };
		isAnimating = true;
		return Pair{ Action::START_ANIMATION, viewModel.getMessage() };
	}

	Action Button::reactMouseLeaveWindow(const SDL_WindowEvent&)
	{
		viewModel.reactMouseLeaveWindow();
		if (isAnimating || !viewModel.getIsAnimating()) return Action::NONE;
		isAnimating = true;
		return Action::START_ANIMATION;
	}

	Pair<Action, Message> Button::reactKeyDown(const SDL_KeyboardEvent& keyEvent)
	{
		viewModel.reactKeyDown(keyEvent.keysym.sym);
		if (!viewModel.getIsAnimating() || isAnimating) return Pair{ Action::NONE, viewModel.getMessage() };
		isAnimating = true;
		return Pair{ Action::START_ANIMATION, viewModel.getMessage() };
	}

	Action Button::reactKeyUp(const SDL_KeyboardEvent& keyEvent)
	{
		viewModel.reactKeyUp(keyEvent.keysym.sym);
		if (isAnimating || !viewModel.getIsAnimating()) return Action::NONE;
		isAnimating = true;
		return Action::START_ANIMATION;
	}

	Action Button::step(const unsigned int dt)
	{
		if (!isAnimating) return Action::NONE;
		viewModel.step(dt);
		if (viewModel.getIsAnimating()) return Action::NONE;
		isAnimating = false;
		return Action::STOP_ANIMATION;
	}

	void Button::renderBackground()
	{
		SDL_SetRenderDrawColor(getRenderer(), static_cast<Uint8>(color.r * viewModel.getLightness().now), static_cast<Uint8>(color.g *
			viewModel.getLightness().now), static_cast<Uint8>(color.b * viewModel.getLightness().now), 255u);
		const SDL_Rect rect{ viewModel.getRect().position.x, viewModel.getRect().position.y, viewModel.getRect().size.w,
			viewModel.getRect().size.h };
		SDL_RenderFillRect(getRenderer(), &rect);
	}

	void Button::renderBorder()
	{
		SDL_SetRenderDrawColor(getRenderer(), 128u, 128u, 128u, static_cast<Uint8>(viewModel.getBorderA().now));
		const SDL_Rect rect{ viewModel.getRect().position.x, viewModel.getRect().position.y, viewModel.getRect().size.w,
			viewModel.getRect().size.h };
		SDL_RenderDrawRect(getRenderer(), &rect);
	}

	void Button::render()
	{
		renderBackground();
		renderBorder();
	}
}

#endif