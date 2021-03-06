#ifndef TEST

#ifndef II887522_CALCULATOR_SCENE_H
#define II887522_CALCULATOR_SCENE_H

#include "../Any/Enums.h"
#include <SDL.h>
#include "../Struct/Pair.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class Scene
	{
		// remove copy semantics
		Scene(const Scene&) = delete;
		Scene& operator=(const Scene&) = delete;

		// remove move semantics
		Scene(Scene&&) = delete;
		Scene& operator=(Scene&&) = delete;

		bool isAnimating;
		unsigned int viewAnimationsCount;

	protected:
		explicit constexpr Scene() : isAnimating{ false }, viewAnimationsCount{ 0u } { }

		constexpr void setIsAnimating(const bool p_isAnimating)
		{
			isAnimating = p_isAnimating;
		}

		constexpr unsigned int getViewAnimationsCount() const
		{
			return viewAnimationsCount;
		}

		constexpr void incrementViewAnimationsCount()
		{
			++viewAnimationsCount;
		}

		constexpr void decrementViewAnimationsCount()
		{
			--viewAnimationsCount;
		}

	public:
		constexpr bool getIsAnimating() const
		{
			return isAnimating;
		}

		virtual void enable();
		virtual void tryDisable();
		virtual Action reactMessage(const Message&) = 0;
		virtual Action reactMouseMotionWithFocus(const SDL_MouseMotionEvent&) = 0;
		virtual Action reactMouseMotionWithoutFocus(const SDL_MouseMotionEvent&);
		virtual Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent&) = 0;
		virtual Pair<Action, Message> reactLeftMouseButtonUp(const SDL_MouseButtonEvent&) = 0;
		virtual Action reactRightMouseButtonDown(const SDL_MouseButtonEvent&);
		virtual Pair<Action, Message> reactRightMouseButtonUp(const SDL_MouseButtonEvent&);
		virtual Action reactMouseLeaveWindow(const SDL_WindowEvent&) = 0;
		virtual Action reactKeyDown(const SDL_KeyboardEvent&);
		virtual Action reactKeyUp(const SDL_KeyboardEvent&);
		virtual Action step(const unsigned int dt) = 0;
		virtual void render() = 0;
		~Scene();
	};
}

#endif
#endif