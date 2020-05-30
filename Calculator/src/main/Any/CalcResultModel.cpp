#include "CalcResultModel.h"
#include "../Struct/Message.h"
#include <string>
#include "../Functions/string_ext.h"

using std::string;

namespace ii887522::Calculator
{
	CalcResultModel::CalcResultModel() : value{ '0' } { }

	void CalcResultModel::reactDigit(const char digitCh)
	{
		if (value != "0")
			if (value.size() != 10u) value += digitCh;
		else value = digitCh;
	}

	void CalcResultModel::reactBackspace()
	{
		if (value.size() != 1u) value.pop_back();
		else value = '0';
	}

	void CalcResultModel::reactDot()
	{

	}

	void CalcResultModel::reactBinaryOperator(const char operatorCh)
	{
		operatorCh;
	}

	void CalcResultModel::reactUnaryOperator(const string& operatorStr)
	{
		operatorStr;
	}

	void CalcResultModel::reactMessage(const Message& message)
	{
		switch (message.head)
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
		case Message::Head::INPUT_C: value = '0';
			break;
		case Message::Head::INPUT_CE: value = '0';
			break;
		case Message::Head::INPUT_DIVIDE: reactBinaryOperator('/');
			break;
		case Message::Head::INPUT_DOT: reactDot();
			break;
		case Message::Head::INPUT_EQUAL: reactBinaryOperator('=');
			break;
		case Message::Head::INPUT_LEFT: moveLeft();
			break;
		case Message::Head::INPUT_MINUS: reactBinaryOperator('-');
			break;
		case Message::Head::INPUT_MULTIPLY: reactBinaryOperator('x');
			break;
		case Message::Head::INPUT_PLUS: reactBinaryOperator('+');
			break;
		case Message::Head::INPUT_RIGHT: moveRight();
			break;
		case Message::Head::INPUT_SIGN: value = -value;
			break;
		case Message::Head::INPUT_SQR: reactUnaryOperator("sqr");
			break;
		case Message::Head::INPUT_SQRT: reactUnaryOperator("sqrt");
		}
	}
}