#ifdef TEST

#include "Struct/Point.test.h"
#include "Struct/Token.test.h"
#include "Model/ButtonModel.test.h"
#include "Functions/math_ext.test.h"
#include "Any/ButtonGrid.test.h"
#include "Model/RadialGradientModel.test.h"
#include "Model/CalcResultModel.test.h"
#include "Functions/string_ext.test.h"
#include "Model/CalcExprModel.test.h"
#include "Model/TextModel.test.h"
#include "Model/CalcScreenModel.test.h"
#include "Model/ResourceViewModel.test.h"
#include "Functions/comparison.test.h"
#include "Any/CalcExprLexer.test.h"
#include "Any/CalcExprValidator.test.h"

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
		testPoint();
		testToken();
		testMathExt();
		testButtonModel();
		testButtonGrid();
		testRadialGradientModel();
		testStringExt();
		testCalcResultModel();
		testCalcExprModel();
		testTextModel();
		testCalcScreenModel();
		testResourceViewModel();
		testComparison();
		testCalcExprLexer();
		testCalcExprValidator();
		return 0;
	}
}

int main()
{
	return ii887522::Calculator::main();
}

#endif