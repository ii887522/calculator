#include "string_ext.h"
#include <string>
#include "control_flow.h"

using std::string;
using std::stod;

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

	string limit(const string& numberStr, const unsigned int maxSizeIgnoreDash)
	{
		const auto maxSize{ maxSizeIgnoreDash + (sizeIgnoreDash(numberStr) == numberStr.size() ? 0u : 1u) };
		const auto dotI{ numberStr.find('.') };
		if (dotI == string::npos && numberStr.size() > maxSize || dotI != string::npos && maxSize < dotI) return "NO SPACE";
		auto result{ numberStr.substr(0u, maxSize) };
		noTrailingZeros(result);
		noTrailingDot(result);
		return result;
	}
}