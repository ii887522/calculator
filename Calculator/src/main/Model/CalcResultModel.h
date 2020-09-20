#ifndef II887522_CALCULATOR_CALC_RESULT_MODEL_H
#define II887522_CALCULATOR_CALC_RESULT_MODEL_H

#include "../Struct/Message.h"
#include <string>

using std::string;

namespace ii887522::Calculator
{
	// Not Thread Safe
	class CalcResultModel final
	{
		enum class State
		{
			INT, FLOAT, BINARY_OPERATOR_PRESSED, BINARY_OPERATOR_PRESSED_THEN_INT, BINARY_OPERATOR_PRESSED_THEN_FLOAT, EQUAL_PRESSED,
			UNARY_OPERATOR_PRESSED, BINARY_OPERATOR_PRESSED_THEN_UNARY_OPERATOR_PRESSED, ERROR
		};

		// remove copy semantics
		CalcResultModel(const CalcResultModel&) = delete;
		CalcResultModel operator=(const CalcResultModel&) = delete;

		// remove move semantics
		CalcResultModel(CalcResultModel&&) = delete;
		CalcResultModel operator=(CalcResultModel&&) = delete;

		State state;
		const unsigned int maxSizeIgnoreDash;
		string value;
		Message message;

		void reactError();
		void reactExprResult(const string& resultStr);
		void reactDigitWhenNumber(const char digitCh);
		void reactDigitWhenBinaryOperatorPressed(const char digitCh);
		void reactDigitWhenEqualPressed(const char digitCh);
		void reactDigitWhenUnaryOperatorPressed(const char digitCh);
		void reactDigitWhenError(const char digitCh);
		void reactDigit(const char digitCh);
		void reactBackspace();
		void clear();
		void clearEntryWhenBinaryOperatorPressed();
		void clearEntry();
		void reactDotWhenInt();
		void reactDotWhenBinaryOperatorPressed();
		void reactDotWhenBinaryOperatorPressedThenInt();
		void reactDotWhenEqualPressed();
		void reactDotWhenUnaryOperatorPressed();
		void reactDot();
		void tryToggleSign();
		void reactBinaryOperatorWhenNumber(const char operatorCh);
		void reactBinaryOperatorWhenBinaryOperatorPressed(const char operatorCh);
		void reactBinaryOperatorWhenBinaryOperatorPressedBefore(const char operatorCh);
		void reactBinaryOperatorWhenEqualPressed(const char operatorCh);
		void reactBinaryOperatorWhenUnaryOperatorPressed(const char operatorCh);
		void reactBinaryOperator(const char operatorCh);
		void reactUnaryOperatorWhenBinaryOperatorNotPressed(const string& operatorStr);
		void reactUnaryOperatorWhenBinaryOperatorPressed(const string& operatorStr);
		void reactUnaryOperatorWhenEqualPressed(const string& operatorStr);
		void reactUnaryOperator(const string& operatorStr);

	public:
		explicit CalcResultModel(const unsigned int maxSizeIgnoreDash);
		const string& getValue() const;
		const Message& getMessage() const;
		void reactMessage(const Message&);
	};
}

#endif