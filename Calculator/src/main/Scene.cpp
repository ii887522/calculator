#ifndef TEST

#include "Scene.h"
#include <SDL.h>
#include "Button.h"
#include "ResourceView.h"
#include "control_flow.h"
#include "Rect.h"
#include "Point.h"
#include "Size.h"
#include "Enums.h"

namespace ii887522::Calculator
{
	Scene::Scene(SDL_Renderer*const renderer) : views{
		new Button{ renderer, Rect{ Point{ 0, 0 }, Size{ 41, 41 } } }, new ResourceView{ renderer, "res/main/drawer.png" }
	}, isAnimating{ false } { }

	Action Scene::reactMouseMotion(const SDL_MouseMotionEvent& motionEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			const auto action{ views[i]->reactMouseMotion(motionEvent) };
			if (action != Action::START_ANIMATION) return;
			if (isAnimating) return;
			result = action;
			isAnimating = true;
		});
		return result;
	}

	Action Scene::reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			const auto action{ views[i]->reactLeftMouseButtonDown(buttonEvent) };
			if (action != Action::START_ANIMATION) return;
			if (isAnimating) return;
			result = action;
			isAnimating = true;
		});
		return result;
	}

	Action Scene::reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			const auto action{ views[i]->reactLeftMouseButtonUp(buttonEvent) };
			if (action != Action::START_ANIMATION) return;
			if (isAnimating) return;
			result = action;
			isAnimating = true;
		});
		return result;
	}

	Action Scene::reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			const auto action{ views[i]->reactMouseLeaveWindow(windowEvent) };
			if (action != Action::START_ANIMATION) return;
			if (isAnimating) return;
			result = action;
			isAnimating = true;
		});
		return result;
	}

	Action Scene::step(const unsigned int dt)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			const auto action{ views[i]->step(dt) };
			if (action != Action::STOP_ANIMATION) return;
			if (!isAnimating) return;
			result = action;
			isAnimating = false;
		});
		return result;
	}

	void Scene::render()
	{
		loop(sizeof views / sizeof(View*), [=](const auto i) {
			views[i]->render();
		});
	}

	Scene::~Scene()
	{
		loop(sizeof views / sizeof(View*), [=](const auto i) {
			delete views[i];
		});
	}
}

#endif