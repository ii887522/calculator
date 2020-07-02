#include "CalcExprModel.h"
#include "../Struct/Message.h"
#include <string>
#include "../Functions/string_ext.h"
#include <cmath>

using std::string;
using std::sqrt;

namespace ii887522::Calculator
{
	CalcExprModel::CalcExprModel(const unsigned int maxSizeIgnoreDash) : state{ State::EMPTY }, result{ 0. },
		maxSizeIgnoreDash{ maxSizeIgnoreDash }, value{ " " }, message{ } { }
		// " " because TTF_RenderText_* requires text with at least 1 character to render

	void CalcExprModel::reactDigit()
	{
		switch (state)
		{
		case State::EQUAL_PRESSED:
			clear();
			break;
		case State::UNARY_OPERATOR_PRESSED:
		case State::BINARY_OPERATOR_PRESSED_THEN_UNARY_OPERATOR_PRESSED:
			clearEntry();
		}
	}

	void CalcExprModel::clear()
	{
		value = " ";
		state = State::EMPTY;
		result = 0.;
	}

	void CalcExprModel::clearEntryWhenBinaryOperatorPressedThenUnaryOperatorPressed()
	{
		value = value.substr(0u, value.rfind(' '));
		state = State::BINARY_OPERATOR_PRESSED;
	}

	void CalcExprModel::clearEntry()
	{
		switch (state)
		{
		case State::EQUAL_PRESSED:
		case State::UNARY_OPERATOR_PRESSED:
			clear();
			break;
		case State::BINARY_OPERATOR_PRESSED_THEN_UNARY_OPERATOR_PRESSED:
			clearEntryWhenBinaryOperatorPressedThenUnaryOperatorPressed();
		}
	}

	void CalcExprModel::reactBinaryExprWhenEmpty(const string& exprStr)
	{
		value += exprStr;
		state = State::BINARY_OPERATOR_PRESSED;
		result = getNumberFromBinaryExpr(exprStr);
	}

	void CalcExprModel::reactBinaryExprWhenUnaryOperatorPressed(const string& exprStr)
	{
		state = State::BINARY_OPERATOR_PRESSED;
		value += string{ ' ' } + exprStr[exprStr.size() - 1u];
	}

	void CalcExprModel::reactBinaryExprWhenBinaryOperatorPressed(const string& exprStr)
	{
		switch (value[value.size() - 1u])
		{
		case '+': result += getNumberFromBinaryExpr(exprStr);
			break;
		case '-': result -= getNumberFromBinaryExpr(exprStr);
			break;
		case 'x': result *= getNumberFromBinaryExpr(exprStr);
			break;
		case '/': result /= getNumberFromBinaryExpr(exprStr);
		}
		value += ' ' + exprStr;
		if (exprStr[exprStr.size() - 1u] == '=') state = State::EQUAL_PRESSED;
		message = Message{ Message::Head::EXPR_RESULT, toString(result, maxSizeIgnoreDash) };
	}

	void CalcExprModel::reactBinaryExprWhenEqualPressed(const string& exprStr)
	{
		clear();
		reactBinaryExprWhenEmpty(exprStr);
	}

	void CalcExprModel::reactBinaryExprWhenBinaryOperatorPressedThenUnaryOperatorPressed(const string& exprStr)
	{
		switch (value[value.rfind(' ') - 1u])
		{
		case '+': result += getNumberFromBinaryExpr(exprStr);
			break;
		case '-': result -= getNumberFromBinaryExpr(exprStr);
			break;
		case 'x': result *= getNumberFromBinaryExpr(exprStr);
			break;
		case '/': result /= getNumberFromBinaryExpr(exprStr);
		}
		value += string{ ' ' } + exprStr[exprStr.size() - 1u];
		state = exprStr[exprStr.size() - 1u] == '=' ? State::EQUAL_PRESSED : State::BINARY_OPERATOR_PRESSED;
		message = Message{ Message::Head::EXPR_RESULT, toString(result, maxSizeIgnoreDash) };
	}

	void CalcExprModel::reactBinaryExpr(const string& exprStr)
	{
		switch (state)
		{
		case State::EMPTY: reactBinaryExprWhenEmpty(exprStr);
			break;
		case State::UNARY_OPERATOR_PRESSED: reactBinaryExprWhenUnaryOperatorPressed(exprStr);
			break;
		case State::BINARY_OPERATOR_PRESSED: reactBinaryExprWhenBinaryOperatorPressed(exprStr);
			break;
		case State::EQUAL_PRESSED: reactBinaryExprWhenEqualPressed(exprStr);
			break;
		case State::BINARY_OPERATOR_PRESSED_THEN_UNARY_OPERATOR_PRESSED:
			reactBinaryExprWhenBinaryOperatorPressedThenUnaryOperatorPressed(exprStr);
		}
	}

	void CalcExprModel::reactUnaryExprWhenEmpty(const string& exprStr)
	{
		const auto unaryOperator{ getUnaryOperator(exprStr) };
		const auto operand{ getNumberFromUnaryExpr(exprStr) };
		if (unaryOperator == "sqr") result = operand * operand;
		else if (unaryOperator == "sqrt") result = sqrt(operand);
		value += exprStr;
		state = State::UNARY_OPERATOR_PRESSED;
		message = Message{ Message::Head::EXPR_RESULT, toString(result, maxSizeIgnoreDash) };
	}

	void CalcExprModel::reactUnaryExprWhenBinaryOperatorPressed(const string& exprStr)
	{
		const auto unaryOperator{ getUnaryOperator(exprStr) };
		const auto operand{ getNumberFromUnaryExpr(exprStr) };
		auto unaryOperatorResult{ 0. };
		if (unaryOperator == "sqr") unaryOperatorResult = operand * operand;
		else if (unaryOperator == "sqrt") unaryOperatorResult = sqrt(operand);
		value += ' ' + exprStr;
		state = State::BINARY_OPERATOR_PRESSED_THEN_UNARY_OPERATOR_PRESSED;
		message = Message{ Message::Head::EXPR_RESULT, toString(unaryOperatorResult, maxSizeIgnoreDash) };
	}

	void CalcExprModel::reactUnaryExprWhenEqualPressed(const string& exprStr)
	{
		const auto unaryOperator{ getUnaryOperator(exprStr) };
		const auto operand{ getNumberFromUnaryExpr(exprStr) };
		if (unaryOperator == "sqr") result = operand * operand;
		else if (unaryOperator == "sqrt") result = sqrt(operand);
		value = ' ' + exprStr;
		state = State::UNARY_OPERATOR_PRESSED;
		message = Message{ Message::Head::EXPR_RESULT, toString(result, maxSizeIgnoreDash) };
	}

	void CalcExprModel::reactUnaryExprWhenUnaryOperatorPressed(const string& exprStr)
	{
		const auto unaryOperator{ getUnaryOperator(exprStr) };
		const auto operand{ getNumberFromUnaryExpr(exprStr) };
		if (unaryOperator == "sqr") result = operand * operand;
		else if (unaryOperator == "sqrt") result = sqrt(operand);
		value.insert(value.rfind(' ') + 1u, unaryOperator + '(');
		value += ')';
		message = Message{ Message::Head::EXPR_RESULT, toString(result, maxSizeIgnoreDash) };
	}

	void CalcExprModel::reactUnaryExpr(const string& exprStr)
	{
		switch (state)
		{
		case State::EMPTY: reactUnaryExprWhenEmpty(exprStr);
			break;
		case State::BINARY_OPERATOR_PRESSED: reactUnaryExprWhenBinaryOperatorPressed(exprStr);
			break;
		case State::EQUAL_PRESSED: reactUnaryExprWhenEqualPressed(exprStr);
			break;
		case State::UNARY_OPERATOR_PRESSED:
		case State::BINARY_OPERATOR_PRESSED_THEN_UNARY_OPERATOR_PRESSED:
			reactUnaryExprWhenUnaryOperatorPressed(exprStr);
		}
	}

	void CalcExprModel::reactMessage(const Message& p_message)
	{
		message = Message{ };
		switch (p_message.head)
		{
		case Message::Head::INPUT_0:
		case Message::Head::INPUT_1:
		case Message::Head::INPUT_2:
		case Message::Head::INPUT_3:
		case Message::Head::INPUT_4:
		case Message::Head::INPUT_5:
		case Message::Head::INPUT_6:
		case Message::Head::INPUT_7:
		case Message::Head::INPUT_8:
		case Message::Head::INPUT_9:
		case Message::Head::INPUT_DOT:
			reactDigit();
			break;
		case Message::Head::INPUT_C: clear();
			break;
		case Message::Head::INPUT_CE: clearEntry();
			break;
		case Message::Head::BINARY_EXPR: reactBinaryExpr(p_message.body);
			break;
		case Message::Head::UNARY_EXPR: reactUnaryExpr(p_message.body);
			break;
		case Message::Head::LAST_BINARY_OPERATOR: value[value.size() - 1u] = p_message.body[0u];
		}
	}
}