#ifndef TEST

#include "App.h"
#include "Activity.h"
#include "../Activity/MainActivity.h"
#include "../Activity/ContextMenu.h"
#include "../Functions/control_flow.h"
#include "../Struct/Message.h"
#include "../Functions/control_flow.h"

namespace ii887522::Calculator
{
	App::App() : activities{ new MainActivity{ }, new ContextMenu{ } }, isAnimating{ false }, activityAnimationsCount{ 0u } { }

	Action App::reactMessage(const Message& message)
	{
		auto result{ Action::NONE };
		loop(sizeof activities / sizeof(Activity*), [=, &result](const auto i) {
			const auto action{ activities[i]->reactMessage(message) };
			if (action != Action::START_ANIMATION) return;
			++activityAnimationsCount;
			if (isAnimating) return;
			result = action;
			isAnimating = true;
		});
		return result;
	}

	Action App::react(const SDL_Event& event)
	{
		auto result{ Action::NONE };
		loop(sizeof activities / sizeof(Activity*), [=, &result](const auto i) {
			const auto [action, message]{ activities[i]->react(event) };
			if (message.head != Message::Head::EMPTY) result = reactMessage(message);
			if (result == Action::QUIT) return;
			switch (action)
			{
			case Action::QUIT: result = action;
				return;
			case Action::START_ANIMATION: break;
			default: return;
			}
			++activityAnimationsCount;
			if (isAnimating) return;
			result = action;
			isAnimating = true;
		});
		return result;
	}

	Action App::step(const unsigned int dt)
	{
		auto result{ Action::NONE };
		loop(sizeof activities / sizeof(Activity*), [=, &result](const auto i) {
			const auto action{ activities[i]->step(dt) };
			if (action != Action::STOP_ANIMATION) return;
			--activityAnimationsCount;
			if (activityAnimationsCount != 0u) return;
			result = action;
			isAnimating = false;
		});
		return result;
	}

	void App::show()
	{
		loop(sizeof activities / sizeof(Activity*), [=](const auto i) {
			activities[i]->show();
		});
	}

	App::~App()
	{
		loop(sizeof activities / sizeof(Activity*), [=](const auto i) {
			delete activities[i];
		});
	}
}

#endif