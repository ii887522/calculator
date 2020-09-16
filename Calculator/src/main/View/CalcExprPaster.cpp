#ifndef TEST

#include "CalcExprPaster.h"
#include "../Any/View.h"
#include "../Any/Enums.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"
#include <iostream>

namespace ii887522::Calculator
{
	CalcExprPaster::CalcExprPaster() : View{ nullptr } { }

	Pair<Action, Message> CalcExprPaster::reactMessage(const Message& message)
	{
		if (message.head != Message::Head::PASTE_TO_CALC_RESULT) return Pair{ Action::NONE, Message{ } };

		return Pair{ Action::NONE, Message{ } };
	}
}

#endif