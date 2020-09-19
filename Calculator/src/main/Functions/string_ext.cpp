#include "string_ext.h"
#include <string>
#include <sstream>

using std::string;
using std::stod;
using std::ostringstream;
using std::ios;

namespace ii887522::Calculator
{
	string operator-(const string& numberStr)
	{
		if (numberStr == "0") return numberStr;
		if (numberStr[0u] == '-') return numberStr.substr(1u);
		return '-' + numberStr;
	}

	unsigned int sizeIgnoreDash(const string& numberStr)
	{
		return numberStr.size() - (numberStr[0u] == '-' ? 1u : 0u);
	}

	void noTrailingDot(string& numberStr)
	{
		if (numberStr[numberStr.size() - 1u] == '.') numberStr.pop_back();
	}

	double getNumberFromBinaryExpr(const string& binaryExprStr)
	{
		return stod(binaryExprStr.substr(0u, binaryExprStr.rfind(' ')));
	}

	void noTrailingZeros(string& numberStr)
	{
		if (numberStr.find('.') == string::npos) return;
		while (numberStr[numberStr.size() - 1u] == '0') numberStr.pop_back();
	}

	double getNumberFromUnaryExpr(const string& unaryExprStr)
	{
		return stod(unaryExprStr.substr(unaryExprStr.find('(') + 1u, unaryExprStr.size() - 1u));
	}

	string getUnaryOperator(const string& unaryExprStr)
	{
		return unaryExprStr.substr(0u, unaryExprStr.find('('));
	}

	string toString(const double src, const unsigned int maxSizeIgnoreDash)
	{
		ostringstream resultStream;
		resultStream.precision(maxSizeIgnoreDash - 2u);
		resultStream.setf(ios::fixed);
		resultStream << src;
		auto resultStr{ resultStream.str() };
		const auto maxSize{ maxSizeIgnoreDash + (sizeIgnoreDash(resultStr) == resultStr.size() ? 0u : 1u) };
		const auto dotI{ resultStr.find('.') };
		if (maxSize < dotI) return "NO SPACE";
		resultStr = resultStr.substr(0u, maxSize);
		noTrailingZeros(resultStr);
		noTrailingDot(resultStr);
		return resultStr;
	}
}