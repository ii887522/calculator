#ifndef II887522_CALCULATOR_CALC_EXPR_VALIDATOR_H
#define II887522_CALCULATOR_CALC_EXPR_VALIDATOR_H

#include <vector>
#include "../Any/Enums.h"

using std::vector;

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class CalcExprValidator final
	{
		enum class State : unsigned int
		{
			EMPTY, NUMBER, BINARY_OPERATOR, BINARY_OPERATOR_THEN_NUMBER, EQUAL, UNARY_OPERATOR, LEFT_BRACKET, RIGHT_BRACKET,
			BINARY_OPERATOR_THEN_UNARY_OPERATOR, BINARY_OPERATOR_THEN_LEFT_BRACKET, BINARY_OPERATOR_THEN_RIGHT_BRACKET
		};

		// remove copy semantics
		CalcExprValidator(const CalcExprValidator&) = delete;
		CalcExprValidator& operator=(const CalcExprValidator&) = delete;

		// remove move semantics
		CalcExprValidator(CalcExprValidator&&) = delete;
		CalcExprValidator& operator=(CalcExprValidator&&) = delete;

		State state;
		unsigned int openLeftBracketCount;

		constexpr bool runNumber()
		{
			switch (state)
			{
			case State::EMPTY: case State::LEFT_BRACKET:
				state = State::NUMBER;
				break;
			case State::BINARY_OPERATOR: case State::BINARY_OPERATOR_THEN_LEFT_BRACKET: state = State::BINARY_OPERATOR_THEN_NUMBER;
				break;
			default: return false;
			}
			return true;
		}

		constexpr bool runBinaryOperator()
		{
			switch (state)
			{
			case State::NUMBER: state = State::BINARY_OPERATOR;
				break;
			case State::BINARY_OPERATOR_THEN_NUMBER: case State::RIGHT_BRACKET: case State::BINARY_OPERATOR_THEN_RIGHT_BRACKET:
				if (openLeftBracketCount != 0u) return false;
				state = State::BINARY_OPERATOR;
				break;
			default: return false;
			}
			return true;
		}

		constexpr bool runEqual()
		{
			switch (state)
			{
			case State::BINARY_OPERATOR_THEN_NUMBER: case State::BINARY_OPERATOR_THEN_RIGHT_BRACKET:
				if (openLeftBracketCount != 0u) return false;
				state = State::EQUAL;
				break;
			default: return false;
			}
			return true;
		}

		constexpr bool runUnaryOperator()
		{
			switch (state)
			{
			case State::EMPTY: case State::LEFT_BRACKET: state = State::UNARY_OPERATOR;
				break;
			case State::BINARY_OPERATOR: state = State::BINARY_OPERATOR_THEN_UNARY_OPERATOR;
				break;
			case State::BINARY_OPERATOR_THEN_LEFT_BRACKET: state = State::BINARY_OPERATOR_THEN_UNARY_OPERATOR;
				break;
			default: return false;
			}
			return true;
		}

		constexpr bool runLeftBracketWhenUnaryOperator()
		{
			state = State::LEFT_BRACKET;
			++openLeftBracketCount;
			return true;
		}

		constexpr bool runLeftBracketWhenBinaryOperatorThenUnaryOperator()
		{
			state = State::BINARY_OPERATOR_THEN_LEFT_BRACKET;
			++openLeftBracketCount;
			return true;
		}

		constexpr bool runLeftBracket()
		{
			switch (state)
			{
			case State::UNARY_OPERATOR: return runLeftBracketWhenUnaryOperator();
			case State::BINARY_OPERATOR_THEN_UNARY_OPERATOR: return runLeftBracketWhenBinaryOperatorThenUnaryOperator();
			default: return false;
			}
		}

		constexpr bool runRightBracketWhenNumber()
		{
			if (openLeftBracketCount == 0u) return false;
			state = State::RIGHT_BRACKET;
			--openLeftBracketCount;
			return true;
		}

		constexpr bool runRightBracketWhenBinaryOperatorThenNumber()
		{
			if (openLeftBracketCount == 0u) return false;
			state = State::BINARY_OPERATOR_THEN_RIGHT_BRACKET;
			--openLeftBracketCount;
			return true;
		}

		constexpr bool runRightBracketWhenRightBracket()
		{
			if (openLeftBracketCount == 0u) return false;
			--openLeftBracketCount;
			return true;
		}

		constexpr bool runRightBracket()
		{
			switch (state)
			{
			case State::NUMBER: return runRightBracketWhenNumber();
			case State::BINARY_OPERATOR_THEN_NUMBER: return runRightBracketWhenBinaryOperatorThenNumber();
			case State::RIGHT_BRACKET: case State::BINARY_OPERATOR_THEN_RIGHT_BRACKET: return runRightBracketWhenRightBracket();
			default: return false;
			}
		}

		constexpr bool runToken(const Token token)
		{
			switch (token)
			{
			case Token::NUMBER: return runNumber();
			case Token::BINARY_OPERATOR: return runBinaryOperator();
			case Token::EQUAL: return runEqual();
			case Token::UNARY_OPERATOR: return runUnaryOperator();
			case Token::LEFT_BRACKET: return runLeftBracket();
			case Token::RIGHT_BRACKET: return runRightBracket();
			}
			return false;
		}

		constexpr bool runEnd()
		{
			if (openLeftBracketCount != 0u) return false;
			switch (state)
			{
			case State::NUMBER:
			case State::BINARY_OPERATOR:
			case State::BINARY_OPERATOR_THEN_NUMBER:
			case State::EQUAL:
			case State::RIGHT_BRACKET:
			case State::BINARY_OPERATOR_THEN_RIGHT_BRACKET:
				break;
			default: return false;
			}
			return true;
		}

	public:
		explicit constexpr CalcExprValidator() : state{ State::EMPTY }, openLeftBracketCount{ 0u } { }

		// Param tokens: it must be non-empty
		// Must Run Time(s): 1
		bool run(const vector<Token>& tokens);
	};
}

#endif