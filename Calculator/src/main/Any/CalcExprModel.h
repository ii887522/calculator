#ifndef II887522_CALCULATOR_CALC_EXPR_MODEL_H
#define II887522_CALCULATOR_CALC_EXPR_MODEL_H

#include "../Struct/Message.h"
#include <string>

using std::string;

namespace ii887522::Calculator
{
	// Not Thread Safe
	class CalcExprModel final
	{
		enum class State : unsigned int
		{
			EMPTY, EXIST, EQUAL_PRESSED
		};

		// remove copy semantics
		CalcExprModel(const CalcExprModel&) = delete;
		CalcExprModel& operator=(const CalcExprModel&) = delete;

		// remove move semantics
		CalcExprModel(CalcExprModel&&) = delete;
		CalcExprModel& operator=(CalcExprModel&&) = delete;

		State state;
		double result;

		void clear();
		void reactBinaryExprWhenEmpty(const string& exprStr);
		void reactBinaryExprWhenExist(const string& exprStr);
		void reactBinaryExprWhenEqualPressed(const string& exprStr);
		void reactBinaryExpr(const string& exprStr);
		void reactUnaryExpr(const string& exprStr);

	public:
		string value;
		Message message;

		explicit CalcExprModel();
		void reactMessage(const Message&);
	};
}

#endif