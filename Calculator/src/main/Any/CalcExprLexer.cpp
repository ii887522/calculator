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
		result.push_back(Token{ Token::Type::NUMBER, value });
		value = "";
	}

	void CalcExprLexer::runDigitWhenEmpty(const char digitCh)
	{
		state = digitCh == '0' ? State::ZERO : State::INT;
		value += digitCh;
	}

	void CalcExprLexer::runDigitWhenSpace(const char digitCh)
	{
		runDigitWhenEmpty(digitCh);
	}

	void CalcExprLexer::runDigitWhenSign(const char digitCh)
	{
		if (digitCh == '0') throw invalid_argument{ "Invalid calculator expression! Please try again." };
		state = State::INT;
		value += "-" + string{ digitCh };
	}

	void CalcExprLexer::runDigitWhenLeftBracket(const char digitCh)
	{
		state = digitCh == '0' ? State::ZERO : State::INT;
		value += digitCh;
	}

	void CalcExprLexer::runBinaryOperatorWhenSpace(const char ch)
	{
		state = State::BINARY_OPERATOR;
		result.push_back(ch == '=' ? Token{ Token::Type::EQUAL } : Token{ Token::Type::BINARY_OPERATOR, string{ ch } });
	}

	void CalcExprLexer::runLeftBracketWhenEndOfUnaryOperator()
	{
		state = State::LEFT_BRACKET;
		result.push_back(Token{ Token::Type::UNARY_OPERATOR, value });
		value = "";
		result.push_back(Token{ Token::Type::LEFT_BRACKET });
	}

	void CalcExprLexer::runRightBracketWhenNumber()
	{
		state = State::RIGHT_BRACKET;
		result.push_back(Token{ Token::Type::NUMBER, value });
		value = "";
		result.push_back(Token{ Token::Type::RIGHT_BRACKET });
	}

	vector<Token> CalcExprLexer::run(const string& str)
	{
		for (const auto ch : str) runChar(ch);
		runEnd();
		return result;
	}
}