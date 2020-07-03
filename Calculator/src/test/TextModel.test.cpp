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
	void TextModelTest::testReactMessage() const
	{
		{
			TextModel textModel;
			textModel.reactMessage(Message{ Message::Head::EMPTY });
			assert(textModel.a.start == initialA);
			assert(textModel.a.now == initialA);
			assert(textModel.a.end == initialA);
			assert(!textModel.isAnimating);
			assert(textModel.message.head == Message::Head::EMPTY);
			textModel.reactMessage(Message{ Message::Head::ERROR });
			assert(textModel.a.start == initialA);
			assert(textModel.a.now == initialA);
			assert(textModel.a.end == initialA);
			assert(!textModel.isAnimating);
			assert(textModel.message.head == Message::Head::EMPTY);
			textModel.reactMessage(Message{ Message::Head::FIXED });
			assert(textModel.a.start == initialA);
			assert(textModel.a.now == initialA);
			assert(textModel.a.end == initialA);
			assert(!textModel.isAnimating);
			assert(textModel.message.head == Message::Head::EMPTY);
		}
		{
			TextModel textModel{ Ability::CAN_DISABLE };
			textModel.reactMessage(Message{ Message::Head::EMPTY });
			assert(textModel.a.start == initialA);
			assert(textModel.a.now == initialA);
			assert(textModel.a.end == initialA);
			assert(!textModel.isAnimating);
			assert(textModel.message.head == Message::Head::EMPTY);
			textModel.reactMessage(Message{ Message::Head::ERROR });
			assert(textModel.a.start == initialA);
			assert(textModel.a.now == initialA);
			assert(textModel.a.end == errorA);
			assert(textModel.isAnimating);
			assert(textModel.message.head == Message::Head::EMPTY);
			textModel.reactMessage(Message{ Message::Head::FIXED });
			assert(textModel.a.start == initialA);
			assert(textModel.a.now == initialA);
			assert(textModel.a.end == initialA);
			assert(textModel.isAnimating);
			assert(textModel.message.head == Message::Head::EMPTY);
		}
	}

	void TextModelTest::testStep() const
	{
		{
			TextModel textModel{ Ability::CAN_DISABLE };
			textModel.reactMessage(Message{ Message::Head::ERROR });
			textModel.step(30u);
			assert(textModel.a.start == initialA);
			assert(textModel.a.now == 221.55f);
			assert(textModel.a.end == errorA);
			assert(textModel.isAnimating);
			assert(textModel.message.head == Message::Head::EMPTY);
			textModel.step(40u);
			assert(textModel.a.start == initialA);
			assert(isOverlapX(textModel.a.now, Range<const float>{ 176.945f, 176.955f }));
			assert(textModel.a.end == errorA);
			assert(textModel.isAnimating);
			assert(textModel.message.head == Message::Head::EMPTY);
			textModel.step(60u);
			assert(textModel.a.start == initialA);
			assert(textModel.a.now == 110.05f);
			assert(textModel.a.end == errorA);
			assert(textModel.isAnimating);
			assert(textModel.message.head == Message::Head::EMPTY);
			textModel.step(70u);
			assert(textModel.a.start == initialA);
			assert(textModel.a.now == errorA);
			assert(textModel.a.end == errorA);
			assert(!textModel.isAnimating);
			assert(textModel.message.head == Message::Head::EMPTY);
		}
	}
}

#endif