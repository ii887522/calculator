#ifndef TEST

#ifndef II887522_CALCULATOR_BUTTON_GROUP_H
#define II887522_CALCULATOR_BUTTON_GROUP_H

#include "../Any/View.h"
#include "Button.h"
#include <SDL.h>
#include "../Any/Enums.h"
#include "../Any/ButtonGrid.h"
#include "../Any/constants.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class ButtonGroup final : public View
	{
		// remove copy semantics
		ButtonGroup(const ButtonGroup&) = delete;
		ButtonGroup& operator=(const ButtonGroup&) = delete;

		// remove move semantics
		ButtonGroup(ButtonGroup&&) = delete;
		ButtonGroup& operator=(ButtonGroup&&) = delete;

		Button buttons[buttonsCount];
		bool isAnimating;
		unsigned int buttonAnimationsCount;

	public:
		// Param renderer: it must not be assigned to integer
		explicit ButtonGroup(SDL_Renderer*const renderer, const ButtonGrid&);

		virtual Pair<Action, Message> reactMessage(const Message&) override;
		virtual Action reactMouseMotion(const SDL_MouseMotionEvent&) override;
		virtual Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent&) override;
		virtual Pair<Action, Message> reactLeftMouseButtonUp(const SDL_MouseButtonEvent&) override;
		virtual Action reactMouseLeaveWindow(const SDL_WindowEvent&) override;
		virtual Pair<Action, Message> reactKeyDown(const SDL_KeyboardEvent&) override;
		virtual Action reactKeyUp(const SDL_KeyboardEvent&) override;
		virtual Action step(const unsigned int dt) override;
		virtual void render() override;
	};
}

#endif
#endif