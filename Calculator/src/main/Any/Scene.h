#ifndef TEST

#ifndef II887522_CALCULATOR_SCENE_H
#define II887522_CALCULATOR_SCENE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "View.h"
#include "Enums.h"
#include "../Struct/Size.h"
#include "../Any/ButtonGrid.h"
#include "../Struct/Point.h"
#include "../Struct/Rect.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class Scene final
	{
		// remove copy semantics
		Scene(const Scene&) = delete;
		Scene& operator=(const Scene&) = delete;

		// remove move semantics
		Scene(Scene&&) = delete;
		Scene& operator=(Scene&&) = delete;

		View*const views[12u];
		bool isAnimating;
		unsigned int viewAnimationsCount;

		void reactMessage(const Message&);

		// Param renderer: it must not be assigned to integer
		// Param font: it must not be assigned to integer
		explicit Scene(SDL_Renderer*const renderer, const Size& size, TTF_Font*const font, const int buttonSize,
			const Rect& calcScreenRect, const ButtonGrid&);
	public:
		// Param renderer: it must not be assigned to integer
		// Param font: it must not be assigned to integer
		explicit Scene(SDL_Renderer*const renderer, const Size& size, TTF_Font*const font = TTF_OpenFont("res/main/arial.ttf", 20),
			const int buttonSize = 41, const ButtonGrid& = ButtonGrid{ Point{ 4, 134 } });

		Action reactMouseMotion(const SDL_MouseMotionEvent&);
		Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent&);
		Action reactLeftMouseButtonUp(const SDL_MouseButtonEvent&);
		Action reactMouseLeaveWindow(const SDL_WindowEvent&);
		Action reactKeyDown(const SDL_KeyboardEvent&);
		Action reactKeyUp(const SDL_KeyboardEvent&);
		Action step(const unsigned int dt);
		void render();
		~Scene();
	};
}

#endif
#endif