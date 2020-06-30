#ifndef TEST

#ifndef II887522_CALUCLATOR_CALC_EXPR_H
#define II887522_CALUCLATOR_CALC_EXPR_H

#include "../ResourceView/Text.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "../Struct/Rect.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class CalcExpr final : public Text
	{
		// remove copy semantics
		CalcExpr(const CalcExpr&) = delete;
		CalcExpr& operator=(const CalcExpr&) = delete;

		// remove move semantics
		CalcExpr(CalcExpr&&) = delete;
		CalcExpr& operator=(CalcExpr&&) = delete;

		TTF_Font* const font;

	public:
		// Param renderer: it must not be assigned to integer
		// Param font: it must not be assigned to integer
		explicit CalcExpr(SDL_Renderer* const renderer, const Rect& calcScreenRect,
			TTF_Font* const font = TTF_OpenFont("res/main/courbd.ttf", 16));

		virtual Message reactMessage(const Message&) override;
		virtual void render() override;
		~CalcExpr();
	};
}

#endif
#endif