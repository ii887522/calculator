#ifndef TEST

#include "TextGroup.h"
#include "../Any/View.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "../ResourceView/Text.h"
#include "../Struct/Point.h"
#include "../Any/ButtonGrid.h"
#include "../Functions/control_flow.h"
#include "../Struct/Size.h"

namespace ii887522::Calculator
{
	TextGroup::TextGroup(SDL_Renderer*const renderer, TTF_Font*const font, const ButtonGrid& buttonGrid, const Size& margin) :
		View{ renderer }, texts{
			Text{ renderer, font, "  <", Point{ buttonGrid.getButtonX(0) + margin.w, buttonGrid.getButtonY(0) + margin.h } },
			Text{ renderer, font, " sqr", Point{ buttonGrid.getButtonX(1) + margin.w, buttonGrid.getButtonY(1) + margin.h } },
			Text{ renderer, font, "sqrt", Point{ buttonGrid.getButtonX(2) + margin.w, buttonGrid.getButtonY(2) + margin.h } },
			Text{ renderer, font, "  >", Point{ buttonGrid.getButtonX(3) + margin.w, buttonGrid.getButtonY(3) + margin.h } },

			Text{ renderer, font, " CE", Point{ buttonGrid.getButtonX(4) + margin.w, buttonGrid.getButtonY(4) + margin.h } },
			Text{ renderer, font, "  C", Point{ buttonGrid.getButtonX(5) + margin.w, buttonGrid.getButtonY(5) + margin.h } },
			Text{ renderer, font, " <--", Point{ buttonGrid.getButtonX(6) + margin.w, buttonGrid.getButtonY(6) + margin.h } },
			Text{ renderer, font, "  /", Point{ buttonGrid.getButtonX(7) + margin.w, buttonGrid.getButtonY(7) + margin.h } },

			Text{ renderer, font, "  7", Point{ buttonGrid.getButtonX(8) + margin.w, buttonGrid.getButtonY(8) + margin.h } },
			Text{ renderer, font, "  8", Point{ buttonGrid.getButtonX(9) + margin.w, buttonGrid.getButtonY(9) + margin.h } },
			Text{ renderer, font, "  9", Point{ buttonGrid.getButtonX(10) + margin.w, buttonGrid.getButtonY(10) + margin.h } },
			Text{ renderer, font, "  x", Point{ buttonGrid.getButtonX(11) + margin.w, buttonGrid.getButtonY(11) + margin.h } },

			Text{ renderer, font, "  4", Point{ buttonGrid.getButtonX(12) + margin.w, buttonGrid.getButtonY(12) + margin.h } },
			Text{ renderer, font, "  5", Point{ buttonGrid.getButtonX(13) + margin.w, buttonGrid.getButtonY(13) + margin.h } },
			Text{ renderer, font, "  6", Point{ buttonGrid.getButtonX(14) + margin.w, buttonGrid.getButtonY(14) + margin.h } },
			Text{ renderer, font, "  -", Point{ buttonGrid.getButtonX(15) + margin.w, buttonGrid.getButtonY(15) + margin.h } },

			Text{ renderer, font, "  1", Point{ buttonGrid.getButtonX(16) + margin.w, buttonGrid.getButtonY(16) + margin.h } },
			Text{ renderer, font, "  2", Point{ buttonGrid.getButtonX(17) + margin.w, buttonGrid.getButtonY(17) + margin.h } },
			Text{ renderer, font, "  3", Point{ buttonGrid.getButtonX(18) + margin.w, buttonGrid.getButtonY(18) + margin.h } },
			Text{ renderer, font, "  +", Point{ buttonGrid.getButtonX(19) + margin.w, buttonGrid.getButtonY(19) + margin.h } },

			Text{ renderer, font, " +/-", Point{ buttonGrid.getButtonX(20) + margin.w, buttonGrid.getButtonY(20) + margin.h } },
			Text{ renderer, font, "  0", Point{ buttonGrid.getButtonX(21) + margin.w, buttonGrid.getButtonY(21) + margin.h } },
			Text{ renderer, font, "  .", Point{ buttonGrid.getButtonX(22) + margin.w, buttonGrid.getButtonY(22) + margin.h } },
			Text{ renderer, font, "  =", Point{ buttonGrid.getButtonX(23) + margin.w, buttonGrid.getButtonY(23) + margin.h } }
		} { }

	void TextGroup::render()
	{
		loop(sizeof texts / sizeof Text, [=](const auto i) {
			texts[i].render();
		});
	}
}

#endif