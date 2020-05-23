#ifdef TEST

#include "ButtonGrid.test.h"
#include "../main/Any/ButtonGrid.h"
#include "../main/Struct/Point.h"

namespace ii887522::Calculator
{
	constexpr static void testGetButtonX()
	{
		{
			constexpr ButtonGrid buttonGrid{ Point{ 0, 0 } };
			static_assert(buttonGrid.getButtonX(0) == 0);
			static_assert(buttonGrid.getButtonX(1) == 74);
			static_assert(buttonGrid.getButtonX(2) == 148);
		}
		{
			constexpr ButtonGrid buttonGrid{ Point{ 1, 0 } };
			static_assert(buttonGrid.getButtonX(0) == 1);
			static_assert(buttonGrid.getButtonX(1) == 75);
			static_assert(buttonGrid.getButtonX(2) == 149);
		}
		{
			constexpr ButtonGrid buttonGrid{ Point{ 2, 0 } };
			static_assert(buttonGrid.getButtonX(0) == 2);
			static_assert(buttonGrid.getButtonX(1) == 76);
			static_assert(buttonGrid.getButtonX(2) == 150);
		}
		{
			constexpr ButtonGrid buttonGrid{ Point{ 2, 1 } };
			static_assert(buttonGrid.getButtonX(0) == 2);
			static_assert(buttonGrid.getButtonX(1) == 76);
			static_assert(buttonGrid.getButtonX(2) == 150);
		}
		{
			constexpr ButtonGrid buttonGrid{ Point{ 2, 2 } };
			static_assert(buttonGrid.getButtonX(0) == 2);
			static_assert(buttonGrid.getButtonX(1) == 76);
			static_assert(buttonGrid.getButtonX(2) == 150);
		}
	}

	constexpr static void testGetButtonY()
	{
		{
			constexpr ButtonGrid buttonGrid{ Point{ 0, 0 } };
			static_assert(buttonGrid.getButtonY(0) == 0);
			static_assert(buttonGrid.getButtonY(1) == 0);
			static_assert(buttonGrid.getButtonY(2) == 0);
			static_assert(buttonGrid.getButtonY(4) == 50);
			static_assert(buttonGrid.getButtonY(8) == 100);
		}
		{
			constexpr ButtonGrid buttonGrid{ Point{ 1, 0 } };
			static_assert(buttonGrid.getButtonY(0) == 0);
			static_assert(buttonGrid.getButtonY(1) == 0);
			static_assert(buttonGrid.getButtonY(2) == 0);
			static_assert(buttonGrid.getButtonY(4) == 50);
			static_assert(buttonGrid.getButtonY(8) == 100);
		}
		{
			constexpr ButtonGrid buttonGrid{ Point{ 2, 0 } };
			static_assert(buttonGrid.getButtonY(0) == 0);
			static_assert(buttonGrid.getButtonY(1) == 0);
			static_assert(buttonGrid.getButtonY(2) == 0);
			static_assert(buttonGrid.getButtonY(4) == 50);
			static_assert(buttonGrid.getButtonY(8) == 100);
		}
		{
			constexpr ButtonGrid buttonGrid{ Point{ 2, 1 } };
			static_assert(buttonGrid.getButtonY(0) == 1);
			static_assert(buttonGrid.getButtonY(1) == 1);
			static_assert(buttonGrid.getButtonY(2) == 1);
			static_assert(buttonGrid.getButtonY(4) == 51);
			static_assert(buttonGrid.getButtonY(8) == 101);
		}
		{
			constexpr ButtonGrid buttonGrid{ Point{ 2, 2 } };
			static_assert(buttonGrid.getButtonY(0) == 2);
			static_assert(buttonGrid.getButtonY(1) == 2);
			static_assert(buttonGrid.getButtonY(2) == 2);
			static_assert(buttonGrid.getButtonY(4) == 52);
			static_assert(buttonGrid.getButtonY(8) == 102);
		}
	}

	void testButtonGrid()
	{
		testGetButtonX();
		testGetButtonY();
	}
}

#endif