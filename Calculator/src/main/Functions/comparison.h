#ifndef II887522_CALCULATOR_COMPARISON_H
#define II887522_CALCULATOR_COMPARISON_H

#include <vector>

using std::vector;

namespace ii887522::Calculator
{
	template <typename T> bool equal(const vector<T>& l, const vector<T>& r)
	{
		if (l.size() != r.size()) return false;
		for (auto i{ 0u }; i != l.size(); ++i) if (l[i] != r[i]) return false;
		return true;
	}
}

#endif