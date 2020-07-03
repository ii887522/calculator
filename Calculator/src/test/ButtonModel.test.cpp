#ifdef TEST

#include "ButtonModel.test.h"
#include <cassert>
#include "../main/Any/ButtonModel.h"
#include "../main/Struct/Rect.h"
#include "../main/Struct/Point.h"
#include <SDL.h>
#include "../main/Struct/Message.h"
#include "../main/Any/Enums.h"

namespace ii887522::Calculator
{
	void ButtonModelTest::testReactMessage() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			buttonModel.reactMessage(Message{ Message::Head::EMPTY });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::ERROR });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::FIXED });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.reactMessage(Message{ Message::Head::EMPTY });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::ERROR });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::FIXED });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactMessage(Message{ Message::Head::EMPTY });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::ERROR });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::FIXED });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::CAN_DISABLE, SDLK_KP_0
			};
			buttonModel.reactMessage(Message{ Message::Head::EMPTY });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::ERROR });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::FIXED });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
		}
	}

	void ButtonModelTest::testReactMouseMotion() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == pressedLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == pressedBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 8, 8 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == pressedLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == pressedBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 8, 8 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 8, 8 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == pressedLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == pressedBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 8, 8 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::CAN_DISABLE, SDLK_KP_0
			};
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 8, 8 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == pressedLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == pressedBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 8, 8 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::ERROR });
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
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
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactLeftMouseButtonUp();
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == pressedLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == pressedBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactLeftMouseButtonUp();
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactLeftMouseButtonUp();
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == pressedLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == pressedBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactLeftMouseButtonUp();
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactLeftMouseButtonUp();
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == pressedLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == pressedBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactLeftMouseButtonUp();
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::CAN_DISABLE, SDLK_KP_0
			};
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactLeftMouseButtonUp();
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == pressedLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == pressedBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
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
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::INPUT_0);
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::CAN_DISABLE, SDLK_KP_0
			};
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::INPUT_0);
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
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactMouseLeaveWindow();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactMouseLeaveWindow();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::CAN_DISABLE, SDLK_KP_0
			};
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactMouseLeaveWindow();
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
		}
	}

	void ButtonModelTest::testReactKeyDown() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactKeyDown(SDLK_KP_1);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactKeyDown(SDLK_KP_0);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == pressedLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == pressedBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::INPUT_0);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactKeyDown(SDLK_KP_1);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactKeyDown(SDLK_KP_0);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == pressedLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == pressedBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::INPUT_0);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_1 }, Ability::NONE, SDLK_KP_1 };
			buttonModel.reactKeyDown(SDLK_KP_0);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactKeyDown(SDLK_KP_1);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == pressedLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == pressedBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::INPUT_1);
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_1 }, Ability::CAN_DISABLE, SDLK_KP_1
			};
			buttonModel.reactKeyDown(SDLK_KP_0);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactKeyDown(SDLK_KP_1);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == pressedLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == pressedBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::INPUT_1);
		}
	}

	void ButtonModelTest::testReactKeyUp() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactKeyDown(SDLK_KP_1);
			buttonModel.reactKeyUp(SDLK_KP_1);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactKeyDown(SDLK_KP_0);
			buttonModel.reactKeyUp(SDLK_KP_0);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::INPUT_0);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactKeyDown(SDLK_KP_1);
			buttonModel.reactKeyUp(SDLK_KP_1);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactKeyDown(SDLK_KP_0);
			buttonModel.reactKeyUp(SDLK_KP_0);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::INPUT_0);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_1 }, Ability::NONE, SDLK_KP_1 };
			buttonModel.reactKeyDown(SDLK_KP_0);
			buttonModel.reactKeyUp(SDLK_KP_0);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactKeyDown(SDLK_KP_1);
			buttonModel.reactKeyUp(SDLK_KP_1);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::INPUT_1);
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_1 }, Ability::CAN_DISABLE, SDLK_KP_1
			};
			buttonModel.reactKeyDown(SDLK_KP_0);
			buttonModel.reactKeyUp(SDLK_KP_0);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.reactKeyDown(SDLK_KP_1);
			buttonModel.reactKeyUp(SDLK_KP_1);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == initialLightness);
			assert(buttonModel.lightness.end == initialLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == initialBorderA);
			assert(buttonModel.borderA.end == initialBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::INPUT_1);
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
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == 38.25f);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.step(40u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .965f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == 89.25f);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.step(60u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .935f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == 165.75f);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.step(70u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .9f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == 255.f);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.step(30u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .985f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == 38.25f);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.step(40u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .965f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == 89.25f);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.step(60u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .935f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == 165.75f);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.step(170u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .9f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == 255.f);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.step(30u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .985f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == 38.25f);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.step(40u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .965f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == 89.25f);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.step(60u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .935f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == 165.75f);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.step(170u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .9f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == 255.f);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::CAN_DISABLE, SDLK_KP_0
			};
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.step(30u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .985f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == 38.25f);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.step(40u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .965f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == 89.25f);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.step(60u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .935f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == 165.75f);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
			buttonModel.step(170u);
			assert(buttonModel.lightness.start == initialLightness);
			assert(buttonModel.lightness.now == .9f);
			assert(buttonModel.lightness.end == hoveredLightness);
			assert(buttonModel.borderA.start == initialBorderA);
			assert(buttonModel.borderA.now == 255.f);
			assert(buttonModel.borderA.end == hoveredBorderA);
			assert(!buttonModel.isAnimating);
			assert(buttonModel.message.head == Message::Head::EMPTY);
		}
	}
}

#endif