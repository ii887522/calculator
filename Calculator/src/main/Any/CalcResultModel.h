#ifndef II887522_CALCULATOR_CALC_RESULT_MODEL_H
#define II887522_CALCULATOR_CALC_RESULT_MODEL_H

#include "../Struct/Message.h"
#include <string>

using std::string;

namespace ii887522::Calculator
{
	// 
	class CalcResultModel final
	{
		// remove copy semantics
		CalcResultModel(const CalcResultModel&) = delete;
		CalcResultModel operator=(const CalcResultModel&) = delete;

		// remove move semantics
		CalcResultModel(CalcResultModel&&) = delete;
		CalcResultModel operator=(CalcResultModel&&) = delete;

		void reactDigit(const char digitCh);
		void reactBackspace();
		void reactDot();
		
		constexpr void moveLeft()
		{

		}

		constexpr void moveRight()
		{

		}

		void reactBinaryOperator(const char operatorCh);
		void reactUnaryOperator(const string& operatorStr);

	public:
		string value;

		// 
		explicit CalcResultModel();

		void reactMessage(const Message&);
	};
}

#endif