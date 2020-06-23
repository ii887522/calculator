#ifdef TEST

#include "CalcResultModel.test.h"
#include <cassert>
#include "../main/Any/CalcResultModel.h"
#include "../main/Struct/Message.h"

namespace ii887522::Calculator
{
	static void testReactMessage()
	{
		CalcResultModel calcResultModel;
		calcResultModel.reactMessage(Message{ });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_0 });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_1 });
		assert(calcResultModel.value == "1");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_2 });
		assert(calcResultModel.value == "12");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_3 });
		assert(calcResultModel.value == "123");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_4 });
		assert(calcResultModel.value == "1234");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_5 });
		assert(calcResultModel.value == "12345");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_6 });
		assert(calcResultModel.value == "123456");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_7 });
		assert(calcResultModel.value == "1234567");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_8 });
		assert(calcResultModel.value == "12345678");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_9 });
		assert(calcResultModel.value == "123456789");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_0 });
		assert(calcResultModel.value == "123456789");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_1 });
		assert(calcResultModel.value == "123456789");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_BACKSPACE });
		assert(calcResultModel.value == "12345678");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_BACKSPACE });
		assert(calcResultModel.value == "1234567");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_BACKSPACE });
		assert(calcResultModel.value == "123456");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_BACKSPACE });
		assert(calcResultModel.value == "12345");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_BACKSPACE });
		assert(calcResultModel.value == "1234");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_BACKSPACE });
		assert(calcResultModel.value == "123");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_BACKSPACE });
		assert(calcResultModel.value == "12");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_BACKSPACE });
		assert(calcResultModel.value == "1");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_BACKSPACE });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_BACKSPACE });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_DOT });
		assert(calcResultModel.value == "0.");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_DOT });
		assert(calcResultModel.value == "0.");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_BACKSPACE });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_SIGN });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_1 });
		assert(calcResultModel.value == "1");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_SIGN });
		assert(calcResultModel.value == "-1");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_C });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_CE });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_1 });
		assert(calcResultModel.value == "1");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_2 });
		assert(calcResultModel.value == "12");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_DOT });
		assert(calcResultModel.value == "12.");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_PLUS });
		assert(calcResultModel.value == "12");
		assert(calcResultModel.message.head == Message::Head::BINARY_EXPR);
		assert(calcResultModel.message.body == "12 +");
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_0 });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_1 });
		assert(calcResultModel.value == "1");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_PLUS });
		assert(calcResultModel.value == "1");
		assert(calcResultModel.message.head == Message::Head::BINARY_EXPR);
		assert(calcResultModel.message.body == "1 +");
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_BACKSPACE });
		assert(calcResultModel.value == "1");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_DOT });
		assert(calcResultModel.value == "0.");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_1 });
		assert(calcResultModel.value == "0.1");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_PLUS });
		assert(calcResultModel.value == "0.1");
		assert(calcResultModel.message.head == Message::Head::BINARY_EXPR);
		assert(calcResultModel.message.body == "0.1 +");
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_SIGN });
		assert(calcResultModel.value == "0.1");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_0 });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_DOT });
		assert(calcResultModel.value == "0.");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_DOT });
		assert(calcResultModel.value == "0.");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_CE });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_C });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_EQUAL });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_PLUS });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::BINARY_EXPR);
		assert(calcResultModel.message.body == "0 +");
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_EQUAL });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_1 });
		assert(calcResultModel.value == "1");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_PLUS });
		assert(calcResultModel.value == "1");
		assert(calcResultModel.message.head == Message::Head::BINARY_EXPR);
		assert(calcResultModel.message.body == "1 +");
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_2 });
		assert(calcResultModel.value == "2");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_EQUAL });
		assert(calcResultModel.value == "2");
		assert(calcResultModel.message.head == Message::Head::BINARY_EXPR);
		assert(calcResultModel.message.body == "2 =");
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_SIGN });
		assert(calcResultModel.value == "2");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_C });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_1 });
		assert(calcResultModel.value == "1");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_SQR });
		assert(calcResultModel.value == "1");
		assert(calcResultModel.message.head == Message::Head::UNARY_EXPR);
		assert(calcResultModel.message.body == "sqr(1)");
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_DOT });
		assert(calcResultModel.value == "0.");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_BACKSPACE });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_2 });
		assert(calcResultModel.value == "2");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_SQR });
		assert(calcResultModel.value == "2");
		assert(calcResultModel.message.head == Message::Head::UNARY_EXPR);
		assert(calcResultModel.message.body == "sqr(2)");
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_C });
		assert(calcResultModel.value == "0");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_2 });
		assert(calcResultModel.value == "2");
		assert(calcResultModel.message.head == Message::Head::EMPTY);
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_PLUS });
		assert(calcResultModel.value == "2");
		assert(calcResultModel.message.head == Message::Head::BINARY_EXPR);
		assert(calcResultModel.message.body == "2 +");
		calcResultModel.reactMessage(Message{ Message::Head::INPUT_SQR });
		assert(calcResultModel.value == "2");
		assert(calcResultModel.message.head == Message::Head::UNARY_EXPR);
		assert(calcResultModel.message.body == "sqr(2)");
	}

	void testCalcResultModel()
	{
		testReactMessage();
	}
}

#endif