#ifndef TEST

#include "Scene.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "../ResourceView/RadialGradient.h"
#include "../View/NavBar.h"
#include "../View/CalcScreen.h"
#include "../View/Button.h"
#include "../View/ResourceView.h"
#include "../View/ButtonGroup.h"
#include "../View/TextGroup.h"
#include "../ResourceView/Text.h"
#include "../Functions/control_flow.h"
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "../Struct/Color.h"
#include "Enums.h"
#include "ButtonGrid.h"

namespace ii887522::Calculator
{
	Scene::Scene(SDL_Renderer*const renderer, const Size& size, TTF_Font*const font, const int buttonSize) : views{
		new RadialGradient{ renderer, size },
		new NavBar{ renderer, Size{ size.w, buttonSize } },
		new CalcScreen{ renderer, Rect{ Point{ 0, buttonSize }, Size{ size.w, 89 } } },
		new Button{ renderer, Rect{ Point{ 0, 0 }, Size{ buttonSize, buttonSize } }, Color{ 192u, 192u, 192u } },
		new ResourceView{ renderer, IMG_Load("res/main/drawer.png") },
		new Text{ renderer, font, "Standard", Point{ 53, 10 } },
		new Button{ renderer, Rect{ Point{ size.w - buttonSize, 0 }, Size{ buttonSize, buttonSize } }, Color{ 192u, 192u, 192u } },
		new ResourceView{ renderer, IMG_Load("res/main/history.png"), Point{ size.w - buttonSize, 0 } },
		new ButtonGroup{ renderer, ButtonGrid{ Point{ 4, 134 } } },
		new TextGroup{ renderer, font, ButtonGrid{ Point{ 4, 134 } } }
	}, isAnimating{ false }, viewAnimationsCount{ 0u }
	{
		TTF_CloseFont(font);
	}

	Action Scene::reactMouseMotion(const SDL_MouseMotionEvent& motionEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			const auto action{ views[i]->reactMouseMotion(motionEvent) };
			if (action != Action::START_ANIMATION) return;
			++viewAnimationsCount;
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
			++viewAnimationsCount;
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
			++viewAnimationsCount;
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
			++viewAnimationsCount;
			if (isAnimating) return;
			result = action;
			isAnimating = true;
		});
		return result;
	}

	Action Scene::reactKeyDown(const SDL_KeyboardEvent& keyEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			const auto action{ views[i]->reactKeyDown(keyEvent) };
			if (action != Action::START_ANIMATION) return;
			++viewAnimationsCount;
			if (isAnimating) return;
			result = action;
			isAnimating = true;
		});
		return result;
	}

	Action Scene::reactKeyUp(const SDL_KeyboardEvent& keyEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof views / sizeof(View*), [=, &result](const auto i) {
			const auto action{ views[i]->reactKeyUp(keyEvent) };
			if (action != Action::START_ANIMATION) return;
			++viewAnimationsCount;
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
			--viewAnimationsCount;
			if (viewAnimationsCount != 0u) return;
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