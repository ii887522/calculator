#include "TextModel.h"
#include "../Any/Enums.h"
#include "../Struct/Message.h"
#include "../Struct/Pair.h"

namespace ii887522::Calculator
{
	TextModel::TextModel(const Ability ability) : elaspedTime{ 0u }, ability{ ability }, a{ 255.f }, isAnimating{ false }, message{ } { }

	void TextModel::reactMessage(const Message& p_message)
	{
		message = Message{ };
		if (p_message.head != Message::Head::ERROR || ability != Ability::CAN_DISABLE) return;
		elaspedTime = 0u;
		a.start = a.now;
		a.end = 32.f;
		isAnimating = true;
	}
}