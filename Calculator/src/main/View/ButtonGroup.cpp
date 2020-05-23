#ifndef TEST

#include "ButtonGroup.h"
#include "../Any/View.h"
#include <SDL.h>
#include "Button.h"
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "../Any/Enums.h"
#include "../Functions/control_flow.h"

namespace ii887522::Calculator
{
	ButtonGroup::ButtonGroup(SDL_Renderer*const renderer) : View{ renderer }, buttons{
		Button{ renderer, Rect{ Point{  }, Size{  } } }, Button{ renderer, Rect{ Point{  }, Size{  } } },
		Button{ renderer, Rect{ Point{  }, Size{  } } }, Button{ renderer, Rect{ Point{  }, Size{  } } },

		Button{ renderer, Rect{ Point{  }, Size{  } } }, Button{ renderer, Rect{ Point{  }, Size{  } } },
		Button{ renderer, Rect{ Point{  }, Size{  } } }, Button{ renderer, Rect{ Point{  }, Size{  } } },

		Button{ renderer, Rect{ Point{  }, Size{  } } }, Button{ renderer, Rect{ Point{  }, Size{  } } },
		Button{ renderer, Rect{ Point{  }, Size{  } } }, Button{ renderer, Rect{ Point{  }, Size{  } } },

		Button{ renderer, Rect{ Point{  }, Size{  } } }, Button{ renderer, Rect{ Point{  }, Size{  } } },
		Button{ renderer, Rect{ Point{  }, Size{  } } }, Button{ renderer, Rect{ Point{  }, Size{  } } },

		Button{ renderer, Rect{ Point{  }, Size{  } } }, Button{ renderer, Rect{ Point{  }, Size{  } } },
		Button{ renderer, Rect{ Point{  }, Size{  } } }, Button{ renderer, Rect{ Point{  }, Size{  } } },

		Button{ renderer, Rect{ Point{  }, Size{  } } }, Button{ renderer, Rect{ Point{  }, Size{  } } },
		Button{ renderer, Rect{ Point{  }, Size{  } } }, Button{ renderer, Rect{ Point{  }, Size{  } } }
	}, isAnimating{ false }, buttonAnimationsCount{ 0u } { }

	Action ButtonGroup::reactMouseMotion(const SDL_MouseMotionEvent& motionEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof buttons / sizeof Button, [=, &result](const auto i) {
			const auto action{ buttons[i].reactMouseMotion(motionEvent) };
			if (action != Action::START_ANIMATION) return Action::NONE;
			++buttonAnimationsCount;
			if (isAnimating) return Action::NONE;
			result = action;
			isAnimating = true;
		});
		return result;
	}

	Action ButtonGroup::reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof buttons / sizeof Button, [=, &result](const auto i) {
			const auto action{ buttons[i].reactLeftMouseButtonDown(buttonEvent) };
			if (action != Action::START_ANIMATION) return Action::NONE;
			++buttonAnimationsCount;
			if (isAnimating) return Action::NONE;
			result = action;
			isAnimating = true;
		});
		return result;
	}

	Action ButtonGroup::reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof buttons / sizeof Button, [=, &result](const auto i) {
			const auto action{ buttons[i].reactLeftMouseButtonUp(buttonEvent) };
			if (action != Action::START_ANIMATION) return Action::NONE;
			++buttonAnimationsCount;
			if (isAnimating) return Action::NONE;
			result = action;
			isAnimating = true;
		});
		return result;
	}

	Action ButtonGroup::reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent)
	{
		auto result{ Action::NONE };
		loop(sizeof buttons / sizeof Button, [=, &result](const auto i) {
			const auto action{ buttons[i].reactMouseLeaveWindow(windowEvent) };
			if (action != Action::START_ANIMATION) return Action::NONE;
			++buttonAnimationsCount;
			if (isAnimating) return Action::NONE;
			result = action;
			isAnimating = true;
		});
		return result;
	}

	Action ButtonGroup::step(const unsigned int dt)
	{
		auto result{ Action::NONE };
		loop(sizeof buttons / sizeof Button, [=, &result](const auto i) {
			const auto action{ buttons[i].step(dt) };
			if (action != Action::STOP_ANIMATION) return Action::NONE;
			--buttonAnimationsCount;
			if (buttonAnimationsCount != 0u) return Action::NONE;
			result = action;
			isAnimating = false;
		});
		return result;
	}

	void ButtonGroup::render()
	{
		loop(sizeof buttons / sizeof Button, [=](const auto i) {
			buttons[i].render();
		});
	}
}

#endif