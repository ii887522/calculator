#ifndef TEST

#ifndef II887522_CALCULATOR_CALC_RESULT_H
#define II887522_CALCULATOR_CALC_RESULT_H

#include "../ResourceView/Text.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "../Struct/Rect.h"
#include "../Struct/Message.h"
#include "../Model/CalcResultModel.h"
#include "../Struct/Pair.h"
#include "../Any/Enums.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class CalcResult final : public Text
	{
		// remove copy semantics
		CalcResult(const CalcResult&) = delete;
		CalcResult& operator=(const CalcResult&) = delete;

		// remove move semantics
		CalcResult(CalcResult&&) = delete;
		CalcResult& operator=(CalcResult&&) = delete;

		TTF_Font*const font;
		CalcResultModel viewModel;

		void set(const string& value);

	public:
		// Param renderer: it must not be assigned to integer
		// Param font: it must not be assigned to integer
		explicit CalcResult(SDL_Renderer*const renderer, const Rect& calcScreenRect, const unsigned int maxSizeIgnoreDash,
			TTF_Font*const font = TTF_OpenFont("res/main/courbd.ttf", 48));

		virtual Pair<Action, Message> reactMessage(const Message&) override;
		virtual void render() override;
		~CalcResult();
	};
}

#endif
#endif