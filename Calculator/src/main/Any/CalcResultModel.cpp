#include "CalcResultModel.h"
#include "../Struct/Message.h"
#include <string>
#include "../Functions/string_ext.h"

using std::string;

namespace ii887522::Calculator
{
	CalcResultModel::CalcResultModel() : state{ State::INT }, value{ '0' }, message{ } { }

	void CalcResultModel::reactDigitWhenNumber(const char digitCh)
	{
		if (value != "0")
		{
			if (sizeIgnoreDash(value) != 9u) value += digitCh;
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
			if (value[value.size() - 1u] == '.') state = State::INT;
			value.pop_back();
		}
		else value = '0';
	}

	void CalcResultModel::clear()
	{
		value = '0';
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
			clear();
		}
	}

	void CalcResultModel::reactDotWhenInt()
	{
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

	void CalcResultModel::reactBinaryOperatorWhenBinaryOperatorPressedThenNumber(const char operatorCh)
	{
		state = operatorCh != '=' ? State::BINARY_OPERATOR_PRESSED : State::EQUAL_PRESSED;
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
		case State::BINARY_OPERATOR_PRESSED_THEN_INT:
		case State::BINARY_OPERATOR_PRESSED_THEN_FLOAT:
			reactBinaryOperatorWhenBinaryOperatorPressedThenNumber(operatorCh);
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
		}
	}

	void CalcResultModel::reactMessage(const Message& p_message)
	{
		message = Message{ };
		switch (p_message.head)
		{
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