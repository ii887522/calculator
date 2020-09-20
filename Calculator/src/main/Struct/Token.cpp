#include "Token.h"
#include <string>

using std::string;

namespace ii887522::Calculator
{
	Token::Token(const Type type, const string& value) : type{ type }, value{ value } { }

	bool Token::operator==(const Token& that) const
	{
		return type == that.type && value == that.value;
	}
}