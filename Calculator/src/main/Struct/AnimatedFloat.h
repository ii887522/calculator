#ifndef II887522_CALCULATOR_ANIMATED_FLOAT_H
#define II887522_CALCULATOR_ANIMATED_FLOAT_H

namespace ii887522::Calculator
{
	struct AnimatedFloat final
	{
		// remove copy semantics
		AnimatedFloat(const AnimatedFloat&) = delete;
		AnimatedFloat& operator=(const AnimatedFloat&) = delete;

		// remove move semantics
		AnimatedFloat(AnimatedFloat&&) = delete;
		AnimatedFloat& operator=(AnimatedFloat&&) = delete;

		float start;
		float now;
		float end;

		explicit constexpr AnimatedFloat(const float now = 0.f) : start{ now }, now{ now }, end{ now } { }
	};
}

#endif