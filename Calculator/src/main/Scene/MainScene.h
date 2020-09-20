#ifndef TEST

#ifndef II887522_CALCULATOR_MAIN_SCENE_H
#define II887522_CALCULATOR_MAIN_SCENE_H

#include "../Any/Scene.h"
#include "../Any/App.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "../Any/View.h"
#include "../Any/Enums.h"
#include "../Struct/Size.h"
#include "../Any/ButtonGrid.h"
#include "../Struct/Point.h"
#include "../Struct/Rect.h"
#include "../Struct/Message.h"
#include "../Struct/Pair.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class MainScene final : public Scene
	{
		// remove copy semantics
		MainScene(const MainScene&) = delete;
		MainScene& operator=(const MainScene&) = delete;

		// remove move semantics
		MainScene(MainScene&&) = delete;
		MainScene& operator=(MainScene&&) = delete;

		View*const views[13u];
		Ability viewAbilities[sizeof views / sizeof(View*)];

		// Param renderer: it must not be assigned to integer
		// Param font: it must not be assigned to integer
		explicit MainScene(App&, SDL_Renderer*const renderer, const Size& size, const unsigned int maxSizeIgnoreDash,
			const Rect& calcScreenRect, TTF_Font*const font, const int buttonSize, const ButtonGrid&);

	public:
		// Param renderer: it must not be assigned to integer
		explicit MainScene(App&, SDL_Renderer*const renderer, const Size& size, const int buttonSize = 41);

		virtual Action reactMessage(const Message&) override;
		virtual Action reactMouseMotionWithFocus(const SDL_MouseMotionEvent&) override;
		virtual Action reactMouseMotionWithoutFocus(const SDL_MouseMotionEvent&) override;
		virtual Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent&) override;
		virtual Pair<Action, Message> reactLeftMouseButtonUp(const SDL_MouseButtonEvent&) override;
		virtual Action reactRightMouseButtonDown(const SDL_MouseButtonEvent&) override;
		virtual Pair<Action, Message> reactRightMouseButtonUp(const SDL_MouseButtonEvent&) override;
		virtual Action reactMouseLeaveWindow(const SDL_WindowEvent&) override;
		virtual Action reactKeyDown(const SDL_KeyboardEvent&) override;
		virtual Action reactKeyUp(const SDL_KeyboardEvent&) override;
		virtual Action step(const unsigned int dt) override;
		virtual void render() override;
		~MainScene();
	};
}

#endif
#endif