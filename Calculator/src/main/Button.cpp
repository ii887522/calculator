#ifndef TEST

#include "Button.h"
#include "View.h"
#include <SDL.h>

namespace ii887522::Calculator
{
	Button::Button(SDL_Renderer*const renderer, const Rect& rect) : View{ renderer }, viewModel{ rect } { }

	Action Button::reactMouseMotion(const SDL_MouseMotionEvent& motionEvent)
	{
		viewModel.reactMouseMotion(Point{ motionEvent.x, motionEvent.y });
		if (viewModel.isAnimating) return Action::START_ANIMATION;
		return Action::NONE;
	}

	Action Button::reactLeftMouseButtonDown(const SDL_MouseButtonEvent&)
	{
		viewModel.reactLeftMouseButtonDown();
		if (viewModel.isAnimating) return Action::START_ANIMATION;
		return Action::NONE;
	}

	Action Button::reactLeftMouseButtonUp(const SDL_MouseButtonEvent&)
	{
		viewModel.reactLeftMouseButtonUp();
		if (viewModel.isAnimating) return Action::START_ANIMATION;
		return Action::NONE;
	}

	Action Button::reactMouseLeaveWindow(const SDL_WindowEvent&)
	{
		viewModel.reactMouseLeaveWindow();
		if (viewModel.isAnimating) return Action::START_ANIMATION;
		return Action::NONE;
	}

	Action Button::step(const unsigned int dt)
	{
		viewModel.step(dt);
		if (viewModel.isAnimating) return Action::NONE;
		return Action::STOP_ANIMATION;
	}

	void Button::render()
	{
		SDL_SetRenderDrawColor(renderer, static_cast<Uint8>(192u * viewModel.lightness.now), static_cast<Uint8>(192u *
			viewModel.lightness.now), static_cast<Uint8>(192u * viewModel.lightness.now), 255u);
		const SDL_Rect rect{ viewModel.rect.position.x, viewModel.rect.position.y, viewModel.rect.size.w, viewModel.rect.size.h };
		SDL_RenderFillRect(renderer, &rect);
	}
}

#endif