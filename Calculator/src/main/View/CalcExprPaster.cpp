#ifndef TEST

#include "CalcExprPaster.h"
#include "../Any/View.h"
#include "../Any/Enums.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"
#include "../Any/CalcExprLexer.h"
#include "../Any/CalcExprValidator.h"
#include <stdexcept>

using std::invalid_argument;

namespace ii887522::Calculator
{
	CalcExprPaster::CalcExprPaster(Scene& thisScene) : View{ nullptr }, thisScene{ thisScene } { }

	Pair<Action, Message> CalcExprPaster::reactMessage(const Message& message)
	{
		if (message.head != Message::Head::PASTE_TO_CALC_RESULT) return Pair{ Action::NONE, Message{ } };
		const auto clipboardText{ SDL_GetClipboardText() };
		try
		{
			if (!CalcExprValidator{ }.run(CalcExprLexer{ }.run(string{ clipboardText })))
				throw invalid_argument{ "Invalid calculator expression! Please try again." };

		}
		catch (const invalid_argument&)
		{
			SDL_free(clipboardText);
			return Pair{ Action::NONE, Message{ Message::Head::ERROR } };
		}
		SDL_free(clipboardText);
		return Pair{ Action::NONE, Message{ } };
	}
}

#endif