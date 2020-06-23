#ifndef TEST

#ifndef II887522_CALCULATOR_BUTTON_H
#define II887522_CALCULATOR_BUTTON_H

#include "../Any/View.h"
#include <SDL.h>
#include "../Any/ButtonModel.h"
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Any/Enums.h"
#include "../Struct/Color.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class Button final : public View
	{
		// remove copy semantics
		Button(const Button&) = delete;
		Button& operator=(const Button&) = delete;

		// remove move semantics
		Button(Button&&) = delete;
		Button& operator=(Button&&) = delete;

		ButtonModel viewModel;
		const Color color;
		bool isAnimating;
		const Message message;

		void renderBackground();
		void renderBorder();

	public:
		// Param renderer: it must not be assigned to integer
		explicit Button(SDL_Renderer*const renderer, const Rect&, const Color&, const Message& = Message{  },
			const SDL_Keycode = SDLK_UNKNOWN);

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