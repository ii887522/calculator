#include "CalcExprLexer.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

namespace ii887522::Calculator
{
	vector<Token> CalcExprLexer::run(const string& str)
	{
		for (const auto ch : str)
		{

			runChar(ch);
		}
		return vector<Token>{ };
	}
}