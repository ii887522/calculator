#ifndef TEST

#ifndef II887522_CALCULATOR_TEXT_H
#define II887522_CALCULATOR_TEXT_H

#include "../View/ResourceView.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "../Struct/Point.h"
#include "../Any/Enums.h"
#include "../Struct/Message.h"
#include "../Struct/Pair.h"
#include "../Any/TextModel.h"

using std::string;

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class Text : public ResourceView
	{
		// remove copy semantics
		Text(const Text&) = delete;
		Text& operator=(const Text&) = delete;

		// remove move semantics
		Text(Text&&) = delete;
		Text& operator=(Text&&) = delete;

		TextModel viewModel;
		bool isAnimating;

	public:
		// Param renderer: it must not be assigned to integer
		// Param font: it must not be assigned to integer
		explicit Text(SDL_Renderer*const renderer, TTF_Font*const font, const Point& position = Point{ }, const string& value = " ",
			const Ability = Ability::NONE); // " " because TTF_RenderText_* requires text with at least 1 character to render

		virtual void enable() override;
		virtual void tryDisable() override;
		virtual Pair<Action, Message> reactMessage(const Message&) override;
		virtual Action step(const unsigned int dt) override;
		virtual void render() override;
	};
}

#endif
#endif