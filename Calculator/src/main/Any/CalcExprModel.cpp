#include "CalcExprModel.h"
#include "../Struct/Message.h"
#include <string>
#include "../Functions/string_ext.h"

using std::string;
using std::to_string;

namespace ii887522::Calculator
{
	CalcExprModel::CalcExprModel() : state{ State::EMPTY }, result{ 0. }, value{ " " }, message{ } { }
		// " " because TTF_RenderText_* requires text with at least 1 character to render

	void CalcExprModel::clear()
	{
		value = " ";
		state = State::EMPTY;
		result = 0.;
	}

	void CalcExprModel::reactBinaryExprWhenEmpty(const string& exprStr)
	{
		value += exprStr;
		state = State::EXIST;
		result = getNumberFromBinaryExpr(exprStr);
	}

	void CalcExprModel::reactBinaryExprWhenExist(const string& exprStr)
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
		value += exprStr;
		message = Message{ Message::Head::EXPR_RESULT, to_string(result) };
	}

	void CalcExprModel::reactBinaryExpr(const string& exprStr)
	{
		switch (state)
		{
		case State::EMPTY: reactBinaryExprWhenEmpty(exprStr);
			break;
		case State::EXIST: reactBinaryExprWhenExist(exprStr);
		}
	}

	void CalcExprModel::reactUnaryExpr(const string& exprStr)
	{
		exprStr;
	}

	void CalcExprModel::reactMessage(const Message& p_message)
	{
		message = Message{ };
		switch (p_message.head)
		{
		case Message::Head::INPUT_C: clear();
			break;
		case Message::Head::INPUT_CE: 
			break;
		case Message::Head::BINARY_EXPR: reactBinaryExpr(p_message.body);
			break;
		case Message::Head::UNARY_EXPR: reactUnaryExpr(p_message.body);
		}
	}
}