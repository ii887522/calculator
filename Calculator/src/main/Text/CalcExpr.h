#ifndef TEST

#ifndef II887522_CALCULATOR_CALC_EXPR_H
#define II887522_CALCULATOR_CALC_EXPR_H

#include "../ResourceView/Text.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "../Struct/Rect.h"
#include "../Struct/Message.h"
#include "../Any/CalcExprModel.h"
#include <algorithm>

using std::max;

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

		const int speed;
		const Rect boundingRect;
		TTF_Font*const font;
		CalcExprModel viewModel;

		void set(const string& value);

		constexpr void moveLeft()
		{
			position.x -= speed;
			if (position.x < boundingRect.position.x + boundingRect.size.w) position.x = boundingRect.position.x + boundingRect.size.w;
		}

		constexpr void moveRight()
		{
			position.x += speed;
			if (position.x - surface->w > boundingRect.position.x)
				position.x = max(boundingRect.position.x + surface->w, boundingRect.position.x + boundingRect.size.w);
		}

	public:
		// Param renderer: it must not be assigned to integer
		// Param font: it must not be assigned to integer
		explicit CalcExpr(SDL_Renderer*const renderer, const Rect& calcScreenRect, const unsigned int maxSizeIgnoreDash,
			const int horizontalMargin = 16, TTF_Font*const font = TTF_OpenFont("res/main/arial.ttf", 16));

		virtual Message reactMessage(const Message&) override;
		virtual void render() override;
		~CalcExpr();
	};
}

#endif
#endif