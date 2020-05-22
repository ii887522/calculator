#ifndef II887522_CALCULATOR_SIZE_H
#define II887522_CALCULATOR_SIZE_H

namespace ii887522::Calculator
{
	struct Size final
	{
		// remove copy semantics
		Size(const Size&) = delete;
		Size& operator=(const Size&) = delete;

		// remove move semantics
		Size(Size&&) = delete;
		Size& operator=(Size&&) = delete;

		const int w;
		const int h;

		explicit constexpr Size(const int w = 0, const int h = 0) : w{ w }, h{ h } { }
	};
}

#endif