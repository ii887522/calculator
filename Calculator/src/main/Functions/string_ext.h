#ifndef II887522_CALCULATOR_STRING_EXT_H
#define II887522_CALCULATOR_STRING_EXT_H

#include <string>

using std::string;

namespace ii887522::Calculator
{
	string operator-(const string& numberStr);
	unsigned int sizeIgnoreDash(const string& numberStr);
	void noTrailingDot(string& numberStr);
	double getNumberFromBinaryExpr(const string& binaryExprStr);
	void noTrailingZeros(string& numberStr);
	double getNumberFromUnaryExpr(const string& unaryExprStr);
	string getUnaryOperator(const string& unaryExprStr);
	string limit(const string& numberStr, const unsigned int maxSizeIgnoreDash);
	string toString(const double src, const unsigned int maxSizeIgnoreDash);
}

#endif