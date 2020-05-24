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
			Text{ renderer, font, Point{ buttonGrid.getButtonX(0) + margin.w, buttonGrid.getButtonY(0) + margin.h }, "  <" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(1) + margin.w, buttonGrid.getButtonY(1) + margin.h }, " sqr" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(2) + margin.w, buttonGrid.getButtonY(2) + margin.h }, "sqrt" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(3) + margin.w, buttonGrid.getButtonY(3) + margin.h }, "  >" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(4) + margin.w, buttonGrid.getButtonY(4) + margin.h }, " CE" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(5) + margin.w, buttonGrid.getButtonY(5) + margin.h }, "  C" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(6) + margin.w, buttonGrid.getButtonY(6) + margin.h }, " <--" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(7) + margin.w, buttonGrid.getButtonY(7) + margin.h }, "  /" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(8) + margin.w, buttonGrid.getButtonY(8) + margin.h }, "  7" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(9) + margin.w, buttonGrid.getButtonY(9) + margin.h }, "  8" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(10) + margin.w, buttonGrid.getButtonY(10) + margin.h }, "  9" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(11) + margin.w, buttonGrid.getButtonY(11) + margin.h }, "  x" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(12) + margin.w, buttonGrid.getButtonY(12) + margin.h }, "  4" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(13) + margin.w, buttonGrid.getButtonY(13) + margin.h }, "  5" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(14) + margin.w, buttonGrid.getButtonY(14) + margin.h }, "  6" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(15) + margin.w, buttonGrid.getButtonY(15) + margin.h }, "  -" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(16) + margin.w, buttonGrid.getButtonY(16) + margin.h }, "  1" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(17) + margin.w, buttonGrid.getButtonY(17) + margin.h }, "  2" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(18) + margin.w, buttonGrid.getButtonY(18) + margin.h }, "  3" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(19) + margin.w, buttonGrid.getButtonY(19) + margin.h }, "  +" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(20) + margin.w, buttonGrid.getButtonY(20) + margin.h }, " +/-" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(21) + margin.w, buttonGrid.getButtonY(21) + margin.h }, "  0" },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(22) + margin.w, buttonGrid.getButtonY(22) + margin.h }, "  ." },
			Text{ renderer, font, Point{ buttonGrid.getButtonX(23) + margin.w, buttonGrid.getButtonY(23) + margin.h }, "  =" }
		} { }

	void TextGroup::render()
	{
		loop(sizeof texts / sizeof Text, [=](const auto i) {
			texts[i].render();
		});
	}
}

#endif