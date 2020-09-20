#include "CalcExprValidator.h"
#include <vector>
#include "../Struct/Token.h"

using std::vector;

namespace ii887522::Calculator
{
	bool CalcExprValidator::runToken(const Token& token)
	{
		switch (token.type)
		{
		case Token::Type::NUMBER: return runNumber();
		case Token::Type::BINARY_OPERATOR: return runBinaryOperator();
		case Token::Type::EQUAL: return runEqual();
		case Token::Type::UNARY_OPERATOR: return runUnaryOperator();
		case Token::Type::LEFT_BRACKET: return runLeftBracket();
		case Token::Type::RIGHT_BRACKET: return runRightBracket();
		}
		return false;
	}

	bool CalcExprValidator::run(const vector<Token>& tokens)
	{
		for (const auto& token : tokens) if (!runToken(token)) return false;
		return runEnd();
	}
}