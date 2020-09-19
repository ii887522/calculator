#ifdef TEST

#include "Token.test.h"
#include <cassert>
#include "../../main/Struct/Token.h"

namespace ii887522::Calculator
{
	static void testEqual()
	{
		assert(!(Token{ Token::Type::BINARY_OPERATOR, "+" }.operator==(Token{ Token::Type::NUMBER, "1" })));
		assert(!(Token{ Token::Type::NUMBER, "0" }.operator==(Token{ Token::Type::NUMBER, "1" })));
		assert((Token{ Token::Type::NUMBER, "1" }.operator==(Token{ Token::Type::NUMBER, "1" })));
		assert(!(Token{ Token::Type::BINARY_OPERATOR, "-" }.operator==(Token{ Token::Type::NUMBER, "1" })));
		assert(!(Token{ Token::Type::BINARY_OPERATOR, "-" }.operator==(Token{ Token::Type::BINARY_OPERATOR, "+" })));
		assert((Token{ Token::Type::BINARY_OPERATOR, "-" }.operator==(Token{ Token::Type::BINARY_OPERATOR, "-" })));
	}

	void testToken()
	{
		testEqual();
	}
}

#endif