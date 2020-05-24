#ifndef TEST

#include "RadialGradient.h"
#include "../View/ResourceView.h"
#include <SDL.h>
#include <SDL_image.h>
#include "../Struct/Point.h"
#include "../Any/Enums.h"

namespace ii887522::Calculator
{
	RadialGradient::RadialGradient(SDL_Renderer*const renderer) :
		ResourceView{ renderer, IMG_Load("res/main/radial_gradient.png"), Point{ 1024, 1024 } } /* 1024, 1024 to hide it */ { }

	Action RadialGradient::reactMouseMotion(const SDL_MouseMotionEvent& motionEvent)
	{
		position.x = motionEvent.x - (surface->w >> 1);
		position.y = motionEvent.y - (surface->h >> 1);
		return Action::NONE;
	}
}

#endif