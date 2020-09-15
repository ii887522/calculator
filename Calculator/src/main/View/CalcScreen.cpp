#ifndef TEST

#include "CalcScreen.h"
#include "../Any/View.h"
#include <SDL.h>
#include "../Any/Enums.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"

namespace ii887522::Calculator
{
	CalcScreen::CalcScreen(SDL_Renderer*const renderer, const Rect& rect) : View{ renderer },
		viewModel{ Rect{ Point{ rect.position.x, rect.position.y + 26 }, Size{ rect.size.w, rect.size.h - 26 } } }, rect{ rect } { }

	Action CalcScreen::reactMouseMotion(const SDL_MouseMotionEvent& motionEvent)
	{
		viewModel.reactMouseMotion(Point{ motionEvent.x, motionEvent.y });
		return Action::NONE;
	}

	Action CalcScreen::reactRightMouseButtonDown(const SDL_MouseButtonEvent&)
	{
		viewModel.reactRightMouseButtonDown();
		return Action::NONE;
	}

	Pair<Action, Message> CalcScreen::reactRightMouseButtonUp(const SDL_MouseButtonEvent&)
	{
		viewModel.reactRightMouseButtonUp();
		return Pair{ Action::NONE, viewModel.getMessage() };
	}

	Action CalcScreen::reactMouseLeaveWindow(const SDL_WindowEvent&)
	{
		viewModel.reactMouseLeaveWindow();
		return Action::NONE;
	}

	void CalcScreen::render()
	{
		SDL_SetRenderDrawColor(getRenderer(), 192u, 192u, 192u, 255u);
		const SDL_Rect sdl_rect{ rect.position.x, rect.position.y, rect.size.w, rect.size.h };
		SDL_RenderFillRect(getRenderer(), &sdl_rect);
	}
}

#endif