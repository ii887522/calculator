#ifdef TEST

#include "CalcScreenModel.test.h"
#include <cassert>
#include "../main/Model/CalcScreenModel.h"
#include "../main/Struct/Rect.h"
#include "../main/Struct/Point.h"
#include "../main/Struct/Size.h"

namespace ii887522::Calculator
{
	static void testReactMouseMotion()
	{
		{
			CalcScreenModel calcScreenModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			calcScreenModel.reactMouseMotion(Point{ 0, 0 });
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
			calcScreenModel.reactMouseMotion(Point{ 2, 2 });
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
			calcScreenModel.reactMouseMotion(Point{ 2, 2 });
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
			calcScreenModel.reactMouseMotion(Point{ 4, 4 });
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
			calcScreenModel.reactMouseMotion(Point{ 2, 2 });
			calcScreenModel.reactRightMouseButtonDown();
			calcScreenModel.reactMouseMotion(Point{ 2, 2 });
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
			calcScreenModel.reactMouseMotion(Point{ 4, 4 });
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			CalcScreenModel calcScreenModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			calcScreenModel.reactMouseMotion(Point{ 0, 0 });
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
			calcScreenModel.reactMouseMotion(Point{ 4, 4 });
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
			calcScreenModel.reactMouseMotion(Point{ 4, 4 });
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
			calcScreenModel.reactMouseMotion(Point{ 8, 8 });
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
			calcScreenModel.reactMouseMotion(Point{ 4, 4 });
			calcScreenModel.reactRightMouseButtonDown();
			calcScreenModel.reactMouseMotion(Point{ 4, 4 });
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
			calcScreenModel.reactMouseMotion(Point{ 8, 8 });
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
		}
	}

	static void testReactRightMouseButtonDown()
	{
		{
			CalcScreenModel calcScreenModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			calcScreenModel.reactMouseMotion(Point{ 0, 0 });
			calcScreenModel.reactRightMouseButtonDown();
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
			calcScreenModel.reactRightMouseButtonUp();
			calcScreenModel.reactMouseMotion(Point{ 2, 2 });
			calcScreenModel.reactRightMouseButtonDown();
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			CalcScreenModel calcScreenModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			calcScreenModel.reactMouseMotion(Point{ 0, 0 });
			calcScreenModel.reactRightMouseButtonDown();
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
			calcScreenModel.reactRightMouseButtonUp();
			calcScreenModel.reactMouseMotion(Point{ 4, 4 });
			calcScreenModel.reactRightMouseButtonDown();
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
		}
	}

	static void testReactRightMouseButtonUp()
	{
		{
			CalcScreenModel calcScreenModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			calcScreenModel.reactMouseMotion(Point{ 0, 0 });
			calcScreenModel.reactRightMouseButtonDown();
			calcScreenModel.reactRightMouseButtonUp();
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
			calcScreenModel.reactMouseMotion(Point{ 2, 2 });
			calcScreenModel.reactRightMouseButtonDown();
			calcScreenModel.reactRightMouseButtonUp();
			assert(calcScreenModel.getMessage().head == Message::Head::SHOW_CONTEXT_MENU);
		}
		{
			CalcScreenModel calcScreenModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			calcScreenModel.reactMouseMotion(Point{ 0, 0 });
			calcScreenModel.reactRightMouseButtonDown();
			calcScreenModel.reactRightMouseButtonUp();
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
			calcScreenModel.reactMouseMotion(Point{ 4, 4 });
			calcScreenModel.reactRightMouseButtonDown();
			calcScreenModel.reactRightMouseButtonUp();
			assert(calcScreenModel.getMessage().head == Message::Head::SHOW_CONTEXT_MENU);
		}
	}

	static void testReactMouseLeaveWindow()
	{
		{
			CalcScreenModel calcScreenModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			calcScreenModel.reactMouseMotion(Point{ 0, 0 });
			calcScreenModel.reactMouseLeaveWindow();
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			CalcScreenModel calcScreenModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			calcScreenModel.reactMouseMotion(Point{ 4, 4 });
			calcScreenModel.reactMouseLeaveWindow();
			assert(calcScreenModel.getMessage().head == Message::Head::EMPTY);
		}
	}

	void testCalcScreenModel()
	{
		testReactMouseMotion();
		testReactRightMouseButtonDown();
		testReactRightMouseButtonUp();
		testReactMouseLeaveWindow();
	}
}

#endif