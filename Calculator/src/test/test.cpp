#ifdef TEST

#include "ButtonModel.test.h"
#include "math_ext.test.h"
#include "control_flow.test.h"
#include "ButtonGrid.test.h"
#include "RadialGradientModel.test.h"

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
	}

	static int main()
	{
		testMathExt();
		testButtonModel();
		testControlFlow();
		testButtonGrid();
		testRadialGradientModel();
		return 0;
	}
}

int main()
{
	return ii887522::Calculator::main();
}

#endif