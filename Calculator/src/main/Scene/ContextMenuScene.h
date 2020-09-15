#ifndef TEST

#ifndef II887522_CALCULATOR_CONTEXT_MENU_SCENE_H
#define II887522_CALCULATOR_CONTEXT_MENU_SCENE_H

#include "../Any/Scene.h"
#include "../Any/View.h"
#include "../Any/Enums.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "../Struct/Size.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class ContextMenuScene final : public Scene
	{
		// remove copy semantics
		ContextMenuScene(const ContextMenuScene&) = delete;
		ContextMenuScene& operator=(const ContextMenuScene&) = delete;

		// remove move semantics
		ContextMenuScene(ContextMenuScene&&) = delete;
		ContextMenuScene& operator=(ContextMenuScene&&) = delete;

		View*const views[6u];

		// Param renderer: it must not be assigned to integer
		// Param font: it must not be assigned to integer
		explicit ContextMenuScene(SDL_Renderer*const renderer, const Size&, TTF_Font*const font, const Size& iconSize);

	public:
		// Param renderer: it must not be assigned to integer
		explicit ContextMenuScene(SDL_Renderer*const renderer, const Size&);

		virtual Action reactMessage(const Message&) override;
		virtual Action reactMouseMotionWithFocus(const SDL_MouseMotionEvent&) override;
		virtual Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent&) override;
		virtual Pair<Action, Message> reactLeftMouseButtonUp(const SDL_MouseButtonEvent&) override;
		virtual Action reactMouseLeaveWindow(const SDL_WindowEvent&) override;
		virtual Action step(const unsigned int dt) override;
		virtual void render() override;
	};
}

#endif
#endif