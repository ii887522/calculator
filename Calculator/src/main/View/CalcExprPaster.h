#ifndef TEST

#ifndef II887522_CALCULATOR_CALC_EXPR_PASTER_H
#define II887522_CALCULATOR_CALC_EXPR_PASTER_H

#include "../Any/View.h"
#include "../Any/Enums.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	struct CalcExprPaster final : public View
	{
		// remove copy semantics
		CalcExprPaster(const CalcExprPaster&) = delete;
		CalcExprPaster& operator=(const CalcExprPaster&) = delete;

		// remove move semantics
		CalcExprPaster(CalcExprPaster&&) = delete;
		CalcExprPaster& operator=(CalcExprPaster&&) = delete;

		explicit CalcExprPaster();
		virtual Pair<Action, Message> reactMessage(const Message&) override;
	};
}

#endif
#endif