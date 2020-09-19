#ifdef TEST

#ifndef II887522_CALCULATOR_BUTTON_MODEL_TEST_H
#define II887522_CALCULATOR_BUTTON_MODEL_TEST_H

namespace ii887522::Calculator
{
	class ButtonModelTest final
	{
		// remove copy semantics
		ButtonModelTest(const ButtonModelTest&) = delete;
		ButtonModelTest& operator=(const ButtonModelTest&) = delete;

		// remove move semantics
		ButtonModelTest(ButtonModelTest&&) = delete;
		ButtonModelTest& operator=(ButtonModelTest&&) = delete;

		const float initialLightness;
		const float hoveredLightness;
		const float pressedLightness;
		const float initialBorderA;
		const float hoveredBorderA;
		const float pressedBorderA;

	public:
		explicit constexpr ButtonModelTest() : initialLightness{ 1.f }, hoveredLightness{ .9f }, pressedLightness{ .8f },
			initialBorderA{ 0.f }, hoveredBorderA{ 255.f }, pressedBorderA{ 255.f } { }

		void testEnable() const;
		void testTryDisable() const;
		void testReactMessage() const;
		void testReactMouseMotion() const;
		void testReactLeftMouseButtonDown() const;
		void testReactLeftMouseButtonUp() const;
		void testReactMouseLeaveWindow() const;
		void testReactKeyDown() const;
		void testReactKeyUp() const;
		void testStep() const;
	};
}

#endif
#endif