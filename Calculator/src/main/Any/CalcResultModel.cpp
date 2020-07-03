#include "CalcResultModel.h"
#include "../Struct/Message.h"
#include <string>
#include "../Functions/string_ext.h"

using std::string;

namespace ii887522::Calculator
{
	CalcResultModel::CalcResultModel(const unsigned int maxSizeIgnoreDash) : state{ State::INT }, maxSizeIgnoreDash{ maxSizeIgnoreDash },
		value{ '0' }, message{ } { }

	void CalcResultModel::reactExprResult(const string& resultStr)
	{
		value = resultStr;
		if (resultStr != "NO SPACE") return;
		state = State::ERROR;
		message = Message{ Message::Head::ERROR };
	}

	void CalcResultModel::reactDigitWhenNumber(const char digitCh)
	{
		if (value != "0")
		{
			if (sizeIgnoreDash(value) != maxSizeIgnoreDash) value += digitCh;
		}
		else value = digitCh;
	}

	void CalcResultModel::reactDigitWhenBinaryOperatorPressed(const char digitCh)
	{
		state = State::BINARY_OPERATOR_PRESSED_THEN_INT;
		value = digitCh;
	}

	void CalcResultModel::reactDigitWhenEqualPressed(const char digitCh)
	{
		state = State::INT;
		value = digitCh;
	}

	void CalcResultModel::reactDigitWhenUnaryOperatorPressed(const char digitCh)
	{
		state = State::INT;
		value = digitCh;
	}

	void CalcResultModel::reactDigitWhenError(const char digitCh)
	{
		state = State::INT;
		value = digitCh;
		message = Message{ Message::Head::FIXED };
	}

	void CalcResultModel::reactDigit(const char digitCh)
	{
		switch (state)
		{
		case State::BINARY_OPERATOR_PRESSED:
		case State::BINARY_OPERATOR_PRESSED_THEN_UNARY_OPERATOR_PRESSED:
			reactDigitWhenBinaryOperatorPressed(digitCh);
			break;
		case State::EQUAL_PRESSED: reactDigitWhenEqualPressed(digitCh);
			break;
		case State::UNARY_OPERATOR_PRESSED: reactDigitWhenUnaryOperatorPressed(digitCh);
			break;
		case State::ERROR: reactDigitWhenError(digitCh);
			break;
		default: reactDigitWhenNumber(digitCh);
		}
	}

	void CalcResultModel::reactBackspace()
	{
		switch (state)
		{
		case State::BINARY_OPERATOR_PRESSED:
		case State::EQUAL_PRESSED:
		case State::UNARY_OPERATOR_PRESSED:
		case State::BINARY_OPERATOR_PRESSED_THEN_UNARY_OPERATOR_PRESSED:
			return;
		}
		if (sizeIgnoreDash(value) != 1u)
		{
			if (value[value.size() - 1u] == '.')
			{
				switch (state)
				{
				case State::FLOAT: state = State::INT;
					break;
				case State::BINARY_OPERATOR_PRESSED_THEN_FLOAT: state = State::BINARY_OPERATOR_PRESSED_THEN_INT;
				}
			}
			value.pop_back();
		}
		else value = '0';
	}

	void CalcResultModel::clear()
	{
		value = '0';
		if (state == State::ERROR) message = Message{ Message::Head::FIXED };
		state = State::INT;
	}

	void CalcResultModel::clearEntryWhenBinaryOperatorPressed()
	{
		value = '0';
		state = State::BINARY_OPERATOR_PRESSED_THEN_INT;
	}

	void CalcResultModel::clearEntry()
	{
		switch (state)
		{
		case State::BINARY_OPERATOR_PRESSED:
		case State::BINARY_OPERATOR_PRESSED_THEN_INT:
		case State::BINARY_OPERATOR_PRESSED_THEN_FLOAT:
		case State::BINARY_OPERATOR_PRESSED_THEN_UNARY_OPERATOR_PRESSED:
			clearEntryWhenBinaryOperatorPressed();
			break;
		case State::EQUAL_PRESSED:
		case State::INT:
		case State::FLOAT:
		case State::UNARY_OPERATOR_PRESSED:
		case State::ERROR:
			clear();
		}
	}

	void CalcResultModel::reactDotWhenInt()
	{
		if (sizeIgnoreDash(value) == maxSizeIgnoreDash) return;
		value += '.';
		state = State::FLOAT;
	}

	void CalcResultModel::reactDotWhenBinaryOperatorPressed()
	{
		value = "0.";
		state = State::BINARY_OPERATOR_PRESSED_THEN_FLOAT;
	}

	void CalcResultModel::reactDotWhenBinaryOperatorPressedThenInt()
	{
		if (sizeIgnoreDash(value) == maxSizeIgnoreDash) return;
		value += '.';
		state = State::BINARY_OPERATOR_PRESSED_THEN_FLOAT;
	}

	void CalcResultModel::reactDotWhenEqualPressed()
	{
		value = "0.";
		state = State::FLOAT;
	}

	void CalcResultModel::reactDotWhenUnaryOperatorPressed()
	{
		value = "0.";
		state = State::FLOAT;
	}

	void CalcResultModel::reactDot()
	{
		switch (state)
		{
		case State::INT:
			reactDotWhenInt();
			break;
		case State::BINARY_OPERATOR_PRESSED:
		case State::BINARY_OPERATOR_PRESSED_THEN_UNARY_OPERATOR_PRESSED:
			reactDotWhenBinaryOperatorPressed();
			break;
		case State::BINARY_OPERATOR_PRESSED_THEN_INT:
			reactDotWhenBinaryOperatorPressedThenInt();
			break;
		case State::EQUAL_PRESSED:
			reactDotWhenEqualPressed();
			break;
		case State::UNARY_OPERATOR_PRESSED:
			reactDotWhenUnaryOperatorPressed();
		}
	}

	void CalcResultModel::tryToggleSign()
	{
		switch (state)
		{
		case State::BINARY_OPERATOR_PRESSED:
		case State::EQUAL_PRESSED:
		case State::UNARY_OPERATOR_PRESSED:
		case State::BINARY_OPERATOR_PRESSED_THEN_UNARY_OPERATOR_PRESSED:
			return;
		}
		value = -value;
	}

	void CalcResultModel::reactBinaryOperatorWhenNumber(const char operatorCh)
	{
		if (operatorCh == '=') return;
		state = State::BINARY_OPERATOR_PRESSED;
		noTrailingDot(value);
		message = Message{ Message::Head::BINARY_EXPR, value + " " + operatorCh };
	}

	void CalcResultModel::reactBinaryOperatorWhenBinaryOperatorPressed(const char operatorCh)
	{
		if (operatorCh != '=') message = Message{ Message::Head::LAST_BINARY_OPERATOR, string{ operatorCh } };
	}

	void CalcResultModel::reactBinaryOperatorWhenBinaryOperatorPressedBefore(const char operatorCh)
	{
		state = operatorCh != '=' ? State::BINARY_OPERATOR_PRESSED : State::EQUAL_PRESSED;
		noTrailingDot(value);
		message = Message{ Message::Head::BINARY_EXPR, value + " " + operatorCh };
	}

	void CalcResultModel::reactBinaryOperatorWhenEqualPressed(const char operatorCh)
	{
		if (operatorCh == '=') return;
		state = State::BINARY_OPERATOR_PRESSED;
		noTrailingDot(value);
		message = Message{ Message::Head::BINARY_EXPR, value + " " + operatorCh };
	}

	void CalcResultModel::reactBinaryOperatorWhenUnaryOperatorPressed(const char operatorCh)
	{
		if (operatorCh == '=') return;
		state = State::BINARY_OPERATOR_PRESSED;
		noTrailingDot(value);
		message = Message{ Message::Head::BINARY_EXPR, value + " " + operatorCh };
	}

	void CalcResultModel::reactBinaryOperator(const char operatorCh)
	{
		switch (state)
		{
		case State::INT:
		case State::FLOAT:
			reactBinaryOperatorWhenNumber(operatorCh);
			break;
		case State::BINARY_OPERATOR_PRESSED:
			reactBinaryOperatorWhenBinaryOperatorPressed(operatorCh);
			break;
		case State::BINARY_OPERATOR_PRESSED_THEN_INT:
		case State::BINARY_OPERATOR_PRESSED_THEN_FLOAT:
		case State::BINARY_OPERATOR_PRESSED_THEN_UNARY_OPERATOR_PRESSED:
			reactBinaryOperatorWhenBinaryOperatorPressedBefore(operatorCh);
			break;
		case State::EQUAL_PRESSED:
			reactBinaryOperatorWhenEqualPressed(operatorCh);
			break;
		case State::UNARY_OPERATOR_PRESSED:
			reactBinaryOperatorWhenUnaryOperatorPressed(operatorCh);
		}
	}

	void CalcResultModel::reactUnaryOperatorWhenBinaryOperatorNotPressed(const string& operatorStr)
	{
		state = State::UNARY_OPERATOR_PRESSED;
		noTrailingDot(value);
		message = Message{ Message::Head::UNARY_EXPR, operatorStr + '(' + value + ')' };
	}

	void CalcResultModel::reactUnaryOperatorWhenBinaryOperatorPressed(const string& operatorStr)
	{
		state = State::BINARY_OPERATOR_PRESSED_THEN_UNARY_OPERATOR_PRESSED;
		noTrailingDot(value);
		message = Message{ Message::Head::UNARY_EXPR, operatorStr + '(' + value + ')' };
	}

	void CalcResultModel::reactUnaryOperatorWhenEqualPressed(const string& operatorStr)
	{
		state = State::UNARY_OPERATOR_PRESSED;
		noTrailingDot(value);
		message = Message{ Message::Head::UNARY_EXPR, operatorStr + '(' + value + ')' };
	}

	void CalcResultModel::reactUnaryOperator(const string& operatorStr)
	{
		switch (state)
		{
		case State::INT:
		case State::FLOAT:
		case State::UNARY_OPERATOR_PRESSED:
			reactUnaryOperatorWhenBinaryOperatorNotPressed(operatorStr);
			break;
		case State::BINARY_OPERATOR_PRESSED:
		case State::BINARY_OPERATOR_PRESSED_THEN_INT:
		case State::BINARY_OPERATOR_PRESSED_THEN_FLOAT:
		case State::BINARY_OPERATOR_PRESSED_THEN_UNARY_OPERATOR_PRESSED:
			reactUnaryOperatorWhenBinaryOperatorPressed(operatorStr);
			break;
		case State::EQUAL_PRESSED:
			reactUnaryOperatorWhenEqualPressed(operatorStr);
		}
	}

	void CalcResultModel::reactMessage(const Message& p_message)
	{
		message = Message{ };
		switch (p_message.head)
		{
		case Message::Head::EXPR_RESULT: reactExprResult(p_message.body);
			break;
		case Message::Head::INPUT_0: reactDigit('0');
			break;
		case Message::Head::INPUT_1: reactDigit('1');
			break;
		case Message::Head::INPUT_2: reactDigit('2');
			break;
		case Message::Head::INPUT_3: reactDigit('3');
			break;
		case Message::Head::INPUT_4: reactDigit('4');
			break;
		case Message::Head::INPUT_5: reactDigit('5');
			break;
		case Message::Head::INPUT_6: reactDigit('6');
			break;
		case Message::Head::INPUT_7: reactDigit('7');
			break;
		case Message::Head::INPUT_8: reactDigit('8');
			break;
		case Message::Head::INPUT_9: reactDigit('9');
			break;
		case Message::Head::INPUT_BACKSPACE: reactBackspace();
			break;
		case Message::Head::INPUT_C: clear();
			break;
		case Message::Head::INPUT_CE: clearEntry();
			break;
		case Message::Head::INPUT_DIVIDE: reactBinaryOperator('/');
			break;
		case Message::Head::INPUT_DOT: reactDot();
			break;
		case Message::Head::INPUT_EQUAL: reactBinaryOperator('=');
			break;
		case Message::Head::INPUT_MINUS: reactBinaryOperator('-');
			break;
		case Message::Head::INPUT_MULTIPLY: reactBinaryOperator('x');
			break;
		case Message::Head::INPUT_PLUS: reactBinaryOperator('+');
			break;
		case Message::Head::INPUT_SIGN: tryToggleSign();
			break;
		case Message::Head::INPUT_SQR: reactUnaryOperator("sqr");
			break;
		case Message::Head::INPUT_SQRT: reactUnaryOperator("sqrt");
		}
	}
}