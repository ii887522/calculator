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
			RadialGradientModel radialGradientModel{ Size{ 64, 64 }, Size{ 1, 1 } };
			radialGradientModel.reactMouseMotion(Point{ 4, 12 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 4, 12 }));
			radialGradientModel.reactMouseMotion(Point{ 12, 4 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 12, 4 }));
			radialGradientModel.reactMouseMotion(Point{ 32, 8 });
			assert(radialGradientModel.a == 127u);
			assert(radialGradientModel.position.operator==(Point{ 32, 8 }));
			radialGradientModel.reactMouseMotion(Point{ 60, 12 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 60, 12 }));
			radialGradientModel.reactMouseMotion(Point{ 52, 4 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 52, 4 }));
			radialGradientModel.reactMouseMotion(Point{ 56, 32 });
			assert(radialGradientModel.a == 127u);
			assert(radialGradientModel.position.operator==(Point{ 56, 32 }));
			radialGradientModel.reactMouseMotion(Point{ 60, 52 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 60, 52 }));
			radialGradientModel.reactMouseMotion(Point{ 52, 60 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 52, 60 }));
			radialGradientModel.reactMouseMotion(Point{ 32, 56 });
			assert(radialGradientModel.a == 127u);
			assert(radialGradientModel.position.operator==(Point{ 32, 56 }));
			radialGradientModel.reactMouseMotion(Point{ 4, 52 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 4, 52 }));
			radialGradientModel.reactMouseMotion(Point{ 12, 60 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 12, 60 }));
			radialGradientModel.reactMouseMotion(Point{ 8, 32 });
			assert(radialGradientModel.a == 127u);
			assert(radialGradientModel.position.operator==(Point{ 8, 32 }));
			radialGradientModel.reactMouseMotion(Point{ 32, 32 });
			assert(radialGradientModel.a == 255u);
			assert(radialGradientModel.position.operator==(Point{ 32, 32 }));
		}
		{
			RadialGradientModel radialGradientModel{ Size{ 128, 128 }, Size{ 1, 1 } };
			radialGradientModel.reactMouseMotion(Point{ 4, 12 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 4, 12 }));
			radialGradientModel.reactMouseMotion(Point{ 12, 4 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 12, 4 }));
			radialGradientModel.reactMouseMotion(Point{ 64, 8 });
			assert(radialGradientModel.a == 127u);
			assert(radialGradientModel.position.operator==(Point{ 64, 8 }));
			radialGradientModel.reactMouseMotion(Point{ 124, 12 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 124, 12 }));
			radialGradientModel.reactMouseMotion(Point{ 116, 4 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 116, 4 }));
			radialGradientModel.reactMouseMotion(Point{ 120, 32 });
			assert(radialGradientModel.a == 127u);
			assert(radialGradientModel.position.operator==(Point{ 120, 32 }));
			radialGradientModel.reactMouseMotion(Point{ 124, 116 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 124, 116 }));
			radialGradientModel.reactMouseMotion(Point{ 116, 124 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 116, 124 }));
			radialGradientModel.reactMouseMotion(Point{ 64, 120 });
			assert(radialGradientModel.a == 127u);
			assert(radialGradientModel.position.operator==(Point{ 64, 120 }));
			radialGradientModel.reactMouseMotion(Point{ 4, 116 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 4, 116 }));
			radialGradientModel.reactMouseMotion(Point{ 12, 124 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 12, 124 }));
			radialGradientModel.reactMouseMotion(Point{ 8, 64 });
			assert(radialGradientModel.a == 127u);
			assert(radialGradientModel.position.operator==(Point{ 8, 64 }));
			radialGradientModel.reactMouseMotion(Point{ 64, 64 });
			assert(radialGradientModel.a == 255u);
			assert(radialGradientModel.position.operator==(Point{ 64, 64 }));
		}
		{
			RadialGradientModel radialGradientModel{ Size{ 128, 128 }, Size{ 3, 3 } };
			radialGradientModel.reactMouseMotion(Point{ 4, 12 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 3, 11 }));
			radialGradientModel.reactMouseMotion(Point{ 12, 4 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 11, 3 }));
			radialGradientModel.reactMouseMotion(Point{ 64, 8 });
			assert(radialGradientModel.a == 127u);
			assert(radialGradientModel.position.operator==(Point{ 63, 7 }));
			radialGradientModel.reactMouseMotion(Point{ 124, 12 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 123, 11 }));
			radialGradientModel.reactMouseMotion(Point{ 116, 4 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 115, 3 }));
			radialGradientModel.reactMouseMotion(Point{ 120, 32 });
			assert(radialGradientModel.a == 127u);
			assert(radialGradientModel.position.operator==(Point{ 119, 31 }));
			radialGradientModel.reactMouseMotion(Point{ 124, 116 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 123, 115 }));
			radialGradientModel.reactMouseMotion(Point{ 116, 124 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 115, 123 }));
			radialGradientModel.reactMouseMotion(Point{ 64, 120 });
			assert(radialGradientModel.a == 127u);
			assert(radialGradientModel.position.operator==(Point{ 63, 119 }));
			radialGradientModel.reactMouseMotion(Point{ 4, 116 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 3, 115 }));
			radialGradientModel.reactMouseMotion(Point{ 12, 124 });
			assert(radialGradientModel.a == 63u);
			assert(radialGradientModel.position.operator==(Point{ 11, 123 }));
			radialGradientModel.reactMouseMotion(Point{ 8, 64 });
			assert(radialGradientModel.a == 127u);
			assert(radialGradientModel.position.operator==(Point{ 7, 63 }));
			radialGradientModel.reactMouseMotion(Point{ 64, 64 });
			assert(radialGradientModel.a == 255u);
			assert(radialGradientModel.position.operator==(Point{ 63, 63 }));
		}
	}

	void testRadialGradientModel()
	{
		testReactMouseMotion();
	}
}

#endif