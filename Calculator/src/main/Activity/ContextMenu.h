#ifndef TEST

#ifndef II887522_CALCULATOR_CONTEXT_MENU_H
#define II887522_CALCULATOR_CONTEXT_MENU_H

#include "../Any/Activity.h"
#include <SDL.h>
#include "../Any/Enums.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	struct ContextMenu final : public Activity
	{
		// remove copy semantics
		ContextMenu(const ContextMenu&) = delete;
		ContextMenu& operator=(const ContextMenu&) = delete;

		// remove move semantics
		ContextMenu(ContextMenu&&) = delete;
		ContextMenu& operator=(ContextMenu&&) = delete;

		explicit ContextMenu();
		virtual Action react(const SDL_Event&) override;
		virtual Action step(const unsigned int dt) override;
		virtual void show() override;
	};
}

#endif
#endif