#ifndef II887522_CALCULATOR_CALC_EXPR_LEXER_H
#define II887522_CALCULATOR_CALC_EXPR_LEXER_H

#include <vector>
#include "../Struct/Token.h"
#include <string>
#include <stdexcept>

using std::vector;
using std::string;
using std::invalid_argument;

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class CalcExprLexer final
	{
		enum class State : unsigned int
		{
			EMPTY, ZERO, INT, FLOAT, SPACE, BINARY_OPERATOR, SIGN, S, Q, R, T, LEFT_BRACKET, RIGHT_BRACKET
		};

		// remove copy semantics
		CalcExprLexer(const CalcExprLexer&) = delete;
		CalcExprLexer& operator=(const CalcExprLexer&) = delete;

		// remove move semantics
		CalcExprLexer(CalcExprLexer&&) = delete;
		CalcExprLexer& operator=(CalcExprLexer&&) = delete;

		State state;
		string value;
		vector<Token> result;

		void runSpaceWhenNumber();
		void runSpaceWhenSign();

		constexpr void runSpace()
		{
			switch (state)
			{
			case State::BINARY_OPERATOR: case State::RIGHT_BRACKET: state = State::SPACE;
				break;
			case State::ZERO: case State::INT: case State::FLOAT: runSpaceWhenNumber();
				break;
			case State::SIGN: runSpaceWhenSign();
				break;
			default: throw invalid_argument{ "Invalid calculator expression! Please try again." };
			}
		}

		void runDigitWhenEmpty(const char digitCh);
		void runDigitWhenSpace(const char digitCh);
		void runDigitWhenSign(const char digitCh);
		void runDigitWhenLeftBracket(const char digitCh);

		constexpr void runDigit(const char digitCh)
		{
			switch (state)
			{
			case State::EMPTY: runDigitWhenEmpty(digitCh);
				break;
			case State::INT: case State::FLOAT: value += digitCh;
				break;
			case State::SPACE: runDigitWhenSpace(digitCh);
				break;
			case State::SIGN: runDigitWhenSign(digitCh);
				break;
			case State::LEFT_BRACKET: runDigitWhenLeftBracket(digitCh);
				break;
			default: throw invalid_argument{ "Invalid calculator expression! Please try again." };
			}
		}

		constexpr void runDot()
		{
			switch (state)
			{
			case State::ZERO: case State::INT:
				state = State::FLOAT;
				value += '.';
				break;
			default: throw invalid_argument{ "Invalid calculator expression! Please try again." };
			}
		}

		constexpr void runMinus()
		{
			switch (state)
			{
			case State::EMPTY: case State::SPACE: case State::LEFT_BRACKET: state = State::SIGN;
				break;
			default: runBinaryOperator('-');
			}
		}

		void runBinaryOperatorWhenSpace(const char ch);

		constexpr void runBinaryOperator(const char ch)
		{
			switch (state)
			{
			case State::SPACE: runBinaryOperatorWhenSpace(ch);
				break;
			default: throw invalid_argument{ "Invalid calculator expression! Please try again." };
			}
		}

		constexpr void runS()
		{
			switch (state)
			{
			case State::EMPTY: case State::SPACE: case State::LEFT_BRACKET:
				state = State::S;
				value += 's';
				break;
			default: throw invalid_argument{ "Invalid calculator expression! Please try again." };
			}
		}

		constexpr void runQ()
		{
			switch (state)
			{
			case State::S:
				state = State::Q;
				value += 'q';
				break;
			default: throw invalid_argument{ "Invalid calculator expression! Please try again." };
			}
		}

		constexpr void runR()
		{
			switch (state)
			{
			case State::Q:
				state = State::R;
				value += 'r';
				break;
			default: throw invalid_argument{ "Invalid calculator expression! Please try again." };
			}
		}

		constexpr void runT()
		{
			switch (state)
			{
			case State::R:
				state = State::T;
				value += 't';
				break;
			default: throw invalid_argument{ "Invalid calculator expression! Please try again." };
			}
		}

		void runLeftBracketWhenEndOfUnaryOperator();

		constexpr void runLeftBracket()
		{
			switch (state)
			{
			case State::R: case State::T: runLeftBracketWhenEndOfUnaryOperator();
				break;
			default: throw invalid_argument{ "Invalid calculator expression! Please try again." };
			}
		}

		void runRightBracketWhenNumber();

		constexpr void runRightBracket()
		{
			switch (state)
			{
			case State::ZERO: case State::INT: case State::FLOAT: runRightBracketWhenNumber();
				break;
			case State::RIGHT_BRACKET: result.push_back(Token{ Token::Type::RIGHT_BRACKET });
				break;
			default: throw invalid_argument{ "Invalid calculator expression! Please try again." };
			}
		}

		constexpr void runChar(const char ch)
		{
			switch (ch)
			{
			case ' ': runSpace();
				break;
			case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': runDigit(ch);
				break;
			case '.': runDot();
				break;
			case '-': runMinus();
				break;
			case '+': case 'x': case '/': case '=': runBinaryOperator(ch);
				break;
			case 's': runS();
				break;
			case 'q': runQ();
				break;
			case 'r': runR();
				break;
			case 't': runT();
				break;
			case '(': runLeftBracket();
				break;
			case ')': runRightBracket();
				break;
			default: throw invalid_argument{ "Invalid calculator expression! Please try again." };
			}
		}

		constexpr void runEnd()
		{
			switch (state)
			{
			case State::ZERO: case State::INT: case State::FLOAT:
				result.push_back(Token{ Token::Type::NUMBER, value });
				value = "";
				break;
			case State::SIGN: result.push_back(Token{ Token::Type::BINARY_OPERATOR, "-" });
				break;
			case State::RIGHT_BRACKET: case State::BINARY_OPERATOR: break;
			default: throw invalid_argument{ "Invalid calculator expression! Please try again." };
			}
		}

	public:
		explicit CalcExprLexer();

		// Param str: it must be non-empty
		// Must Run Time(s): 1
		vector<Token> run(const string& str);
	};
}

#endif