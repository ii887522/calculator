#ifndef II887522_CALCULATOR_FLOW_H
#define II887522_CALCULATOR_FLOW_H

namespace ii887522::Calculator
{
	template <typename T> struct Flow final
	{
		// remove copy semantics
		Flow(const Flow&) = delete;
		Flow& operator=(const Flow&) = delete;

		// remove move semantics
		Flow(Flow&&) = delete;
		Flow& operator=(Flow&&) = delete;

		const T src;
		const T dest;

		explicit constexpr Flow(const T& src, const T& dest) : src{ src }, dest{ dest } { }
	};
}

#endif