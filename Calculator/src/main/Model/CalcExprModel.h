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
			EMPTY, UNARY_OPERATOR_PRESSED, BINARY_OPERATOR_PRESSED, EQUAL_PRESSED, BINARY_OPERATOR_PRESSED_THEN_UNARY_OPERATOR_PRESSED
		};

		// remove copy semantics
		CalcExprModel(const CalcExprModel&) = delete;
		CalcExprModel& operator=(const CalcExprModel&) = delete;

		// remove move semantics
		CalcExprModel(CalcExprModel&&) = delete;
		CalcExprModel& operator=(CalcExprModel&&) = delete;

		State state;
		double result;
		const unsigned int maxSizeIgnoreDash;
		string value;
		Message message;

		void reactDigit();
		void clear();
		void clearEntryWhenBinaryOperatorPressedThenUnaryOperatorPressed();
		void clearEntry();
		void reactBinaryExprWhenEmpty(const string& exprStr);
		void reactBinaryExprWhenUnaryOperatorPressed(const string& exprStr);
		void reactBinaryExprWhenBinaryOperatorPressed(const string& exprStr);
		void reactBinaryExprWhenEqualPressed(const string& exprStr);
		void reactBinaryExprWhenBinaryOperatorPressedThenUnaryOperatorPressed(const string& exprStr);
		void reactBinaryExpr(const string& exprStr);
		void reactUnaryExprWhenEmpty(const string& exprStr);
		void reactUnaryExprWhenBinaryOperatorPressed(const string& exprStr);
		void reactUnaryExprWhenEqualPressed(const string& exprStr);
		void reactUnaryExprWhenUnaryOperatorPressed(const string& exprStr);
		void reactUnaryExpr(const string& exprStr);

	public:
		explicit CalcExprModel(const unsigned int maxSizeIgnoreDash);
		const string& getValue() const;
		const Message& getMessage() const;
		void reactMessage(const Message&);
	};
}

#endif