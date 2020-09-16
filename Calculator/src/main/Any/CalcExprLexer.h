#ifndef II887522_CALCULATOR_CALC_EXPR_LEXER_H
#define II887522_CALCULATOR_CALC_EXPR_LEXER_H

#include <vector>
#include "../Any/Enums.h"
#include <string>

using std::vector;
using std::string;

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	// 
	class CalcExprLexer final
	{
		enum class State : unsigned int
		{
			EMPTY
		};

		// remove copy semantics
		CalcExprLexer(const CalcExprLexer&) = delete;
		CalcExprLexer& operator=(const CalcExprLexer&) = delete;

		// remove move semantics
		CalcExprLexer(CalcExprLexer&&) = delete;
		CalcExprLexer& operator=(CalcExprLexer&&) = delete;

		State state;

		// 
		constexpr void runChar(const char ch)
		{
			switch (ch)
			{
			case '0': 
				break;
			case '1': 
				break;
			case '2': 
				break;
			case '3': 
				break;
			case '4': 
				break;
			case '5': 
				break;
			case '6': 
				break;
			case '7': 
				break;
			case '8': 
				break;
			case '9': 
				break;
			case '.': 
				break;
			case '+': 
				break;
			case '-': 
				break;
			case 'x': 
				break;
			case '/': 
				break;
			case '=': 
				break;
			case 's': 
				break;
			case 'q': 
				break;
			case 'r': 
				break;
			case 't': 
				break;
			default: ;
			}
		}

	public:
		explicit constexpr CalcExprLexer() : state{ State::EMPTY } { }
		vector<Token> run(const string&);
	};
}

#endif