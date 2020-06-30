#ifdef TEST

#include "CalcExprModel.test.h"
#include <cassert>
#include "../main/Any/CalcExprModel.h"
#include "../main/Struct/Message.h"

namespace ii887522::Calculator
{
	static void testReactMessage()
	{
		CalcExprModel calcExprModel;
		calcExprModel.reactMessage(Message{ Message::Head::INPUT_C });
		assert(calcExprModel.message.head == Message::Head::EMPTY);
		assert(calcExprModel.value == " ");
		calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "1 +" });
		assert(calcExprModel.message.head == Message::Head::EMPTY);
		assert(calcExprModel.value == " 1 +");
		calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "2 -" });
		assert(calcExprModel.message.head == Message::Head::EXPR_RESULT);
		assert(calcExprModel.message.body == "3");
		assert(calcExprModel.value == " 1 + 2 -");
	}

	void testCalcExprModel()
	{
		testReactMessage();
	}
}

#endif