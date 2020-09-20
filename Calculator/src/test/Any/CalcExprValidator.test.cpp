#ifdef TEST

#include "CalcExprValidator.test.h"
#include <cassert>
#include "../../main/Any/CalcExprValidator.h"
#include <vector>
#include "../../main/Struct/Token.h"

using std::vector;

namespace ii887522::Calculator
{
	static void testRun()
	{
		assert(CalcExprValidator{ }.run(vector{ Token{ Token::Type::NUMBER } }));
		assert(CalcExprValidator{ }.run(vector{
			Token{ Token::Type::NUMBER }, Token{ Token::Type::BINARY_OPERATOR }, Token{ Token::Type::NUMBER }
		}));
		assert(!CalcExprValidator{ }.run(vector{ Token{ Token::Type::NUMBER }, Token{ Token::Type::NUMBER } }));
		assert(CalcExprValidator{ }.run(vector{ Token{ Token::Type::NUMBER }, Token{ Token::Type::BINARY_OPERATOR } }));
		assert(CalcExprValidator{ }.run(vector{
			Token{ Token::Type::NUMBER }, Token{ Token::Type::BINARY_OPERATOR }, Token{ Token::Type::NUMBER },
			Token{ Token::Type::BINARY_OPERATOR }
		}));
		assert(!CalcExprValidator{ }.run(vector{ Token{ Token::Type::BINARY_OPERATOR } }));
		assert(CalcExprValidator{ }.run(vector{
			Token{ Token::Type::NUMBER }, Token{ Token::Type::BINARY_OPERATOR }, Token{ Token::Type::NUMBER }, Token{ Token::Type::EQUAL }
		}));
		assert(!CalcExprValidator{ }.run(vector{ Token{ Token::Type::EQUAL } }));
		assert(!CalcExprValidator{ }.run(vector{ Token{ Token::Type::UNARY_OPERATOR } }));
		assert(!CalcExprValidator{ }.run(vector{
			Token{ Token::Type::NUMBER }, Token{ Token::Type::BINARY_OPERATOR }, Token{ Token::Type::UNARY_OPERATOR }
		}));
		assert(!CalcExprValidator{ }.run(vector{
			Token{ Token::Type::NUMBER }, Token{ Token::Type::BINARY_OPERATOR }, Token{ Token::Type::UNARY_OPERATOR },
			Token{ Token::Type::LEFT_BRACKET }, Token{ Token::Type::UNARY_OPERATOR }
		}));
		assert(!CalcExprValidator{ }.run(vector{ Token{ Token::Type::NUMBER }, Token{ Token::Type::UNARY_OPERATOR } }));
		assert(!CalcExprValidator{ }.run(vector{ Token{ Token::Type::UNARY_OPERATOR }, Token{ Token::Type::LEFT_BRACKET } }));
		assert(!CalcExprValidator{ }.run(vector{
			Token{ Token::Type::NUMBER }, Token{ Token::Type::BINARY_OPERATOR }, Token{ Token::Type::UNARY_OPERATOR },
			Token{ Token::Type::LEFT_BRACKET }
		}));
		assert(!CalcExprValidator{ }.run(vector{ Token{ Token::Type::LEFT_BRACKET } }));
		assert(!CalcExprValidator{ }.run(vector{ Token{ Token::Type::NUMBER }, Token{ Token::Type::RIGHT_BRACKET } }));
		assert(CalcExprValidator{ }.run(vector{
			Token{ Token::Type::UNARY_OPERATOR }, Token{ Token::Type::LEFT_BRACKET }, Token{ Token::Type::NUMBER },
			Token{ Token::Type::RIGHT_BRACKET }
		}));
		assert(!CalcExprValidator{ }.run(vector{
			Token{ Token::Type::NUMBER }, Token{ Token::Type::BINARY_OPERATOR }, Token{ Token::Type::NUMBER },
			Token{ Token::Type::RIGHT_BRACKET }
		}));
		assert(CalcExprValidator{ }.run(vector{
			Token{ Token::Type::NUMBER }, Token{ Token::Type::BINARY_OPERATOR }, Token{ Token::Type::UNARY_OPERATOR },
			Token{ Token::Type::LEFT_BRACKET }, Token{ Token::Type::NUMBER }, Token{ Token::Type::RIGHT_BRACKET }
		}));
		assert(!CalcExprValidator{ }.run(vector{
			Token{ Token::Type::UNARY_OPERATOR }, Token{ Token::Type::LEFT_BRACKET }, Token{ Token::Type::NUMBER },
			Token{ Token::Type::RIGHT_BRACKET }, Token{ Token::Type::RIGHT_BRACKET }
		}));
		assert(CalcExprValidator{ }.run(vector{
			Token{ Token::Type::UNARY_OPERATOR }, Token{ Token::Type::LEFT_BRACKET }, Token{ Token::Type::UNARY_OPERATOR },
			Token{ Token::Type::LEFT_BRACKET }, Token{ Token::Type::NUMBER }, Token{ Token::Type::RIGHT_BRACKET },
			Token{ Token::Type::RIGHT_BRACKET }
		}));
		assert(!CalcExprValidator{ }.run(vector{ Token{ Token::Type::RIGHT_BRACKET } }));
		assert(CalcExprValidator{ }.run(vector{
			Token{ Token::Type::UNARY_OPERATOR }, Token{ Token::Type::LEFT_BRACKET }, Token{ Token::Type::UNARY_OPERATOR },
			Token{ Token::Type::LEFT_BRACKET }, Token{ Token::Type::NUMBER }, Token{ Token::Type::RIGHT_BRACKET },
			Token{ Token::Type::RIGHT_BRACKET }, Token{ Token::Type::BINARY_OPERATOR }
		}));
	}

	void testCalcExprValidator()
	{
		testRun();
	}
}

#endif