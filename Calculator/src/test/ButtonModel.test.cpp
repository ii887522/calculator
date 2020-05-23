#ifdef TEST

#include "ButtonModel.test.h"
#include <cassert>
#include "../main/Any/ButtonModel.h"
#include "../main/Struct/Rect.h"
#include "../main/Struct/Point.h"

namespace ii887522::Calculator
{
	void ButtonModelTest::testReactMouseMotion() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(!buttonModel.isAnimating);
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.isAnimating);
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.isAnimating);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.isAnimating);
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == pressedLightness);
			assert(buttonModel.isAnimating);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.isAnimating);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(!buttonModel.isAnimating);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.isAnimating);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.isAnimating);
			buttonModel.reactMouseMotion(Point{ 8, 8 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.isAnimating);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == pressedLightness);
			assert(buttonModel.isAnimating);
			buttonModel.reactMouseMotion(Point{ 8, 8 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.isAnimating);
		}
	}

	void ButtonModelTest::testReactLeftMouseButtonDown() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(!buttonModel.isAnimating);
			buttonModel.reactLeftMouseButtonUp();
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == pressedLightness);
			assert(buttonModel.isAnimating);
			buttonModel.reactLeftMouseButtonUp();
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(!buttonModel.isAnimating);
			buttonModel.reactLeftMouseButtonUp();
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == pressedLightness);
			assert(buttonModel.isAnimating);
			buttonModel.reactLeftMouseButtonUp();
		}
	}

	void ButtonModelTest::testReactLeftMouseButtonUp() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(!buttonModel.isAnimating);
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.isAnimating);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(!buttonModel.isAnimating);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.isAnimating);
		}
	}

	void ButtonModelTest::testReactMouseLeaveWindow() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			buttonModel.reactMouseLeaveWindow();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.isAnimating);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactMouseLeaveWindow();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.isAnimating);
		}
	}

	void ButtonModelTest::testStep() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			buttonModel.step(30u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .985f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.isAnimating);
			buttonModel.step(40u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .965f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.isAnimating);
			buttonModel.step(60u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .935f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.isAnimating);
			buttonModel.step(70u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .9f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(!buttonModel.isAnimating);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.step(30u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .985f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.isAnimating);
			buttonModel.step(40u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .965f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.isAnimating);
			buttonModel.step(60u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .935f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.isAnimating);
			buttonModel.step(170u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .9f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(!buttonModel.isAnimating);
		}
	}
}

#endif