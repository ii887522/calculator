#ifdef TEST

#ifndef II887522_CALCULATOR_TEXT_MODEL_TEST_H
#define II887522_CALCULATOR_TEXT_MODEL_TEST_H

namespace ii887522::Calculator
{
	class TextModelTest final
	{
		// remove copy semantics
		TextModelTest(const TextModelTest&) = delete;
		TextModelTest& operator=(const TextModelTest&) = delete;

		// remove move semantics
		TextModelTest(TextModelTest&&) = delete;
		TextModelTest& operator=(TextModelTest&&) = delete;

		const float initialA;
		const float errorA;

	public:
		explicit constexpr TextModelTest() : initialA{ 255.f }, errorA{ 32.f } { }
		void testReactMessage() const;
		void testStep() const;
	};
}

#endif
#endif