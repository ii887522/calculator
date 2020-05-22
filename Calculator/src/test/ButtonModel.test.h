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

	public:
		explicit constexpr ButtonModelTest() : initialLightness{ 1.f }, hoveredLightness{ .9f }, pressedLightness{ .8f } { }

		void testReactMouseMotion() const;
		void testReactLeftMouseButtonDown() const;
		void testReactLeftMouseButtonUp() const;
		void testReactMouseLeaveWindow() const;
	};
}

#endif
#endif