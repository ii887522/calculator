#ifdef TEST

#include "CalcExprValidator.test.h"
#include <cassert>
#include "../main/Any/CalcExprValidator.h"
#include <vector>

using std::vector;

namespace ii887522::Calculator
{
	static void testRun()
	{
		assert(CalcExprValidator{ }.run(vector{ Token::NUMBER }));
		assert(CalcExprValidator{ }.run(vector{ Token::NUMBER, Token::BINARY_OPERATOR, Token::NUMBER }));
		assert(!CalcExprValidator{ }.run(vector{ Token::NUMBER, Token::NUMBER }));
		assert(CalcExprValidator{ }.run(vector{ Token::NUMBER, Token::BINARY_OPERATOR }));
		assert(CalcExprValidator{ }.run(vector{ Token::NUMBER, Token::BINARY_OPERATOR, Token::NUMBER, Token::BINARY_OPERATOR }));
		assert(!CalcExprValidator{ }.run(vector{ Token::BINARY_OPERATOR }));
		assert(CalcExprValidator{ }.run(vector{ Token::NUMBER, Token::BINARY_OPERATOR, Token::NUMBER, Token::EQUAL }));
		assert(!CalcExprValidator{ }.run(vector{ Token::EQUAL }));
		assert(!CalcExprValidator{ }.run(vector{ Token::UNARY_OPERATOR }));
		assert(!CalcExprValidator{ }.run(vector{ Token::NUMBER, Token::BINARY_OPERATOR, Token::UNARY_OPERATOR }));
		assert(!CalcExprValidator{ }.run(vector{
			Token::NUMBER, Token::BINARY_OPERATOR, Token::UNARY_OPERATOR, Token::LEFT_BRACKET, Token::UNARY_OPERATOR
		}));
		assert(!CalcExprValidator{ }.run(vector{ Token::NUMBER, Token::UNARY_OPERATOR }));
		assert(!CalcExprValidator{ }.run(vector{ Token::UNARY_OPERATOR, Token::LEFT_BRACKET }));
		assert(!CalcExprValidator{ }.run(vector{ Token::NUMBER, Token::BINARY_OPERATOR, Token::UNARY_OPERATOR, Token::LEFT_BRACKET }));
		assert(!CalcExprValidator{ }.run(vector{ Token::LEFT_BRACKET }));
		assert(!CalcExprValidator{ }.run(vector{ Token::NUMBER, Token::RIGHT_BRACKET }));
		assert(CalcExprValidator{ }.run(vector{ Token::UNARY_OPERATOR, Token::LEFT_BRACKET, Token::NUMBER, Token::RIGHT_BRACKET }));
		assert(!CalcExprValidator{ }.run(vector{ Token::NUMBER, Token::BINARY_OPERATOR, Token::NUMBER, Token::RIGHT_BRACKET }));
		assert(CalcExprValidator{ }.run(vector{
			Token::NUMBER, Token::BINARY_OPERATOR, Token::UNARY_OPERATOR, Token::LEFT_BRACKET, Token::NUMBER, Token::RIGHT_BRACKET
		}));
		assert(!CalcExprValidator{ }.run(vector{
			Token::UNARY_OPERATOR, Token::LEFT_BRACKET, Token::NUMBER, Token::RIGHT_BRACKET, Token::RIGHT_BRACKET
		}));
		assert(CalcExprValidator{ }.run(vector{
			Token::UNARY_OPERATOR, Token::LEFT_BRACKET, Token::UNARY_OPERATOR, Token::LEFT_BRACKET, Token::NUMBER, Token::RIGHT_BRACKET,
			Token::RIGHT_BRACKET
		}));
		assert(!CalcExprValidator{ }.run(vector{ Token::RIGHT_BRACKET }));
	}

	void testCalcExprValidator()
	{
		testRun();
	}
}

#endif