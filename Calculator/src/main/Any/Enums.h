#ifndef II887522_CALCULATOR_ENUMS_H
#define II887522_CALCULATOR_ENUMS_H

namespace ii887522::Calculator
{
	enum class Action : unsigned int
	{
		NONE, QUIT, START_ANIMATION, STOP_ANIMATION
	};

	enum class Ability : unsigned int
	{
		NONE, CAN_DISABLE, ALWAYS_REACT
	};

	enum class Token : unsigned int
	{
		NUMBER, BINARY_OPERATOR, UNARY_OPERATOR, LEFT_BRACKET, RIGHT_BRACKET, EQUAL
	};
}

#endif