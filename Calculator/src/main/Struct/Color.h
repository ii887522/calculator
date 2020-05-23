#ifndef II887522_CALCULATOR_COLOR_H
#define II887522_CALCULATOR_COLOR_H

namespace ii887522::Calculator
{
	struct Color final
	{
		// remove copy semantics
		Color(const Color&) = delete;
		Color& operator=(const Color&) = delete;

		// remove move semantics
		Color(Color&&) = delete;
		Color& operator=(Color&&) = delete;

		const unsigned int r;
		const unsigned int g;
		const unsigned int b;

		explicit constexpr Color(const unsigned int r = 0u, const unsigned int g = 0u, const unsigned int b = 0u) : r{ r }, g{ g }, b{ b }
		{ }
	};
}

#endif