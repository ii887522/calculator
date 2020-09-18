#include "CalcExprValidator.h"
#include <vector>
#include "../Any/Enums.h"

using std::vector;

namespace ii887522::Calculator
{
	bool CalcExprValidator::run(const vector<Token>& tokens)
	{
		for (const auto token : tokens) if (!runToken(token)) return false;
		return runEnd();
	}
}