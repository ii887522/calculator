#ifndef TEST

#ifndef II887522_CALCULATOR_CALC_SCREEN_H
#define II887522_CALCULATOR_CALC_SCREEN_H

#include <SDL.h>
#include "../Any/View.h"
#include "../Struct/Rect.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"
#include "../Any/Enums.h"
#include "../Model/CalcScreenModel.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class CalcScreen final : public View
	{
		// remove copy semantics
		CalcScreen(const CalcScreen&) = delete;
		CalcScreen& operator=(const CalcScreen&) = delete;

		// remove move semantics
		CalcScreen(CalcScreen&&) = delete;
		CalcScreen& operator=(CalcScreen&&) = delete;

		CalcScreenModel viewModel;
		const Rect rect;

	public:
		// Param renderer: it must not be assigned to integer
		explicit CalcScreen(SDL_Renderer*const renderer, const Rect&);

		virtual Action reactMouseMotion(const SDL_MouseMotionEvent&) override;
		virtual Action reactRightMouseButtonDown(const SDL_MouseButtonEvent&) override;
		virtual Pair<Action, Message> reactRightMouseButtonUp(const SDL_MouseButtonEvent&) override;
		virtual Action reactMouseLeaveWindow(const SDL_WindowEvent&) override;
		virtual void render() override;
	};
}

#endif
#endif