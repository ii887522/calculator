#ifndef TEST

#ifndef II887522_CALCULATOR_TEXT_GROUP_H
#define II887522_CALCULATOR_TEXT_GROUP_H

#include "../Any/View.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "../ResourceView/Text.h"
#include "../Any/ButtonGrid.h"
#include "../Struct/Size.h"
#include "../Any/constants.h"
#include "../Struct/Pair.h"
#include "../Any/Enums.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class TextGroup final : public View
	{
		// remove copy semantics
		TextGroup(const TextGroup&) = delete;
		TextGroup& operator=(const TextGroup&) = delete;

		// remove move semantics
		TextGroup(TextGroup&&) = delete;
		TextGroup& operator=(TextGroup&&) = delete;

		Text texts[textsCount];
		bool isAnimating;
		unsigned int textAnimationCount;

	public:
		// Param renderer: it must not be assigned to integer
		// Param font: it must not be assigned to integer
		explicit TextGroup(SDL_Renderer*const renderer, TTF_Font*const font, const ButtonGrid&, const Size& margin = Size{ 20, 12 });

		virtual Pair<Action, Message> reactMessage(const Message&) override;
		virtual Action step(const unsigned int dt);
		virtual void render() override;
	};
}

#endif
#endif