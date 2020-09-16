#ifdef TEST

#include "TextModel.test.h"
#include <cassert>
#include "../main/Any/TextModel.h"
#include "../main/Struct/Message.h"
#include "../main/Any/Enums.h"
#include "../main/Functions/math_ext.h"
#include "../main/Struct/Range.h"

namespace ii887522::Calculator
{
	void TextModelTest::testEnable() const
	{
		{
			TextModel textModel;
			textModel.enable();
			assert(textModel.getA().start == initialA);
			assert(textModel.getA().now == initialA);
			assert(textModel.getA().end == initialA);
			assert(!textModel.getIsAnimating());
			assert(textModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			TextModel textModel{ Ability::CAN_DISABLE };
			textModel.enable();
			assert(textModel.getA().start == initialA);
			assert(textModel.getA().now == initialA);
			assert(textModel.getA().end == initialA);
			assert(!textModel.getIsAnimating());
			assert(textModel.getMessage().head == Message::Head::EMPTY);
		}
	}

	void TextModelTest::testTryDisable() const
	{
		{
			TextModel textModel;
			textModel.tryDisable();
			assert(textModel.getA().start == initialA);
			assert(textModel.getA().now == initialA);
			assert(textModel.getA().end == initialA);
			assert(!textModel.getIsAnimating());
			assert(textModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			TextModel textModel{ Ability::CAN_DISABLE };
			textModel.tryDisable();
			assert(textModel.getA().start == initialA);
			assert(textModel.getA().now == disabledA);
			assert(textModel.getA().end == disabledA);
			assert(!textModel.getIsAnimating());
			assert(textModel.getMessage().head == Message::Head::EMPTY);
		}
	}

	void TextModelTest::testReactMessage() const
	{
		{
			TextModel textModel;
			textModel.reactMessage(Message{ Message::Head::EMPTY });
			assert(textModel.getA().start == initialA);
			assert(textModel.getA().now == initialA);
			assert(textModel.getA().end == initialA);
			assert(!textModel.getIsAnimating());
			assert(textModel.getMessage().head == Message::Head::EMPTY);
			textModel.reactMessage(Message{ Message::Head::ERROR });
			assert(textModel.getA().start == initialA);
			assert(textModel.getA().now == initialA);
			assert(textModel.getA().end == initialA);
			assert(!textModel.getIsAnimating());
			assert(textModel.getMessage().head == Message::Head::EMPTY);
			textModel.reactMessage(Message{ Message::Head::FIXED });
			assert(textModel.getA().start == initialA);
			assert(textModel.getA().now == initialA);
			assert(textModel.getA().end == initialA);
			assert(!textModel.getIsAnimating());
			assert(textModel.getMessage().head == Message::Head::EMPTY);
		}
		{
			TextModel textModel{ Ability::CAN_DISABLE };
			textModel.reactMessage(Message{ Message::Head::EMPTY });
			assert(textModel.getA().start == initialA);
			assert(textModel.getA().now == initialA);
			assert(textModel.getA().end == initialA);
			assert(!textModel.getIsAnimating());
			assert(textModel.getMessage().head == Message::Head::EMPTY);
			textModel.reactMessage(Message{ Message::Head::ERROR });
			assert(textModel.getA().start == initialA);
			assert(textModel.getA().now == initialA);
			assert(textModel.getA().end == disabledA);
			assert(textModel.getIsAnimating());
			assert(textModel.getMessage().head == Message::Head::EMPTY);
			textModel.reactMessage(Message{ Message::Head::FIXED });
			assert(textModel.getA().start == initialA);
			assert(textModel.getA().now == initialA);
			assert(textModel.getA().end == initialA);
			assert(textModel.getIsAnimating());
			assert(textModel.getMessage().head == Message::Head::EMPTY);
		}
	}

	void TextModelTest::testStep() const
	{
		{
			TextModel textModel{ Ability::CAN_DISABLE };
			textModel.reactMessage(Message{ Message::Head::ERROR });
			textModel.step(30u);
			assert(textModel.getA().start == initialA);
			assert(textModel.getA().now == 221.55f);
			assert(textModel.getA().end == disabledA);
			assert(textModel.getIsAnimating());
			assert(textModel.getMessage().head == Message::Head::EMPTY);
			textModel.step(40u);
			assert(textModel.getA().start == initialA);
			assert(isOverlapX(textModel.getA().now, Range<const float>{ 176.945f, 176.955f }));
			assert(textModel.getA().end == disabledA);
			assert(textModel.getIsAnimating());
			assert(textModel.getMessage().head == Message::Head::EMPTY);
			textModel.step(60u);
			assert(textModel.getA().start == initialA);
			assert(textModel.getA().now == 110.05f);
			assert(textModel.getA().end == disabledA);
			assert(textModel.getIsAnimating());
			assert(textModel.getMessage().head == Message::Head::EMPTY);
			textModel.step(70u);
			assert(textModel.getA().start == initialA);
			assert(textModel.getA().now == disabledA);
			assert(textModel.getA().end == disabledA);
			assert(!textModel.getIsAnimating());
			assert(textModel.getMessage().head == Message::Head::EMPTY);
		}
	}
}

#endif