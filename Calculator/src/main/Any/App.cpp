#ifndef TEST

#include "App.h"
#include "Activity.h"
#include "../Activity/MainActivity.h"
#include "../Activity/ContextMenu.h"
#include "../Struct/Message.h"

namespace ii887522::Calculator
{
	App::App(SDL_Window*const window) : activities{ new MainActivity{ window }, new ContextMenu{ window } }, isAnimating{ false },
		activityAnimationsCount{ 0u } { }

	Action App::reactMessage(const Message& message)
	{
		auto result{ Action::NONE };
		for (auto i{ 0u }; i != sizeof activities / sizeof(Activity*); ++i)
		{
			const auto action{ activities[i]->reactMessage(message) };
			if (action != Action::START_ANIMATION) continue;
			++activityAnimationsCount;
			if (isAnimating) continue;
			result = action;
			isAnimating = true;
		}
		return result;
	}

	Action App::react(const SDL_Event& event)
	{
		auto result{ Action::NONE };
		for (auto i{ 0u }; i != sizeof activities / sizeof(Activity*); ++i)
		{
			const auto [action, message]{ activities[i]->react(event) };
			if (message.head != Message::Head::EMPTY) result = reactMessage(message);
			if (result == Action::QUIT) return;
			switch (action)
			{
			case Action::QUIT: result = action;
				return;
			case Action::START_ANIMATION: break;
			default: continue;
			}
			++activityAnimationsCount;
			if (isAnimating) continue;
			result = action;
			isAnimating = true;
		}
		return result;
	}

	Action App::step(const unsigned int dt)
	{
		auto result{ Action::NONE };
		for (auto i{ 0u }; i != sizeof activities / sizeof(Activity*); ++i)
		{
			const auto action{ activities[i]->step(dt) };
			if (action != Action::STOP_ANIMATION) continue;
			--activityAnimationsCount;
			if (activityAnimationsCount != 0u) continue;
			result = action;
			isAnimating = false;
		}
		return result;
	}

	void App::show()
	{
		for (auto i{ 0u }; i != sizeof activities / sizeof(Activity*); ++i) activities[i]->show();
	}

	App::~App()
	{
		for (auto i{ 0u }; i != sizeof activities / sizeof(Activity*); ++i) delete activities[i];
	}
}

#endif