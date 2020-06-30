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
}

#endif