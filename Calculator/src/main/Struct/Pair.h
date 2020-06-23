#ifndef II887522_CALCULATOR_PAIR_H
#define II887522_CALCULATOR_PAIR_H

namespace ii887522::Calculator
{
	template <typename T, typename U> struct Pair final
	{
		// remove operator= copy semantics
		Pair& operator=(const Pair&) = delete;

		// remove move semantics
		Pair(Pair&&) = delete;
		Pair& operator=(Pair&&) = delete;

		T first;
		U second;

		explicit constexpr Pair(const T& first, const U& second) : first{ first }, second{ second } { }
		constexpr Pair(const Pair&) = default;
	};
}

#endif