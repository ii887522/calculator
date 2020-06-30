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
		calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "2 +" });
		assert(calcExprModel.message.head == Message::Head::EXPR_RESULT);
		assert(calcExprModel.message.body == "3");
		assert(calcExprModel.value == " 1 + 2 +");
		calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "3 -" });
		assert(calcExprModel.message.head == Message::Head::EXPR_RESULT);
		assert(calcExprModel.message.body == "6");
		assert(calcExprModel.value == " 1 + 2 + 3 -");
		calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "4 x" });
		assert(calcExprModel.message.head == Message::Head::EXPR_RESULT);
		assert(calcExprModel.message.body == "2");
		assert(calcExprModel.value == " 1 + 2 + 3 - 4 x");
		calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "5 /" });
		assert(calcExprModel.message.head == Message::Head::EXPR_RESULT);
		assert(calcExprModel.message.body == "10");
		assert(calcExprModel.value == " 1 + 2 + 3 - 4 x 5 /");
		calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "4 +" });
		assert(calcExprModel.message.head == Message::Head::EXPR_RESULT);
		assert(calcExprModel.message.body == "2.5");
		assert(calcExprModel.value == " 1 + 2 + 3 - 4 x 5 / 4 +");
		calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "6 =" });
		assert(calcExprModel.message.head == Message::Head::EXPR_RESULT);
		assert(calcExprModel.message.body == "8.5");
		assert(calcExprModel.value == " 1 + 2 + 3 - 4 x 5 / 4 + 6 =");
		calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "7 +" });
		assert(calcExprModel.message.head == Message::Head::EMPTY);
		assert(calcExprModel.value == " 7 +");
		/*calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(3)" });
		assert(calcExprModel.message.head == Message::Head::EXPR_RESULT);
		assert(calcExprModel.message.body == "9");
		assert(calcExprModel.value == "sqr(3)");*/
	}

	void testCalcExprModel()
	{
		testReactMessage();
	}
}

#endif