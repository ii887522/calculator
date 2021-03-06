#ifndef II887522_CALCULATOR_TEXT_MODEL_H
#define II887522_CALCULATOR_TEXT_MODEL_H

#include "../Any/Enums.h"
#include "../Struct/Message.h"
#include "../Struct/Pair.h"
#include "../Struct/AnimatedFloat.h"
#include "../Functions/math_ext.h"
#include "../Struct/Range.h"

namespace ii887522::Calculator
{
	// Not Thread Safe
	class TextModel final
	{
		// remove copy semantics
		TextModel(const TextModel&) = delete;
		TextModel& operator=(const TextModel&) = delete;

		// remove move semantics
		TextModel(TextModel&&) = delete;
		TextModel& operator=(TextModel&&) = delete;

		unsigned int elaspedTime;
		const Ability ability;

		AnimatedFloat a;
		bool isAnimating;
		Message message;

		constexpr void reactError()
		{
			elaspedTime = 0u;
			a.start = a.now;
			a.end = 32.f;
			isAnimating = true;
		}

		constexpr void reactFixed()
		{
			elaspedTime = 0u;
			a.start = a.now;
			a.end = 255.f;
			isAnimating = true;
		}

	public:
		explicit TextModel(const Ability = Ability::NONE);

		constexpr const AnimatedFloat& getA() const
		{
			return a;
		}

		constexpr bool getIsAnimating() const
		{
			return isAnimating;
		}

		constexpr const Message& getMessage() const
		{
			return message;
		}

		constexpr void enable()
		{
			elaspedTime = 0u;
			a.start = a.now;
			a.end = 255.f;
			a.now = a.end;
			isAnimating = false;
		}

		constexpr void tryDisable()
		{
			if (ability != Ability::CAN_DISABLE) return;
			elaspedTime = 0u;
			a.start = a.now;
			a.end = 32.f;
			a.now = a.end;
			isAnimating = false;
		}

		void reactMessage(const Message&);

		constexpr void step(const unsigned int dt)
		{
			elaspedTime += dt;
			const auto duration{ 200u };
			clamp(elaspedTime, Range<const unsigned int>{ 0u, duration });
			a.now = a.start + (a.end - a.start) * (static_cast<float>(elaspedTime) / duration);
			if (elaspedTime == duration) isAnimating = false;
		}
	};
}

#endif