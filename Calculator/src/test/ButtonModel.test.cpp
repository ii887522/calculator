#ifdef TEST

#include "ButtonModel.test.h"
#include <cassert>
#include "../main/Model/ButtonModel.h"
#include "../main/Struct/Rect.h"
#include "../main/Struct/Point.h"
#include <SDL.h>
#include "../main/Struct/Message.h"
#include "../main/Any/Enums.h"

namespace ii887522::Calculator
{
	void ButtonModelTest::testEnable() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			buttonModel.enable();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.enable();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.enable();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::CAN_DISABLE, SDLK_KP_0
			};
			buttonModel.enable();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
	}

	void ButtonModelTest::testTryDisable() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			buttonModel.tryDisable();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.tryDisable();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.tryDisable();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::CAN_DISABLE, SDLK_KP_0
			};
			buttonModel.tryDisable();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
	}

	void ButtonModelTest::testReactMessage() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			buttonModel.reactMessage(Message{ Message::Head::EMPTY });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::ERROR });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::FIXED });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.reactMessage(Message{ Message::Head::EMPTY });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::ERROR });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::FIXED });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactMessage(Message{ Message::Head::EMPTY });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::ERROR });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::FIXED });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::CAN_DISABLE, SDLK_KP_0
			};
			buttonModel.reactMessage(Message{ Message::Head::EMPTY });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::ERROR });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::FIXED });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
	}

	void ButtonModelTest::testReactMouseMotion() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == pressedLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == pressedBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 8, 8 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == pressedLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == pressedBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 8, 8 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 8, 8 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == pressedLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == pressedBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 8, 8 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::CAN_DISABLE, SDLK_KP_0
			};
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 8, 8 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == pressedLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == pressedBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 8, 8 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMessage(Message{ Message::Head::ERROR });
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
	}

	void ButtonModelTest::testReactLeftMouseButtonDown() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactLeftMouseButtonUp();
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == pressedLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == pressedBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactLeftMouseButtonUp();
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactLeftMouseButtonUp();
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == pressedLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == pressedBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactLeftMouseButtonUp();
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactLeftMouseButtonUp();
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == pressedLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == pressedBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactLeftMouseButtonUp();
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::CAN_DISABLE, SDLK_KP_0
			};
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactLeftMouseButtonUp();
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == pressedLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == pressedBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
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
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::INPUT_0);
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::CAN_DISABLE, SDLK_KP_0
			};
			buttonModel.reactMouseMotion(Point{ 0, 0 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactLeftMouseButtonDown();
			buttonModel.reactLeftMouseButtonUp();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::INPUT_0);
		}
	}

	void ButtonModelTest::testReactMouseLeaveWindow() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			buttonModel.reactMouseLeaveWindow();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactMouseLeaveWindow();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactMouseLeaveWindow();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::CAN_DISABLE, SDLK_KP_0
			};
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.reactMouseLeaveWindow();
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
	}

	void ButtonModelTest::testReactKeyDown() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactKeyDown(SDLK_KP_1);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactKeyDown(SDLK_KP_0);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == pressedLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == pressedBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::INPUT_0);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactKeyDown(SDLK_KP_1);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactKeyDown(SDLK_KP_0);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == pressedLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == pressedBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::INPUT_0);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_1 }, Ability::NONE, SDLK_KP_1 };
			buttonModel.reactKeyDown(SDLK_KP_0);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactKeyDown(SDLK_KP_1);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == pressedLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == pressedBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::INPUT_1);
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_1 }, Ability::CAN_DISABLE, SDLK_KP_1
			};
			buttonModel.reactKeyDown(SDLK_KP_0);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactKeyDown(SDLK_KP_1);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == pressedLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == pressedBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::INPUT_1);
		}
	}

	void ButtonModelTest::testReactKeyUp() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactKeyDown(SDLK_KP_1);
			buttonModel.reactKeyUp(SDLK_KP_1);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactKeyDown(SDLK_KP_0);
			buttonModel.reactKeyUp(SDLK_KP_0);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::INPUT_0);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactKeyDown(SDLK_KP_1);
			buttonModel.reactKeyUp(SDLK_KP_1);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactKeyDown(SDLK_KP_0);
			buttonModel.reactKeyUp(SDLK_KP_0);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::INPUT_0);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_1 }, Ability::NONE, SDLK_KP_1 };
			buttonModel.reactKeyDown(SDLK_KP_0);
			buttonModel.reactKeyUp(SDLK_KP_0);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactKeyDown(SDLK_KP_1);
			buttonModel.reactKeyUp(SDLK_KP_1);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::INPUT_1);
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_1 }, Ability::CAN_DISABLE, SDLK_KP_1
			};
			buttonModel.reactKeyDown(SDLK_KP_0);
			buttonModel.reactKeyUp(SDLK_KP_0);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.reactKeyDown(SDLK_KP_1);
			buttonModel.reactKeyUp(SDLK_KP_1);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == initialLightness);
			assert(buttonModel.getLightness().end == initialLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == initialBorderA);
			assert(buttonModel.getBorderA().end == initialBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::INPUT_1);
		}
	}

	void ButtonModelTest::testStep() const
	{
		{
			ButtonModel buttonModel{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } };
			buttonModel.reactMouseMotion(Point{ 2, 2 });
			buttonModel.step(30u);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == .985f);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == 38.25f);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.step(40u);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == .965f);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == 89.25f);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.step(60u);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == .935f);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == 165.75f);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.step(70u);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == .9f);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == 255.f);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } };
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.step(30u);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == .985f);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == 38.25f);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.step(40u);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == .965f);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == 89.25f);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.step(60u);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == .935f);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == 165.75f);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.step(170u);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == .9f);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == 255.f);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::NONE, SDLK_KP_0 };
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.step(30u);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == .985f);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == 38.25f);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.step(40u);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == .965f);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == 89.25f);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.step(60u);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == .935f);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == 165.75f);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.step(170u);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == .9f);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == 255.f);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			ButtonModel buttonModel{
				Rect{ Point{ 2, 2 }, Size{ 5, 5 } }, Message{ Message::Head::INPUT_0 }, Ability::CAN_DISABLE, SDLK_KP_0
			};
			buttonModel.reactMouseMotion(Point{ 4, 4 });
			buttonModel.step(30u);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == .985f);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == 38.25f);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.step(40u);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == .965f);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == 89.25f);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.step(60u);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == .935f);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == 165.75f);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
			buttonModel.step(170u);
			assert(buttonModel.getLightness().start == initialLightness);
			assert(buttonModel.getLightness().now == .9f);
			assert(buttonModel.getLightness().end == hoveredLightness);
			assert(buttonModel.getBorderA().start == initialBorderA);
			assert(buttonModel.getBorderA().now == 255.f);
			assert(buttonModel.getBorderA().end == hoveredBorderA);
			assert(!buttonModel.getIsAnimating());
			assert(buttonModel.getMessage().head == Message::Head::EMPTY);
		}
	}
}

#endif