#ifndef II887522_CALCULATOR_TOKEN_H
#define II887522_CALCULATOR_TOKEN_H

#include <string>

using std::string;

namespace ii887522::Calculator
{
	struct Token final
	{
		enum class Type : unsigned int
		{
			EMPTY, NUMBER, BINARY_OPERATOR, UNARY_OPERATOR, LEFT_BRACKET, RIGHT_BRACKET, EQUAL
		};

		const Type type;
		const string value;

		explicit Token(const Type type = Type::EMPTY, const string& value = "");
		bool operator==(const Token&) const;
	};
}

#endif