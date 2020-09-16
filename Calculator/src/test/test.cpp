#ifdef TEST

#include "ButtonModel.test.h"
#include "math_ext.test.h"
#include "control_flow.test.h"
#include "ButtonGrid.test.h"
#include "RadialGradientModel.test.h"
#include "CalcResultModel.test.h"
#include "string_ext.test.h"
#include "CalcExprModel.test.h"
#include "TextModel.test.h"
#include "CalcScreenModel.test.h"
#include "ResourceViewModel.test.h"

namespace ii887522::Calculator
{
	static void testButtonModel()
	{
		const ButtonModelTest buttonModelTest;
		buttonModelTest.testReactMouseMotion();
		buttonModelTest.testReactLeftMouseButtonDown();
		buttonModelTest.testReactLeftMouseButtonUp();
		buttonModelTest.testReactMouseLeaveWindow();
		buttonModelTest.testReactKeyDown();
		buttonModelTest.testReactKeyUp();
		buttonModelTest.testStep();
		buttonModelTest.testReactMessage();
		buttonModelTest.testEnable();
		buttonModelTest.testTryDisable();
	}

	static void testTextModel()
	{
		const TextModelTest textModelTest;
		textModelTest.testEnable();
		textModelTest.testTryDisable();
		textModelTest.testReactMessage();
		textModelTest.testStep();
	}

	static int main()
	{
		testMathExt();
		testButtonModel();
		testControlFlow();
		testButtonGrid();
		testRadialGradientModel();
		testStringExt();
		testCalcResultModel();
		testCalcExprModel();
		testTextModel();
		testCalcScreenModel();
		testResourceViewModel();
		return 0;
	}
}

int main()
{
	return ii887522::Calculator::main();
}

#endif