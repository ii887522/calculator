#ifndef TEST

#include "Scene.h"
#include "../Any/Enums.h"
#include <SDL.h>
#include "../Struct/Pair.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	Action Scene::reactMouseMotionWithoutFocus(const SDL_MouseMotionEvent&)
	{
		return Action::NONE;
	}

	Action Scene::reactRightMouseButtonDown(const SDL_MouseButtonEvent&)
	{
		return Action::NONE;
	}

	Pair<Action, Message> Scene::reactRightMouseButtonUp(const SDL_MouseButtonEvent&)
	{
		return Pair{ Action::NONE, Message{ } };
	}

	Action Scene::reactKeyDown(const SDL_KeyboardEvent&)
	{
		return Action::NONE;
	}

	Action Scene::reactKeyUp(const SDL_KeyboardEvent&)
	{
		return Action::NONE;
	}

	Scene::~Scene() { }
}

#endif