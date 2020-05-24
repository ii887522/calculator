#ifndef TEST

#ifndef II887522_CALCULATOR_CALC_SCREEN_H
#define II887522_CALCULATOR_CALC_SCREEN_H

#include <SDL.h>
#include "../Any/View.h"
#include "../Struct/Rect.h"

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

		const Rect rect;

	public:
		// Param renderer: it must not be assigned to integer
		explicit CalcScreen(SDL_Renderer*const renderer, const Rect&);

		virtual void render() override;
	};
}

#endif
#endif