#include "CalcExprLexer.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

namespace ii887522::Calculator
{
	CalcExprLexer::CalcExprLexer() : state{ State::EMPTY }, openLeftBracketCount{ 0u } { }

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
		++openLeftBracketCount;
		result.push_back(Token::UNARY_OPERATOR);
		result.push_back(Token::LEFT_BRACKET);
	}

	void CalcExprLexer::runRightBracketWhenNumber()
	{
		if (openLeftBracketCount == 0u) throw invalid_argument{ "Invalid calculator expression! Please try again." };
		state = State::RIGHT_BRACKET;
		--openLeftBracketCount;
		result.push_back(Token::NUMBER);
		result.push_back(Token::RIGHT_BRACKET);
	}

	void CalcExprLexer::runRightBracketWhenRightBracket()
	{
		if (openLeftBracketCount == 0u) throw invalid_argument{ "Invalid calculator expression! Please try again." };
		--openLeftBracketCount;
		result.push_back(Token::RIGHT_BRACKET);
	}

	vector<Token> CalcExprLexer::run(const string& str)
	{
		for (const auto ch : str) runChar(ch);
		runEnd();
		return result;
	}
}