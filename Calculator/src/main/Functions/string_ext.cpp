#include "string_ext.h"
#include <string>

using std::string;

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
}