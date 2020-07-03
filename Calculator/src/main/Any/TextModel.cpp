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
		if (ability != Ability::CAN_DISABLE) return;
		switch (p_message.head)
		{
		case Message::Head::ERROR: reactError();
			break;
		case Message::Head::FIXED: reactFixed();
		}
	}
}