#include "CalcExprLexer.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

namespace ii887522::Calculator
{
	CalcExprLexer::CalcExprLexer() : state{ State::EMPTY } { }

	void CalcExprLexer::runSpaceWhenNumber()
	{
		state = State::SPACE;
		result.push_back(Token::NUMBER);
	}

	void CalcExprLexer::runBinaryOperatorWhenSpace(const char ch)
	{
		state = State::BINARY_OPERATOR;
		result.push_back(ch == '=' ? Token::EQUAL : Token::BINARY_OPERATOR);
	}

	void CalcExprLexer::runLeftBracketWhenEndOfUnaryOperator()
	{
		state = State::LEFT_BRACKET;
		result.push_back(Token::UNARY_OPERATOR);
		result.push_back(Token::LEFT_BRACKET);
	}

	void CalcExprLexer::runRightBracketWhenNumber()
	{
		state = State::RIGHT_BRACKET;
		result.push_back(Token::NUMBER);
		result.push_back(Token::RIGHT_BRACKET);
	}

	vector<Token> CalcExprLexer::run(const string& str)
	{
		for (const auto ch : str) runChar(ch);
		runEnd();
		return result;
	}
}