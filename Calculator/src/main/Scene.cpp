#ifndef TEST

#include "Scene.h"
#include <SDL.h>
#include "Button.h"
#include "ResourceView.h"
#include "control_flow.h"

namespace ii887522::Calculator
{
	Scene::Scene(SDL_Renderer*const renderer) : views{  } { }

	Scene::~Scene()
	{
		loop(sizeof views / sizeof(View*), []() {

		});
	}
}

#endif