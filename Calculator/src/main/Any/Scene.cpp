#ifndef TEST

#include "Scene.h"
#include "../Any/Enums.h"
#include <SDL.h>

namespace ii887522::Calculator
{
	Action Scene::reactMouseMotionWithoutFocus(const SDL_MouseMotionEvent&)
	{
		return Action::NONE;
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