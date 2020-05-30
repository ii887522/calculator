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
}