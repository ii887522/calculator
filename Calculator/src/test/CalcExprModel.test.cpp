#ifdef TEST

#include "CalcExprModel.test.h"
#include <cassert>
#include "../main/Model/CalcExprModel.h"
#include "../main/Struct/Message.h"

#include <iostream>

namespace ii887522::Calculator
{
	static void testReactMessage()
	{
		{
			CalcExprModel calcExprModel{ 9u };
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_C });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " ");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "1 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " 1 +");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "2 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "3");
			assert(calcExprModel.getValue() == " 1 + 2 +");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "3 -" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "6");
			assert(calcExprModel.getValue() == " 1 + 2 + 3 -");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "4 x" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "2");
			assert(calcExprModel.getValue() == " 1 + 2 + 3 - 4 x");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "5 /" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "10");
			assert(calcExprModel.getValue() == " 1 + 2 + 3 - 4 x 5 /");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "4 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "2.5");
			assert(calcExprModel.getValue() == " 1 + 2 + 3 - 4 x 5 / 4 +");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "6 =" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "8.5");
			assert(calcExprModel.getValue() == " 1 + 2 + 3 - 4 x 5 / 4 + 6 =");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "7 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " 7 +");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_C });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " ");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(3)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "9");
			assert(calcExprModel.getValue() == " sqr(3)");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqrt(9)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "3");
			assert(calcExprModel.getValue() == " sqrt(sqr(3))");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(3)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "9");
			assert(calcExprModel.getValue() == " sqr(sqrt(sqr(3)))");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_C });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " ");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqrt(9)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "3");
			assert(calcExprModel.getValue() == " sqrt(9)");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "3 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " sqrt(9) +");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "1 =" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "4");
			assert(calcExprModel.getValue() == " sqrt(9) + 1 =");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_CE });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " ");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "1 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " 1 +");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(3)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "9");
			assert(calcExprModel.getValue() == " 1 + sqr(3)");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_CE });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " 1 +");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqrt(9)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "3");
			assert(calcExprModel.getValue() == " 1 + sqrt(9)");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "3 -" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "4");
			assert(calcExprModel.getValue() == " 1 + sqrt(9) -");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "2 =" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "2");
			assert(calcExprModel.getValue() == " 1 + sqrt(9) - 2 =");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(2)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "4");
			assert(calcExprModel.getValue() == " sqr(2)");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "4 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " sqr(2) +");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_CE });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " sqr(2) +");
			calcExprModel.reactMessage(Message{ Message::Head::LAST_BINARY_OPERATOR, "-" });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " sqr(2) -");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_DOT });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " sqr(2) -");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "1 =" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "3");
			assert(calcExprModel.getValue() == " sqr(2) - 1 =");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_DOT });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " ");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "0 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " 0 +");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(3)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "9");
			assert(calcExprModel.getValue() == " 0 + sqr(3)");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "9 =" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "9");
			assert(calcExprModel.getValue() == " 0 + sqr(3) =");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqrt(9)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "3");
			assert(calcExprModel.getValue() == " sqrt(9)");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_4 });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " ");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "4 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " 4 +");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(4)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "16");
			assert(calcExprModel.getValue() == " 4 + sqr(4)");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_0 });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " 4 +");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(3)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "9");
			assert(calcExprModel.getValue() == " 4 + sqr(3)");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "9 -" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "13");
			assert(calcExprModel.getValue() == " 4 + sqr(3) -");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(4)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "16");
			assert(calcExprModel.getValue() == " 4 + sqr(3) - sqr(4)");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "16 x" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "-3");
			assert(calcExprModel.getValue() == " 4 + sqr(3) - sqr(4) x");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(5)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "25");
			assert(calcExprModel.getValue() == " 4 + sqr(3) - sqr(4) x sqr(5)");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "25 /" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "-75");
			assert(calcExprModel.getValue() == " 4 + sqr(3) - sqr(4) x sqr(5) /");
		}
		{
			CalcExprModel calcExprModel{ 3u };
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_C });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " ");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "1 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " 1 +");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "2 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "3");
			assert(calcExprModel.getValue() == " 1 + 2 +");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "3 -" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "6");
			assert(calcExprModel.getValue() == " 1 + 2 + 3 -");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "4 x" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "2");
			assert(calcExprModel.getValue() == " 1 + 2 + 3 - 4 x");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "5 /" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "10");
			assert(calcExprModel.getValue() == " 1 + 2 + 3 - 4 x 5 /");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "4 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "2.5");
			assert(calcExprModel.getValue() == " 1 + 2 + 3 - 4 x 5 / 4 +");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "6 =" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "8.5");
			assert(calcExprModel.getValue() == " 1 + 2 + 3 - 4 x 5 / 4 + 6 =");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "7 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " 7 +");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_C });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " ");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(3)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "9");
			assert(calcExprModel.getValue() == " sqr(3)");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqrt(9)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "3");
			assert(calcExprModel.getValue() == " sqrt(sqr(3))");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(3)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "9");
			assert(calcExprModel.getValue() == " sqr(sqrt(sqr(3)))");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_C });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " ");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqrt(9)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "3");
			assert(calcExprModel.getValue() == " sqrt(9)");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "3 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " sqrt(9) +");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "1 =" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "4");
			assert(calcExprModel.getValue() == " sqrt(9) + 1 =");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_CE });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " ");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "1 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " 1 +");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(3)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "9");
			assert(calcExprModel.getValue() == " 1 + sqr(3)");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_CE });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " 1 +");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqrt(9)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "3");
			assert(calcExprModel.getValue() == " 1 + sqrt(9)");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "3 -" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "4");
			assert(calcExprModel.getValue() == " 1 + sqrt(9) -");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "2 =" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "2");
			assert(calcExprModel.getValue() == " 1 + sqrt(9) - 2 =");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(2)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "4");
			assert(calcExprModel.getValue() == " sqr(2)");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "4 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " sqr(2) +");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_CE });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " sqr(2) +");
			calcExprModel.reactMessage(Message{ Message::Head::LAST_BINARY_OPERATOR, "-" });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " sqr(2) -");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_DOT });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " sqr(2) -");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "1 =" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "3");
			assert(calcExprModel.getValue() == " sqr(2) - 1 =");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_DOT });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " ");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "0 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " 0 +");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(3)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "9");
			assert(calcExprModel.getValue() == " 0 + sqr(3)");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "9 =" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "9");
			assert(calcExprModel.getValue() == " 0 + sqr(3) =");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqrt(9)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "3");
			assert(calcExprModel.getValue() == " sqrt(9)");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_4 });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " ");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "4 +" });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " 4 +");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(4)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "16");
			assert(calcExprModel.getValue() == " 4 + sqr(4)");
			calcExprModel.reactMessage(Message{ Message::Head::INPUT_0 });
			assert(calcExprModel.getMessage().head == Message::Head::EMPTY);
			assert(calcExprModel.getValue() == " 4 +");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(3)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "9");
			assert(calcExprModel.getValue() == " 4 + sqr(3)");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "9 -" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "13");
			assert(calcExprModel.getValue() == " 4 + sqr(3) -");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(4)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "16");
			assert(calcExprModel.getValue() == " 4 + sqr(3) - sqr(4)");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "16 x" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "-3");
			assert(calcExprModel.getValue() == " 4 + sqr(3) - sqr(4) x");
			calcExprModel.reactMessage(Message{ Message::Head::UNARY_EXPR, "sqr(5)" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "25");
			assert(calcExprModel.getValue() == " 4 + sqr(3) - sqr(4) x sqr(5)");
			calcExprModel.reactMessage(Message{ Message::Head::BINARY_EXPR, "25 /" });
			assert(calcExprModel.getMessage().head == Message::Head::EXPR_RESULT);
			assert(calcExprModel.getMessage().body == "-75");
			assert(calcExprModel.getValue() == " 4 + sqr(3) - sqr(4) x sqr(5) /");
		}
	}

	void testCalcExprModel()
	{
		testReactMessage();
	}
}

#endif