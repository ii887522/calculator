#ifdef TEST

#include "RadialGradientModel.test.h"
#include <cassert>
#include "../main/Any/RadialGradientModel.h"
#include "../main/Struct/Size.h"
#include "../main/Struct/Point.h"

namespace ii887522::Calculator
{
	static void testReactMouseMotion()
	{
		{
			RadialGradientModel radialGradientModel{ Size{ 1, 1 } };
			radialGradientModel.reactMouseMotion(Point{ 0, 0 });
			assert(radialGradientModel.position.operator==(Point{ 0, 0 }));
			radialGradientModel.reactMouseMotion(Point{ 1, 0 });
			assert(radialGradientModel.position.operator==(Point{ 1, 0 }));
			radialGradientModel.reactMouseMotion(Point{ 1, 1 });
			assert(radialGradientModel.position.operator==(Point{ 1, 1 }));
		}
		{
			RadialGradientModel radialGradientModel{ Size{ 3, 3 } };
			radialGradientModel.reactMouseMotion(Point{ 0, 0 });
			assert(radialGradientModel.position.operator==(Point{ -1, -1 }));
			radialGradientModel.reactMouseMotion(Point{ 1, 0 });
			assert(radialGradientModel.position.operator==(Point{ 0, -1 }));
			radialGradientModel.reactMouseMotion(Point{ 1, 1 });
			assert(radialGradientModel.position.operator==(Point{ 0, 0 }));
		}
	}

	void testRadialGradientModel()
	{
		testReactMouseMotion();
	}
}

#endif